#include <stdio.h>


int main(void)
{
    int a,b;
    char error[100];
    printf("Input two numbers: ");
    while( scanf("%d%d",&a,&b)!=2 ) {
        scanf("%s",error);
        printf("%s not number, please input correct numbers: ",error);
    }
    printf("You input %d %d\n",a,b);
    return 0;
}
