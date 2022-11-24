#include <stdio.h>
#include <stdlib.h>

void sort_array(unsigned int a[], int size) {
    int i,tmp,is_sort=0;
    while(is_sort==0) {
        is_sort=1;
        for(i=0;i<size-1;i++) {
            if(a[i]>a[i+1]) {
                tmp=a[i];
                a[i]=a[i+1];
                a[i+1]=tmp;
                is_sort=0;
            }
        }
    }
}
void print_array(unsigned int a[], int size) {
    int i;
    for(i=0;i<size;i++)
        printf("%d ",a[i]);
}
int main()
{
    char s[1001]={0};
    unsigned int i, ans[1000], ians=0,num=0, is_num=0;
    scanf("%[^\n]1000",s);
    for(i=0;s[i];i++)
        if(s[i]>='0' && s[i]<='9') {//переводим строку в число
            num*=10;
            num+=s[i]-'0';
            is_num=1;
        } else if(is_num){//заносим число в массив
            ans[ians++]=num;
            num=0;
            is_num=0;
        }
    if(is_num)//если строка заканчивается числом
        ans[ians++]=num;
    
    sort_array(ans,ians);
    print_array(ans,ians);
    return 0;
}


