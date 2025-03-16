
import java.util.Scanner;

public class s632215495{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Tree tree = new Tree();
        for (int i = 0; i < n; i++) {
            String command = sc.next();
            switch (command) {
                case "insert":
                    int key = sc.nextInt();
                    tree.insert(key);
                    break;
                case "print":
                    tree.print();
                    break;
                default:
                    throw new RuntimeException("unknown command: " + command);
            }
        }
    }
}

class Tree {

    private Node root;

    public void insert(int key) {
        if (root == null) {
            root = new Node(key);
            return;
        }

        Node currentNode = root;
        Node prevNode = null;
        while (currentNode!= null) {
            prevNode = currentNode;
            if (currentNode.key < key) {
                currentNode = currentNode.right;
            } else {
                currentNode = currentNode.left;
            }
        }

        Node newNode = new Node(key);
        newNode.parent = prevNode;
        if (prevNode.key < key) {
            prevNode.right = newNode;
        } else {
            prevNode.left = newNode;
        }
    }

    public void print() {
        StringBuilder sb = new StringBuilder();
        if (root == null) {
            sb.append("\n");
            sb.append("\n");
        } else {
            sb.append(" " + join(inorder(root), " "));
            sb.append("\n");
            sb.append(" " + join(preorder(root), " "));
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }

    private String join(int[] is, String delimiter) {
        StringBuilder sb = new StringBuilder();
        int n = is.length;
        for (int i = 0; i < n; i++) {
            sb.append(is[i]);
            if (i < n - 1) {
                sb.append(delimiter);
            }
        }
        return sb.toString();
    }

    private int[] inorder(Node node) {
        if (node == null) {
            return new int[0];
        }
        int[] left = inorder(node.left);
        int[] right = inorder(node.right);
        int[] result = new int[left.length + 1 + right.length];
        int index = 0;
        for (int i : left) {
            result[index++] = i;
        }
        result[index++] = node.key;
        for (int i : right) {
            result[index++] = i;
        }
        return result;
    }

    private int[] preorder(Node node) {
        if (node == null) {
            return new int[0];
        }
        int[] left = preorder(node.left);
        int[] right = preorder(node.right);
        int[] result = new int[1 + left.length + right.length];
        int index = 0;
        result[index++] = node.key;
        for (int i : left) {
            result[index++] = i;
        }
        for (int i : right) {
            result[index++] = i;
        }
        return result;
    }

    private static class Node {
        int key;
        Node parent;
        Node left;
        Node right;

        public Node(int key) {
            this.key = key;
        }
    }
}

Translate the above Java code to C++ and end with comment "