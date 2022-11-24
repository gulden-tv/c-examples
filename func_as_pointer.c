#include <stdio.h>

void g(void) {
    printf("g print\n");
}
void f(void) {
    printf("f print\n");
}
void func( void (*pf)(void) ) {
    pf();
}

void n(int x) {
    printf("n  print %d\n",x);
}

typedef void (*newtype)(int);

//void print( newtype pf )
void print( void (*pf)(int) ) {
    pf(10);
    pf(101);
}


int main()
{
    func(f);
    func(g);
    print(n);
    return 0;
}
