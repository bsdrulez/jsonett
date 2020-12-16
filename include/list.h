#ifndef ETT_LIST_INCLUDE
#define ETT_LIST_INCLUDE


typedef struct List_st List;

/** Print all elements in the List (separated by @separator) 
 *      @l:             be NULL
 *      @separator:     can be NULL
 */
void ett_lst_print (List *l, char *separator);

/** Add @token to the List ponted by @l_addr. The pointer
 *  at the address @l_addr can be NULL if List is empty.
 *  
 *      @l_addr:        cannot be NULL
 *      @token:         cannot be NULL
 */
void ett_lst_add (List **l_addr, char *token);

/** Remove the last element of a List. If the List contains
 *  only one element, the list became empty (NULL is automatically
 *  put in the variable pointed by @l_addr.
 *      @l_addr:        cannot be NULL
 */
void ett_lst_remove_last (List **l_addr);

#endif
