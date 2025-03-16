import java.util.Scanner;

// Define a doubly linked list node class
class Node {
    int key;                // Value of the node
    Node next;             // Pointer to the next node
    Node prev;             // Pointer to the previous node

    // Constructor to create a new node
    Node(int key) {
        this.key = key;
    }
}

public class DoublyLinkedList {
    private Node head; // Pointer to the head of the doubly linked list

    // Constructor to initialize the doubly linked list
    public DoublyLinkedList() {
        head = new Node(0); // Initialize the head node
        head.next = head;    // Point next of head to itself (circular)
        head.prev = head;    // Point prev of head to itself (circular)
    }

    // Function to insert a new node with a given key at the beginning of the list
    public void insert(int key) {
        Node newNode = new Node(key); // Create a new node
        newNode.next = head.next; // Set the new node's next to the current first node
        head.next.prev = newNode; // Update the current first node's previous to the new node
        head.next = newNode; // Update head's next to the new node
        newNode.prev = head; // Set the new node's previous to head
    }

    // Function to delete a node with a given key from the list
    public void delete(int key) {
        Node current = head; // Start from the head

        // Traverse the list to find the node with the given key
        while (current.next != head) {
            current = current.next; // Move to the next node
            if (current.key == key) { // Check if the current node's key matches the key to delete
                // Update the pointers to remove the node from the list
                current.prev.next = current.next; // Bypass the node to delete it
                current.next.prev = current.prev; // Update the previous node's next pointer
                return; // Exit the method after deletion
            }
        }
    }

    // Function to delete the first node in the list
    public void deleteFirst() {
        Node firstNode = head.next; // Get the first node
        head.next = firstNode.next; // Update head's next to the second node
        firstNode.next.prev = head; // Update the new first node's previous to head
    }

    // Function to delete the last node in the list
    public void deleteLast() {
        Node lastNode = head.prev; // Get the last node
        head.prev = lastNode.prev; // Update head's previous to the second last node
        lastNode.prev.next = head; // Update the new last node's next to head
    }

    // Function to print the remaining elements in the list
    public void printList() {
        Node current = head;
        while (current.next != head) { // Traverse the list until we reach the head again
            current = current.next; // Move to the next node
            System.out.print(current.key); // Print the key of the current node
            if (current.next != head) { // Check if we are not at the head node
                System.out.print(" "); // Print space between numbers
            }
        }
        System.out.println(); // Print newline after all elements
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DoublyLinkedList list = new DoublyLinkedList(); // Create a new doubly linked list

        // Read the number of operations to perform
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            String op = scanner.next(); // Read the operation command
            if (op.equals("insert")) { // Check if the operation is "insert"
                int a = scanner.nextInt(); // Read the value to insert
                list.insert(a); // Call insert function
            } else if (op.equals("delete")) { // Check if the operation is "delete"
                int a = scanner.nextInt(); // Read the value to delete
                list.delete(a); // Call delete function
            } else if (op.equals("deleteFirst")) { // Check if the operation is "deleteFirst"
                list.deleteFirst(); // Call function to delete the first node
            } else if (op.equals("deleteLast")) { // Check if the operation is "deleteLast"
                list.deleteLast(); // Call function to delete the last node
            }
        }

        // Print the remaining elements in the list
        list.printList(); // Print the list

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
