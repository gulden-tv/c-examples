#include <stdio.h>
#include <stdlib.h>
typedef char datatype;

typedef struct stack{
    datatype *item;// хранится в стеки
    int size; // размер стека
    int sp;  // указатель на вершину стека
} stack;

void init_stack(stack *st)
{
    st->size=16; //минимальный размер 16
    st->sp=0; // стек пустой
    st->item=malloc(16*sizeof(datatype));
}

void delete_stack(stack *st)
{
    free(st->item);
}
// положить в стек
void push (stack *st, datatype value)
{
    if(st->sp==st->size-1)
    {
        st->size=st->size*2;// 16*2 = 32
        st->item=realloc(st->item,st->size*sizeof(datatype));
    }
    st->item[st->sp]=value;
    st->sp++;
}

//взять из стека
void pop (stack *st, datatype *value)
{
    if(st->sp < 1) {
        fprintf(stderr, "No\n");
        exit(1);
    }
    *value=st->item[--(st->sp)];
}
_Bool empty_stack(stack *st)
{
    return (st->sp < 1);
}

int main()
{
    stack st;
    
    char c;
    init_stack(&st);
    while(  (c=getchar())!='.' ) {
        if(c=='(')
            push(&st,c);
        else if(c==')')
            pop(&st,&c);
            
    }
    if(empty_stack(&st))
        printf("Yes\n");
    else
        printf("No\n");
    
    return 0;
}

