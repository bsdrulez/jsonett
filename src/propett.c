#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <assert.h>

#include<bintree.h>
#include<list.h>

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

static BinTree * put_if_missing(const char *s, const char *e, BinTree *b){
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

static char * find_token(char *e, char *delimiter){
    char *d;
    while(*e){
        for(d=delimiter; *d; d++)
            if(*e == *d)
                return e;
        e++;
    }
    return e;
}

static void parse(char **s, BinTree *b, BinTree *root){
    if(!**s) return;
    char *e;
    switch(**s){
        case '\r':
        case '\n':
            b = root;   // back to the root of the tree (one property per line)
        case ' ':
        case '\t':
        case '.':
        case '=':
            (*s)++; // skip character
        break;
        
        default:
            e = find_token(*s,".=\n\r");
            b = put_if_missing(*s,e,b);
            *s = e;
            // FIXME: spazi a fine riga vengono aggiunti in coda al valore
        break;
    }

    parse(s,b, root);
}



BinTree *ett_prop_parse(char * prop_str){
    assert(prop_str);
    BinTree *b = ett_bintree_create(calloc(1,sizeof(int)));
    parse(&prop_str, b, b);
    return b;
}

// ----- PRINT -------
static void print_node(BinTree *b, List *l){
    BinTree *son = ett_bintree_get_son(b); 
    if(!son){
        // is a value
        ett_lst_print(l,"."); printf("=%s\n",ett_bintree_get_data(b));
        return;
    }
    
    ett_lst_add(&l, ett_bintree_get_data(b));
    print_node(son,l);
    ett_lst_remove_last(&l);

    BinTree *bro = ett_bintree_get_bro(b);
    if(!bro)
        return;
    print_node(bro,l);
        
}
char *  ett_prop_print(BinTree *b){
    print_node(b,NULL);
    printf("\n");
}

/* OLD: npt working
static void visit(BinTree *b, void *data){
    struct dt *l = data;
    BinTree *son = ett_bintree_get_son(b); 
    BinTree *bro = ett_bintree_get_bro(b);
    if(!bro){
        if(!son ){
            print_key(key);
            printf("=%s\n",ett_bintree_get_data(b));
            // remove last token from key
            remove_last_token(l);
            return;
        } 
        else {
            add_token(l,ett_bintree_get_data(b));
        }
    }
    add_token(l,ett_bintree_get_data(b));

}

//    parse_old(prop_str, b);
static char *add_key_value_pairs(const char *s, BinTree *b){
    char *e = find_token(s,".=\n\r");
    switch(*e){
        case '.':
        case '=':
        case '\n':
        case '\r':
            b = put_if_missing(s,e,b);
            parse(e+1,b);
        break;
    }
}
static void parse_old(const char *s, BinTree *b){
    switch(*s){
        case ' ':
        case '\t':
        case '\r':
        case '\n':
            s++; // skip character
        break;
        default:
            s = add_key_value_pairs(s,b);
            // TODO: forse questa chiamata a funzione è inutile
            //       basta chiamare qua direttamente le tre funzioni
            //       di add_key_value_pairs
            // FIXME: cosa fa se incontra spazi a fine riga ???
        break;
    }

    parse(s,b);
}

static BinTree *check_son(BinTree *b, char *data){
    BinTree *son;
    son = ett_bintree_get_son(b);
    if(!son)
        return NULL;
    if(streq(data, ett_bintree_get_data(son)))
        return son;
    return check_son(son,data);
}
static BinTree * last_bro(BinTree *b){
    BinTree * bro = ett_bintree_get_bro(b);
    if(!bro) return b;
    return last_bro(bro);
}
*/


