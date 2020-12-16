#ifndef ETT_BINTREE_INCLUDE
#define ETT_BINTREE_INCLUDE


typedef struct BinTree_st BinTree;

/** Create a binary tree and put @data in the node.
 *      @data:  can be NULL.
 */
BinTree *ett_bintree_create(void *data);

/** Deallocate memory of a binary tree recursively.
 *      @b, @free_data:  can be NULL.
 */
void ett_bintree_free(
                        BinTree *b, 
                        void (*free_data)(void *data));

/** Create a node SON or a node BROther and put @data
 *  in the new node.
 *      @b:     cannot be NULL
 *      @data:  can be NULL
 */
BinTree *ett_bintree_add_son(BinTree *b, void *data);
BinTree *ett_bintree_add_bro(BinTree *b, void *data);

/** Get field of a node.
 *      @b:     cannot be NULL
 */
BinTree *ett_bintree_get_son (BinTree *b);
BinTree *ett_bintree_get_bro (BinTree *b);
void    *ett_bintree_get_data(BinTree *b);

/** Visit the tree in a prefix order (first the root,
 *  second the brother, and last the son.
 *      @b:     can be NULL
 *      @visit: cannot be NULL
 *      @data:  is used directly by visit()
 */
void ett_bintree_visit_pref(
                            BinTree *b, 
                            void (*visit)(BinTree *b, void *data), 
                            void *data);

/** Visit the tree in a postfix order (first the brother,
 *  second the son, and last the root.
 *      @b:     can be NULL
 *      @visit: cannot be NULL
 *      @data:  is used directly by visit()
 */
void ett_bintree_visit_post(
                            BinTree *b, 
                            void (*visit)(BinTree *b, void *data), 
                            void *data);

/** Visit the tree in a way expressed by the last three letters (r for 
 *  'root'. b for 'brother' and s for 'son')
 *      @b:     can be NULL
 *      @visit: cannot be NULL
 *      @data:  is used directly by visit()
 */
void ett_bintree_visit_rbs (BinTree *b, void (*visit)(BinTree *b, void *data), void *data);
void ett_bintree_visit_rsb (BinTree *b, void (*visit)(BinTree *b, void *data), void *data);
void ett_bintree_visit_sbr (BinTree *b, void (*visit)(BinTree *b, void *data), void *data);
void ett_bintree_visit_bsr (BinTree *b, void (*visit)(BinTree *b, void *data), void *data);

    /** Print a tree
 *      @b:     can be NULL
 *      @print: cannot be NULL
 */
void ett_bintree_print(
                        BinTree *b, 
                        char *(*sprint)(void *data));

#endif

