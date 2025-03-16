import java.util.*;

public class Main {
  public static void main(String[] args) {
    int n, i, id, l, r;
    int p;

    Scanner sc = new Scanner(System.in);
    n = sc.nextInt(); // Read the number of nodes
    Node[] N = new Node[n]; // Array of nodes

    // Read each node's id, left child, and right child
    for (i = 0; i < n; i++) {
      id = sc.nextInt();
      l = sc.nextInt();
      r = sc.nextInt();

      if (l!= -1) {
        N[id].l = l; // Set left child
        N[l].par = id; // Set parent of left child
      }
      if (r!= -1) {
        N[id].r = r; // Set right child
        N[r].par = id; // Set parent of right child
      }
    }

    // Find the root node (the node with no parent)
    for (i = 0; i < n; i++) {
      if (N[i].par == -1) {
        p = i; // Store the index of the root node
        break;
      }
    }

    // Print the preorder, inorder, and postorder traversals
    System.out.println("Preorder");
    Preorder(N, p);
    System.out.println("");

    System.out.println("Inorder");
    Inorder(N, p);
    System.out.println("");

    System.out.println("Postorder");
    Postorder(N, p);
    System.out.println("");
  }

  // Preorder traversal: root, left, right
  public static void Preorder(Node[] N, int p) {
    if (p!= -1) {
      System.out.print(" " + p); // Print current node
      Preorder(N, N[p].l); // Recursively traverse left subtree
      Preorder(N, N[p].r); // Recursively traverse right subtree
    }
  }

  // Inorder traversal: left, root, right
  public static void Inorder(Node[] N, int p) {
    if (p!= -1) {
      Inorder(N, N[p].l); // Recursively traverse left subtree
      System.out.print(" " + p); // Print current node
      Inorder(N, N[p].r); // Recursively traverse right subtree
    }
  }

  // Postorder traversal: left, right, root
  public static void Postorder(Node[] N, int p) {
    if (p!= -1) {
      Postorder(N, N[p].l); // Recursively traverse left subtree
      Postorder(N, N[p].r); // Recursively traverse right subtree
      System.out.print(" " + p); // Print current node
    }
  }
}

class Node {
  int l, r, par; // l: left child, r: right child, par: parent
}

