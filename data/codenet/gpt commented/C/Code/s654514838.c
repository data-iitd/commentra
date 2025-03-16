#include <stdio.h>
#include <stdlib.h>
#define NIL NULL

// Definition of the node structure for the treap
typedef struct node{
	int key;            // Key of the node
	int priority;       // Priority of the node
	struct node *right; // Pointer to the right child
	struct node *left;  // Pointer to the left child
}Node;

// Function prototypes for delete operations
Node * Delete(Node **,int);
Node * delete(Node **,int);

// Function to find a key in the treap
int find(Node *p,int x)
{
	while(p!=NIL) // Traverse until a leaf is reached
	{
		if(p->key==x) return 1; // Key found
		else if(p->key > x) p = p->left; // Move to the left child
		else p = p->right; // Move to the right child
	}
	return 0; // Key not found
}

// Function for inorder traversal of the treap
void inorder(Node *a)
{
	if(a->left!=NIL) inorder(a->left); // Traverse left subtree
	printf(" %d",a->key); // Print the current node's key
	if(a->right!=NIL) inorder(a->right); // Traverse right subtree
	return;
}

// Function for preorder traversal of the treap
void preorder(Node *p)
{
	printf(" %d",p->key); // Print the current node's key
	if(p->left!=NIL) preorder(p->left); // Traverse left subtree
	if(p->right!=NIL) preorder(p->right); // Traverse right subtree
	return;
}

// Function to print the treap in both inorder and preorder
void print(Node *p)
{
	inorder(p); // Print inorder
	printf("\n");
	preorder(p); // Print preorder
	printf("\n");
	return;
}

// Function to create a new node with given key and priority
Node * makenode(int x , int y)
{
	Node *new = malloc(sizeof(Node)); // Allocate memory for a new node
	new->key = x; // Set the key
	new->priority = y; // Set the priority
	new->left = NIL; // Initialize left child to NIL
	new->right = NIL; // Initialize right child to NIL
	return new; // Return the new node
}

// Function to perform a right rotation on the treap
Node *rightRotate(Node *p)
{
	Node *q = p->left; // Store the left child
	p->left = q->right; // Move the right child of left child to the left of p
	q->right = p; // Perform the rotation
	return q; // Return the new root after rotation
}

// Function to perform a left rotation on the treap
Node *leftRotate(Node *p)
{
	Node *q = p->right; // Store the right child
	p->right = q->left; // Move the left child of right child to the right of p
	q->left = p; // Perform the rotation
	return q; // Return the new root after rotation
}

// Function to insert a new node into the treap
Node* insert(Node **t , int key, int priority)  
{
	Node *new;
	if((*t)==NIL)
		return new = makenode(key,priority); // Create a new node if leaf is reached
	if((*t)->key == key)
		return *t;  // Ignore duplicate keys
	
	if(key < (*t)->key) // Move to the left child
	{
		(*t)->left = insert(&(*t)->left,key,priority); // Update left child pointer
		if((*t)->priority < (*t)->left->priority) // Right rotation if left child has higher priority
			(*t) = rightRotate(*t);
	}
	else{ // Move to the right child
		(*t)->right = insert(&(*t)->right,key,priority); // Update right child pointer
		if((*t)->priority < (*t)->right->priority) // Left rotation if right child has higher priority
			(*t) = leftRotate((*t));
	}
	return *t; // Return the updated root
}

// Function to delete a node from the treap
Node * Delete(Node **t , int key)
{
	if((*t)==NIL)
		return NIL; // Return NIL if the tree is empty
	
	if(key < (*t)->key) // Search for the key in the left subtree
		(*t)->left = Delete(&((*t)->left),key);
	else if(key > (*t)->key) // Search for the key in the right subtree
		(*t)->right = Delete(&((*t)->right),key);
	else 
		return delete(t,key); // Key found, proceed to delete it
	return *t; // Return the updated root
}

// Helper function to handle the actual deletion of a node
Node * delete(Node **t , int key)
{
	if((*t)->left == NIL && (*t)->right == NIL)  // Case: Leaf node
	{
		return NIL; // Remove the leaf node
	}
	else if((*t)->left == NIL) // Case: Node with only right child
	{
		(*t) = leftRotate(*t); // Perform left rotation
	}
	else if((*t)->right ==NIL) // Case: Node with only left child
	{
		(*t) = rightRotate(*t); // Perform right rotation
	}
	else{ // Case: Node with both children
		if((*t)->left->priority > (*t)->right->priority) // Compare priorities
			(*t) = rightRotate(*t); // Rotate right if left child has higher priority
		else
			(*t) = leftRotate(*t); // Rotate left otherwise
	}
	return Delete(t,key); // Continue deletion process
}

// Main function to execute the program
int main(void)
{
	int num ,  x, y; // Variables for number of commands and key/priority values
	char com[8]; // Command buffer
	Node *root = NIL; // Initialize the root of the treap
	scanf("%d",&num); // Read the number of commands
	
	for(int i = 0; i < num; i++)
	{
		scanf("%s",com); // Read the command
		switch(com[0]) // Determine the command type
		{
		  case 'i': // Insert command
			scanf("%d %d",&x,&y); // Read key and priority
			root = insert(&root,x,y); // Insert the new node
			break;
		  case 'd': // Delete command
			scanf("%d",&x); // Read key to delete
			root = Delete(&root,x); // Delete the node
			break;
		  case 'f': // Find command
			scanf("%d",&x); // Read key to find
			if(find(root,x)) printf("yes\n"); // Print "yes" if found
			else printf("no\n"); // Print "no" if not found
			break;
		  case 'p': // Print command
			print(root); // Print the treap
			break;
		}
	}
	return 0; // Exit the program
}
