#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <math.h>
enum {RESET=0, RED=31, GREEN, YELLOW};

void color(uint32_t color) {
    if(color)
        printf("\033[0;%um",color);
    else
        printf("\033[0m");
}

//Перевод вещетсвенного числа в двоичный вид
void print_float_bin(float *num) {
    uint32_t *fi = num;
    //memcpy(&fi, &num, 4); //копируем память
    for(int32_t i=31; i>=0; i--) {
        if(i==30 || i==22)
            putchar(' ');
        putchar('0' + (((*fi)>>i)&1) );
    }
    color(RED);
    printf("\nS ");
    color(YELLOW);
    printf("E");
    color(GREEN);
    printf("        M\n");
    color(RESET);
}


int main()
{
    float f = 2.0;
    float f1 = 1.0;
    
    
    print_float_bin(&f);
    printf("\n");
    print_float_bin(&f1);
    printf("\n");
    
    printf("f = %f f1 = %f\n",f,f1);
    
    if( fabs(f-f1) < 0.00001 )
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}


