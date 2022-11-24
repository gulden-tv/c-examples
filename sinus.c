#include <stdio.h>
//вычислить n факториал
int fact(int n){
    int i,f=1;
    for(i=2;i<=n;i++)
        f*=i;
    return f;
}
// возведение числа x в степень p
float power(float x, int p){
    int i; float power=1;
    for(i=0;i<p;i++)
        power*=x;
    return power;
}
//модуль числа
float floatabs(float x){
    if(x<0)
        return -x;
    return x;
}
float convert2radian(float x) {
    return 3.14159/180*x;
}
float sinus(float x) {
    float sum=0, elem, xrad;
    elem = xrad = convert2radian(x); // переводим градусы в радианы
    int i=3, z=-1;
    while(floatabs(elem) > 0.001) {
        sum+=elem;
        elem = z * (power(xrad,i) / fact(i));
        //printf("%d * power(%f,%d)=%f / fact(%d)=%d\n",z,xrad,i,power(xrad,i), i, fact(i));
        i=i+2;
        z=-z;
    }
    return sum;
}
float cosinus(float x) {
    float sum=0, elem, xrad;
    elem = 1;
    xrad = convert2radian(x); // переводим градусы в радианы
    int i=2, z=-1;
    while(floatabs(elem) > 0.001) {
        sum+=elem;
        elem = z * (power(xrad,i) / fact(i));
        //printf("%d * power(%f,%d)=%f / fact(%d)=%d\n",z,xrad,i,power(xrad,i), i, fact(i));
        i=i+2;
        z=-z;
    }
    return sum;
}
int main() {
    float x;
    //printf("Input x: ");
    scanf("%f",&x);
    printf("%.3f\n ",cosinus(x));
    return 0;
}
