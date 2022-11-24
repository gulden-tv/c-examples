#include <stdio.h>

int main(void) {
    int tot_chars = 0;     /* total characters */
    int tot_lines = 0;     /* total lines */
    int tot_words = 0;     /* total words */
    int in_space = 1;
    int c, last = '\n';
    char fname[256];
    printf("Input file name: ");
    scanf("%255s",fname);
    FILE *f = fopen(fname,"r");
    
    while ((c = fgetc(f)) != EOF) {
        last = c;
        tot_chars++;
        if (c == '\n') {
            tot_lines++;
            in_space = 1;
        }else if (c==' ') {
            in_space = 1;
        } else {
            tot_words += in_space;
            in_space = 0;
        }
    }
    
    //if (last != '\n') {
        /* count last line if not linefeed terminated */
    //    tot_lines++;
    //}
    fclose(f);
    printf("Lines  Words  Characters\n");
    printf(" %3d %3d    %3d\n", tot_lines, tot_words, tot_chars);
    
    return 0;
}
