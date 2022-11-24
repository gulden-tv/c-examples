#include <stdio.h>
#include <inttypes.h>

int main (void)
{
    uint32_t count=0, n;
    uint8_t is_two_digits=0;
    
    scanf ("%" PRIu32, &n);
    
    while ( (n/10)!=0 )
    {
        if (n%10 == (n/10)%10)//сравниваем две сосдние цифры
            is_two_digits = 1;
        
        n/=10;//отсекаем младшую цифру
    }
    
    if (is_two_digits)
        printf ("YES\n");
    else
        printf ("NO\n");
    return 0;
}
