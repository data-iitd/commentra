#include <iostream>
#include <cstdlib>
#define NIL NULL

using namespace std;

struct node{
	int key;
	int priority;
	node *right , *left;
};

node * Delete(node **,int);
node * delete(node **,int);

// This function searches for a key in the tree. Returns 1 if found, otherwise 0.
int find(node *p,int x)
{
	while(p!=NIL)
	{
		if(p->key==x)return 1;
		else if(p->key > x)p = p->left;
		else p = p->right;
	}
	return 0;
}

// This function performs an inorder traversal of the tree and prints the keys.
void inorder(node *a)
{
	if(a->left!=NIL) inorder(a->left);
	cout<<" "<<a->key;
	if(a->right!=NIL) inorder(a->right);
	return;
}

// This function performs a preorder traversal of the tree and prints the keys.
void preorder(node *p)
{
	cout<<" "<<p->key;
	if(p->left!=NIL) preorder(p->left);
	if(p->right!=NIL) preorder(p->right);
	return;
}

// This function prints the tree in both inorder and preorder traversal formats.
void print(node *p)
{
	inorder(p);
	cout<<endl;
	preorder(p);
	cout<<endl;
	return;
}

// This function creates a new node with given key and priority.
node * makenode(int x , int y)
{
	node *new = new node;
	new->key = x;
	new->priority = y;
	new->left = NIL;
	new->right = NIL;
	return new;
}

// This function performs a right rotation on the given node.
node *rightRotate(node *p)
{
	node *q = p->left;
	p->left = q->right;
	q->right = p;
	return q;
}

// This function performs a left rotation on the given node.
node *leftRotate(node *p)
{
	node *q = p->right;
	p->right = q->left;
	q->left = p;
	return q;
}

// This function inserts a new node into the tree while maintaining the heap property using rotations.
node* insert(node **t , int key, int priority)  // Recursive search
{
	node *new;
	if((*t)==NIL)
	return new = makenode(key,priority); // Create new node if leaf is reached
	if((*t)->key == key)
	return *t;  // Ignore duplicate keys
	
	if(key < (*t)->key) // Move to left child
	{
		(*t)->left = insert(&(*t)->left,key,priority); // Update left child pointer
		if((*t)->priority < (*t)->left->priority) // Right rotate if left child has higher priority
		(*t) = rightRotate(*t);
	}
	else{ // Move to right child
		(*t)->right = insert(&(*t)->right,key,priority); // Update right child pointer
		if((*t)->priority < (*t)->right->priority) // Left rotate if right child has higher priority
		(*t) = leftRotate((*t));
	}
	return *t;
}

// This function initiates the deletion process and calls `delete` for actual deletion.
node * Delete(node **t , int key)
{
	if((*t)==NIL)
	return NIL;
	
	if(key < (*t)->key) // Search for the node to delete
	(*t)->left = Delete(&((*t)->left),key);
	
	else if(key > (*t)->key)
	(*t)->right = Delete(&((*t)->right),key);
	
	else return delete(t,key);
	return *t;
}

// This function handles the actual deletion of nodes, including cases where the node has one or two children.
node * delete(node **t , int key)
{
	if((*t)->left == NIL && (*t)->right == NIL)  // Case for leaf node
	{
		return NIL;
	}
	else if((*t)->left == NIL) // Case for node with only right child
	{
		(*t) = leftRotate(*t);
	}
	else if((*t)->right ==NIL) // Case for node with only left child
	{
		(*t) = rightRotate(*t);
	}
	else{ // Case for node with both left and right children
		if((*t)->left->priority > (*t)->right->priority) // Rotate based on higher priority child
		(*t) = rightRotate(*t);
		else
		(*t) = leftRotate(*t);
	}
	return Delete(t,key);
}

// Entry point of the program. Reads commands to insert, delete, find, or print the tree.
int main(void)
{
	int num ,  x, y;
	char com[8];
	node *root = NIL;
	cin>>num;
	
	for(int i = 0; i < num; i++)
	{
		cin>>com;
		switch(com[0])
		{
		  case 'i':cin>>x>>y;
			root = insert(&root,x,y);
			break;
		  case 'd':cin>>x;
			root = Delete(&root,x);
			break;
		  case 'f':cin>>x;
			if(find(root,x))cout<<"yes"<<endl;
			else cout<<"no"<<endl;
			break;
		  case 'p':print(root);
			break;
		}
	}
	return 0;
}

