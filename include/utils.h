#ifndef ETT_UTILS_INCLUDE
#define ETT_UTILS_INCLUDE

#include<bintree.h>


BinTree * ett_utils_put_if_missing (const char *s, const char *e, BinTree *b);
char    * ett_utils_find_token (char *e, char *delimiter);

#endif
