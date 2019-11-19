/*
 * The _const versions of the functions avoid unecessary duplication of data if the source is
 * read-only. We just eat the cost of the extra memory on versions which don't support the newer
 * functions.
 *
 * a4bb1e43e22d3cade8f942fc6f95920248eb2fd0 introduced kstrdup_const and kfree_const
 * 0a9df786a6ae2f898114bdd242b64920dedf53bd introduced kvasprintf_const
 */

@ kfree_const @
expression p;
@@
+#if LINUX_VERSION_IS_LESS(4,3,0)
+kfree(p);
+#else
 kfree_const(p);
+#endif

@ kstrdup_const @
expression r, s, gfp;
@@
+#if LINUX_VERSION_IS_LESS(4,3,0)
+r = kstrdup(s, gfp);
+#else
 r = kstrdup_const(s, gfp);
+#endif

@ kvasprintf_const @
expression r, gfp, fmt, va;
@@
+#if LINUX_VERSION_IS_LESS(4,3,0)
+r = kvasprintf(gfp, fmt, va);
+#else
 r = kvasprintf_const(gfp, fmt, va);
+#endif
