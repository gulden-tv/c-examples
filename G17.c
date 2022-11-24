#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char *a, char *b) {
    char tmp=*a;
    *a=*b;
    *b=tmp;
}

void swapSymbols(char s[]) {
    int i=0, first=-1, last=-1;
    char tmp;
    while(s[i]) {
        if(s[i]!=' ') {
            if(first==-1)
                first=i;
            else if(last==-1)
                last=i;
        }
        if(first!=-1 && last!=-1) {
            swap(&s[first],&s[last]);
            first=last=-1;
        }
        //printf("first - %d last %d\n",first,last);
        i++;
    }
    return;
}

int main()
{
    char s[1001];
    scanf("%[^\n]",s);
    swapSymbols(s);
    printf("Answer\n%s\n",s);
    
    return 0;
}

