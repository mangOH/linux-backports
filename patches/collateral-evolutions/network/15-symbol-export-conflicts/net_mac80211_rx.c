--- a/net/mac80211/rx.c
+++ b/net/mac80211/rx.c
@@ -3317,7 +3317,12 @@
  drop:
 	kfree_skb(skb);
 }
+#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,32))
 EXPORT_SYMBOL(ieee80211_rx);
+#else
+EXPORT_SYMBOL(mac80211_ieee80211_rx);
+#endif
+
 
 /* This is a version of the rx handler that can be called from hard irq
  * context. Post the skb on the queue and schedule the tasklet */