
#include <stdio.h>
#define NIL -1
class Node{
  int parent,left,right;
  public Node(){
    parent=left=right=NIL;
  }
};
Node R[10000];
int n;
void preorder(int);
void inorder(int);
void postorder(int);

void preorder(int x){
  if(x==NIL)
    return;
  System.out.print(" "+x);
  preorder(R[x].left);
  preorder(R[x].right);
}
void inorder(int x){
  if(x==NIL)
    return;
  inorder(R[x].left);
  System.out.print(" "+x);
  inorder(R[x].right);
}
void postorder(int x){
  if(x==NIL)
    return;
  postorder(R[x].left);
  postorder(R[x].right);
  System.out.print(" "+x);
}

public class Main{
  public static void main(String[] args){
    int i,a,b,c,root;
    Scanner sc=new Scanner(System.in);
    n=sc.nextInt();
    for(i=0;i<n;i++)
      R[i]=new Node();
    for(i=0;i<n;i++){
      a=sc.nextInt();
      b=sc.nextInt();
      c=sc.nextInt();
      R[a].left=b;
      R[a].right=c;
      if(b!=NIL)R[b].parent=a;
      if(c!=NIL)R[c].parent=a;
    }
    for(i=0;i<n;i++){
      if(R[i].parent==NIL)
        root=i;
    }
    System.out.println("Preorder");
    preorder(root);
    System.out.println();
    System.out.println("Inorder");
    inorder(root);
    System.out.println();
    System.out.println("Postorder");
    postorder(root);
    System.out.println();
  }
}

