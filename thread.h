/*
#define thread_create(routine, arg)				\
  void *sp = malloc(1024);					\
  int pid = thread(sp);						\
  if(!pid) {printf(1,"pid %d [%x]\n",pid, arg);routine(arg);}	\
  else printf(1,"%d arg [%x]\n", pid, arg);
*/

static int 
thread_create( void *(*start_routine)(void*), void *arg){
  void *sp = malloc(32);
  int pid = thread(sp);
  if(!pid) (*start_routine)(arg);
  return pid;
}
