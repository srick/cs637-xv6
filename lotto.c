#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid, tickets;

  if(argc != 3){
    printf(1 ,"usage: lotto PID [-]tickets\n");
    exit();
  }
  pid = atoi(argv[1]);
  if(pid <= 0){
    printf(1, "PID must be number greater than 0\n");
    exit();
  }
  
  tickets = atoi(argv[2]);
  if(tickets <= 0){
    printf(1, "tickets must be a non zero number\n");
    exit();
  }
  
  if(lotto(pid, tickets))
    printf(1, "lotto failed - check pid\n");

  exit();
}
