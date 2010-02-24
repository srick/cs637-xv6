#include "types.h"
#include "user.h"
//#include "kthread.h"
#include "thread.h"

mutex_t lock;

void* thread2_func (void *arg) {
  int *i;
  i = (int *) arg;
  mutex_lock(&lock);
  printf(1, "I got %d\n", *i);
  mutex_unlock(&lock);
  exit();
}

void* thread_func (void *arg) {
  int j;
  int *ptr;
  ptr = (int *) arg;
  mutex_lock(&lock);
  printf(1, "I am thread with pid %d and now I'll create 10 more threads and pass the array\n", getpid());
  mutex_unlock(&lock);
  for (j=0; j<10; j++) {
    int rc = thread_create (&thread2_func, (void *)(ptr+j));
    mutex_lock(&lock);
    printf (1, "created thread with pid %d\n", rc);
    mutex_unlock(&lock);
  }
  thread_wait();
  mutex_lock(&lock);
  printf(1, "exiting from thread_func\n");
  mutex_unlock(&lock);
  exit();
}

int main (void) {

  mutex_init(&lock);
  int i, rc;
  int arg[10] = {100,200,300,400,500,600,700,800,900,1000};
  for (i=0; i<1; i++) {
    rc = thread_create (&thread_func, (void*)  (arg));
    mutex_lock(&lock);
    printf (1, "created thread with pid %d\n", rc);
    mutex_unlock(&lock);
  }

  thread_wait();

  printf(1,"parent exiting\n");
  exit();
}






