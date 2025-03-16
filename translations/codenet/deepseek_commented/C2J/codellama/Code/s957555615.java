
#include<stdio.h>
#include<stdlib.h>

class Node{
  Node right;
  Node left;
  Node parent;
  int key;
  public Node(int k){
    key=k;
    right=null;
    left=null;
    parent=null;
  }
}

Node root;

// This function finds the node with the minimum key in the subtree rooted at x
Node treeMinimum(Node x){
  while(x.left!=null) x=x.left;
  return x;
}

// This function finds the node with the maximum key in the subtree rooted at x
Node treeMaximum(Node x){
  while(x.right!=null) x=x.right;
  return x;
}

// This function searches for a node with a given key k in the subtree rooted at u
Node treeSearch(Node u, int k){
  if(u==null || k==u.key) return u;
  if(k<u.key) return treeSearch(u.left,k);
  else return treeSearch(u.right,k);
}

// This function finds the successor of a given node x in the tree
Node treeSuccessor(Node x){
  Node y;
  if(x.right!=null) return treeMinimum(x.right);
  y=x.parent;
  while(y!=null && x==y.right){
    x=y;
    y=y.parent;
  }
  return y;
}

// This function deletes a node z from the tree
void treeDelete(Node z){
  Node y; // node to be deleted
  Node x; // child of y
  if(z.left==null || z.right == null) y=z;
  else y=treeSuccessor(z);
  if(y.left!=null) x=y.left;
  else x=y.right;
  if(x!=null) x.parent = y.parent;
  if(y.parent==null) root=x;
  else if(y==y.parent.left) y.parent.left = x;
  else y.parent.right = x;
  if(y!=z) z.key=y.key;
}

// This function inserts a new node with key k into the tree
void insert(int k){
  Node y = null;
  Node x = root;
  Node z;
  z = new Node(k);
  while (x!=null){
    y=x;
    if(z.key < x.key){
      x=x.left;
    }
    else{
      x=x.right;
    }
  }
  z.parent=y;
  if(y==null) root =z;
  else if(z.key<y.key) y.left=z;
  else y.right = z;
}

// This function performs an inorder traversal of the tree and prints the keys
void inorder(Node u){
  if(u==null) return;
  inorder(u.left);
  System.out.print(" "+u.key);
  inorder(u.right);
}

// This function performs a preorder traversal of the tree and prints the keys
void preorder(Node u){
  if(u==null) return;
  System.out.print(" "+u.key);
  preorder(u.left);
  preorder(u.right);
}

public class Main{
  public static void main(String[] args){
    int n, i, x;
    String com;
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    for ( i = 0; i < n; i++ ){
      com = sc.next();
      if ( com.charAt(0) == 'f' ){
        x = sc.nextInt();
        Node t = treeSearch(root, x);
        if ( t != null ) System.out.println("yes");
        else System.out.println("no");
      } else if ( com.charAt(0) == 'i' ){
        x = sc.nextInt();
        insert(x);
      } else if ( com.charAt(0) == 'p' ){
        inorder(root);
        System.out.println();
        preorder(root);
        System.out.println();
      } else if ( com.charAt(0) == 'd' ){
        x = sc.nextInt();
        treeDelete(treeSearch(root, x));
      }
    }
  }
}

