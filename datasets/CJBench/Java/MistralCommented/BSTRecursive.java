
import java.util.Scanner;

// Define a Node class for BST node
public static class Node {
    int data; // Data to be stored in the node
    Node left; // Reference to left child
    Node right; // Reference to right child

    // Constructor for Node
    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

// Main class with a private Node reference to the root of BST
public class Main {
    private Node root; // Reference to the root of BST

    // Constructor for Main class
    public Main() {
        root = null; // Initialize root to null
    }

    // Getter method for root reference
    public Node getRoot() {
        return root;
    }

    // Method to insert a new node in the BST
    private Node insert(Node node, int data) {
        // If the tree is empty, return a new node
        if (node == null) {
            node = new Node(data);
        }

        // If the new data is smaller than the current node, traverse left
        else if (data < node.data) {
            node.left = insert(node.left, data);
        }

        // If the new data is greater than the current node, traverse right
        else if (data > node.data) {
            node.right = insert(node.right, data);
        }

        // Return the current node
        return node;
    }

    // Method to add a new node to the BST
    public void add(int data) {
        root = insert(root, data); // Insert the new node in the BST
    }

    // Method to delete a node from the BST
    private Node delete(Node node, int data) {
        // If the tree is empty, return null
        if (node == null) {
            System.out.println("No such data present in BST.");
            return null;
        }

        // If the data to be deleted is smaller than the current node, traverse left
        if (data < node.data) {
            node.left = delete(node.left, data);
        }

        // If the data to be deleted is greater than the current node, traverse right
        else if (data > node.data) {
            node.right = delete(node.right, data);
        }

        // If the data to be deleted is equal to the current node, perform deletion
        else {
            // If the current node has no children
            if (node.left == null && node.right == null) {
                return null;
            }

            // If the current node has only one child or no children
            else if (node.left == null) {
                return node.right;
            }

            else if (node.right == null) {
                return node.left;
            }

            // If the current node has two children, find the minimum node in the right subtree
            else {
                Node temp = findMin(node.right);
                node.data = temp.data;
                node.right = delete(node.right, temp.data);
            }
        }

        // Return the modified node
        return node;
    }

    // Method to remove a node from the BST
    public void remove(int data) {
        root = delete(root, data); // Delete the node from the BST
    }

    // Method to find the minimum node in the BST
    private Node findMin(Node node) {
        // Traverse left until we reach the minimum node
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }

    // Method to search for a node in the BST
    private boolean search(Node node, int data) {
        // If the tree is empty, return false
        if (node == null) {
            return false;
        }

        // If the data to be searched is smaller than the current node, traverse left
        if (data < node.data) {
            return search(node.left, data);
        }

        // If the data to be searched is greater than the current node, traverse right
        else if (data > node.data) {
            return search(node.right, data);
        }

        // If the data to be searched is equal to the current node, return true
        else {
            return true;
        }
    }

    // Method to search for a node in the BST and print the result
    public boolean find(int data) {
        boolean result = search(root, data); // Search for the node in the BST
        if (result) {
            System.out.println(data + " is present in the BST.");
        } else {
            System.out.println(data + " is not found.");
        }
        return result;
    }

    // Method to perform inorder traversal of the BST and print the elements
    public void inOrderTraversal(Node node) {
        // If the node is not null, traverse left, print the data, and traverse right
        if (node != null) {
            inOrderTraversal(node.left);
            System.out.print(node.data + " ");
            inOrderTraversal(node.right);
        }
    }

    // Main method to take user input and perform the required operations on the BST
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read user input
        Main bst = new Main(); // Create an instance of the Main class

        // Read the number of nodes to be inserted in the BST
        int n = scanner.nextInt();

        // Perform the required operations based on user input
        for (int i = 0; i < n; i++) {
            int choice = scanner.nextInt();
            switch (choice) {
                case 1: // Insert a new node
                    int insertValue = scanner.nextInt();
                    bst.add(insertValue);
                    break;
                case 2: // Delete a node
                    int deleteValue = scanner.nextInt();
                    bst.remove(deleteValue);
                    break;
                case 3: // Search for a node
                    int searchValue = scanner.nextInt();
                    bst.find(searchValue);
                    break;
                case 4: // Perform inorder traversal and print the elements
                    bst.inOrderTraversal(bst.getRoot());
                    System.out.println();
                    break;
                default:
                    System.out.println("Invalid choice. Try again.");
            }
        }

        // Close the Scanner object
        scanner.close();
    }
}