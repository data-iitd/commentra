
# include<stdio.h>
# include<stdlib.h>

class BT{
  int parent;
  int right;
  int left;

  public BT(){
    parent = -1;
    right = -1;
    left = -1;
  }
}

BT bt[26];
int n;

void Preorder(int a){
  if(a == -1) return;

  System.out.print(" "+a);
  Preorder(bt[a].left);
  Preorder(bt[a].right);

}

void Inorder(int a){
  if(a==-1)return;

  Inorder(bt[a].left);
  System.out.print(" "+a);
  Inorder(bt[a].right);
}

void Postorder(int a){
  if(a==-1)return;

  Postorder(bt[a].left);
  Postorder(bt[a].right);
  System.out.print(" "+a);
}

public class Main{
  public static void main(String[] args){
    int i,j,num,depth = 0;
   

    
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();

    for(i=0;i<n;++i) bt[i].parent = -1;

    for(i=0;i<n;i++){
      num = sc.nextInt();
      bt[num].left = sc.nextInt();
      bt[num].right = sc.nextInt();

      if(bt[num].left != -1 &&bt[num].right != -1){
        bt[bt[num].left].parent = num;
        bt[bt[num].right].parent = num;
        
      }
      else if(bt[num].left != -1) bt[bt[num].left].parent = num;
      else if(bt[num].right != -1) bt[bt[num].right].parent = num;
    }

    for(i=0;bt[i].parent != -1;++i);
    
    System.out.println("Preorder");
    Preorder(i);
    System.out.println();

    System.out.println("Inorder");
    Inorder(i);
    System.out.println();

    System.out.println("Postorder");
    Postorder(i);
    System.out.println();

  }
}

