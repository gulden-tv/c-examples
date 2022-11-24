#include <stdio.h>
#include <stdlib.h>

int randomInt(int n) {
    return rand()%n; // random number from 0 to n-1
}

void packArray01(int a[], int n) {
    int i, lastElem=0, count0=0, count1=0;
    for(i=0; i<n; i++)
        if(a[i]==0) {
            count0++;
            if(lastElem==1)
            {
                printf("%d, ",count1);
                count1=0;
            }
            lastElem=0;
        } else  { //if(a[i]==1)
            count1++;
            if(lastElem==0)
            {
                printf("%d, ",count0);
                count0=0;
            }
            lastElem=1;
        }
    if(count1)
        printf("%d\n", count1);
    if(count0)
        printf("%d\n", count0);
}
void packArray2(int a[], int n) {
    int i,count=1;
    printf("[");
    if(a[0]==1)
        printf("0,");
    for(i=0; i<n-1;i++) {
        if(a[i]==a[i+1])
            count++;
        else {
            printf("%d,",count);
            count=1;
        }
    }
    printf("%d]\n",count);
    return;
}
int compression(int a[], int b[], int size) {
    
    int i, j = 0;
    int counter = 0;
    int lastElem = 0;
    if(a[0] == 1) {
        b[j++] = 0;
        lastElem = 1;
    }
    for (i = 1; i < size; i++) {
        counter++;
        if (a[i] != lastElem) {
                b[j++] = counter;
                counter = 0;
        }
        lastElem = a[i];
    }
    b[j++] = counter+1;
    return j;
}
#define N 100
int main() {
    int i,a[N];
    srand(120);
    for(i=N/2;i<N;i++)
        a[i]=randomInt(2);

    for(i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
    packArray2(a,N);
    return 0;
}

