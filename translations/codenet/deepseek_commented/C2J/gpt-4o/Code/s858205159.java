import java.util.Scanner;

// Define the structure for a node in the doubly linked list
class Node {
    int key;  // The integer key stored in the node
    Node next;  // Pointer to the next node in the list
    Node prev;  // Pointer to the previous node in the list

    // Constructor to initialize a node
    Node(int key) {
        this.key = key;
        this.next = null;
        this.prev = null;
    }
}

// Class for the doubly linked list
public class DoublyLinkedList {
    private Node nil;  // Sentinel node (dummy node) for the doubly linked list

    // Constructor to initialize the doubly linked list with a sentinel node
    public DoublyLinkedList() {
        nil = new Node(0);  // Create the sentinel node
        nil.next = nil;  // The next pointer of the sentinel node points to itself
        nil.prev = nil;  // The prev pointer of the sentinel node points to itself
    }

    // Function to search for a node with a given key
    private Node listSearch(int key) {
        Node cur = nil.next;  // Start from the first node
        while (cur != nil) {  // Traverse the list until we reach the sentinel node
            if (cur.key == key) break;  // If the key matches, break the loop
            cur = cur.next;  // Move to the next node
        }
        return cur;  // Return the node with the matching key, or nil if not found
    }

    // Function to print the entire list starting from the first node
    public void printList() {
        Node cur = nil.next;  // Start from the first node
        boolean isFirst = true;  // Flag to check if it's the first node to be printed
        while (cur != nil) {  // Traverse until the sentinel node
            if (!isFirst) System.out.print(" ");  // Print a space before each key except the first
            System.out.print(cur.key);  // Print the key of the current node
            cur = cur.next;  // Move to the next node
            isFirst = false;  // Update the flag to indicate that a node has been printed
        }
        System.out.println();  // Print a newline character at the end
    }

    // Function to delete a specified node from the list
    private void deleteNode(Node t) {
        if (t == nil) return;  // If the node is the sentinel node, do nothing
        t.prev.next = t.next;  // Update the next pointer of the previous node
        t.next.prev = t.prev;  // Update the prev pointer of the next node
    }

    // Function to delete the first node in the list
    public void deleteFirst() {
        Node t = nil.next;  // Get the first node
        if (t == nil) return;  // If the list is empty, do nothing
        deleteNode(t);  // Delete the first node
    }

    // Function to delete the last node in the list
    public void deleteLast() {
        Node t = nil.prev;  // Get the last node
        if (t == nil) return;  // If the list is empty, do nothing
        deleteNode(t);  // Delete the last node
    }

    // Function to delete the node with a specified key
    public void deleteKey(int key) {
        Node t = listSearch(key);  // Find the node with the specified key
        if (t != nil) deleteNode(t);  // If the node is found, delete it
    }

    // Function to insert a new node with a specified key at the beginning of the list
    public void insert(int key) {
        Node x = new Node(key);  // Allocate memory for the new node
        x.prev = nil;  // The prev pointer of the new node points to the sentinel node
        x.next = nil.next;  // The next pointer of the new node points to the current first node
        x.next.prev = x;  // Update the prev pointer of the current first node
        nil.next = x;  // Update the next pointer of the sentinel node to the new node
    }

    // Main function to read commands and manipulate the doubly linked list
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int key, n;
        DoublyLinkedList list = new DoublyLinkedList();  // Initialize the list
        n = scanner.nextInt();  // Read the number of commands
        for (int i = 0; i < n; i++) {
            String command = scanner.next();  // Read the command
            key = scanner.nextInt();  // Read the key
            if (command.charAt(0) == 'i') {
                list.insert(key);  // Insert a new node if the command is 'i'
            } else if (command.charAt(0) == 'd') {
                if (command.length() > 6) {  // Check if the command is to delete the first or last node
                    if (command.charAt(6) == 'F') list.deleteFirst();
                    else if (command.charAt(6) == 'L') list.deleteLast();
                } else {
                    list.deleteKey(key);  // Delete the node with the specified key
                }
            }
        }
        list.printList();  // Print the final state of the list
        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
