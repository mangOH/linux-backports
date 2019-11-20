/*
 * Prior to kernel 4.2 the percpu-rwsem functions weren't exported and thus they
 * are not available for use by backportd modules.  To solve this, we re-write
 * the code change percpu_* -> percpu_backport_* and define the backport macros
 * in the backport-include directory.
 */

@@
identifier sem;
type t;
@@
t {
...
+#if LINUX_VERSION_IS_LESS(4,2,0)
+struct rw_semaphore sem;
+#else
 struct percpu_rw_semaphore sem;
+#endif /* < 4.2.0 */
...
};

@@
expression sem;
@@
-percpu_init_rwsem(sem)
+percpu_backport_init_rwsem(sem)

@@
expression sem;
@@
-percpu_down_read(sem)
+percpu_backport_down_read(sem)

@@
expression sem;
@@
-percpu_down_read_trylock(sem)
+percpu_backport_down_read_trylock(sem)

@@
expression sem;
@@
-percpu_down_write(sem)
+percpu_backport_down_write(sem)

@@
expression sem;
@@
-percpu_free_rwsem(sem)
+percpu_backport_free_rwsem(sem)

@@
expression sem;
@@
-percpu_up_read(sem)
+percpu_backport_up_read(sem)

@@
expression sem;
@@
-percpu_up_write(sem)
+percpu_backport_up_write(sem)

