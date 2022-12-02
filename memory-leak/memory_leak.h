#include <stdio.h>
#include <stdlib.h>

#ifndef MEMORY_LEAK_H

#define MEMORY_LEAK_H
typedef struct list list;

struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
}; 

static void insert(void *, size_t, char *);

static _Bool delete(void *);

void printMemoryLeak();
 
void* my_malloc(size_t size, const char *, int, const char *);

void my_free(void *, const char *, int line, const char *);

#define malloc(X) my_malloc( (X), __FILE__, __LINE__, __FUNCTION__)
#define free(X) my_free( (X), __FILE__, __LINE__, __FUNCTION__)

#endif

