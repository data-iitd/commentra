#include<stdio.h>
#include<stdlib.h>

struct node{
  struct node *right;
  struct node *left;
  struct node *parent;
  int key;
};
typedef struct node * Node;
#define NIL NULL

Node root;

// This function finds the node with the minimum key in the subtree rooted at x
Node treeMinimum(Node x){
  while(x->left!=NIL) x=x->left;
  return x;
}

// This function finds the node with the maximum key in the subtree rooted at x
Node treeMaximum(Node x){
  while(x->right!=NIL) x=x->right;
  return x;
}

// This function searches for a node with a given key k in the subtree rooted at u
Node treeSearch(Node u, int k){
  if(u==NIL || k==u->key) return u;
  if(k<u->key) return treeSearch(u->left,k);
  else return treeSearch(u->right,k);
}

// This function finds the successor of a given node x in the tree
Node treeSuccessor(Node x){
  Node y;
  if(x->right!=NIL) return treeMinimum(x->right);
  y=x->parent;
  while(y!=NIL && x==y->right){
    x=y;
    y=y->parent;
  }
  return y;
}

// This function deletes a node z from the tree
void treeDelete(Node z){
  Node y; // node to be deleted
  Node x; // child of y
  if(z->left==NIL || z->right == NIL) y=z;
  else y=treeSuccessor(z);
  if(y->left!=NIL) x=y->left;
  else x=y->right;
  if(x!=NIL) x->parent = y->parent;
  if(y->parent==NIL) root=x;
  else if(y==y->parent->left) y->parent->left = x;
  else y->parent->right = x;
  if(y!=z) z->key=y->key;
}

// This function inserts a new node with key k into the tree
void insert(int k){
  Node y = NIL;
  Node x = root;
  Node z;
  z = malloc(sizeof(struct node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;
  while (x!=NIL){
    y=x;
    if(z->key < x->key){
      x=x->left;
    }
    else{
      x=x->right;
    }
  }
  z->parent=y;
  if(y==NIL) root =z;
  else if(z->key<y->key) y->left=z;
  else y->right = z;
}

// This function performs an inorder traversal of the tree and prints the keys
void inorder(Node u){
  if(u==NIL) return;
  inorder(u->left);
  printf(" %d",u->key);
  inorder(u->right);
}

// This function performs a preorder traversal of the tree and prints the keys
void preorder(Node u){
  if(u==NIL) return;
  printf(" %d",u->key);
  preorder(u->left);
  preorder(u->right);
}

int main(){
  int n, i, x;
  char com[20];
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ){
    scanf("%s", com);
    if ( com[0] == 'f' ){
      scanf("%d", &x);
      Node t = treeSearch(root, x);
      if ( t != NIL ) printf("yes\n");
      else printf("no\n");
    } else if ( com[0] == 'i' ){
      scanf("%d", &x);
      insert(x);
    } else if ( com[0] == 'p' ){
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    } else if ( com[0] == 'd' ){
      scanf("%d", &x);
      treeDelete(treeSearch(root, x));
    }
  }
  return 0;
}
