/*
#define thread_create(routine, arg) \
  void *sp = malloc(1024);	    \
  int pid = thread(sp);		    \
  if(!pid){routine(arg);printf(1,"pid %d %x[%x]\n",pid, *arg, arg);}	\
  printf(1,"%d arg %x[%x]\n", pid,*arg, arg);
*/

static int 
thread_create( void *(*start_routine)(void*), void *arg){
  void *sp = malloc(1024);
  int pid = thread(sp);
  if(!pid) (*start_routine)(arg);
  else 
    return pid;
}

