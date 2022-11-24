#include <stdio.h>
#include <stdlib.h>
//G2
int main()
{
    char s[27]={0};
    int i,n,j;
    scanf("%d",&n);
    for(i=0,j=0;i<n;i+=2,j++) {
        s[i]='A'+j;
        s[i+1]='2'+i%8;
    }
    printf("%s\n",s);
    return 0;
}

