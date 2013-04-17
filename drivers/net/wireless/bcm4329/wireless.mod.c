#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xa1f43910, "module_layout" },
	{ 0xe2c8396a, "sdio_writeb" },
	{ 0x51c7f893, "sdio_readb" },
	{ 0xbeef0151, "kmalloc_caches" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x235443d3, "complete_and_exit" },
	{ 0x17a142df, "__copy_from_user" },
	{ 0x349cba85, "strchr" },
	{ 0x6980fe91, "param_get_int" },
	{ 0x98082893, "__copy_to_user" },
	{ 0x97255bdf, "strlen" },
	{ 0xcccca482, "_test_and_clear_bit_le" },
	{ 0xc7ec6c27, "strspn" },
	{ 0x382782f5, "wake_lock_destroy" },
	{ 0x326df9e1, "vfs_stat" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0xa695ca4a, "remove_wait_queue" },
	{ 0x8539717e, "sdio_enable_func" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0xa2de2f9, "sdio_claim_irq" },
	{ 0xba890c4b, "skb_clone" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xf7802486, "__aeabi_uidivmod" },
	{ 0x94af7d90, "down_interruptible" },
	{ 0x1a41a5ed, "wake_lock" },
	{ 0x432fd7f6, "__gpio_set_value" },
	{ 0x6faea507, "filp_close" },
	{ 0x4e830a3e, "strnicmp" },
	{ 0xb3803aaa, "init_timer_key" },
	{ 0xa826aefc, "mutex_unlock" },
	{ 0x85df9b6c, "strsep" },
	{ 0x4a37af33, "___dma_single_cpu_to_dev" },
	{ 0xff964b25, "param_set_int" },
	{ 0xa2e85741, "_spin_lock_irqsave" },
	{ 0x6c1ce5ce, "strcspn" },
	{ 0x4f099aa5, "wake_unlock" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0x88ffee8b, "skb_realloc_headroom" },
	{ 0xb3a307c6, "si_meminfo" },
	{ 0x7d11c268, "jiffies" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xb788c8f, "netif_rx" },
	{ 0x5b89a27c, "__init_waitqueue_head" },
	{ 0xffd5a395, "default_wake_function" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0x6e765cdb, "wait_for_completion" },
	{ 0x70a7c1b2, "kernel_read" },
	{ 0xb7e4b99d, "sdio_writel" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x4a33da2d, "del_timer_sync" },
	{ 0xb5eeb329, "register_early_suspend" },
	{ 0x5f754e5a, "memset" },
	{ 0x64abb63, "netif_rx_ni" },
	{ 0xa2c2b6f4, "dev_alloc_skb" },
	{ 0x8d3894f2, "_ctype" },
	{ 0xa7c559b9, "__mutex_init" },
	{ 0xea147363, "printk" },
	{ 0x42224298, "sscanf" },
	{ 0xdb3877d, "___dma_single_dev_to_cpu" },
	{ 0x71c90087, "memcmp" },
	{ 0x1664f95b, "free_netdev" },
	{ 0xf397b9aa, "__tasklet_schedule" },
	{ 0x328a05f1, "strncpy" },
	{ 0xc501cab6, "register_netdev" },
	{ 0xbd28ef82, "dma_free_coherent" },
	{ 0xe2d8f40a, "sdio_readl" },
	{ 0x8bf22a4a, "wireless_send_event" },
	{ 0x3cfedb3f, "register_pm_notifier" },
	{ 0x84b183ae, "strncmp" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0x41979593, "skb_push" },
	{ 0x53db53b3, "mutex_lock" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x24051c6f, "down" },
	{ 0x8e80d4fd, "_spin_unlock_irqrestore" },
	{ 0xa5808bbf, "tasklet_init" },
	{ 0xf8e7c3ad, "mod_timer" },
	{ 0xe1a8727b, "do_wifi_cardetect" },
	{ 0xb3206600, "skb_pull" },
	{ 0x5093fa82, "_clear_bit_le" },
	{ 0x2196324, "__aeabi_idiv" },
	{ 0xc7b91ac, "dev_kfree_skb_any" },
	{ 0xd79b5a02, "allow_signal" },
	{ 0xbc505707, "dma_alloc_coherent" },
	{ 0x5a7f524f, "dev_open" },
	{ 0x61651be, "strcat" },
	{ 0x79ad224b, "tasklet_kill" },
	{ 0x405c6bf9, "sdio_readsb" },
	{ 0xe55dacb0, "sdio_unregister_driver" },
	{ 0x6f58a99f, "sdio_f0_writeb" },
	{ 0x7dceceac, "capable" },
	{ 0x9f984513, "strrchr" },
	{ 0x9aba63a3, "kmem_cache_alloc" },
	{ 0x105a856c, "sdio_release_irq" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0xbc763774, "alloc_netdev_mq" },
	{ 0x108e8985, "param_get_uint" },
	{ 0xe5bca160, "wake_lock_timeout" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0x4b7984d4, "eth_type_trans" },
	{ 0xc5b3f84c, "sdio_f0_readb" },
	{ 0x4101bbde, "param_set_copystring" },
	{ 0xc3c48806, "ether_setup" },
	{ 0x94dc300b, "tegra_ioremap" },
	{ 0x57a6504e, "vsnprintf" },
	{ 0xfeef01ca, "sched_setscheduler" },
	{ 0xd93c7eef, "__wake_up" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0xed7a306, "sdio_memcpy_toio" },
	{ 0x7db22c14, "sdio_writew" },
	{ 0x8bc18b61, "add_wait_queue" },
	{ 0x4fd6fa59, "_spin_unlock_bh" },
	{ 0x37a0cba, "kfree" },
	{ 0x2b0935de, "tegra_iounmap" },
	{ 0x9d669763, "memcpy" },
	{ 0x89e9d8e5, "wake_lock_init" },
	{ 0xda5ea696, "_test_and_set_bit_le" },
	{ 0xda6c388d, "prepare_to_wait" },
	{ 0x3285cc48, "param_set_uint" },
	{ 0x6c8d5ae8, "__gpio_get_value" },
	{ 0xc38be2b, "up" },
	{ 0x6892088c, "unregister_pm_notifier" },
	{ 0xfbdd8f5b, "finish_wait" },
	{ 0x7e9ebb05, "kernel_thread" },
	{ 0x8046f2c3, "sdio_reset_comm" },
	{ 0xb227ae83, "unregister_early_suspend" },
	{ 0xa7feb0a2, "unregister_netdev" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0xe5ada986, "complete" },
	{ 0x701d0ebd, "snprintf" },
	{ 0xeafc6cd7, "NvOdmWlanEnable" },
	{ 0x9f0be6ca, "__netif_schedule" },
	{ 0x49e182c0, "param_get_string" },
	{ 0xa7cd57f4, "sdio_readw" },
	{ 0x5aa6a3c4, "sdio_register_driver" },
	{ 0xb808a2aa, "consume_skb" },
	{ 0x40ab656a, "sdio_memcpy_fromio" },
	{ 0xdc799aae, "sdio_claim_host" },
	{ 0xe9a23a48, "_spin_lock_bh" },
	{ 0x6189b10e, "skb_put" },
	{ 0x1b28c2d4, "down_timeout" },
	{ 0xad8b059b, "sdio_set_block_size" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0xdc43a9c8, "daemonize" },
	{ 0xb296cc69, "sdio_disable_func" },
	{ 0x618ffac1, "sdio_release_host" },
	{ 0xe914e41e, "strcpy" },
	{ 0xa41accce, "filp_open" },
	{ 0x313341a3, "_set_bit_le" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("sdio:c*v02D0d0000*");
MODULE_ALIAS("sdio:c*v02D0d0492*");
MODULE_ALIAS("sdio:c*v02D0d04C6*");
MODULE_ALIAS("sdio:c*v02D0d4329*");
MODULE_ALIAS("sdio:c*v02D0d4319*");
