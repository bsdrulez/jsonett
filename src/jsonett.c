#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

#include<bintree.h>
#include<stack.h>
#include<utils.h>

static void parse(char **s, BinTree *b, Stack *stk){
    if(!**s) return;
    char *e;
    switch(**s){
        case '{':
        case '[':
            e = calloc(1,sizeof(char)*4); e[1]=**s; e[2]=(**s)+2;
            b = ett_bintree_add_son(b,e);
            stk = ett_stk_push(stk, b);
        case ':':
        case '\r':
        case '\n':
        case ' ':
        case '\t':
        case '"':
            (*s)++; // skip character
        break;

            
        case ',':
            b=ett_stk_get_head(&stk);
            (*s)++; // skip character
        break;
        case '}':
        case ']':
            b=ett_stk_pop(&stk);
            (*s)++; // skip character
        break;

        default:
            e = ett_utils_find_token(*s,"\",]}");
            b = ett_utils_put_if_missing(*s,e,b); /*FIXME: put if missing put as 
                                                    the son or the brother of the 
                                                    son, but it should put as son 
                                                    or brother of the root
                                                    */
            *s = e;
        break;
    }

    parse(s,b, stk);
}
BinTree *ett_json_parse(char * json_str){
    assert(json_str);
    BinTree *b = ett_bintree_create(calloc(1,sizeof(char)*4));
    parse(&json_str, b, NULL);
    return b;
}

// print
static void print_node(BinTree *b, Stack *st){
    
    if(!b) return;
    
    BinTree *son = NULL;
    son = ett_bintree_get_son(b); 
    BinTree *bro = ett_bintree_get_bro(b);
    char *val = ett_bintree_get_data(b);
    if(*val == '\0'){
        printf("%c\n", val[1]);
        st = ett_stk_push(st, (void*)val[2]);
    }else{
        printf("\"%s\"", ett_bintree_get_data(b));
        if(son){
            printf(":");
            if(bro)
                st = ett_stk_push(st, (void*)',');
        }else{
            do{
                val = ett_stk_pop(&st); if(!val) break; // last '}' is followeb by NULL
                printf("%c\n", (char)val);
            } while( ((char)val)=='}'  );
        }
    }

    
    print_node(son,st);

    print_node(bro,st);
        
}
char *  ett_json_print(BinTree *b){
    print_node(ett_bintree_get_son(b),NULL);    // FIXME: very ugly workaround just to test the algorimt. Get rid of it ASAP
    printf("\n");
}
