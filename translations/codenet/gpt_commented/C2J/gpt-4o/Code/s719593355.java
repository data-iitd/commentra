import java.util.Scanner;

// Define a doubly linked list node class
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

    // Constructor to initialize the doubly linked list
    public DoublyLinkedList() {
        nil = new Node(0); // Create the sentinel node
        nil.next = nil; // Point next of nil to itself
        nil.prev = nil; // Point prev of nil to itself
    }

    // Function to search for a node with a specific key
    private Node listSearch(int key) {
        Node cur = nil.next; // Start searching from the first node

        // Traverse the list until the end or until the key is found
        while (cur != nil && cur.key != key) {
            cur = cur.next;
        }

        return cur; // Return the found node or nil if not found
    }

    // Function to print the contents of the list
    public void printList() {
        Node cur = nil.next; // Start from the first node
        boolean isFirst = true; // Flag to manage spacing between numbers

        // Loop to print each node's key
        while (cur != nil) {
            if (!isFirst) {
                System.out.print(" "); // Print space before subsequent numbers
            }
            System.out.print(cur.key); // Print the key of the current node
            cur = cur.next; // Move to the next node
            isFirst = false; // Set flag to indicate that the first number has been printed
        }
        System.out.println(); // Print a newline at the end
    }

    // Function to delete a specific node from the list
    private void deleteNode(Node t) {
        t.prev.next = t.next; // Bypass the node to be deleted
        t.next.prev = t.prev; // Bypass the node to be deleted
    }

    // Function to delete the first node in the list
    public void deleteFirst() {
        Node t = nil.next; // Get the first node
        if (t == nil) // Check if the list is empty
            return;

        deleteNode(t); // Delete the first node
    }

    // Function to delete the last node in the list
    public void deleteLast() {
        Node t = nil.prev; // Get the last node
        if (t == nil) // Check if the list is empty
            return;

        deleteNode(t); // Delete the last node
    }

    // Function to delete a node with a specific key
    public void delete(int key) {
        Node t = listSearch(key); // Search for the node with the given key

        if (t == nil) // If the node is not found, return
            return;

        deleteNode(t); // Delete the found node
    }

    // Function to insert a new node with a specific key at the beginning of the list
    public void insert(int key) {
        Node x = new Node(key); // Create a new node

        // Insert the new node at the beginning of the list
        x.next = nil.next; // Point the new node's next to the current first node
        nil.next.prev = x; // Update the current first node's previous to point to the new node
        nil.next = x; // Update the sentinel's next to point to the new node
        x.prev = nil; // Set the new node's previous to the sentinel
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n; // Number of operations
        int size = 0; // Variable to keep track of the size of the list
        String command; // Variable to hold command strings
        int key; // Variable for key value
        int np = 0, nd = 0; // Counters for number of insertions and deletions

        // Read the number of operations to perform
        n = scanner.nextInt();

        // Initialize the doubly linked list
        DoublyLinkedList list = new DoublyLinkedList();

        // Loop to process each operation
        for (int i = 0; i < n; i++) {
            command = scanner.next(); // Read command
            key = scanner.nextInt(); // Read key value

            // If the command is to insert a node
            if (command.charAt(0) == 'i') {
                list.insert(key); // Insert the key into the list
                np++; // Increment the insertion counter
                size++; // Increment the size of the list
            }
            // If the command is to delete a node
            else if (command.charAt(0) == 'd') {
                // Check for specific delete commands (delete first or last)
                if (command.length() > 6) {
                    if (command.charAt(6) == 'F') {
                        list.deleteFirst(); // Delete the first node
                    } else if (command.charAt(6) == 'L') {
                        list.deleteLast(); // Delete the last node
                    }
                } else {
                    list.delete(key); // Delete the node with the specified key
                    nd++; // Increment the deletion counter
                }
                size--; // Decrement the size of the list
            }
        }

        // Print the final state of the list
        list.printList();

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
