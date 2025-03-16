public class DoublyLinkedList {
    // Define a doubly linked list node class
    static class Node {
        int key;          // Key value of the node
        Node next;        // Pointer to the next node
        Node prev;        // Pointer to the previous node
    }

    // Sentinel node to represent the head and tail of the list
    static Node nil;

    // Function prototypes
    static Node listSearch(int key);
    static void init();
    static void printList();
    static void deleteNode(Node node);
    static void deleteFirst();
    static void deleteLast();
    static void delete(int key);
    static void insert(int key);

    public static void main(String[] args) {
        int key, n, i; // Variables for key, number of operations, and loop index
        int size = 0;  // Variable to keep track of the size of the list
        String com;    // String to hold command strings
        int np = 0, nd = 0; // Counters for number of insertions and deletions

        // Read the number of operations to perform
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        
        // Initialize the doubly linked list
        init();
        
        // Loop to process each operation
        for (i = 0; i < n; i++) {
            // Read command and key value
            com = scanner.next();
            key = scanner.nextInt();
            
            // If the command is to insert a node
            if (com.equals("i")) {
                insert(key); // Insert the key into the list
                np++;        // Increment the insertion counter
                size++;      // Increment the size of the list
            }
            // If the command is to delete a node
            else if (com.equals("d")) {
                // Check for specific delete commands (delete first or last)
                if (com.equals("d") && com.length() > 6) {
                    if (com.charAt(6) == 'F') {
                        deleteFirst(); // Delete the first node
                    } else if (com.charAt(6) == 'L') {
                        deleteLast(); // Delete the last node
                    }
                } else {
                    delete(key); // Delete the node with the specified key
                    nd++;        // Increment the deletion counter
                }
                size--; // Decrement the size of the list
            }
        }

        // Print the final state of the list
        printList();
    }

    // Function to search for a node with a specific key
    static Node listSearch(int key) {
        Node cur = nil.next; // Start searching from the first node

        // Traverse the list until the end or until the key is found
        while (cur != nil && cur.key != key)
            cur = cur.next;

        return cur; // Return the found node or nil if not found
    }

    // Function to initialize the doubly linked list
    static void init() {
        nil = new Node(); // Allocate memory for the sentinel node
        nil.next = nil; // Point next of nil to itself
        nil.prev = nil; // Point prev of nil to itself
    }

    // Function to print the contents of the list
    static void printList() {
        Node cur = nil.next; // Start from the first node
        boolean isf = true; // Flag to manage spacing between numbers

        // Loop to print each node's key
        while (true) {
            if (cur == nil) break; // Stop if we reach the sentinel node
            if (!isf) System.out.print(" "); // Print space before subsequent numbers
            System.out.print(cur.key); // Print the key of the current node
            cur = cur.next; // Move to the next node
            isf = false; // Set flag to indicate that the first number has been printed
        }
        System.out.println(); // Print a newline at the end
    }

    // Function to delete a specific node from the list
    static void deleteNode(Node t) {
        t.prev.next = t.next; // Bypass the node to be deleted
        t.next.prev = t.prev; // Bypass the node to be deleted
    }

    // Function to delete the first node in the list
    static void deleteFirst() {
        Node t = nil.next; // Get the first node
        if (t == nil) // Check if the list is empty
            return;
        
        deleteNode(t); // Delete the first node
    }

    // Function to delete the last node in the list
    static void deleteLast() {
        Node t = nil.prev; // Get the last node
        if (t == nil) // Check if the list is empty
            return;
        
        deleteNode(t); // Delete the last node
    }

    // Function to delete a node with a specific key
    static void delete(int key) {
        Node t = listSearch(key); // Search for the node with the given key

        if (t == nil) // If the node is not found, return
            return;

        deleteNode(t); // Delete the found node
    }

    // Function to insert a new node with a specific key at the beginning of the list
    static void insert(int key) {
        Node x = new Node(); // Allocate memory for the new node
        x.key = key; // Set the key of the new node

        // Insert the new node at the beginning of the list
        x.next = nil.next; // Point the new node's next to the current first node
        nil.next.prev = x; // Update the current first node's previous to point to the new node
        nil.next = x; // Update the sentinel's next to point to the new node
        x.prev = nil; // Set the new node's previous to the sentinel
    }
}
