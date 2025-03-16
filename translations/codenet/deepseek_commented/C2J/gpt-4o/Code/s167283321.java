import java.util.Scanner;

// Define the class Node
class Node {
    int parent, left, right;

    public Node() {
        this.parent = -1;
        this.left = -1;
        this.right = -1;
    }
}

public class BinaryTreeTraversal {
    // Declare an array of Node structures and an integer variable n
    static Node[] R = new Node[10000];
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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int root = -1;

        // Initialize the nodes
        for (int i = 0; i < 10000; i++) {
            R[i] = new Node();
        }

        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();
            R[a].left = b;
            R[a].right = c;
            if (b != -1) R[b].parent = a;
            if (c != -1) R[c].parent = a;
        }

        for (int i = 0; i < n; i++) {
            if (R[i].parent == -1)
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

        scanner.close();
    }
}

// <END-OF-CODE>
