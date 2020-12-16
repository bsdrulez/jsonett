#include <stdlib.h>
#include<bintree.h>

static char *str(void *data){
    return (char*)data;
}

int main(){
    BinTree *b;
    
    // test 1
    b = ett_bintree_create(NULL);
    ett_bintree_add_bro(b,"ciao");
    ett_bintree_add_son(b,"");
    ett_bintree_print(b,str);
    ett_bintree_free(b,NULL);
    
    //test 2
    b = ett_bintree_create(malloc(10));
    ett_bintree_add_bro(b, malloc(20));
    BinTree * n = ett_bintree_add_son(b, malloc(24));
    ett_bintree_add_bro(
            ett_bintree_add_bro(n,malloc(5)),
            malloc(18));
    ett_bintree_add_son(n,malloc(1));
    ett_bintree_print(b,NULL);
    ett_bintree_free(b,free);

    return 0;
}
