import java.util.Scanner;

class STNode {
    STNode stParent;
    STNode stLeft;
    STNode stRight;
    int s4Key;

    public STNode(int key) {
        this.s4Key = key;
        this.stParent = null;
        this.stLeft = null;
        this.stRight = null;
    }
}

public class BinarySearchTree {
    private STNode stRoot;

    public BinarySearchTree() {
        this.stRoot = null; // Initialize the root of the tree to null
    }

    public void insert(int key) {
        STNode newNode = new STNode(key); // Create a new node with the given key
        STNode parentNode = null;
        STNode indexNode = stRoot;

        while (indexNode != null) {
            parentNode = indexNode;
            if (newNode.s4Key < indexNode.s4Key) {
                indexNode = indexNode.stLeft;
            } else {
                indexNode = indexNode.stRight;
            }
        }

        if (parentNode == null) {
            stRoot = newNode; // If the tree was empty, set the root to the new node
        } else if (newNode.s4Key < parentNode.s4Key) {
            parentNode.stLeft = newNode; // Insert the new node as the left child
        } else {
            parentNode.stRight = newNode; // Insert the new node as the right child
        }
    }

    public void print() {
        printInOrder(stRoot); // Print the tree in in-order traversal
        System.out.println();
        printPreOrder(stRoot); // Print the tree in pre-order traversal
        System.out.println();
    }

    private void printPreOrder(STNode node) {
        if (node == null) {
            return;
        }
        System.out.print(" " + node.s4Key); // Print the current node's key
        printPreOrder(node.stLeft); // Recursively print the left subtree
        printPreOrder(node.stRight); // Recursively print the right subtree
    }

    private void printInOrder(STNode node) {
        if (node == null) {
            return;
        }
        printInOrder(node.stLeft); // Recursively print the left subtree
        System.out.print(" " + node.s4Key); // Print the current node's key
        printInOrder(node.stRight); // Recursively print the right subtree
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BinarySearchTree bst = new BinarySearchTree();
        int numCommands = scanner.nextInt(); // Read the number of commands

        for (int i = 0; i < numCommands; i++) {
            String command = scanner.next(); // Read the command
            if (command.equals("insert")) {
                int insertKey = scanner.nextInt(); // Read the key value
                bst.insert(insertKey); // Insert it into the tree
            } else if (command.equals("print")) {
                bst.print(); // Print the tree
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
