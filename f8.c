#include <stdio.h>

int main(void) {
    int n, xor=0, min=0, max=0;
    do {
        scanf("%d", &n);
        if( n && (min == 0 || min>n) )
            min = n;
        if( n && (max == 0 || max<n))
            max = n;
        xor ^= n;
    }while(n);
    while(min<=max)
        xor ^= min++;
    printf("%d\n", xor);
    return 0;
}
