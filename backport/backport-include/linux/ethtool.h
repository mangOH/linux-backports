#ifndef __BACKPORT_LINUX_ETHTOOL_H
#define __BACKPORT_LINUX_ETHTOOL_H
#include_next <linux/ethtool.h>
#include <linux/version.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(3,3,0)
static inline u32 ethtool_rxfh_indir_default(u32 index, u32 n_rx_rings)
{
	return index % n_rx_rings;
}
#endif

#ifndef ETHTOOL_FWVERS_LEN
#define ETHTOOL_FWVERS_LEN 32
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,31)
#define SUPPORTED_Backplane            (1 << 16)
#define SUPPORTED_1000baseKX_Full      (1 << 17)
#define SUPPORTED_10000baseKX4_Full    (1 << 18)
#define SUPPORTED_10000baseKR_Full     (1 << 19)
#define SUPPORTED_10000baseR_FEC       (1 << 20)

#define ADVERTISED_Backplane           (1 << 16)
#define ADVERTISED_1000baseKX_Full     (1 << 17)
#define ADVERTISED_10000baseKX4_Full   (1 << 18)
#define ADVERTISED_10000baseKR_Full    (1 << 19)
#define ADVERTISED_10000baseR_FEC      (1 << 20)
#endif

#endif /* __BACKPORT_LINUX_ETHTOOL_H */
