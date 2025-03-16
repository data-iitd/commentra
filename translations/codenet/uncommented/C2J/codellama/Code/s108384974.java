
#include<stdio.h>
#include<stdlib.h>

class Node{
  int key;
  Node p;
  Node l;
  Node r;

  public Node(int k){
    key = k;
    p = null;
    l = null;
    r = null;
  }
}

class Tree{
  Node r;
  Node NIL;

  public Tree(){
    r = null;
    NIL = new Node(0);
  }

  public Node find(Node x,int k){
    while(x != NIL && k != x.key){
      if(k < x.key){
        x = x.l;
      }else{
        x = x.r;
      }
    }
    return x;
  }

  public void insert(int k){
    Node y = NIL;
    Node x = r;

    Node z = new Node(k);
    z.l = NIL;
    z.r = NIL;

    while(x != NIL){
      y = x;
      if(z.key < x.key){
        x = x.l;
      }else{
        x = x.r;
      }
    }
    z.p = y;
    
    if(y == NIL){
      r = z;
    }else if(z.key < y.key){
      y.l = z;
    }else{
      y.r = z;
    }
  }

  public void inorder(Node u){
    if(u == NIL){
      return;
    }
    inorder(u.l);
    System.out.print(" "+u.key);
    inorder(u.r);
  }

  public void preorder(Node u){
    if(u == NIL){
      return;
    }
    System.out.print(" "+u.key);
    preorder(u.l);
    preorder(u.r);
  }

  public void print(){
    inorder(r);
    System.out.println("");
    preorder(r);
    System.out.println("");
  }

  public static void main(String[] args){
    int n,i,j,z,x;
    String s;

    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    Tree t = new Tree();
    for(i=0;i<n;i++){
      s = sc.next();
      if(s.equals("f")){
        x = sc.nextInt();
        Node tt = t.find(t.r,x);
        if(tt == null)System.out.println("no");
        else System.out.println("yes");

      }else if(s.equals("i")){
        z = sc.nextInt();
        t.insert(z);
      }else{
        t.print();
      }
    }

    sc.close();
  }
}

