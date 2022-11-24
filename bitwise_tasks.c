#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
struct pack_array {
    uint32_t array; // массив из 0 и 1
    uint32_t count0 : 8; // 0 массиве
    uint32_t count1 : 8; // 1 массиве
} pa = {0};
void array2struct(int ar[], struct pack_array *ps) {
    ps->array = 0;
    for(size_t i=0; i<32; i++) {
        ps->array |= ar[i]<<(31-i);
        ps->count0 += !(ar[i]&0x1);
        ps->count1 += ar[i]&0x1;
    }
}
int extractExp(float f) {
    union {
        float f;
        struct {
            uint32_t mantissa : 23;
            uint32_t exp : 8;
            uint32_t s : 1;
        } field;
    } fl;
    fl.f = f;
    return fl.field.exp;
}
_Bool difSign(int32_t a, int32_t b) {
    return (a>>31)^(b>>31);
}
int div1IfEven(int a) {
    return a - !(a&0x1);
}
_Bool isEqual(int a, int b) {
    return !(a^b);
}
void changeSign(float *f) {
    union {
        float f;
        uint32_t u;
    } tmp;
    tmp.f = *f;
    tmp.u = tmp.u ^ 0x80000000;
    *f = tmp.f;
}
uint32_t bitrevers(uint32_t n) {
    uint32_t r=0;
    while(n) {
        r <<= 1;
        r |= n&0x1;
        n >>= 1;
    }
    return r;
}
struct test {
    int32_t i;
    int16_t s;
    int32_t j;
};

int main()
{
    struct test t;
    int8_t *pt;
    t = (struct test){0};
    pt = &t;
    printf("sizeof = %zu\n",sizeof t);
    for(size_t i=0; i<sizeof(t); i++)
        printf("%x ",0xff&*pt++);
    printf("\n");
    return 0;
}

