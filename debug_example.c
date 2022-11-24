#include <stdio.h>


void func() {
    int i = 0;
    printf("hello func\n");
    i++;
}

int main() {
    unsigned int u=5;
    int ar[10] = {11,22,33,44};
    int *pa = ar;
    while(u>0) {
        printf("This is debug message\n");
        func();
        u--;
    }
    return 0;
}
