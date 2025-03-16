import java.util.*;

public class Main {
  // Define the structure Node
  static class Node {
    int parent, left, right;
  }

  // Declare an array of Node structures and an integer variable n
  static Node R[] = new Node[10000];
  static int n;

  // Declare the traversal functions
  static void preorder(int x) {
    if (x == -1)
      return;
    System.out.print(" " + x);
    preorder(R[x].left);
    preorder(R[x].right);
  }

  static void inorder(int x) {
    if (x == -1)
      return;
    inorder(R[x].left);
    System.out.print(" " + x);
    inorder(R[x].right);
  }

  static void postorder(int x) {
    if (x == -1)
      return;
    postorder(R[x].left);
    postorder(R[x].right);
    System.out.print(" " + x);
  }

  // Implement the main function
  public static void main(String[] args) {
    int i, a, b, c, root;
    Scanner in = new Scanner(System.in);
    n = in.nextInt();
    for (i = 0; i < n; i++)
      R[i] = new Node();
    for (i = 0; i < n; i++) {
      a = in.nextInt();
      b = in.nextInt();
      c = in.nextInt();
      R[a].left = b;
      R[a].right = c;
      if (b!= -1)
        R[b].parent = a;
      if (c!= -1)
        R[c].parent = a;
    }
    for (i = 0; i < n; i++) {
      if (R[i].parent == -1)
        root = i;
    }
    System.out.print("Preorder\n");
    preorder(root);
    System.out.println();
    System.out.print("Inorder\n");
    inorder(root);
    System.out.println();
    System.out.print("Postorder\n");
    postorder(root);
    System.out.println();
  }
}
