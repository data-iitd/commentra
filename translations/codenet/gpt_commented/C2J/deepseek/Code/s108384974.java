public class BST {
    // Define the structure for a node in the binary search tree
    static class Node {
        int key;                // The key value of the node
        Node p;        // Pointer to the parent node
        Node l;        // Pointer to the left child
        Node r;        // Pointer to the right child
    }

    // Global variables for the root of the tree and a sentinel NIL node
    static Node r, NIL;

    // Function to find a node with a specific key in the binary search tree
    static Node find(Node x, int k) {
        // Traverse the tree until the key is found or a NIL node is reached
        while (x != NIL && k != x.key) {
            if (k < x.key) {
                x = x.l;  // Move to the left child if the key is smaller
            } else {
                x = x.r;  // Move to the right child if the key is larger
            }
        }
        return x;  // Return the found node or NIL if not found
    }

    // Function to insert a new key into the binary search tree
    static void insert(int k) {
        Node y = NIL;  // Parent node of the new node
        Node x = r;    // Start from the root

        // Allocate memory for the new node and initialize its fields
        Node z = new Node();
        z.key = k;
        z.l = NIL;
        z.r = NIL;

        // Find the appropriate position for the new node
        while (x != NIL) {
            y = x;  // Keep track of the parent node
            if (z.key < x.key) {
                x = x.l;  // Move to the left child
            } else {
                x = x.r;  // Move to the right child
            }
        }
        z.p = y;  // Set the parent of the new node

        // Insert the new node in the tree
        if (y == NIL) {
            r = z;  // Tree was empty, new node becomes the root
        } else if (z.key < y.key) {
            y.l = z;  // Insert as the left child
        } else {
            y.r = z;  // Insert as the right child
        }
    }

    // Function to perform an inorder traversal of the tree
    static void inorder(Node u) {
        if (u == NIL) {
            return;  // Base case: if the node is NIL, return
        }
        inorder(u.l);  // Traverse the left subtree
        System.out.print(" " + u.key);  // Visit the current node
        inorder(u.r);  // Traverse the right subtree
    }

    // Function to perform a preorder traversal of the tree
    static void preorder(Node u) {
        if (u == NIL) {
            return;  // Base case: if the node is NIL, return
        }
        System.out.print(" " + u.key);  // Visit the current node
        preorder(u.l);  // Traverse the left subtree
        preorder(u.r);  // Traverse the right subtree
    }

    // Function to print the tree in both inorder and preorder
    static void print() {
        inorder(r);  // Print the inorder traversal
        System.out.println();    // New line after inorder
        preorder(r); // Print the preorder traversal
        System.out.println();    // New line after preorder
    }

    public static void main(String[] args) {
        // Initialize the NIL node
        NIL = new Node();
        NIL.l = NIL;
        NIL.r = NIL;
        NIL.p = NIL;

        // Declare variables for input
        int n, i, z, x;  // Declare variables for input
        String s;        // Array to hold command strings

        // Read the number of operations to perform
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        for (i = 0; i < n; i++) {
            s = scanner.next();  // Read the command
            if (s.equals("find")) {  // If the command is 'find'
                x = scanner.nextInt();  // Read the key to find
                Node t = find(r, x);  // Search for the key
                if (t == NIL) System.out.println("no");  // Key not found
                else System.out.println("yes");  // Key found

            } else if (s.equals("insert")) {  // If the command is 'insert'
                z = scanner.nextInt();  // Read the key to insert
                insert(z);  // Insert the key into the tree
            } else {  // If the command is 'print'
                print();  // Print the tree
            }
        }
    }
}
