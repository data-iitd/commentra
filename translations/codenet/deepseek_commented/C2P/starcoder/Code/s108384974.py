#include<stdio.h>
#include<stdlib.h>

#define NIL (NodePointer)0  # NIL pointer

#define LEFT(x) (x->l)  # Left child of a node
#define RIGHT(x) (x->r) # Right child of a node
#define PARENT(x) (x->p) # Parent of a node
#define KEY(x) (x->key) # Key of a node

#define IS_NIL(x) (x == NIL)  # Check if a node is NIL
#define IS_LEAF(x) (IS_NIL(LEFT(x)) && IS_NIL(RIGHT(x)))  # Check if a node is a leaf
#define IS_ROOT(x) (PARENT(x) == NIL)  # Check if a node is the root

#define MIN(x, y) (x < y? x : y)  # Return the minimum of two values

#define INORDER(x) (inorder(x))  # Inorder traversal of the tree
#define PREORDER(x) (preorder(x))  # Preorder traversal of the tree

#define INSERT(x, k) (insert(x, k))  # Insert a key into the tree
#define FIND(x, k) (find(x, k))  # Find a key in the tree
#define PRINT(x) (print(x))  # Print the tree

#define DELETE(x, k) (delete(x, k))  # Delete a key from the tree

#define SIZE(x) (size(x))  # Return the number of nodes in the tree

#define MAX_TREE_HEIGHT 1000  # Maximum height of the tree

#define LEFT_ROTATE(x) (left_rotate(x))  # Left rotation of a node
#define RIGHT_ROTATE(x) (right_rotate(x))  # Right rotation of a node

#define LEFT_RIGHT_ROTATE(x) (left_right_rotate(x))  # Left-right rotation of a node
#define RIGHT_LEFT_ROTATE(x) (right_left_rotate(x))  # Right-left rotation of a node

#define LEFT_LEFT_ROTATE(x) (left_left_rotate(x))  # Left-left rotation of a node
#define RIGHT_RIGHT_ROTATE(x) (right_right_rotate(x))  # Right-right rotation of a node

#define BALANCE(x) (balance(x))  # Balance the tree

#define NEW_NODE(k) (new_node(k))  # Create a new node
#define FREE_NODE(x) (free_node(x))  # Free a node

#define NEW_TREE() (new_tree())  # Create a new tree
#define FREE_TREE(x) (free_tree(x))  # Free a tree

#define IS_EMPTY(x) (IS_NIL(x->r))  # Check if the tree is empty
#define IS_FULL(x) (IS_NIL(x->l))  # Check if the tree is full

#define LEFT_CHILD(x) (x->l)  # Return the left child of a node
#define RIGHT_CHILD(x) (x->r)  # Return the right child of a node
#define PARENT_NODE(x) (x->p)  # Return the parent of a node

#define LEFT_SIBLING(x) (LEFT_CHILD(PARENT_NODE(x)))  # Return the left sibling of a node
#define RIGHT_SIBLING(x) (RIGHT_CHILD(PARENT_NODE(x)))  # Return the right sibling of a node

#define LEFT_CHILD_OF_LEFT_CHILD(x) (LEFT_CHILD(LEFT_CHILD(x)))  # Return the left child of the left child of a node
#define RIGHT_CHILD_OF_LEFT_CHILD(x) (RIGHT_CHILD(LEFT_CHILD(x)))  # Return the right child of the left child of a node

#define LEFT_CHILD_OF_RIGHT_CHILD(x) (LEFT_CHILD(RIGHT_CHILD(x)))  # Return the left child of the right child of a node
#define RIGHT_CHILD_OF_RIGHT_CHILD(x) (RIGHT_CHILD(RIGHT_CHILD(x)))  # Return the right child of the right child of a node

#define LEFT_CHILD_OF_PARENT(x) (LEFT_CHILD(PARENT_NODE(x)))  # Return the left child of the parent of a node
#define RIGHT_CHILD_OF_PARENT(x) (RIGHT_CHILD(PARENT_NODE(x)))  # Return the right child of the parent of a node

#define LEFT_SIBLING_OF_LEFT_CHILD(x) (LEFT_SIBLING(LEFT_CHILD(x)))  # Return the left sibling of the left child of a node
#define RIGHT_SIBLING_OF_LEFT_CHILD(x) (RIGHT_SIBLING(LEFT_CHILD(x)))  # Return the right sibling of the left child of a node

#define LEFT_SIBLING_OF_RIGHT_CHILD(x) (LEFT_SIBLING(RIGHT_CHILD(x)))  # Return the left sibling of the right child of a node
#define RIGHT_SIBLING_OF_RIGHT_CHILD(x) (RIGHT_SIBLING(RIGHT_CHILD(x)))  # Return the right sibling of the right child of a node

#define LEFT_SIBLING_OF_PARENT(x) (LEFT_SIBLING(PARENT_NODE(x)))  # Return the left sibling of the parent of a node
#define RIGHT_SIBLING_OF_PARENT(x) (RIGHT_SIBLING(PARENT_NODE(x)))  # Return the right sibling of the parent of a node

#define IS_LEFT_CHILD(x) (PARENT_NODE(x)!= NIL && PARENT_NODE(x)->l == x)  # Check if a node is the left child of its parent
#define IS_RIGHT_CHILD(x) (PARENT_NODE(x)!= NIL && PARENT_NODE(x)->r == x)  # Check if a node is the right child of its parent

#define IS_LEFT_SUBTREE_OF(x, y) (IS_LEFT_CHILD(x) && PARENT_NODE(x) == y)  # Check if a node is the left subtree of another node
#define IS_RIGHT_SUBTREE_OF(x, y) (IS_RIGHT_CHILD(x) && PARENT_NODE(x) == y)  # Check if a node is the right subtree of another node

#define IS_LEFT_UNCLE(x) (IS_LEFT_CHILD(PARENT_NODE(x)) && IS_RIGHT_SUBTREE_OF(PARENT_NODE(x), PARENT_NODE(PARENT_NODE(x))))  # Check if a node is the left uncle of its parent
#define IS_RIGHT_UNCLE(x) (IS_RIGHT_CHILD(PARENT_NODE(x)) && IS_LEFT_SUBTREE_OF(PARENT_NODE(x), PARENT_NODE(PARENT_NODE(x))))  # Check if a node is the right uncle of its parent

#define IS_LEFT_BROTHER(x) (IS_LEFT_CHILD(x) && IS_RIGHT_SUBTREE_OF(x, PARENT_NODE(x)))  # Check if a node is the left brother of its parent
#define IS_RIGHT_BROTHER(x) (IS_RIGHT_CHILD(x) && IS_LEFT_SUBTREE_OF(x, PARENT_NODE(x)))  # Check if a node is the right brother of its parent

#define IS_LEFT_SIBLING(x) (IS_LEFT_CHILD(x) && IS_LEFT_SIBLING_OF_PARENT(x))  # Check if a node is the left sibling of its parent
#define IS_RIGHT_SIBLING(x) (IS_RIGHT_CHILD(x) && IS_RIGHT_SIBLING_OF_PARENT(x))  # Check if a node is the right sibling of its parent

#define IS_LEFT_CHILD_OF_LEFT_SIBLING(x) (IS_LEFT_CHILD(x) && IS_LEFT_CHILD_OF_LEFT_CHILD(LEFT_SIBLING(x)))  # Check if a node is the left child of the left sibling of its parent
#define IS_RIGHT_CHILD_OF_LEFT_SIBLING(x) (IS_RIGHT_CHILD(x) && IS_RIGHT_CHILD_OF_LEFT_CHILD(LEFT_SIBLING(x)))  # Check if a node is the right child of the left sibling of its parent

#define IS_LEFT_CHILD_OF_RIGHT_SIBLING(x) (IS_LEFT_CHILD(x) && IS_LEFT_CHILD_OF_RIGHT_CHILD(RIGHT_SIBLING(x)))  # Check if a node is the left child of the right sibling of its parent
#define IS_RIGHT_CHILD_OF_RIGHT_SIBLING(x) (IS_RIGHT_CHILD(x) && IS_RIGHT_CHILD_OF_RIGHT_CHILD(RIGHT_SIBLING(x)))  # Check if a node is the right child of the right sibling of its parent

#define IS_LEFT_SIBLING_OF_LEFT_SIBLING(x) (IS_LEFT_SIBLING(x) && IS_LEFT_SIBLING_OF_LEFT_CHILD(LEFT_SIBLING(x)))  # Check if a node is the left sibling of the left sibling of its parent
#define IS_RIGHT_SIBLING_OF_LEFT_SIBLING(x) (IS_RIGHT_SIBLING(x) && IS_RIGHT_SIBLING_OF_LEFT_CHILD(LEFT_SIBLING(x)))  # Check if a node is the right sibling of the left sibling of its parent

#define IS_LEFT_SIBLING_OF_RIGHT_SIBLING(x) (IS_LEFT_SIBLING(x) && IS_LEFT_SIBLING_OF_RIGHT_CHILD(RIGHT_SIBLING(x)))  # Check if a node is the left sibling of the right sibling of its parent
#define IS_RIGHT_SIBLING_OF_RIGHT_SIBLING(x) (IS_RIGHT_SIBLING(x) && IS_RIGHT_SIBLING_OF_RIGHT_CHILD(RIGHT_SIBLING(x)))  # Check if a node is the right sibling of the right sibling of its parent

#define IS_ROOT_OF_LEFT_SIBLING(x) (IS_LEFT_SIBLING(x) && IS_ROOT(LEFT_SIBLING(x)))  # Check if a node is the root of the left sibling of its parent
#define IS_ROOT_OF_RIGHT_SIBLING(x) (IS_RIGHT_SIBLING(x) && IS_ROOT(RIGHT_SIBLING(x)))  # Check if a node is the root of the right sibling of its parent

#define IS_ROOT_OF_LEFT_CHILD(x) (IS_LEFT_CHILD(x) && IS_ROOT(LEFT_CHILD(x)))  # Check if a node is the root of the left child of its parent
#define IS_ROOT_OF_RIGHT_CHILD(x) (IS_RIGHT_CHILD(x) && IS_ROOT(RIGHT_CHILD(x)))  # Check if a node is the root of the right child of its parent

#define IS_ROOT_OF_LEFT_CHILD_OF_LEFT_SIBLING(x) (IS_LEFT_CHILD_OF_LEFT_SIBLING(x) && IS_ROOT_OF_LEFT_SIBLING(x))  # Check if a node is the root of the left child of the left sibling of its parent
#define IS_ROOT_OF_RIGHT_CHILD_OF_LEFT_SIBLING(x) (IS_RIGHT_CHILD_OF_LEFT_SIBLING(x) && IS_ROOT_OF_LEFT_SIBLING(x))  # Check if a node is the root of the right child of the left sibling of its parent

#define IS_ROOT_OF_LEFT_CHILD_OF_RIGHT_SIBLING(x) (IS_LEFT_CHILD_OF_RIGHT_SIBLING(x) && IS_ROOT_OF_RIGHT_SIBLING(x))  # Check if a node is the root of the left child of the right sibling of its parent
#define IS_ROOT_OF_RIGHT_CHILD_OF_RIGHT_SIBLING(x) (IS_RIGHT_CHILD_OF_RIGHT_SIBLING(x) && IS_ROOT_OF_RIGHT_SIBLING(x))  # Check if a node is the root of the right child of the right sibling of its parent

#define IS_ROOT_OF_LEFT_SIBLING_OF_LEFT_SIBLING(x) (IS_LEFT_SIBLING_OF_LEFT_SIBLING(x) && IS_ROOT_OF_LEFT_SIBLING(x))  # Check if a node is the root of the left sibling of the left sibling of its parent
#define IS_ROOT_OF_RIGHT_SIBLING_OF_LEFT_SIBLING(x) (IS_RIGHT_SIBLING_OF_LEFT_SIBLING(x) && IS_ROOT_OF_LEFT_SIBLING(x))  # Check if a node is the root of the right sibling of the left sibling of its parent

#define IS_ROOT_OF_LEFT_SIBLING_OF_RIGHT_SIBLING(x) (IS_LEFT_SIBLING_OF_RIGHT_SIBLING(x) && IS_ROOT_OF_RIGHT_SIBLING(x))  # Check if a node is the root of the left sibling of the right sibling of its parent
#define IS_ROOT_OF_RIGHT_SIBLING_OF_RIGHT_SIBLING(x) (IS_RIGHT_SIBLING_OF_RIGHT_SIBLING(x) && IS_ROOT_OF_RIGHT_SIBLING(x))  # Check if a node is the root of the right sibling of the right sibling of its parent

#define IS_ROOT_OF_LEFT_CHILD_OF_LEFT_CHILD(x) (IS_LEFT_CHILD_OF_LEFT_CHILD(x) && IS_ROOT_OF_LEFT_CHILD(x))  # Check if a node is the root of the left child of the left child of its parent
#define IS_ROOT_OF_RIGHT_CHILD_OF_LEFT_CHILD(x) (IS_RIGHT_CHILD_OF_LEFT_CHILD(x) && IS_ROOT_OF_LEFT_CHILD(x))  # Check if a node is the root of the right child of the left child of its parent

#define IS_ROOT_OF_LEFT_CHILD_OF_RIGHT_CHILD(x) (IS_LEFT_CHILD_OF_RIGHT_CHILD(x) && IS_ROOT_OF_RIGHT_CHILD(x))  # Check if a node is the root of the left child of the right child of its parent
#define IS_ROOT_OF_RIGHT_CHILD_OF_RIGHT_CHILD(x) (IS_RIGHT_CHILD_OF_RIGHT_CHILD(x) && IS_ROOT_OF_RIGHT_CHILD(x))  # Check if a node is the root of the right child of the right child of its parent

#define IS_ROOT_OF_LEFT_CHILD_OF_PARENT(x) (IS_LEFT_CHILD(PARENT_NODE(x)) && IS_ROOT_OF_LEFT_CHILD(x))  # Check if a node is the root of the left child of its parent
#define IS_ROOT_OF_RIGHT_CHILD_OF_PARENT(x) (IS_RIGHT_CHILD(PARENT_NODE(x)) && IS_ROOT_OF_RIGHT_CHILD(x))  # Check if a node is the root of the right child of its parent

#def