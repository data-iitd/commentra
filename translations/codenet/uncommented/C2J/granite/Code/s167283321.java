
import java.util.Scanner;
class s167283321{
  static final int NIL = -1;
  static Node[] R = new Node[10000];
  static int n;
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    for(int i=0;i<n;i++)
      R[i] = new Node();
    for(int i=0;i<n;i++){
      int a = sc.nextInt();
      int b = sc.nextInt();
      int c = sc.nextInt();
      R[a].left = b;
      R[a].right = c;
      if(b!=NIL)R[b].parent = a;
      if(c!=NIL)R[c].parent = a;
    }
    int root = 0;
    for(int i=0;i<n;i++){
      if(R[i].parent==NIL)
        root = i;
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
  static void preorder(int x){
    if(x==NIL)
      return;
    System.out.print(" "+x);
    preorder(R[x].left);
    preorder(R[x].right);
  }
  static void inorder(int x){
    if(x==NIL)
      return;
    inorder(R[x].left);
    System.out.print(" "+x);
    inorder(R[x].right);
  }
  static void postorder(int x){
    if(x==NIL)
      return;
    postorder(R[x].left);
    postorder(R[x].right);
    System.out.print(" "+x);
  }
}
class Node{
  int parent,left,right;
  Node(){
    parent = NIL;
    left = NIL;
    right = NIL;
  }
}
