
import java.util.Scanner;

class s120278714 {
  static final int MAX = 10000;
  static final int NIL = -1;

  static class Node {
    int p, l, r;
  }

  static Node[] T = new Node[MAX];
  static int n;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    n = sc.nextInt();

    for (int i = 0; i < n; i++) {
      T[i] = new Node();
      T[i].p = NIL;
    }

    int id, l, r;
    for (int i = 0; i < n; i++) {
      id = sc.nextInt();
      l = sc.nextInt();
      r = sc.nextInt();
      T[id].l = l;
      T[id].r = r;
      if (l!= NIL) T[l].p = id;
      if (r!= NIL) T[r].p = id;
    }

    int root = 0;
    while (T[root].p!= NIL) root++;

    System.out.println("Preorder");
    Preorder(root);
    System.out.println();

    System.out.println("Inorder");
    Inorder(root);
    System.out.println();

    System.out.println("Postorder");
    Postorder(root);
    System.out.println();
  }

  static void Preorder(int u) {
    if (u == NIL) return;
    System.out.print(" " + u);
    Preorder(T[u].l);
    Preorder(T[u].r);
  }

  static void Inorder(int u) {
    if (u == NIL) return;
    Inorder(T[u].l);
    System.out.print(" " + u);
    Inorder(T[u].r);
  }

  static void Postorder(int u) {
    if (u == NIL) return;
    Postorder(T[u].l);
    Postorder(T[u].r);
    System.out.print(" " + u);
  }
}

// Comment: This is the Java code that translates the given C code. It initializes the tree, reads the input, and performs the tree traversals in Preorder, Inorder, and Postorder.