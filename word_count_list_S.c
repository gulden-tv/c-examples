#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char *word;
    struct list *next;
}list;
void addword(char **dest, char *source) {
    //Добавляем слово к элементу
    *dest=malloc(strlen(source)+1);
    strcpy(*dest,source);
}
void add2list(list **l, char *w) {
    // Итеративная функция добавления элемента в список
    list *ptmp=*l, *new, *ins=NULL;
    while( ptmp && strcmp(ptmp->word,w) <=0 ) {
        ins=ptmp;
        ptmp=ptmp->next;
    }
    new=malloc(sizeof(list));
    addword(&(new->word),w);
    new->next=NULL;
    if(ptmp == *l) {
        new->next=*l;
        *l=new;
    } else {
        new->next=ptmp;
        ins->next=new;
    }
}
void add2listRecurs(list **l, char *w) {
    // Рекурсивная функция добавления элемента в список
    if( *l == NULL || strcmp((*l)->word,w) >= 0 ) {
        list *new = malloc(sizeof(list));
        addword(&(new->word),w);
        new->next = *l;
        *l = new;
    } else
        add2listRecurs(&((*l)->next),w);
}

void print_all(list *l) {
    while(l) {
        printf("%s ",l->word);
        l=l->next;
    }
    printf("\n");
}
void clean(list *l) {
    if(l == NULL)
        return;
    clean(l->next);
    free(l->word);
    free(l);
}

int main(void) {
    list *p=NULL;
    char word[50]={0};
    while( scanf("%s",word)==1 ) {
        if(word[strlen(word)-1]=='.')
            word[strlen(word)-1]=0;
        add2listRecurs(&p,word);
    }
    print_all(p);
    clean(p);

    return 0;
}
