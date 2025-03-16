import java.util.Scanner;

// Define a class for a doubly linked list node
class Node {
    int key;                // Key value of the node
    Node next;             // Pointer to the next node
    Node prev;             // Pointer to the previous node

    // Constructor to initialize a node
    Node(int key) {
        this.key = key;
        this.next = null;
        this.prev = null;
    }
}

// Define a class for the doubly linked list
public class DoublyLinkedList {
    private Node head;      // Head of the doubly linked list

    // Constructor to initialize the doubly linked list
    public DoublyLinkedList() {
        head = new Node(0); // Create a head node
        head.next = head;   // Point next of head to itself (circular)
        head.prev = head;   // Point prev of head to itself (circular)
    }

    // Function to print the elements of the list
    public void printList() {
        Node cur = head.next; // Start from the first node
        boolean first = true; // Flag to manage spacing
        while (cur != head) { // Traverse until we reach the head again
            if (!first) {
                System.out.print(" "); // Print space before the next number
            }
            System.out.print(cur.key); // Print the key of the current node
            cur = cur.next;            // Move to the next node
            first = false;             // Set flag to indicate that we have printed at least one element
        }
        System.out.println(); // Print a newline after the list
    }

    // Function to delete the first node in the list
    public void deleteFirst() {
        Node t = head.next; // Node to be deleted (first node)
        head.next = t.next; // Update head's next to the second node
        t.next.prev = head; // Update the new first node's prev to head
    }

    // Function to delete the last node in the list
    public void deleteLast() {
        Node delNode = head.prev; // Node to be deleted (last node)
        head.prev = delNode.prev; // Update head's prev to the second last node
        delNode.prev.next = head;  // Update the new last node's next to head
    }

    // Function to delete a node with a specific key
    public void delete(int skey) {
        Node n = head.next; // Pointer for traversal

        // Traverse the list to find the node with the key
        while (n != head) {
            if (n.key == skey) {
                // If the key exists, proceed to delete the node
                n.prev.next = n.next; // Bypass the node to be deleted
                n.next.prev = n.prev; // Update the next node's prev pointer
                return;               // Exit after deletion
            }
            n = n.next; // Move to the next node
        }
    }

    // Function to insert a new node with a specific key
    public void insert(int skey) {
        Node newNode = new Node(skey); // Create a new node

        // Insert the new node at the beginning of the list
        newNode.next = head.next;      // Point new node's next to the first node
        head.next.prev = newNode;      // Update the first node's prev to new node
        head.next = newNode;            // Update head's next to new node
        newNode.prev = head;            // Point new node's prev to head
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of operations
        DoublyLinkedList list = new DoublyLinkedList(); // Initialize the doubly linked list

        for (int i = 0; i < n; i++) { // Loop through each operation
            String command = scanner.next(); // Read the command
            if (command.equals("insert")) { // Check if command is 'insert'
                int key = scanner.nextInt(); // Read the key to insert
                list.insert(key); // Call insert function
            } else if (command.equals("deleteFirst")) { // Check if command is 'deleteFirst'
                list.deleteFirst(); // Call deleteFirst function
            } else if (command.equals("deleteLast")) { // Check if command is 'deleteLast'
                list.deleteLast(); // Call deleteLast function
            } else { // If command is 'delete'
                int key = scanner.nextInt(); // Read the key to delete
                list.delete(key); // Call delete function
            }
        }
        list.printList(); // Print the final state of the list
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
