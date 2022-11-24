#include <stdio.h>
#include <string.h>

int main()
{
    char s[1001]={0};
    int i, lens, point=0, slash=0;
    //printf("%d\n",scanf("%s",s));//example
    FILE *fin = fopen("input.txt","r");
    FILE *fou = fopen("output.txt","w");
    fscanf(fin, "%[^\n]",s);
    lens=strlen(s);
    for(i=lens-1;i>=0;i--) {
        if(s[i]=='.')
            point=i;
        else if(s[i]=='/') {
            slash=i;
            break;// встретили '/' прервать
        }
    }
    if(point>slash) {// /doc/file.com
        strcpy(s+point,".html");
    } else { // /doc.txt/file
        strcat(s,".html");
    }
    fprintf(fou, "%s\n",s);
    return 0;
}
