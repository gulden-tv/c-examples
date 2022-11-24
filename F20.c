#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int abs(int n) {
    if(n<0)
        return -n;
    return n;
}
int multDigit(int n) {
    int mult=1, num=n;
    while(n) {
        if( (n%10)%2==num%2 )
            mult*=n%10;
        n/=10;
    }
    return mult;
}
int main(void)
{
    const int N=10;
    int i,j,a[N], odd=0, even=0;

    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    
    //считаю количество четных и нечетных
    for(i=0;i<N;i++) {
        if(a[i]%2)
            odd++;
        else
            even++;
    }
    if(even>odd) {
        for(i=0;i<N;i++)
            if(a[i]%2)
                a[i]=multDigit(a[i]);
    } else {
        for(i=0;i<N;i++)
            if(a[i]%2==0)
                a[i]=multDigit(a[i]);
    }
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
    
    return 0;
}

