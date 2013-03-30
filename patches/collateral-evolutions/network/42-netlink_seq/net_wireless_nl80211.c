--- a/net/wireless/nl80211.c
+++ b/net/wireless/nl80211.c
@@ -5669,7 +5669,9 @@
 	spin_lock_bh(&rdev->bss_lock);
 	cfg80211_bss_expire(rdev);
 
+#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,1,0))
 	cb->seq = rdev->bss_generation;
+#endif
 
 	list_for_each_entry(scan, &rdev->bss_list, list) {
 		if (++idx <= start)