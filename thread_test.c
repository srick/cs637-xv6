#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "thread.h"
 
void* chill(int *arg) {
    printf(1, "Chillin' commenced.\n");
    int tic, toc;
    tic = tim();
    while((toc = tim()) < tic + (int)*arg)
        if(!(toc % 50))
            printf(1, "%d\n", tic + (int)*arg - toc);
    exit();
}
 
int main() {
    int arg = 100;
    printf(1, "Chillin' for %d tics.\n", arg);
    thread_create(&chill, (void *)&arg);
 
    int toc;
    int tic = tim();
    while((toc = tim()) < tic + 50);
 
    printf(1, "Just kidding! Chillin' for %d tics.\n", (arg = 500));
    thread_wait();
    printf(1, "\nChillin' complete.\n");
    exit();
}
