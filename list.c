#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct list {
    int32_t id;
    struct list *next;
} list;

list *L = NULL;

/* Без заглавного элемента */
void insert(list **head, int32_t value) {
    list *new = calloc(1,sizeof(list));
    new->id = value;
    new->next = *head;
    *head = new;
}
/* Без заглавного элемента */
void insert_end(list **head, int32_t value) {
    list *new = calloc(1,sizeof(list));
    new->id = value;
    if( *head == NULL ) {// пустой список
        *head = new;
    } else {
        list *p = *head;
        while(p->next != NULL)
            p = p->next; //идем в конец списка
        p->next = new;
    }
}
/* Без заглавного элемента рекурсиявный вариант*/
void insert_end_recurs(list **head, int32_t value) {
    if(*head == NULL) {
        (*head) = calloc(1,sizeof(list));
        (*head)->id = value;
    } else
        insert_end_recurs( &((*head)->next), value );
}

/* Без заглавного элемента и без двойного указателя*/
list* insert2(list *head, int32_t value) {
    list *new = calloc(1,sizeof(list));
    new->id = value;
    new->next = head;
    return new;
}
/* Без заглавного элемента и без двойного указателя*/
list* insert_end2(list *head, int32_t value) {
    list *new = calloc(1,sizeof(list));
    new->id = value;
    if( head == NULL ) {// пустой список
        return new;
    } else {
        list *p = head;
        while(p->next != NULL)
            p = p->next; //идем в конец списка
        p->next = new;
        return head;
    }
}

/* С заглавным элементом*/
void insert3(list *head, int32_t value) {
    list *new = calloc(1,sizeof(list));
    new->id = value;
    new->next = head->next; //в спсике точно есть хотябы одно звено
    head->next = new;
}
list *revers(list *head) { //  Реверс списка
    list *tmp = NULL, *new = NULL;
    while(head) {
        tmp = head;
        head = head->next;
        tmp->next = new;
        new = tmp;
    }
    return new;
}
void print_list(list *head) {
    while(head) {
        printf("%d ",head->id);
        head = head->next;
    }
    printf("\n");
}
int main(void)
{
    //L = calloc(1,sizeof(list)); // Добавляем заглавное звено
    //L->id = -1;
    
    insert_end_recurs(&L,1);
    insert_end_recurs(&L,2);
    insert_end_recurs(&L,3);
    print_list(L);
    return 0;
}
