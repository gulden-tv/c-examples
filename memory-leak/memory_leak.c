#include <stdio.h>
#include <stdlib.h>
#include "memory_leak.h"

list *memlist = NULL;

#undef malloc 
#undef free

void insert(void *address, size_t size, char *comment) {
    list *tmp = malloc(sizeof(list));
    tmp->next = memlist;
    tmp->address = address;
    tmp->size = size;
    sprintf(tmp->comment,"%s",comment);
    memlist = tmp;
}
_Bool delete(void *address) {
    if(memlist == NULL)
        return 0;
    list *del = NULL;
    if( memlist->address == address) {
        del = memlist;
        memlist = memlist->next;
        free(del);
        return  1;
    }
    list *tmp = memlist;
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
void printList() {
    list *head = memlist;
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
    insert(ptr,size,coment);
    
    return ptr;
}
void my_free(void *ptr, const char *file, int line, const char *func)
 {
    if(!delete(ptr))
        free(ptr);
}

