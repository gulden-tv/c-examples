#include <stdio.h>
#include <inttypes.h>

union floatbit {
    float value;
    struct {
        uint32_t mant : 23;
        uint32_t exp : 8;
        uint32_t sign : 1;
    } bit;
} f;

int main()
{
    f.value = 4.0;
    printf("Memory size is %lu\n",sizeof(f));
    printf("f.value = %f\n",f.value );
    printf("sign = %x\n",f.bit.sign);
    printf("exp = %x\n",f.bit.exp);
    printf("mantissa = %x\n",f.bit.mant);
    return 0;
}
