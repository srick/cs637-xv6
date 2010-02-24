#include "types.h"
#include "user.h"
#include "thread.h"

void*
WTF(void *p) // work time fun
{
  printf(1, "thread %d[%x]\n", *(int*)p, p);
  exit();
}

void*
work1(void *p)
{
  int a, b, c;
  printf(1, "caller thread: (%d) %x [%x]\n",*(int*)p, p, &p);
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
  a = thread_create(work1, &a);
  thread_wait();
  b = thread_create(work1, &b);
  c = thread_create(work1, &c);
  thread_wait();
  exit();
}
