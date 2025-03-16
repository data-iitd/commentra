
import java.util.*;

class Node{
  int key;
  Node left,right,parent;
}

class BST{
  Node root;
  Node NIL;

  public BST(){
    root = NIL;
    NIL = new Node();
    NIL.key = 0;
    NIL.left = NIL.right = NIL.parent = NIL;
  }

  public Node find(int k){
    Node x = root;
    while(x!= NIL && k!= x.key){
      if(k < x.key){
        x = x.left;
      }else{
        x = x.right;
      }
    }
    return x;
  }

  public void insert(int k){
    Node y = NIL;
    Node x = root;

    Node z = new Node();
    z.key = k;
    z.left = NIL;
    z.right = NIL;

    while(x!= NIL){
      y = x;
      if(z.key < x.key){
        x = x.left;
      }else{
        x = x.right;
      }
    }
    z.parent = y;
    
    if(y == NIL){
      root = z;
    }else if(z.key < y.key){
      y.left = z;
    }else{
      y.right = z;
    }
  }

  public void inorder(Node u){
    if(u == NIL){
      return;
    }
    inorder(u.left);
    System.out.print(" "+u.key);
    inorder(u.right);
  }

  public void preorder(Node u){
    if(u == NIL){
      return;
    }
    System.out.print(" "+u.key);
    preorder(u.left);
    preorder(u.right);
  }

  public void print(){
    inorder(root);
    System.out.println("");
    preorder(root);
    System.out.println("");
  }
}

public class Main{
  public static void main(String args[]){
    BST tree = new BST();
    int n,i,j,z,x;
    String s;

    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    for(i=0;i<n;i++){
      s = sc.next();
      if(s.charAt(0) == 'f'){
        x = sc.nextInt();
        Node t = tree.find(x);
        if(t == tree.NIL)System.out.println("no");
        else System.out.println("yes");

      }else if(s.charAt(0) == 'i'){
        z = sc.nextInt();
        tree.insert(z);
      }else{
        tree.print();
      }
    }
  }
}

