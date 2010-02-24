#include "x86.h"
#include "user.h"
#include "thread.h"

void
mutex_init(mutex_t *m)
{

}

int
mutex_lock(mutex_t *m)
{

}

int
mutex_unlock(mutex_t *m)
{


} 

int
cond_wait(cond_t *c, mutex_t *m)
{
  

}

int
cond_signal(cond_t *c)
{


}

int
thread_create( void *(*start_routine)(void*), void *arg)
{
  void *sp = malloc(1024);
  int pid = thread(sp);
  if(!pid) (*start_routine)(arg);
  return pid;
}
