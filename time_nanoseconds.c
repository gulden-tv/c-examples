#include <stdio.h>
#include <time.h>
/*
struct timespec {
    time_t   tv_sec;        // seconds
    long     tv_nsec;       // nanoseconds
};
*/
struct timespec tstart, tstop;

int main()
{
    timespec_get(&tstart, TIME_UTC);
    printf("start = %ld s %ld ns\n",tstart.tv_sec,tstart.tv_nsec);
    printf("Hello\n");
    timespec_get(&tstop, TIME_UTC);
    printf("stop = %ld s %ld ns",tstop.tv_sec,tstop.tv_nsec);
    printf("duration = %f seconds\n",(tstop.tv_nsec - tstart.tv_nsec)/1e9);
    return 0;
}
