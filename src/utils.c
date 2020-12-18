#include<stdlib.h>
#include<string.h>
#include<assert.h>

#include<utils.h>
#include<bintree.h>

#define streq(a,b) (!(strcmp(a,b)))

static char *extract_string(const char *s, const char *e){
    int len = (e-s) + 1;
    return strncpy( calloc(1,sizeof(char)*len), s, len-1);
}

static BinTree *check_bro(BinTree *b, char *data){
    if(streq(data, ett_bintree_get_data(b))){
        free(data);
        return b;
    }
    
    BinTree *bro = ett_bintree_get_bro(b);
    if(!bro) return ett_bintree_add_bro(b,data);
    
    return check_bro(bro,data);
}

BinTree * ett_utils_put_if_missing(const char *s, const char *e, BinTree *b){
    assert(s<=e);       // START less or equal to END
    if(s==e) 
        return b;  //do nothing
    
    char *value = extract_string(s,e);
    BinTree *son = ett_bintree_get_son(b);
    if(!son)
        return ett_bintree_add_son(b,value);
    else
        return check_bro(son,value);
}


char * ett_utils_find_token(char *e, char *delimiter){
    char *d;
    while(*e){
        for(d=delimiter; *d; d++)
            if(*e == *d)
                return e;
        e++;
    }
    return e;
}

