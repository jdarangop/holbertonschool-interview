#ifndef BINARY_TREES_H
#define BINARY_TREES_H


/**
 * struct binary_tree_t - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_t
{
	int n;
	struct binary_tree_t *parent;
	struct binary_tree_t *left;
	struct binary_tree_t *right;
};

typedef struct binary_tree_t binary_tree_t;
typedef struct binary_tree_t heap_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);

#endif
