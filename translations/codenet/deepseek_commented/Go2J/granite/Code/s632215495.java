
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
        if (root == null) {
            System.out.println("");
            System.out.println("");
            return;
        }

        System.out.println(" " + inorder(root));
        System.out.println(" " + preorder(root));
    }

    private String inorder(Node node) {
        if (node == null) {
            return "";
        }

        StringBuilder sb = new StringBuilder();
        sb.append(inorder(node.left));
        sb.append(" ").append(node.key);
        sb.append(" ").append(inorder(node.right));
        return sb.toString();
    }

    private String preorder(Node node) {
        if (node == null) {
            return "";
        }

        StringBuilder sb = new StringBuilder();
        sb.append(" ").append(node.key);
        sb.append(" ").append(preorder(node.left));
        sb.append(" ").append(preorder(node.right));
        return sb.toString();
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

