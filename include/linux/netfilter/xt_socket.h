#ifndef _XT_SOCKET_H
#define _XT_SOCKET_H

enum {
	XT_SOCKET_TRANSPARENT = 1 << 0,
};

struct xt_socket_mtinfo1 {
	__u8 flags;
};

void xt_socket_put_sk(struct sock *sk);
struct sock *xt_socket_get4_sk(const struct sk_buff *skb,
                               struct xt_match_param *par);

#endif /* _XT_SOCKET_H */
