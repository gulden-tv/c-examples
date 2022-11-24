#include <stdio.h>
#include <stdlib.h>
 
typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;
 
list *memlist = NULL;
 
void insert(list **head, void *address, size_t size, char *comment) {
    list *tmp = malloc(sizeof(list));
    tmp->next = *head;
    tmp->address = address;
    tmp->size = size;
    sprintf(tmp->comment,"%s",comment);
    *head = tmp;
}
_Bool delete(list **head, void *address) {
    if(*head == NULL)
        return 0;
    list *del = NULL;
    if( (*head)->address == address) {
        del = *head;
        *head = (*head)->next;
        free(del);
        return  1;
    }
    list *tmp = *head;
    while( tmp->next ) {
        if( tmp->next->address == address ) {
            del = tmp->next;
            tmp->next = del->next;
            free(del);
            return 1;
        }
        tmp=tmp->next;
    }
    return 0;
}
void printList(list *head) {
    if(head == NULL) {
        printf("No memory leak detect\n");
    }
    while(head) {
        printf("%s\n",head->comment);
        head = head->next;
    }
}
 
void* my_malloc(size_t size, const char *file, int line, const char *func)
 {
    void *ptr = malloc(size);
    char coment[64] = {0};
    sprintf (coment,"Allocated = %s, %i, %s, %p[%li]", file, line, func, ptr, size);
    insert(&memlist,ptr,size,coment);
    
    return ptr;
}
void my_free(void *ptr, const char *file, int line, const char *func)
 {
    free(ptr);
    delete(&memlist, ptr);
}
#define malloc(X) my_malloc( (X), __FILE__, __LINE__, __FUNCTION__)
#define free(X) my_free( (X), __FILE__, __LINE__, __FUNCTION__)
 
int main(void) {
    int *p = malloc( sizeof(int) );
    int *ar = malloc(sizeof(int)*10);
    *p = 5;
    free(p);
    p = malloc(sizeof(int));
 
    free(p);
    printList(memlist);
    return 0;
}
