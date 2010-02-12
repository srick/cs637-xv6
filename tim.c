#include "types.h"
#include "stat.h"
#include "user.h"


int
spin(int n)
{
  int t0, tf;

  volatile uint balls = 82345678;
  t0 = tim();

  while(balls--);
  
  tf = tim() - t0;
   
  printf(1, "Spinner %d: %d ticks\n",n, tf);

  exit();
}

int
main(int argc, char *argv[])
{
  int kid1;

  kid1 = fork();
  
  if(kid1 == 0)
    spin(800);


  if(kid1 > 0){
    lotto(kid1, 800);
    spin(100);
  }
  
  exit();
}

