public class BinarySearchTree {
    // Define the structure for a node in the binary search tree
    static class Node {
        int key;          // The key value of the node
        Node p;   // Pointer to the parent node
        Node l;   // Pointer to the left child node
        Node r;   // Pointer to the right child node
    }

    // Alias for the structure pointer
    static class NodePointer {
        Node node;
        NodePointer(Node node) {
            this.node = node;
        }
    }

    // Global variables for the root of the tree and a NIL pointer
    static NodePointer r, NIL;

    // Function to find a node with a given key in the binary search tree
    static NodePointer find(NodePointer x, int k) {
        while (x != NIL && k != x.node.key) {
            if (k < x.node.key) {
                x = new NodePointer(x.node.l);  // Move to the left child if the key is smaller
            } else {
                x = new NodePointer(x.node.r);  // Move to the right child if the key is larger
            }
        }
        return x;  // Return the node with the key or NIL if not found
    }

    // Function to insert a new key into the binary search tree
    static void insert(int k) {
        NodePointer y = NIL;  // Parent of the new node
        NodePointer x = r;    // Start from the root

        Node z = new Node();  // Allocate memory for the new node
        z.key = k;  // Set the key of the new node
        z.l = NIL;  // Initialize left child to NIL
        z.r = NIL;  // Initialize right child to NIL

        // Find the position to insert the new node
        while (x != NIL) {
            y = x;  // Update the parent of the new node
            if (z.key < x.node.key) {
                x = new NodePointer(x.node.l);  // Move to the left child if the key is smaller
            } else {
                x = new NodePointer(x.node.r);  // Move to the right child if the key is larger
            }
        }
        z.p = y.node;  // Set the parent of the new node

        if (y == NIL) {
            r = new NodePointer(z);  // If the tree was empty, the new node becomes the root
        } else if (z.key < y.node.key) {
            y.node.l = z;  // Insert as the left child if the key is smaller
        } else {
            y.node.r = z;  // Insert as the right child if the key is larger
        }
    }

    // Function to perform an inorder traversal of the tree and print the keys
    static void inorder(NodePointer u) {
        if (u == NIL) {
            return;  // Base case: if the node is NIL, return
        }
        inorder(new NodePointer(u.node.l));  // Recursively traverse the left subtree
        System.out.print(" " + u.node.key);  // Print the key of the current node
        inorder(new NodePointer(u.node.r));  // Recursively traverse the right subtree
    }

    // Function to perform a preorder traversal of the tree and print the keys
    static void preorder(NodePointer u) {
        if (u == NIL) {
            return;  // Base case: if the node is NIL, return
        }
        System.out.print(" " + u.node.key);  // Print the key of the current node
        preorder(new NodePointer(u.node.l));  // Recursively traverse the left subtree
        preorder(new NodePointer(u.node.r));  // Recursively traverse the right subtree
    }

    // Function to print the tree in both inorder and preorder traversals
    static void print() {
        inorder(r);  // Perform inorder traversal
        System.out.println();  // Print a newline
        preorder(r);  // Perform preorder traversal
        System.out.println();  // Print a newline
    }

    // Main function to execute the program
    public static void main(String[] args) {
        int n, i, z, x;
        String s;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();  // Read the number of operations
        for (i = 0; i < n; i++) {
            s = scanner.next();  // Read the command
            if (s.equals("find")) {
                x = scanner.nextInt();  // Read the key to find
                NodePointer t = find(r, x);  // Find the key in the tree
                if (t == NIL) System.out.println("no");  // Print "no" if not found
                else System.out.println("yes");  // Print "yes" if found

            } else if (s.equals("insert")) {
                z = scanner.nextInt();  // Read the key to insert
                insert(z);  // Insert the key into the tree
            } else {
                print();  // Print the tree in both traversals
            }
        }

        scanner.close();  // Close the scanner
    }
}
