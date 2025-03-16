import java.util.Scanner;

class Node {
    int parent, left, right;

    Node() {
        this.parent = -1;
        this.left = -1;
        this.right = -1;
    }
}

public class BinaryTree {
    static Node[] R = new Node[10000];
    static int n;

    public static void preorder(int x) {
        if (x == -1) return;
        System.out.print(" " + x);
        preorder(R[x].left);
        preorder(R[x].right);
    }

    public static void inorder(int x) {
        if (x == -1) return;
        inorder(R[x].left);
        System.out.print(" " + x);
        inorder(R[x].right);
    }

    public static void postorder(int x) {
        if (x == -1) return;
        postorder(R[x].left);
        postorder(R[x].right);
        System.out.print(" " + x);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            R[i] = new Node();
        }
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();
            R[a].left = b;
            R[a].right = c;
            if (b != -1) R[b].parent = a;
            if (c != -1) R[c].parent = a;
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (R[i].parent == -1) {
                root = i;
                break;
            }
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
        scanner.close();
    }
}

// <END-OF-CODE>
