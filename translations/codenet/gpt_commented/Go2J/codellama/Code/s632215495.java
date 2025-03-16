
import java.util.Scanner;

public class Main {
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
                    System.out.println("unknown command: " + command);
                    break;
            }
        }
    }
}

class Tree {
    Node root;

    public void insert(int key) {
        if (root == null) {
            root = new Node(key);
            return;
        }

        Node currentNode = root;
        Node prevNode = null;
        while (currentNode != null) {
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
        } else {
            System.out.println(" " + visitInorder(root, new StringBuilder()).toString());
            System.out.println(" " + visitPreorder(root, new StringBuilder()).toString());
        }
    }

    private StringBuilder visitPreorder(Node node, StringBuilder acc) {
        if (node == null) {
            return acc;
        }
        acc.append(node.key + " ");
        if (node.left != null) {
            acc = visitPreorder(node.left, acc);
        }
        if (node.right != null) {
            acc = visitPreorder(node.right, acc);
        }
        return acc;
    }

    private StringBuilder visitInorder(Node node, StringBuilder acc) {
        if (node == null) {
            return acc;
        }
        if (node.left != null) {
            acc = visitInorder(node.left, acc);
        }
        acc.append(node.key + " ");
        if (node.right != null) {
            acc = visitInorder(node.right, acc);
        }
        return acc;
    }
}

class Node {
    int key;
    Node parent;
    Node left;
    Node right;

    public Node(int key) {
        this.key = key;
    }
}

