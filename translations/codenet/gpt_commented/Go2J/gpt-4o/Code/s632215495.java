import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Define a class for a node in the binary tree
class Node {
    int key;        // The key value of the node
    Node parent;   // Pointer to the parent node
    Node left;     // Pointer to the left child node
    Node right;    // Pointer to the right child node

    Node(int key) {
        this.key = key;
    }
}

// Define a class for the binary tree
class Tree {
    Node root;     // Pointer to the root node of the tree

    // Insert a new key into the binary tree
    void insert(int key) {
        // If the tree is empty, create a new root node
        if (root == null) {
            root = new Node(key);
            return;
        }

        Node currentNode = root;
        Node prevNode = null;

        // Traverse the tree to find the correct position for the new key
        while (currentNode != null) {
            prevNode = currentNode;
            if (currentNode.key < key) {
                currentNode = currentNode.right; // Move to the right child
            } else {
                currentNode = currentNode.left; // Move to the left child
            }
        }

        // Create a new node for the key and set its parent
        Node newNode = new Node(key);
        newNode.parent = prevNode;

        // Attach the new node to the correct position in the tree
        if (prevNode.key < key) {
            prevNode.right = newNode; // Insert as right child
        } else {
            prevNode.left = newNode; // Insert as left child
        }
    }

    // Print the keys in the tree in both inorder and preorder traversal
    void print() {
        List<Integer> acc = new ArrayList<>();
        // Check if the tree is empty
        if (root == null) {
            System.out.println("");
            System.out.println("");
        } else {
            // Print inorder traversal
            System.out.println(" " + String.join(" ", isToAs(visitInorder(root, acc))));
            // Print preorder traversal
            acc.clear(); // Clear the accumulator for the next traversal
            System.out.println(" " + String.join(" ", isToAs(visitPreorder(root, acc))));
        }
    }

    // Perform a preorder traversal of the tree
    List<Integer> visitPreorder(Node node, List<Integer> acc) {
        if (node == null) {
            return acc; // Return accumulated keys if node is null
        }
        acc.add(node.key); // Add the current node's key
        visitPreorder(node.left, acc); // Traverse left subtree
        visitPreorder(node.right, acc); // Traverse right subtree
        return acc;
    }

    // Perform an inorder traversal of the tree
    List<Integer> visitInorder(Node node, List<Integer> acc) {
        if (node == null) {
            return acc; // Return accumulated keys if node is null
        }
        visitInorder(node.left, acc); // Traverse left subtree
        acc.add(node.key); // Add the current node's key
        visitInorder(node.right, acc); // Traverse right subtree
        return acc;
    }

    // Convert a list of integers to a list of strings
    List<String> isToAs(List<Integer> is) {
        List<String> as = new ArrayList<>();
        for (Integer i : is) {
            as.add(String.valueOf(i)); // Convert each integer to a string
        }
        return as; // Return the list of strings
    }
}

// Main class to read commands and manipulate the binary tree
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a new scanner for standard input

        int n = scanner.nextInt(); // Read the number of commands
        Tree tree = new Tree(); // Initialize a new binary tree

        // Process each command
        for (int i = 0; i < n; i++) {
            String command = scanner.next(); // Read the command
            switch (command) {
                case "insert":
                    int key = scanner.nextInt(); // Read the key to insert
                    tree.insert(key); // Insert the key into the tree
                    break;
                case "print":
                    tree.print(); // Print the tree's keys
                    break;
                default:
                    throw new IllegalArgumentException("unknown command: " + command); // Handle unknown commands
            }
        }
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
