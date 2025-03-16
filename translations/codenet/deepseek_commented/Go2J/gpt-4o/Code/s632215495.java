import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Node represents a node in a binary search tree (BST)
// It contains an integer key, and references to its parent, left child, and right child.
class Node {
    int key;
    Node parent;
    Node left;
    Node right;

    Node(int key) {
        this.key = key;
    }
}

// Tree represents a binary search tree
// It contains a root node, which is the topmost node in the tree.
class Tree {
    Node root;

    // Insert adds a new node with the given key to the BST.
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

    // Print prints the tree using inorder and preorder traversals.
    public void print() {
        if (root == null) {
            System.out.println("");
            System.out.println("");
        } else {
            System.out.println(" " + String.join(" ", isToAs(visitInorder(root, new ArrayList<>()))));
            System.out.println(" " + String.join(" ", isToAs(visitPreorder(root, new ArrayList<>()))));
        }
    }

    // VisitPreorder performs a preorder traversal of the tree.
    private List<Integer> visitPreorder(Node node, List<Integer> acc) {
        if (node == null) {
            return acc;
        }
        acc.add(node.key);
        visitPreorder(node.left, acc);
        visitPreorder(node.right, acc);
        return acc;
    }

    // VisitInorder performs an inorder traversal of the tree.
    private List<Integer> visitInorder(Node node, List<Integer> acc) {
        if (node == null) {
            return acc;
        }
        visitInorder(node.left, acc);
        acc.add(node.key);
        visitInorder(node.right, acc);
        return acc;
    }

    // Convert a list of integers to a list of strings.
    private List<String> isToAs(List<Integer> is) {
        List<String> as = new ArrayList<>();
        for (int i : is) {
            as.add(String.valueOf(i));
        }
        return as;
    }
}

// Main class to read commands from standard input.
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Tree tree = new Tree();

        for (int i = 0; i < n; i++) {
            String command = scanner.next();
            switch (command) {
                case "insert":
                    int key = scanner.nextInt();
                    tree.insert(key);
                    break;
                case "print":
                    tree.print();
                    break;
                default:
                    throw new IllegalArgumentException("unknown command: " + command);
            }
        }
        scanner.close();
    }
}

// <END-OF-CODE>
