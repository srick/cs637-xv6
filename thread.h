static int 
thread_create( void *(*start_routine)(void*), void *arg){
  void *sp = malloc(1024);
  int pid = thread(sp);
  if(!pid) (*start_routine)(arg);
  return pid;
}

struct mutex{
  uint flag;
};

typedef struct mutex mutex_t;

struct cond{
  uint flag;
};

typedef struct cond cond_t;

int mutex_lock(mutex_t *m);
int mutex_unlock(mutex_t *m); 
int cond_wait(cond_t *c, mutex_t *m);
int cond_signal(cond_t *c);
