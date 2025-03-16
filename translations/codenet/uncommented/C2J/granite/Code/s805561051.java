
import java.util.Scanner;

public class s805561051{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
        }
        for (int i = 0; i < n; i++) {
            int id = scanner.nextInt();
            int left = scanner.nextInt();
            int right = scanner.nextInt();
            nodes[id].left = left;
            nodes[id].right = right;
            if (left!= -1) {
                nodes[left].parent = id;
            }
            if (right!= -1) {
                nodes[right].parent = id;
            }
        }
        int rootId = 0;
        while (nodes[rootId].parent!= -1) {
            rootId++;
        }
        System.out.println("Preorder");
        preorder(nodes, rootId);
        System.out.println();
        System.out.println("Inorder");
        inorder(nodes, rootId);
        System.out.println();
        System.out.println("Postorder");
        postorder(nodes, rootId);
        System.out.println();
    }

    private static void preorder(Node[] nodes, int id) {
        if (id == -1) {
            return;
        }
        System.out.print(" " + id);
        preorder(nodes, nodes[id].left);
        preorder(nodes, nodes[id].right);
    }

    private static void inorder(Node[] nodes, int id) {
        if (id == -1) {
            return;
        }
        inorder(nodes, nodes[id].left);
        System.out.print(" " + id);
        inorder(nodes, nodes[id].right);
    }

    private static void postorder(Node[] nodes, int id) {
        if (id == -1) {
            return;
        }
        postorder(nodes, nodes[id].left);
        postorder(nodes, nodes[id].right);
        System.out.print(" " + id);
    }

    static class Node {
        int parent = -1;
        int left = -1;
        int right = -1;
    }
}
