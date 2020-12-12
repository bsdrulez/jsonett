
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

#include<bintree.h>


struct BinTree_st {
    void * data;
    BinTree * bro;
    BinTree * son;
};

#define BRO(b) ((b)->bro)
#define SON(b) ((b)->son)
#define DATA(b) ((b)->data)


BinTree *ett_bintree_create(void *data){
    BinTree * b = calloc(1, sizeof(BinTree));
    DATA(b) = data;
    return b;
}


static void free_node(BinTree *b, void *data){
    void (*free_data)(void *) = (void (*)(void *)) data;
    if(free_data) free_data(DATA(b));
    free(b);
}
void ett_bintree_free(BinTree *b, void (*free_data)(void *data)){
    ett_bintree_visit_post(b, free_node, free_data);
}


BinTree *ett_bintree_add_son(BinTree *b, void *data){
    assert(b);
    return SON(b)= ett_bintree_create(data);
}


BinTree *ett_bintree_add_bro(BinTree *b, void *data){
    assert(b);
    return BRO(b)= ett_bintree_create(data);
}


void ett_bintree_visit_pref(
                            BinTree *b, 
                            void (*visit)(BinTree *b, void *data), 
                            void *data){
    assert(visit);
    if(!b) return;
    visit(b,data);
    ett_bintree_visit_pref(BRO(b),visit,data);
    ett_bintree_visit_pref(SON(b),visit,data);
}
void ett_bintree_visit_post(
                            BinTree *b, 
                            void (*visit)(BinTree *b, void *data), 
                            void *data){
    assert(visit);
    if(!b) return;
    ett_bintree_visit_post(BRO(b),visit,data);
    ett_bintree_visit_post(SON(b),visit,data);
    visit(b,data);
}




static void print_node(BinTree *b, void *data){
    printf("&b=%p    bro=%p    son%p    data=%p", b,BRO(b),SON(b),DATA(b));
    if(data){
        char *(*str)(void *) = (char *(*)(void *)) data;
        printf(" -> %s",str(DATA(b)));
    }
    printf("\n");
}
void ett_bintree_print(BinTree *b, char *(*sprint)(void *data)){
    ett_bintree_visit_pref(b, print_node, (void*)sprint);
    printf("\n");
}
