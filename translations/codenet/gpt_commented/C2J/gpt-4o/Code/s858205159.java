import java.util.Scanner;

// Define a class for a doubly linked list node
class Node {
    int key;          // Key value of the node
    Node next;       // Pointer to the next node
    Node prev;       // Pointer to the previous node

    // Constructor to initialize a node
    Node(int key) {
        this.key = key;
        this.next = null;
        this.prev = null;
    }
}

public class DoublyLinkedList {
    private Node nil; // Sentinel node to represent the head and tail of the list

    // Constructor to initialize the linked list
    public DoublyLinkedList() {
        nil = new Node(0); // Create the sentinel node
        nil.next = nil; // Point next of sentinel to itself
        nil.prev = nil; // Point prev of sentinel to itself
    }

    // Function to search for a node with a specific key
    private Node listSearch(int key) {
        Node cur = nil.next; // Start from the first node
        while (cur != nil) { // Traverse until the sentinel node
            if (cur.key == key) return cur; // If the key is found, return the node
            cur = cur.next; // Move to the next node
        }
        return nil; // Return sentinel if not found
    }

    // Function to print all the keys in the linked list
    public void printList() {
        Node cur = nil.next; // Start from the first node
        boolean isFirst = true; // Flag to manage spacing between numbers
        while (cur != nil) { // Stop if we reach the sentinel node
            if (!isFirst) System.out.print(" "); // Print space before the next number if not the first
            System.out.print(cur.key); // Print the key of the current node
            cur = cur.next; // Move to the next node
            isFirst = false; // Set flag to indicate that we have printed at least one number
        }
        System.out.println(); // Print a new line after printing all keys
    }

    // Function to delete a specific node from the list
    private void deleteNode(Node t) {
        if (t == nil) return; // Do nothing if the node is the sentinel
        t.prev.next = t.next; // Bypass the node in the next pointer of the previous node
        t.next.prev = t.prev; // Bypass the node in the prev pointer of the next node
    }

    // Function to delete the first node in the list
    public void deleteFirst() {
        Node t = nil.next; // Get the first node
        if (t == nil) return; // Do nothing if the list is empty
        deleteNode(t); // Delete the first node
    }

    // Function to delete the last node in the list
    public void deleteLast() {
        Node t = nil.prev; // Get the last node
        if (t == nil) return; // Do nothing if the list is empty
        deleteNode(t); // Delete the last node
    }

    // Function to delete a node with a specific key
    public void deleteKey(int key) {
        Node t = listSearch(key); // Search for the node with the key
        if (t != nil) deleteNode(t); // If found, delete the node
    }

    // Function to insert a new node with a specific key at the beginning of the list
    public void insert(int key) {
        Node x = new Node(key); // Create a new node
        x.prev = nil; // Set the previous pointer to the sentinel
        x.next = nil.next; // Set the next pointer to the current first node
        x.next.prev = x; // Update the previous pointer of the current first node to point to the new node
        nil.next = x; // Update the sentinel's next pointer to point to the new node
    }

    // Main function to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int key, n; // Variables for key and number of operations
        DoublyLinkedList list = new DoublyLinkedList(); // Initialize the linked list

        n = scanner.nextInt(); // Read the number of operations
        for (int i = 0; i < n; i++) { // Loop through each operation
            String command = scanner.next(); // Read the command
            key = scanner.nextInt(); // Read the key
            if (command.charAt(0) == 'i') { // If the command is 'insert'
                list.insert(key); // Insert the key
            } else if (command.charAt(0) == 'd') { // If the command is 'delete'
                if (command.length() > 6) { // Check if the command specifies 'First' or 'Last'
                    if (command.charAt(6) == 'F') list.deleteFirst(); // Delete the first node
                    else if (command.charAt(6) == 'L') list.deleteLast(); // Delete the last node
                } else {
                    list.deleteKey(key); // Delete the node with the specified key
                }
            }
        }

        list.printList(); // Print the final state of the list
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
