#include "types.h"
#include "stat.h"
#include "user.h"

int
spin(int n, int t0)
{
  int tf;

  volatile uint balls = 0;
  t0 = tim();

  while((tim() - t0) < 10000)
    balls++;
  
  printf(1, "Spinner %d: %d balls\n", n, balls);
  exit();
}

int
main(int argc, char *argv[])
{
  int kid1;
  int t0 = tim();
  int num = atoi(argv[1]);


  kid1 = fork();
  
  if(kid1 == 0)
    spin(num, t0);


  if(kid1 > 0){
    lotto(kid1, num);
    spin(100, t0);
  }
  
  exit();
}

