#include<list.h>
#include<stack.h>


Stack *ett_stk_push (Stack *stk, void * data){
    List *l = (List*)stk;
    ett_lst_add(&l, (char*)data);
    return (Stack*)l;
}
void * ett_stk_pop (Stack **stk){
    return (void*)ett_lst_remove_last((List**)stk);
}
void * ett_stk_get_head(Stack **stk){
    if(!*stk) return 0;
    void * data = ett_stk_pop(stk);
    *stk = ett_stk_push(*stk,data);
    return data;
}
