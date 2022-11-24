#include <stdio.h>
enum {SIZE = 10};

void scanMatrix(int size, int m[][size]) {
    for(size_t i=0; i<size; i++) {
        for(size_t j=0; j<size; j++) {
            scanf("%d", &m[i][j]);
        }
    }
}
int maxFind(int size, int a[]) {
    size_t iMax = 0;
    for(size_t i=1; i<size; i++) {
        if(a[iMax]<a[i]) {
            iMax = i;
        }
    }
    return a[iMax];
}

int main(void) {
    int matrix[SIZE][SIZE], sum = 0;
    scanMatrix(SIZE, matrix);
    
    for(size_t i=0; i<SIZE; i++) {
        sum += maxFind(SIZE, matrix[i]);
    }
    
    printf("%d\n", sum);
    
    return 0;
}



