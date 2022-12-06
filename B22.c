#include <stdio.h>
 
int main(void) {
    unsigned i,n,k, max=0, mask;
    scanf("%u%u", &n,&k);
    mask = (1<<k) - 1;
    //printf("mask = %x\n",mask);
    for(i=0;i<32;i++) {
        if( (n&mask) > max) {
            max = mask&n;
        }
        n >>= 1;
    }
    printf("%u\n",max);
    return 0;
}
