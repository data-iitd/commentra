import java.util.*;

class Node{
  int id,l,r,par;
  Node(int id,int l,int r,int par){
    this.id = id;
    this.l = l;
    this.r = r;
    this.par = par;
  }
}

class Main{
  static Node[] N;

  public static void main(String[] args){
    // Declare and initialize variables
    int n,i,id,l,r;
    int p;

    // Read the number of nodes in the tree
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();

    // Initialize the tree
    N = new Node[n];
    init(n);

    // Read the input and build the tree
    for(i = 0 ; i < n ; i++){
      // Read the id, left child, and right child of the current node
      id = sc.nextInt();
      l = sc.nextInt();
      r = sc.nextInt();

      // If the left child is not -1, assign it to the left child of the current node
      if(l!= -1){
        N[id].l = l;
        N[l].par = id;
      }

      // If the right child is not -1, assign it to the right child of the current node
      if(r!= -1){
        N[id].r = r;
        N[r].par = id;
      }
    }

    // Find the root node and perform tree traversals
    for(i = 0 ; i < n ; i++){
      if(N[i].par == -1){
        p = i;
        break;
      }
    }

    // Print the tree traversals in Preorder, Inorder, and Postorder
    System.out.println("Preorder");
    Preorder(p);
    System.out.println("");

    System.out.println("Inorder");
    Inorder(p);
    System.out.println("");

    System.out.println("Postorder");
    Postorder(p);
    System.out.println("");
  }

  // Comment: This is the main function that initializes the tree, reads the input, and performs the tree traversals in Preorder, Inorder, and Postorder.

  // Comment: This is the function that initializes the tree.
  public static void init(int n){
    for(int i = 0 ; i < n ; i++){
      N[i] = new Node(i,-1,-1,-1);
    }
  }

  // Comment: This is the function that performs the Preorder tree traversal.
  public static void Preorder(int p){
    if(p == -1) return;
    System.out.print(p + " ");
    Preorder(N[p].l);
    Preorder(N[p].r);
  }

  // Comment: This is the function that performs the Inorder tree traversal.
  public static void Inorder(int p){
    if(p == -1) return;
    Inorder(N[p].l);
    System.out.print(p + " ");
    Inorder(N[p].r);
  }

  // Comment: This is the function that performs the Postorder tree traversal.
  public static void Postorder(int p){
    if(p == -1) return;
    Postorder(N[p].l);
    Postorder(N[p].r);
    System.out.print(p + " ");
  }
}

// Comment: This is the main function that initializes the tree, reads the input, and performs the tree traversals in Preorder, Inorder, and Postorder.

