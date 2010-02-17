int thread(void *);

#define thread_create(routine, arg) \
  void *sp = malloc(1024); \
  int pid = thread(sp);			\
  if(!pid) routine(arg);
  
