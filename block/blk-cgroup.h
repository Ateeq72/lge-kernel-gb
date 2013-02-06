#ifndef _BLK_CGROUP_H
#define _BLK_CGROUP_H
/*
 * Common Block IO controller cgroup interface
 *
 * Based on ideas and code from CFQ, CFS and BFQ:
 * Copyright (C) 2003 Jens Axboe <axboe@kernel.dk>
 *
 * Copyright (C) 2008 Fabio Checconi <fabio@gandalf.sssup.it>
 *		      Paolo Valente <paolo.valente@unimore.it>
 *
 * Copyright (C) 2009 Vivek Goyal <vgoyal@redhat.com>
 * 	              Nauman Rafique <nauman@google.com>
 */

#include <linux/cgroup.h>

#if defined(CONFIG_BLK_CGROUP) || defined(CONFIG_BLK_CGROUP_MODULE)

#ifndef CONFIG_BLK_CGROUP
/* When blk-cgroup is a module, its subsys_id isn't a compile-time constant */
extern struct cgroup_subsys blkio_subsys;
#define blkio_subsys_id blkio_subsys.subsys_id
#endif

enum stat_type {
	/* Total time spent (in ns) between request dispatch to the driver and
	 * request completion for IOs doen by this cgroup. This may not be
	 * accurate when NCQ is turned on. */
	BLKIO_STAT_SERVICE_TIME = 0,
	/* Total bytes transferred */
	BLKIO_STAT_SERVICE_BYTES,
	/* Total IOs serviced, post merge */
	BLKIO_STAT_SERVICED,
	/* Total time spent waiting in scheduler queue in ns */
	BLKIO_STAT_WAIT_TIME,
	/* Number of IOs merged */
	BLKIO_STAT_MERGED,
	/* All the single valued stats go below this */
	BLKIO_STAT_TIME,
	BLKIO_STAT_SECTORS,
#ifdef CONFIG_DEBUG_BLK_CGROUP
	BLKIO_STAT_DEQUEUE
#endif
};

enum stat_sub_type {
	BLKIO_STAT_READ = 0,
	BLKIO_STAT_WRITE,
	BLKIO_STAT_SYNC,
	BLKIO_STAT_ASYNC,
	BLKIO_STAT_TOTAL
};

struct blkio_cgroup {
	struct cgroup_subsys_state css;
	unsigned int weight;
	spinlock_t lock;
	struct hlist_head blkg_list;
};

struct blkio_group_stats {
	/* total disk time and nr sectors dispatched by this group */
	uint64_t time;
	uint64_t sectors;
	uint64_t stat_arr[BLKIO_STAT_MERGED + 1][BLKIO_STAT_TOTAL];
#ifdef CONFIG_DEBUG_BLK_CGROUP
	/* How many times this group has been removed from service tree */
	unsigned long dequeue;
#endif
};

struct blkio_group {
	/* An rcu protected unique identifier for the group */
	void *key;
	struct hlist_node blkcg_node;
	unsigned short blkcg_id;
#ifdef CONFIG_DEBUG_BLK_CGROUP
	/* Store cgroup path */
	char path[128];
#endif
	/* The device MKDEV(major, minor), this group has been created for */
	dev_t dev;
    
	/* Need to serialize the stats in the case of reset/update */
	spinlock_t stats_lock;
	struct blkio_group_stats stats;
};

typedef void (blkio_unlink_group_fn) (void *key, struct blkio_group *blkg);
typedef void (blkio_update_group_weight_fn) (struct blkio_group *blkg,
unsigned int weight);

struct blkio_policy_ops {
	blkio_unlink_group_fn *blkio_unlink_group_fn;
	blkio_update_group_weight_fn *blkio_update_group_weight_fn;
};

struct blkio_policy_type {
	struct list_head list;
	struct blkio_policy_ops ops;
};

/* Blkio controller policy registration */
extern void blkio_policy_register(struct blkio_policy_type *);
extern void blkio_policy_unregister(struct blkio_policy_type *);

#else

struct blkio_group {
};

struct blkio_policy_type {
};

static inline void blkio_policy_register(struct blkio_policy_type *blkiop) { }
static inline void blkio_policy_unregister(struct blkio_policy_type *blkiop) { }

#endif

#define BLKIO_WEIGHT_MIN	100
#define BLKIO_WEIGHT_MAX	1000
#define BLKIO_WEIGHT_DEFAULT	500

#ifdef CONFIG_DEBUG_BLK_CGROUP
static inline char *blkg_path(struct blkio_group *blkg)
{
	return blkg->path;
}
void blkiocg_update_dequeue_stats(struct blkio_group *blkg,
                                  unsigned long dequeue);
#else
static inline char *blkg_path(struct blkio_group *blkg) { return NULL; }
static inline void blkiocg_update_dequeue_stats(struct blkio_group *blkg,
                                                unsigned long dequeue) {}
#endif

#if defined(CONFIG_BLK_CGROUP) || defined(CONFIG_BLK_CGROUP_MODULE)
extern struct blkio_cgroup blkio_root_cgroup;
extern struct blkio_cgroup *cgroup_to_blkio_cgroup(struct cgroup *cgroup);
extern void blkiocg_add_blkio_group(struct blkio_cgroup *blkcg,
                                    struct blkio_group *blkg, void *key, dev_t dev);
extern int blkiocg_del_blkio_group(struct blkio_group *blkg);
extern struct blkio_group *blkiocg_lookup_group(struct blkio_cgroup *blkcg,
                                                void *key);
void blkio_group_init(struct blkio_group *blkg);
void blkiocg_update_timeslice_used(struct blkio_group *blkg,
                                   unsigned long time);
void blkiocg_update_dispatch_stats(struct blkio_group *blkg, uint64_t bytes,
                                   bool direction, bool sync);
void blkiocg_update_completion_stats(struct blkio_group *blkg,
                                     uint64_t start_time, uint64_t io_start_time, bool direction, bool sync);
void blkiocg_update_io_merged_stats(struct blkio_group *blkg, bool direction,
                                    bool sync);
#else
struct cgroup;
static inline struct blkio_cgroup *
cgroup_to_blkio_cgroup(struct cgroup *cgroup) { return NULL; }

static inline void blkio_group_init(struct blkio_group *blkg) {}
static inline void blkiocg_add_blkio_group(struct blkio_cgroup *blkcg,
                                           struct blkio_group *blkg, void *key, dev_t dev) {}

static inline int
blkiocg_del_blkio_group(struct blkio_group *blkg) { return 0; }

static inline struct blkio_group *
blkiocg_lookup_group(struct blkio_cgroup *blkcg, void *key) { return NULL; }
static inline void blkiocg_update_timeslice_used(struct blkio_group *blkg,
                                                 unsigned long time) {}
static inline void blkiocg_update_dispatch_stats(struct blkio_group *blkg,
                                                 uint64_t bytes, bool direction, bool sync) {}
static inline void blkiocg_update_completion_stats(struct blkio_group *blkg,
                                                   uint64_t start_time, uint64_t io_start_time, bool direction,
                                                   bool sync) {}
static inline void blkiocg_update_io_merged_stats(struct blkio_group *blkg,
                                                  bool direction, bool sync) {}
#endif
#endif /* _BLK_CGROUP_H */