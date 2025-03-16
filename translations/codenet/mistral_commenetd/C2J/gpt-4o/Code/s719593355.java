import java.util.Scanner;

// Define a class for a node in the linked list
class Node {
    unsigned int key;
    Node next;
    Node prev;

    // Constructor to initialize a node
    Node(int key) {
        this.key = key;
        this.next = null;
        this.prev = null;
    }
}

// Define a class for the doubly linked list
public class DoublyLinkedList {
    private Node nil; // Initialize the linked list with a nil node

    // Constructor to initialize the linked list
    public DoublyLinkedList() {
        nil = new Node(0); // Allocate memory for the nil node
        nil.next = nil; // Set the next pointer of the nil node to itself
        nil.prev = nil; // Set the prev pointer of the nil node to itself
    }

    // Function to search for a node with a given key in the list
    private Node listSearch(int key) {
        Node cur = nil.next; // Initialize a pointer to the first node in the list

        // Search for the node with the given key
        while (cur != nil && cur.key != key) {
            cur = cur.next;
        }

        // Return the found node or nil if not found
        return cur;
    }

    // Print the contents of the linked list
    public void printList() {
        Node cur = nil.next; // Initialize a pointer to the first node in the list
        boolean isFirst = true; // Flag to indicate if this is the first node to be printed

        // Traverse the list and print each node
        while (true) {
            if (cur == nil) break; // If we have reached the end of the list, exit the loop
            if (!isFirst) System.out.print(" "); // If this is not the first node, print a space before the key
            System.out.print(cur.key); // Print the key of the current node
            cur = cur.next; // Move to the next node
            isFirst = false; // Reset the flag for the next iteration
        }
        System.out.println(); // Print a newline at the end
    }

    // Delete a node from the linked list
    private void deleteNode(Node t) {
        t.prev.next = t.next; // Set the next pointer of the previous node to the next node of the node to be deleted
        t.next.prev = t.prev; // Set the prev pointer of the next node to the previous node of the node to be deleted
    }

    // Delete and free the first node in the list
    public void deleteFirst() {
        Node t = nil.next; // Initialize a pointer to the first node in the list

        // If the list is empty, return
        if (t == nil) return;

        // Delete the first node
        deleteNode(t);
    }

    // Delete and free the last node in the list
    public void deleteLast() {
        Node t = nil.prev; // Initialize a pointer to the last node in the list

        // If the list is empty, return
        if (t == nil) return;

        // Delete the last node
        deleteNode(t);
    }

    // Delete a node with the given key from the list
    public void delete(int key) {
        Node t = listSearch(key); // Search for the node with the given key

        // If the node is not found, return
        if (t == nil) return;

        // Delete the node
        deleteNode(t);
    }

    // Allocate memory for a new node and insert it into the list
    public void insert(int key) {
        Node x = new Node(key); // Allocate memory for the new node

        // Insert the new node at the end of the list
        x.next = nil.next;
        nil.next.prev = x;
        nil.next = x;
        x.prev = nil;
    }

    // Main function to read commands from standard input and perform the corresponding actions
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int key, n, size = 0; // Declare variables to store the number of commands and the current size of the list
        String command; // Declare a variable to store the command as a string
        int np = 0, nd = 0; // Initialize counters for the number of insert and delete operations

        // Read the number of commands from standard input
        n = scanner.nextInt();

        // Initialize the linked list
        DoublyLinkedList list = new DoublyLinkedList();

        // Process each command in the input
        for (int i = 0; i < n; i++) {
            command = scanner.next(); // Read the command from standard input
            key = scanner.nextInt(); // Read the key (if any) from standard input

            // If the command is an insert command, increment the np counter and insert the key into the list
            if (command.charAt(0) == 'i') {
                list.insert(key);
                np++;
                size++;
            }

            // If the command is a delete command, increment the nd counter and delete the node with the given key from the list
            else if (command.charAt(0) == 'd') {
                if (command.length() > 6) { // If the command is a delete first or delete last command, process it accordingly
                    if (command.charAt(6) == 'F') {
                        list.deleteFirst();
                    } else if (command.charAt(6) == 'L') {
                        list.deleteLast();
                    }
                } else { // If the command is a delete command with a key, delete the node with the given key from the list
                    list.delete(key);
                    nd++;
                }
                size--; // Decrement the size of the list after the delete operation
            }
        }

        // Print the final size of the list and the number of insert and delete operations
        System.out.printf("Size: %d, Number of insert operations: %d, Number of delete operations: %d\n", size, np, nd);
        scanner.close();
    }
}

// <END-OF-CODE>
