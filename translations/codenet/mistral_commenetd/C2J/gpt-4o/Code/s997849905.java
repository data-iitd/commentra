import java.util.Scanner;

// Define a class for a node
class Node {
    int key; // Key value of the node
    Node next; // Pointer to the next node
    Node prev; // Pointer to the previous node

    // Constructor to initialize a node
    Node(int key) {
        this.key = key;
        this.next = this; // Initialize next pointer to itself
        this.prev = this; // Initialize prev pointer to itself
    }
}

// Define a class for the doubly linked list
public class DoublyLinkedList {
    private Node head; // Pointer to the first node

    // Initialize the linked list
    public void init() {
        head = new Node(0); // Create a dummy head node
    }

    // Print the contents of the linked list
    public void printList() {
        Node cur = head.next; // Initialize a pointer to traverse the list
        boolean first = true; // Flag to control the printing of spaces between numbers
        while (cur != head) { // Traverse the list until the end is reached
            if (!first) // If not the first element, print a space
                System.out.print(" ");
            System.out.print(cur.key); // Print the key value of the current node
            cur = cur.next; // Move to the next node
            first = false; // Reset the flag for the next iteration
        }
        System.out.println(); // Print a newline at the end
    }

    // Delete the first node from the list
    public void deleteFirst() {
        if (head.next != head) { // Check if the list is not empty
            Node t = head.next; // Initialize a pointer to the second node
            head.next = t.next; // Update the next pointer of the head to point to the third node
            t.next.prev = head; // Update the prev pointer of the third node to point to the head
        }
    }

    // Delete the last node from the list
    public void deleteLast() {
        if (head.prev != head) { // Check if the list is not empty
            Node delNode = head.prev; // Initialize a pointer to the last node
            head.prev = delNode.prev; // Update the prev pointer of the head to point to the second last node
            delNode.prev.next = head; // Update the next pointer of the second last node to point to the head
        }
    }

    // Delete a node with the given key from the list
    public void delete(int skey) {
        Node n = head.next; // Initialize a pointer to traverse the list
        while (n != head) { // Traverse the list to find the node to be deleted
            if (n.key == skey) { // If the key matches, delete the node
                n.prev.next = n.next; // Update the next pointer of the previous node
                n.next.prev = n.prev; // Update the prev pointer of the next node
                return; // Exit after deletion
            }
            n = n.next; // Move to the next node
        }
    }

    // Insert a new node with the given key into the list
    public void insert(int skey) {
        Node newNode = new Node(skey); // Create a new node
        if (head.next == head) { // If the list is empty
            head.next = newNode;
            head.prev = newNode;
            newNode.next = head;
            newNode.prev = head;
        } else { // If the list is not empty, insert the new node at the end
            newNode.next = head;
            newNode.prev = head.prev;
            head.prev.next = newNode;
            head.prev = newNode;
        }
    }

    // Main method to read commands and perform the corresponding operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DoublyLinkedList list = new DoublyLinkedList();
        list.init(); // Initialize the linked list

        int n = scanner.nextInt(); // Read the number of operations to be performed
        for (int i = 0; i < n; i++) { // Perform each operation in the loop
            String command = scanner.next(); // Read the command string
            if (command.equals("insert")) { // If the command is to insert a node
                int key = scanner.nextInt();
                list.insert(key);
            } else if (command.equals("deleteFirst")) {
                list.deleteFirst(); // If the command is to delete the first node
            } else if (command.equals("deleteLast")) {
                list.deleteLast(); // If the command is to delete the last node
            } else { // If the command is to delete a node with a given key
                int key = scanner.nextInt();
                list.delete(key);
            }
        }
        list.printList(); // Print the updated list after performing all the operations
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
