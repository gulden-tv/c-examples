#include <stdio.h>
#include <string.h>
#include <stdint.h>

char s[]="hello";
char text[]="hello hello   ABCVD hhh hello worldworld helo hello";
/*
char s[]="135";
char text[]="21355678135";
 */
uint64_t p=1979; // p = 10 для наглядности

uint64_t getHash(char *s) {
    uint64_t h=0;
    while(*s) {
        h *= p;
        h += *s++; // *s++ - '0'
    }
    return h;
}

void getHashArray(char *s, size_t hsize, uint64_t hash[]) {
    uint64_t p_pow = 1;
    for(size_t i=1; i< hsize; i++)
        p_pow *= p;
    // printf("p_pow = %llu\n",p_pow);
    hash[0] = *s; // *s -'0'
    for(size_t i=1; s[i]; i++) {
        hash[i] = (hash[i-1]%p_pow) * p + s[i]; // - '0'
    }
}

int main ()
{
    size_t lens = strlen(s);
    size_t lent = strlen(text);
    uint64_t hs[lent], hashs;
    hashs = getHash(s);
    // printf("s hash = %llu\n",hashs);
    getHashArray(text, lens, hs);
    printf("String = '%s' found in text in:\n",s);
    for(size_t i=0; i< lent; i++)
        if(hashs == hs[i])
            printf("position %zu\n", i - lens + 1);
    printf("\n");
    return 0;
}
