
// Importing necessary packages
import java.util.Scanner;

// Defining node and tree structures
class Node {
    int key;
    Node parent;
    Node left;
    Node right;

    public Node(int key) {
        this.key = key;
    }
}

class Tree {
    Node root;

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
        while (currentNode!= null) {
            prevNode = currentNode;
            if (currentNode.key < key) {
                currentNode = currentNode.right;
            } else {
                currentNode = currentNode.left;
            }
        }

        // Create a new node with the given key
        Node newNode = new Node(key);

        // Set the new node's parent to the previous node
        newNode.parent = prevNode;

        // If the previous node's key is less than the new node's key,
        // set the previous node's right child to the new node
        if (prevNode.key < key) {
            prevNode.right = newNode;
        } else {
            // Otherwise, set the previous node's left child to the new node
            prevNode.left = newNode;
        }
    }

    public void print() {
        // Base case: If the tree is empty, print an empty tree
        if (root == null) {
            System.out.println("");
            System.out.println("");
            return;
        }

        // Variable to store the visited nodes in inorder traversal
        StringBuilder sb = new StringBuilder();

        // Print the tree in inorder and preorder traversals
        System.out.println("Inorder traversal: " + inorder(root, sb).toString());
        System.out.println("Preorder traversal: " + preorder(root, sb).toString());
    }

    // Helper functions for depth-first traversals of the tree
    private StringBuilder preorder(Node node, StringBuilder sb) {
        // Base case: If the node is null, return the accumulator string
        if (node == null) {
            return sb;
        }

        // Add the current node's key to the accumulator string
        sb.append(node.key).append(" ");

        // Recursively traverse the left and right subtrees
        if (node.left!= null) {
            preorder(node.left, sb);
        }
        if (node.right!= null) {
            preorder(node.right, sb);
        }

        // Return the updated accumulator string
        return sb;
    }

    private StringBuilder inorder(Node node, StringBuilder sb) {
        // Base case: If the node is null, return the accumulator string
        if (node == null) {
            return sb;
        }

        // Recursively traverse the left subtree and add its keys to the accumulator string
        if (node.left!= null) {
            inorder(node.left, sb);
        }

        // Add the current node's key to the accumulator string
        sb.append(node.key).append(" ");

        // Recursively traverse the right subtree and add its keys to the accumulator string
        if (node.right!= null) {
            inorder(node.right, sb);
        }

        // Return the updated accumulator string
        return sb;
    }
}

// s632215495 function to read input and call the appropriate methods
public class s632215495{
    public static void main(String[] args) {
        // Creating a new scanner to read input from stdin
        Scanner sc = new Scanner(System.in);

        // Reading the number of nodes in the tree
        int n = sc.nextInt();

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
                    throw new RuntimeException("unknown command: " + command);
            }
        }
    }
}

// Helper function to read text and integers from the scanner
private static String nextText(Scanner sc) {
    return sc.next();
}

private static int nextInt(Scanner sc) {
    return sc.nextInt();
}

// Helper function to convert an integer array to a string array
private static String[] isToAs(int[] is) {
    int n = is.length;
    String[] as = new String[n];
    for (int i = 0; i < n; i++) {
        as[i] = String.valueOf(is[i]);
    }
    return as;
}

