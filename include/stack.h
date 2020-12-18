#ifndef ETT_STACK_INCLUDE
#define ETT_STACK_INCLUDE

#include<list.h>

typedef struct List Stack;

Stack *ett_stk_push (Stack *stk, void * data);
void * ett_stk_pop (Stack **stk);
void * ett_stk_get_head(Stack **stk);

#endif
