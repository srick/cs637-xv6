#include "types.h"
#include "user.h"
#include "thread.h"

void
work(int i){

  printf(1, "I LOVE THREADS: %d\n", i);
  
  exit();
}


int
main(int argc, char* argv[])
{

  thread_create(work, 1);

  wait();

}
