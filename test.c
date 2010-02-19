#include "types.h"
#include "user.h"
#include "thread.h"

void
WTF(int *p) // work time fun
{
  printf(1, "thread %d\n", *p);
  exit();
}

void
work1(int *p)
{
  int x, t0;
  printf(1, "PICARD: (%d) %x [%x]\n",*p, p, &p);
  thread_create(WTF, p);
  thread_create(WTF, p);
  thread_create(WTF, p);
  thread_wait();
  exit();
}

int
main(int argc, char* argv[])
{
  int tid;
  int i = 456;
  tid = thread_create(work1, &i);
  printf(1, "tid: %d\n", tid);
  thread_wait();
  exit();
}
