import java.util.Scanner;

class Node{
  int id;
  int l;
  int r;
  int par;

  Node(int id){
    this.id = id;
    this.l = -1;
    this.r = -1;
    this.par = -1;
  }
}

class Tree{
  Node[] N;

  Tree(int n){
    N = new Node[n];
    for(int i = 0 ; i < n ; i++){
      N[i] = new Node(i);
    }
  }

  void init(int n){
    for(int i = 0 ; i < n ; i++){
      N[i].l = -1;
      N[i].r = -1;
      N[i].par = -1;
    }
  }

  void Preorder(int p){
    if(p == -1){
      return;
    }

    System.out.print(N[p].id + " ");
    Preorder(N[p].l);
    Preorder(N[p].r);
  }

  void Inorder(int p){
    if(p == -1){
      return;
    }

    Inorder(N[p].l);
    System.out.print(N[p].id + " ");
    Inorder(N[p].r);
  }

  void Postorder(int p){
    if(p == -1){
      return;
    }

    Postorder(N[p].l);
    Postorder(N[p].r);
    System.out.print(N[p].id + " ");
  }
}

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    // Read the number of nodes in the tree
    int n = sc.nextInt();

    // Initialize the tree
    Tree T = new Tree(n);
    T.init(n);

    // Read the input and build the tree
    for(int i = 0 ; i < n ; i++){
      // Read the id, left child, and right child of the current node
      int id = sc.nextInt();
      int l = sc.nextInt();
      int r = sc.nextInt();

      // If the left child is not -1, assign it to the left child of the current node
      if(l != -1){
        T.N[id].l = l;
        T.N[l].par = id;
      }

      // If the right child is not -1, assign it to the right child of the current node
      if(r != -1){
        T.N[id].r = r;
        T.N[r].par = id;
      }
    }

    // Find the root node and perform tree traversals
    int p = -1;
    for(int i = 0 ; i < n ; i++){
      if(T.N[i].par == -1){
        p = i;
        break;
      }
    }

    // Print the tree traversals in Preorder, Inorder, and Postorder
    System.out.println("Preorder");
    T.Preorder(p);
    System.out.println("");

    System.out.println("Inorder");
    T.Inorder(p);
    System.out.println("");

    System.out.println("Postorder");
    T.Postorder(p);
    System.out.println("");
  }
}

// Comment: This is the main function that initializes the tree, reads the input, and performs the tree traversals in Preorder, Inorder, and Postorder.

