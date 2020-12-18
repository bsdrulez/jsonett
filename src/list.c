#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include<list.h>

struct List_st {
    List *next;
    char *token;
};

void ett_lst_print (List *l, char *separator){
    if(!l) return;
    if(l->token) printf("%s",l->token); 
    if(!(l->next)) return; 
    if(*(l->token) && separator) printf("%s",separator); 
    ett_lst_print(l->next, separator);
}

void ett_lst_add (List **l_addr, char *token){
    assert(l_addr);
    assert(token);
    if(!(*l_addr)){
        *l_addr  = calloc(1,sizeof(List));
        (*l_addr)->token = token;
        return;
    }
    return ett_lst_add( &((*l_addr)->next), token);
}

char * ett_lst_remove_last (List **l_addr){
    assert(l_addr);
    if(!*l_addr) return NULL;
    List *l = *l_addr;
    char *token = NULL;
    if(!(l->next)){ 
        token = l->token; 
        free(l); 
        *l_addr = NULL; 
        return token; 
    }
    return ett_lst_remove_last(&(l->next));
}
