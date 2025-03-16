
import java.util.*;

public class AVLTree {
    static NodePointer r = null, NIL = null; // Initialize the root and NIL pointers

    // Function to find a node with given key in the AVL tree
    static NodePointer find(NodePointer x,int k){
        while(x!= NIL && k!= x.key){ // Search for the node with the given key
            if(k < x.key){ // If the key is less than the current node's key
                x = x.l; // Move to the left subtree
            }else{
                x = x.r; // Move to the right subtree
            }
        }
        return x; // Return the node if found, otherwise return NIL
    }

    // Function to insert a new node with given key into the AVL tree
    static void insert(int k){
        NodePointer y = NIL, x = r; // Initialize y and x pointers
        NodePointer z = new NodePointer(); // Allocate memory for the new node

        z.key = k; // Set the key value of the new node
        z.l = NIL; // Initialize the left and right child pointers of the new node
        z.r = NIL;

        // Traverse down the tree to find the position for the new node
        while(x!= NIL){
            y = x; // Move y pointer one level up
            if(z.key < x.key){ // If the new key is less than the current node's key
                x = x.l; // Move to the left subtree
            }else{
                x = x.r; // Move to the right subtree
            }
        }

        // Link the new node to its parent node
        z.p = y;

        // Update the left or right child of the parent node
        if(y == null){
            r = z; // If y is NIL, the new node is the root
        }else if(z.key < y.key){
            y.l = z;
        }else{
            y.r = z;
        }
    }

    // Function to perform inorder traversal of the AVL tree and print the keys
    static void inorder(NodePointer u){
        if(u == null){ // Base case: if the tree is empty, return
            return;
        }
        inorder(u.l); // Recursively traverse the left subtree
        System.out.print(" " + u.key); // Print the key of the current node
        inorder(u.r); // Recursively traverse the right subtree
    }

    // Function to perform preorder traversal of the AVL tree and print the keys
    static void preorder(NodePointer u){
        if(u == null){ // Base case: if the tree is empty, return
            return;
        }
        System.out.print(" " + u.key); // Print the key of the current node
        preorder(u.l); // Recursively traverse the left subtree
        preorder(u.r); // Recursively traverse the right subtree
    }

    // Function to print the keys of the AVL tree in inorder and preorder traversals
    static void print(){
        inorder(r); // Perform inorder traversal and print the keys
        System.out.println(""); // Print a newline character
        preorder(r); // Perform preorder traversal and print the keys
        System.out.println(""); // Print a newline character
    }

    // Main function to read commands from the standard input and perform the corresponding operations
    public static void main(String[] args) {
        int n,i,j,z,x; // Declare variables for the number of commands and their arguments
        String s; // Declare a string to read the command string

        Scanner sc = new Scanner(System.in); // Create a Scanner object to read from the standard input
        n = sc.nextInt(); // Read the number of commands from the standard input
        for(i=0;i<n;i++){ // Iterate through each command
            s = sc.next(); // Read the command string from the standard input

            if(s.charAt(0) == 'f'){ // If the command is to find a node
                x = sc.nextInt(); // Read the key value to search for
                NodePointer t = find(r,x); // Find the node with the given key
                if(t == null){ // If the node is not found
                    System.out.println("no");
                }else{ // If the node is found
                    System.out.println("yes");
                }

            }else if(s.charAt(0) == 'i'){ // If the command is to insert a new node
                z = sc.nextInt(); // Read the key value of the new node
                insert(z); // Insert the new node into the AVL tree

            }else{ // If the command is to print the keys of the AVL tree
                print(); // Print the keys in inorder and preorder traversals
            }
        }
    }
}

