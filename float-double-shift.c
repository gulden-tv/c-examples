#include <stdio.h>
#include <string.h>


int main() {
    float f=0;
    uint32_t u = (127+3)<<23; 
    float *pf = &u;
    printf("%.0f\n", *pf);
    
    unsigned long long int llu = 1023+3;// 2^3
    llu <<=52;
    double lf=0;
    double *plf = &llu;
    // memcpy(&lf,&llu,8);
    printf("%.0lf\n",*plf);
    return 0;
}
