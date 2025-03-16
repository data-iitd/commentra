import java.util.*;
public class Main{
  static class Node{
    int parent,left,right;
  }
  static Node R[]=new Node[10000];
  static int n;
  static void preorder(int x){
    if(x==-1)
      return;
    System.out.print(" "+x);
    preorder(R[x].left);
    preorder(R[x].right);
  }
  static void inorder(int x){
    if(x==-1)
      return;
    inorder(R[x].left);
    System.out.print(" "+x);
    inorder(R[x].right);
  }
  static void postorder(int x){
    if(x==-1)
      return;
    postorder(R[x].left);
    postorder(R[x].right);
    System.out.print(" "+x);
  }
  public static void main(String args[]){
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
      if(b!=-1)R[b].parent=a;
      if(c!=-1)R[c].parent=a;
    }
    for(i=0;i<n;i++){
      if(R[i].parent==-1)
        root=i;
    }
    System.out.print("Preorder\n");
    preorder(root);
    System.out.print("\n");
    System.out.print("Inorder\n");
    inorder(root);
    System.out.print("\n");
    System.out.print("Postorder\n");
    postorder(root);
    System.out.print("\n");
  }
}
