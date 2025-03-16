
import java.util.Scanner;

public class s701716787{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numCommand = scanner.nextInt();
        String command;
        int insertKey;
        Node root = null;
        for (int i = 0; i < numCommand; i++) {
            command = scanner.next();
            if (command.equals("insert")) {
                insertKey = scanner.nextInt();
                d_insert(root, insertKey);
            } else {
                d_print(root);
            }
        }
    }

    public static void d_insert(Node root, int key) {
        Node parent = null;
        Node index = root;
        while (index!= null) {
            parent = index;
            if (key < index.key) {
                index = index.left;
            } else {
                index = index.right;
            }
        }
        Node insertNode = new Node(key);
        insertNode.parent = parent;
        if (parent == null) {
            root = insertNode;
        } else if (key < parent.key) {
            parent.left = insertNode;
        } else {
            parent.right = insertNode;
        }
    }

    public static void d_print(Node root) {
        s_printInOrder(root);
        System.out.println();
        s_printPreOrder(root);
        System.out.println();
    }

    //st_ap_node…探索開始ノード
    public static void s_printPreOrder(Node node) {
        if (node == null) {
            return;
        }
        System.out.print(" " + node.key);
        s_printPreOrder(node.left);
        s_printPreOrder(node.right);
    }

    //st_ap_node…探索開始ノード
    public static void s_printInOrder(Node node) {
        static int printedNumNode = 0;
        if (node == null) {
            return;
        }
        s_printInOrder(node.left);
        System.out.print(" " + node.key);
        s_printInOrder(node.right);
    }

    public static class Node {
        Node parent;
        Node left;
        Node right;
        int key;

        public Node(int key) {
            this.key = key;
        }
    }
}

