// Importing necessary packages
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Defining node and tree classes
class Node {
    int key;
    Node parent;
    Node left;
    Node right;

    Node(int key) {
        this.key = key;
    }
}

class Tree {
    Node root;

    // Method to insert a new node into the tree
    public void insert(int key) {
        // Base case: If the tree is empty, create a new root node
        if (root == null) {
            root = new Node(key);
            return;
        }

        // Variables to keep track of current and previous nodes
        Node currentNode = root;
        Node prevNode = null;

        // Traverse the tree to find the correct position for the new node
        while (currentNode != null) {
            prevNode = currentNode;
            if (currentNode.key < key) {
                currentNode = currentNode.right;
            } else {
                currentNode = currentNode.left;
            }
        }

        // Create a new node with the given key
        Node newNode = new Node(key);
        newNode.parent = prevNode;

        // Set the new node's parent to the previous node
        if (prevNode.key < key) {
            prevNode.right = newNode;
        } else {
            prevNode.left = newNode;
        }
    }

    // Method to print the tree in inorder and preorder traversals
    public void print() {
        // Base case: If the tree is empty, print an empty tree
        if (root == null) {
            System.out.println("");
            System.out.println("");
            return;
        }

        // Print the tree in inorder and preorder traversals
        System.out.println("Inorder traversal: " + String.join(" ", visitInorder(root, new ArrayList<>())));
        System.out.println("Preorder traversal: " + String.join(" ", visitPreorder(root, new ArrayList<>())));
    }

    // Helper functions for depth-first traversals of the tree
    private List<String> visitPreorder(Node node, List<String> acc) {
        // Base case: If the node is null, return the accumulator list
        if (node == null) {
            return acc;
        }

        // Add the current node's key to the accumulator list
        acc.add(String.valueOf(node.key));

        // Recursively traverse the left and right subtrees
        visitPreorder(node.left, acc);
        visitPreorder(node.right, acc);

        // Return the updated accumulator list
        return acc;
    }

    private List<String> visitInorder(Node node, List<String> acc) {
        // Base case: If the node is null, return the accumulator list
        if (node == null) {
            return acc;
        }

        // Recursively traverse the left subtree and add its keys to the accumulator list
        visitInorder(node.left, acc);

        // Add the current node's key to the accumulator list
        acc.add(String.valueOf(node.key));

        // Recursively traverse the right subtree and add its keys to the accumulator list
        visitInorder(node.right, acc);

        // Return the updated accumulator list
        return acc;
    }
}

// Main class to read input and call the appropriate methods
public class Main {
    public static void main(String[] args) {
        // Creating a new scanner to read input from stdin
        Scanner sc = new Scanner(System.in);

        // Reading the number of nodes in the tree
        int n = sc.nextInt();
        sc.nextLine(); // Consume the newline

        // Creating a new tree object
        Tree tree = new Tree();

        // Reading the commands and calling the appropriate methods
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
                    throw new IllegalArgumentException("unknown command: " + command);
            }
        }

        sc.close();
    }
}

// <END-OF-CODE>
