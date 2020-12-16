#include<stdlib.h>
#include<bintree.h>
#include<propett.h>

static char *str(void *data){
    return (char*)data;
}

int main(){
    BinTree *b;
    
    // test 1
    b = ett_prop_parse("a.b.c=123");
    ett_bintree_print(b,str);
    ett_prop_print(b);
    ett_bintree_free(b,free);

    // test 2
    b = ett_prop_parse(
            "prima.b.c=123\n"\
            "prima.b.R=123 ddd sds\n"\
            "seconda.F=123   \n"\
            "terza=123\n"\
            );
    ett_bintree_print(b,str);
    ett_prop_print(b);
    ett_bintree_free(b,free);
    
    return 0;
}
