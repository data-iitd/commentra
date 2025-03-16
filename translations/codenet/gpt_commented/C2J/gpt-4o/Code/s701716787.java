import java.util.Scanner;

class STNode {
    STNode stParent;  // Pointer to the parent node
    STNode stLeft;    // Pointer to the left child node
    STNode stRight;   // Pointer to the right child node
    int s4Key;        // Key value of the node

    // Constructor to create a new node
    STNode(int key) {
        this.s4Key = key;
        this.stParent = null;
        this.stLeft = null;
        this.stRight = null;
    }
}

public class BinarySearchTree {
    private STNode root; // Root of the binary search tree

    public void insert(int key) {
        STNode newNode = new STNode(key);
        STNode parentNode = null;
        STNode indexNode = root;

        // Traverse the tree to find the correct insertion point
        while (indexNode != null) {
            parentNode = indexNode; // Update parent node
            if (newNode.s4Key < indexNode.s4Key) {
                indexNode = indexNode.stLeft; // Go left
            } else {
                indexNode = indexNode.stRight; // Go right
            }
        }
        newNode.stParent = parentNode; // Set parent for the new node

        // Insert the new node in the tree
        if (parentNode == null) {
            root = newNode; // Tree was empty, new node becomes root
        } else if (key < parentNode.s4Key) {
            parentNode.stLeft = newNode; // Insert as left child
        } else {
            parentNode.stRight = newNode; // Insert as right child
        }
    }

    public void print() {
        printInOrder(root);
        System.out.println();
        printPreOrder(root);
        System.out.println();
    }

    private void printPreOrder(STNode node) {
        if (node == null) {
            return; // Base case: if the node is NULL, return
        }
        System.out.print(" " + node.s4Key); // Print the key of the current node
        printPreOrder(node.stLeft); // Recursively print left subtree
        printPreOrder(node.stRight); // Recursively print right subtree
    }

    private void printInOrder(STNode node) {
        if (node == null) {
            return; // Base case: if the node is NULL, return
        }
        printInOrder(node.stLeft); // Recursively print left subtree
        System.out.print(" " + node.s4Key); // Print the key of the current node
        printInOrder(node.stRight); // Recursively print right subtree
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        Scanner scanner = new Scanner(System.in);

        // Read the number of commands from user input
        int numCommands = scanner.nextInt();

        // Execute commands based on user input
        for (int i = 0; i < numCommands; i++) {
            String command = scanner.next();

            // Execute the command based on its type
            if (command.equals("insert")) {
                int insertKey = scanner.nextInt();
                bst.insert(insertKey); // Insert the key into the tree
            } else {
                bst.print(); // Print the current state of the tree
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
