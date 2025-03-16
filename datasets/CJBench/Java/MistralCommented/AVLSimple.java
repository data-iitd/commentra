
import java.util.Scanner;

public class Main {
    // Declare a private nested class Node for AVL tree node
    private class Node {
        int data;
        int height;
        Node left;
        Node right;
        
        // Constructor for Node with given data
        Node(int data) {
            this.data = data;
            this.height = 1;
        }
    }
    
    // Declare a reference for root node
    private Node root;
    
    // Method to insert a new node with given data into the tree
    public void insert(int data) {
        this.root = insert(this.root, data);
    }
    
    // Recursive method to insert a new node with given data into the tree
    private Node insert(Node node, int item) {
        // Base case: if node is null, create a new node with given data
        if (node == null) {
            return new Node(item);
        }
        
        // Recursive case: if the new data is less than the current node's data, traverse left
        if (node.data > item) {
            node.left = insert(node.left, item);
        } else if (node.data < item) { // if the new data is greater than the current node's data, traverse right
            node.right = insert(node.right, item);
        }
        
        // Update the height of the current node
        node.height = Math.max(height(node.left), height(node.right)) + 1;
        
        // Check for balance factor and perform rotations if necessary
        int bf = bf(node);
        if (bf > 1) { // if the balance factor is greater than 1, perform right rotation
            if (item < node.left.data) {
                return rightRotate(node);
            }
            node.right = rightRotate(node.right); // perform right rotation on the right subtree if needed
            return leftRotate(node); // perform left rotation on the current node
        } else if (bf < -1) { // if the balance factor is less than -1, perform left rotation
            if (item > node.right.data) {
                return leftRotate(node);
            }
            node.left = leftRotate(node.left); // perform left rotation on the left subtree if needed
            return rightRotate(node); // perform right rotation on the current node
        }
        
        return node; // if the tree is balanced, return the current node
    }
    
    // Method to display the tree structure and its height
    public void display() {
        this.display(this.root);
        System.out.println("Tree Height: " + this.root.height);
    }
    
    // Recursive method to display the tree structure
    private void display(Node node) {
        if (node == null) return;
        
        String str = "";
        // If the current node has a left child, append its data to the string
        if (node.left != null) {
            str += node.left.data + " => ";
        } else {
            str += "END => "; // if the left child is null, append "END" to the string
        }
        
        // Append the current node's data to the string
        str += node.data;
        
        // If the current node has a right child, append its data to the string with a separator
        if (node.right != null) {
            str += " <= " + node.right.data;
        } else {
            str += " <= END"; // if the right child is null, append "<= END" to the string
        }
        
        System.out.println(str); // print the string to the console
        
        // Recursively display the left and right subtrees
        if (node.left != null) {
            display(node.left);
        }
        if (node.right != null) {
            display(node.right);
        }
    }
    
    // Helper method to calculate the height of a node
    private int height(Node node) {
        if (node == null) {
            return 0;
        }
        return node.height;
    }
    
    // Helper method to calculate the balance factor of a node
    private int bf(Node node) {
        if (node == null) {
            return 0;
        }
        return height(node.left) - height(node.right);
    }
    
    // Method to perform right rotation on a node
    private Node rightRotate(Node c) {
        Node b = c.left;
        Node t3 = b.right;
        
        // Update the references of the nodes
        b.right = c;
        c.left = t3;
        
        // Update the heights of the nodes
        c.height = Math.max(height(c.left), height(c.right)) + 1;
        b.height = Math.max(height(b.left), height(b.right)) + 1;
        
        return b; // return the new root of the subtree
    }
    
    // Method to perform left rotation on a node
    private Node leftRotate(Node c) {
        Node b = c.right;
        Node t3 = b.left;
        
        // Update the references of the nodes
        b.left = c;
        c.right = t3;
        
        // Update the heights of the nodes
        c.height = Math.max(height(c.left), height(c.right)) + 1;
        b.height = Math.max(height(b.left), height(b.right)) + 1;
        
        return b; // return the new root of the subtree
    }
    
    // Main method to read user input and call the methods
    public static void main(String[] args) {
        Main tree = new Main();
        Scanner scanner = new Scanner(System.in);
        
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            
            if (command.equalsIgnoreCase("exit")) { // if the user enters "exit", terminate the program
                break;
            }
            
            String[] parts = command.split(" ");
            
            try {
                switch (parts[0]) { // switch on the command
                    case "insert":
                        if (parts.length < 2) { // if the command does not have an argument, print an error message
                            System.out.println("Error: Missing value for insert");
                        } else {
                            int value = Integer.parseInt(parts[1]); // parse the value from the argument
                            tree.insert(value); // call the insert method with the value
                            System.out.println("Inserted: " + value); // print a success message
                        }
                        break;
                    case "display":
                        tree.display(); // call the display method to show the tree structure and its height
                        break;
                    default: // if the command is not recognized, print an error message
                        System.out.println("Unknown command: " + parts[0]);
                }
            } catch (Exception e) { // catch any exceptions and print an error message
                System.out.println("Error: " + e.getMessage());
            }
        }
        
        scanner.close(); // close the scanner when finished
    }
}

