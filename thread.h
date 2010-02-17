#define thread_create(routine, arg) \
  void *sp = malloc(1024); \
  int pid = thread_creat(sp); \
  if(!pid) routine(arg); \
  
int thread_creat(void *sp);
