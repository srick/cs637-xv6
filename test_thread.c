#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
//#include "fcntl.h"
//#include "kthread.h"
#include "thread.h"

mutex_t lock;

void* thread_func (void *arg) {
  int *ptr;
  ptr = (int *) arg;	
  int i = *ptr;
  mutex_lock(&lock);
  printf(1, "I am thread with pid %d and I got %d\n", getpid(), i);
  mutex_unlock(&lock);
  exit();
}

int main (void) {

  mutex_init(&lock);
  int i, rc;
  int arg[10] = {100,200,300,400,500,600,700,800,900,1000};
  for (i=0; i<10; i++) {
    rc = thread_create (&thread_func, (void*)  (arg+i));
    mutex_lock(&lock);
    printf (1, "created thread with pid %d\n", rc);
    mutex_unlock(&lock);
  }

  thread_wait();

  printf(1,"parent exiting\n");
  exit();
}






