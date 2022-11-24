#include <stdio.h>
struct data {
    int year, month, day, hour, min, t;
};

struct temperature {
    int sum;
    int count;
    struct data max, min;
} month[12] = {0};

int main(void) {
    FILE *f = fopen("temperature_small.csv","r");
    
    int a;
    int y,m,d,h,mi,t;
    while( (a = (fscanf(f, "%d;%d;%d;%d;%d;%d",&y,&m,&d,&h,&mi,&t)))!= EOF) {
        if(a != 6){
            char error[100] = {0};
            fscanf(f,"%[^\n]",error);
            printf("Error string: %s\n",error);
        } else {
            //printf("Ok string: %d;%d;%d;%d;%d;%d\n",y,m,d,h,mi,t);
            month[m].sum += t;
            month[m].count++;
            
            // тут сделать логику поиска максимум и минимума
            month[m].max.t = t;
            month[m].max.day = d;
            month[m].max.month = m;
            month[m].max.hour = h;
            month[m].max.min = mi;
            
        }
    }
    
    // printf("Month %d sum = %d count = %d\n",2,month[2].sum, month[2].count);
    
    return 0;
}


