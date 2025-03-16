import java.util.Scanner;

// Define a class for a node
class Node {
    int key; // Key value of the node
    Node next; // Pointer to the next node
    Node prev; // Pointer to the previous node

    // Constructor to initialize a node
    Node(int key) {
        this.key = key;
        this.next = null;
        this.prev = null;
    }
}

// Define a class for the doubly linked list
public class DoublyLinkedList {
    private Node nil; // Initialize nil node

    // Constructor to initialize the linked list with a nil node
    public DoublyLinkedList() {
        nil = new Node(0); // Create a nil node
        nil.next = nil; // Initialize next pointer of nil to itself
        nil.prev = nil; // Initialize prev pointer of nil to itself
    }

    // Function to search a node with given key
    private Node listSearch(int key) {
        Node cur = nil.next; // Initialize current node as the first node after nil
        while (cur != nil) { // Traverse the list until nil is reached
            if (cur.key == key) break; // If the current node's key matches the given key, break the loop
            cur = cur.next; // Move to the next node
        }
        return cur; // Return the found node or nil if not found
    }

    // Function to print the linked list
    public void printList() {
        Node cur = nil.next; // Initialize current node as the first node after nil
        boolean isFirst = true; // Initialize isFirst flag to true
        while (cur != nil) { // Traverse the list until nil is reached
            if (isFirst) {
                System.out.print("[" + cur.key + "] "); // If it's the first node, print its key with brackets
                isFirst = false; // Set isFirst flag to false
            } else {
                System.out.print(cur.key + " "); // Otherwise, print only the key
            }
            cur = cur.next; // Move to the next node
        }
        System.out.println(); // Print a newline after the list is printed
    }

    // Function to delete a node from the linked list
    private void deleteNode(Node t) {
        if (t == nil) return; // Return if the node to be deleted is nil
        t.prev.next = t.next; // Update the next pointer of the previous node
        t.next.prev = t.prev; // Update the prev pointer of the next node
    }

    // Function to delete the first node from the linked list
    public void deleteFirst() {
        Node t = nil.next; // Initialize the node to be deleted as the first node
        if (t == nil) return; // Return if the list is empty
        deleteNode(t); // Delete the first node
    }

    // Function to delete the last node from the linked list
    public void deleteLast() {
        Node t = nil.prev; // Initialize the node to be deleted as the last node
        if (t == nil) return; // Return if the list is empty
        deleteNode(t); // Delete the last node
    }

    // Function to delete a node with the given key from the linked list
    public void deleteKey(int key) {
        Node t = listSearch(key); // Search for the node with the given key
        if (t != nil) deleteNode(t); // Delete the node if it's found
    }

    // Function to insert a new node with the given key into the linked list
    public void insert(int key) {
        Node x = new Node(key); // Allocate memory for the new node
        x.prev = nil; // Set the prev pointer of the new node to nil
        x.next = nil.next; // Set the next pointer of the new node to the first node after nil
        nil.next.prev = x; // Update the prev pointer of the first node after nil
        nil.next = x; // Update the next pointer of nil to point to the new node
    }

    // Main function to read commands and perform the corresponding actions
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int key, n; // Initialize variables for reading commands
        DoublyLinkedList list = new DoublyLinkedList(); // Initialize the linked list
        n = scanner.nextInt(); // Read the number of commands
        for (int i = 0; i < n; i++) { // Traverse the commands
            String command = scanner.next(); // Read the command
            key = scanner.nextInt(); // Read the key value
            if (command.charAt(0) == 'i') { // If the command is 'i', insert a new node
                list.insert(key);
            } else if (command.charAt(0) == 'd') { // If the command is 'd', delete a node
                if (command.length() > 6) { // If the command is 'd F' or 'd L'
                    if (command.charAt(6) == 'F') list.deleteFirst();
                    else if (command.charAt(6) == 'L') list.deleteLast();
                } else { // Otherwise, delete a node with the given key
                    list.deleteKey(key);
                }
            }
        }
        list.printList(); // Print the updated linked list
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
