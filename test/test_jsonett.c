#include<stdlib.h>

#include<jsonett.h>
#include<propett.h>
#include<bintree.h>

static char *str(void *data){
    return (char*)data;
}

int main(){
    BinTree *b = NULL;
    
    //Test 1
    b = ett_json_parse(
            "{\"chiave1\": \"valore 1\"}"
            );
    ett_bintree_print(b,str);
    ett_prop_print(b);
    ett_json_print(b);
    ett_bintree_free(b,NULL);
    
    //Test 2
    b = ett_json_parse( "{"
            "\"chiave1\": \"valore 1\","
            "\"chiave2\": \"valore 2\","
            "\"chiave3\": true,"
            "\"chiave4\": 123"
        "}"
        );
    ett_bintree_print(b,str);
    ett_prop_print(b);
    ett_json_print(b);
    ett_bintree_free(b,NULL);
    
    //Test 3
    b = ett_json_parse( "{"
            "\"chiave1\": \"valore 1\","
            "\"chiave2\": {"
            "\"sub-chiave1\": true,"
            "\"sub-chiave2\": 123"
            "},"
            "\"chiave3\": \"valore 3\""
        "}"
        );
    ett_bintree_print(b,str);
    ett_prop_print(b);
    ett_json_print(b);
    ett_bintree_free(b,NULL);
    
    //Test 4
    b = ett_json_parse( 
        "{"
            "\"chiave1\": {"
                "\"sub-chiave1\": {"
                    "\"sub-sub-chiave1\": 123"
                "}"
            "}"
        "}"
        );
    ett_bintree_print(b,str);
    ett_prop_print(b);
    ett_json_print(b);
    ett_bintree_free(b,NULL);
    
    return 0;
}
