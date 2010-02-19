#include "types.h"
#include "user.h"
#include "thread.h"

void
work(int *p)
{
  int x;
  printf(1, "I LOVE THREADS: %x[%x]\n", p, &p);
  printf(1, "I LOVE THREADS: %x[%x]\n", x, &x);

  //  tim();
  exit();
}


int
main(int argc, char* argv[])
{
  int tid;
  int i = 0;
  printf(1, "calling thread_create %x\n", &i);

  tid = thread_create(&work, &i);
  printf(1, "tid: %d\n", tid);
  tim();
  thread_wait();
  printf(1, "result: %d\n", i);
  exit();
}
