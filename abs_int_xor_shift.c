#include <stdio.h>

int main(void)
{
    int num, abs;
    int mask;
    unsigned int sign_bit;
    scanf("%d",&num);
    abs = num;
    sign_bit = num>>31;
    mask = num>>31;
    abs = num^mask + sign_bit;
    printf("abs(%d) = %d\n",num, abs);
    return 0;
}
