#ifndef BINARY_TREES_T
#define BINARY_TREES_T

#include <stddef.h>

#define RELEASE 1

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef binary_tree_t heap_t;

int heap_extract(heap_t **root);
void binary_tree_print(const binary_tree_t *tree);

#define SWAP(a, b)                   \
	do {                         \
		const int tmp = (a); \
		(a) = (b);           \
		(b) = tmp;           \
	} while (0)


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvariadic-macros"

#ifndef PRINT_NODE_ARRAY
void print_int_node_array(const binary_tree_t **, size_t);
#define PRINT_NODE_ARRAY print_int_node_array
#endif

#ifndef C99
#define C99(...) \
do { \
_Pragma("GCC diagnostic push")\
_Pragma("GCC diagnostic ignored \"-Wpedantic\"")\
_Pragma("GCC diagnostic ignored \"-Wvla\"")\
	__VA_ARGS__ \
_Pragma("GCC diagnostic pop")\
} while (0)
#endif /* C99 */

#ifndef DBG
#if !RELEASE
#include <stdio.h>
#define DBG(...) C99(do {			\
	printf("%s:%d: ", __func__, __LINE__);	\
	__VA_ARGS__;				\
	} while (0);)
#else
#define DBG(...)
#endif
#endif

#pragma GCC diagnostic pop

#endif /* BINARY_TREES_T */
