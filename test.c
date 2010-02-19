#include "types.h"
#include "user.h"
#include "thread.h"

void
WTF(int *p) // work time fun
{
  printf(1, "8=====D - - - %d\n", *p);
  exit();
}

void
work1(int *p)
{
  int x, t0;
  printf(1, "PICARD: (%d) %x [%x]\n",*p, p, &p);
  thread_create(WTF, p);
  thread_wait();
  thread_create(WTF, p);
  thread_wait();
  thread_create(WTF, p);
  thread_wait();
  exit();
}

void
work(int *p)
{
  int x, t0;
  printf(1, "I LOVE THREADS: (%d) %x [%x]\n",*p, p, &p);
  thread_create(work1, p);
  thread_wait();
  exit();
}

int
main(int argc, char* argv[])
{
  int tid;
  int i = 456;
  tid = thread_create(work, &i);
  printf(1, "spawn %d overlords\n", tid);
  thread_wait();
  exit();
}
