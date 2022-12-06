#include <stdio.h>
#include <stdlib.h>
#include "memory_leak.h"

int main(void) {
    int *p = malloc( sizeof(int) );
    int *ar = malloc(sizeof(int)*10); // this unfree memory example

    *p = 5;
    free(p);
    p = malloc(sizeof(int));
    
    for(int i = 0; i<5; i++) {
        p = malloc( sizeof(int) * i*i*i );
        if(i%2) {
            free(p);
        }
    }

    free(p); // try to comment this and uncomment
    printMemoryLeak();
    return 0;
}
