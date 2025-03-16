import java.util.Scanner;

// Define the structure for a node in the circular doubly linked list
class Node {
    int key;          // Integer key stored in the node
    Node next;       // Pointer to the next node in the list
    Node prev;       // Pointer to the previous node in the list

    // Constructor to initialize a new node
    Node(int key) {
        this.key = key;
        this.next = null;
        this.prev = null;
    }
}

// Define a class for the circular doubly linked list
class CircularDoublyLinkedList {
    private Node sentinel; // Sentinel node

    // Initialize the circular doubly linked list
    public CircularDoublyLinkedList() {
        sentinel = new Node(0); // Create the sentinel node
        sentinel.next = sentinel; // Set the next pointer of the sentinel node to itself
        sentinel.prev = sentinel; // Set the previous pointer of the sentinel node to itself
    }

    // Print the elements of the circular doubly linked list
    public void printList() {
        Node cur = sentinel.next; // Start from the first node
        boolean firstElement = true; // Flag to determine if it's the first element
        while (cur != sentinel) { // Iterate until the sentinel node is reached
            if (!firstElement) {
                System.out.print(" "); // Print a space before non-first elements
            }
            System.out.print(cur.key); // Print the key of the current node
            cur = cur.next; // Move to the next node
            firstElement = false; // Set the flag to indicate a non-first element
        }
        System.out.println(); // Print a newline at the end
    }

    // Delete the first node in the circular doubly linked list
    public void deleteFirst() {
        if (sentinel.next == sentinel) return; // If the list is empty, do nothing
        Node t = sentinel.next; // Store the first node
        sentinel.next = t.next; // Update the next pointer of the sentinel node
        t.next.prev = sentinel; // Update the previous pointer of the new first node
    }

    // Delete the last node in the circular doubly linked list
    public void deleteLast() {
        if (sentinel.prev == sentinel) return; // If the list is empty, do nothing
        Node delNode = sentinel.prev; // Store the last node
        sentinel.prev = delNode.prev; // Update the previous pointer of the sentinel node
        delNode.prev.next = sentinel; // Update the next pointer of the new last node
    }

    // Delete a node with a specific key from the circular doubly linked list
    public void delete(int skey) {
        Node n = sentinel.next; // Start from the first node
        while (n != sentinel) { // Iterate through the list to find the node with the specified key
            if (n.key == skey) {
                n.prev.next = n.next; // Remove the node from the list
                n.next.prev = n.prev; // Update the previous pointer of the next node
                return; // Exit after deleting the node
            }
            n = n.next; // Move to the next node
        }
    }

    // Insert a new node with a specific key into the circular doubly linked list
    public void insert(int skey) {
        Node newNode = new Node(skey); // Create a new node
        if (sentinel.next == sentinel) { // Special case: if the list is empty
            newNode.next = sentinel;
            newNode.prev = sentinel;
            sentinel.next = newNode;
            sentinel.prev = newNode;
        } else {
            newNode.next = sentinel.next; // Set the next pointer of the new node
            sentinel.next.prev = newNode; // Update the previous pointer of the current first node
            sentinel.next = newNode; // Update the next pointer of the sentinel node
            newNode.prev = sentinel; // Set the previous pointer of the new node
        }
    }
}

// Main class to execute the operations on the circular doubly linked list
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of commands
        CircularDoublyLinkedList list = new CircularDoublyLinkedList(); // Initialize the circular doubly linked list

        for (int i = 0; i < n; i++) { // Loop through the number of commands
            String command = scanner.next(); // Read the command
            if (command.equals("insert")) { // If the command is to insert
                int key = scanner.nextInt(); // Read the key to insert
                list.insert(key); // Insert the key into the list
            } else if (command.equals("deleteFirst")) { // If the command is to delete the first node
                list.deleteFirst();
            } else if (command.equals("deleteLast")) { // If the command is to delete the last node
                list.deleteLast();
            } else { // If the command is to delete a specific node
                int key = scanner.nextInt(); // Read the key to delete
                list.delete(key); // Delete the node with the specified key
            }
        }
        list.printList(); // Print the final state of the list
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
