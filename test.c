#include "types.h"
#include "user.h"
#include "thread.h"

void
WTF(int *p) // work time fun
{
  printf(1, "thread %d[%x]\n", *p, p);
  exit();
}

void
work1(int *p)
{
  int a, b, c, x, t0;
  printf(1, "caller thread: (%d) %x [%x]\n",*p, p, &p);
  a = thread_create(WTF, &a);
  b = thread_create(WTF, &b);
  c = thread_create(WTF, &c);
  thread_wait();
  exit();
}

int
main(int argc, char* argv[])
{
  int a, b, c;
  int i = 456;
  a = thread_create(WTF, &a);
  thread_wait();
  b = thread_create(WTF, &b);
  c = thread_create(WTF, &c);
  thread_wait();
  //for(;;);
  exit();
}
