
import java.util.*;

class Node{
  Node left, right, parent;
  int key;
}

class BST{
  Node root;
  Node treeMinimum(Node x){
    while(x.left!=null) x=x.left;
    return x;
  }
  Node treeMaximum(Node x){
    while(x.right!=null) x=x.right;
    return x;
  }
  Node treeSearch(Node u, int k){
    if(u==null || k==u.key) return u;
    if(k<u.key) return treeSearch(u.left,k);
    else return treeSearch(u.right,k);
  }
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
  void insert(int k){
    Node y = null;
    Node x = root;
    Node z;
    z = new Node();
    z.key = k;
    z.left = null;
    z.right = null;
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
  void inorder(Node u){
    if(u==null) return;
    inorder(u.left);
    System.out.print(" "+u.key);
    inorder(u.right);
  }
  void preorder(Node u){
    if(u==null) return;
    System.out.print(" "+u.key);
    preorder(u.left);
    preorder(u.right);
  }
}

public class Main{
  public static void main(String[] args){
    BST tree = new BST();
    Scanner sc = new Scanner(System.in);
    int n, i, x;
    String com;
    n = sc.nextInt();
    for ( i = 0; i < n; i++ ){
      com = sc.next();
      if ( com.charAt(0) == 'f' ){
        x = sc.nextInt();
        Node t = tree.treeSearch(tree.root, x);
        if ( t!= null ) System.out.println("yes");
        else System.out.println("no");
      } else if ( com.charAt(0) == 'i' ){
        x = sc.nextInt();
        tree.insert(x);
      } else if ( com.charAt(0) == 'p' ){
        tree.inorder(tree.root);
        System.out.println();
        tree.preorder(tree.root);
        System.out.println();
      } else if ( com.charAt(0) == 'd' ){
        x = sc.nextInt();
        tree.treeDelete(tree.treeSearch(tree.root, x));
      }
    }
  }
}

