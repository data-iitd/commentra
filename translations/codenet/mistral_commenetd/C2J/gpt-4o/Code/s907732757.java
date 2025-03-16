import java.util.Scanner;

class Node {
    int key;
    Node next;
    Node prev;

    Node(int a) {
        this.key = a;
    }
}

public class DoublyLinkedList {
    private Node head; // Initialize head pointer to null

    // Initialize the head node with a dummy node
    public void init() {
        head = new Node(0);
        head.next = head;
        head.prev = head;
    }

    public void insert(int a) {
        Node x = new Node(a); // Allocate memory for new node

        // Insert new node at the end of the list
        x.next = head.next;
        head.next.prev = x;
        head.next = x;
        x.prev = head;
    }

    public void delete(int a) {
        Node x = head;

        // Search for the node to be deleted
        while (x.next != head) {
            x = x.next;
            if (x.key == a) { // Found the node to be deleted
                Node prev = x.prev; // Save the previous node
                prev.next = x.next; // Update the previous node's next pointer
                x.next.prev = prev; // Update the next node's prev pointer
                break;
            }
        }
    }

    public void deleteFirst() {
        Node x = head.next; // Save the second node in a temporary variable

        // Update the head pointer and the previous node's next pointer
        head.next = x.next;
        x.next.prev = head;

        // Free the memory occupied by the first node (handled by Java's garbage collector)
    }

    public void deleteLast() {
        Node x = head;

        // Search for the second last node
        while (x.next != head) {
            x = x.next;
        }

        Node prev = x.prev; // Save the previous node

        // Update the previous node's next pointer and the head pointer's prev pointer
        prev.next = head;
        head.prev = prev;

        // Free the memory occupied by the last node (handled by Java's garbage collector)
    }

    public void printList() {
        Node x = head;

        while (x.next != head) { // Traverse the list and print the keys of the nodes
            System.out.print(x.next.key + " ");
            x = x.next;
        }
        System.out.println(); // Print a newline character at the end
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DoublyLinkedList list = new DoublyLinkedList();
        list.init(); // Initialize the head node

        int n = scanner.nextInt(); // Read the number of operations

        for (int i = 0; i < n; i++) {
            String op = scanner.next(); // Read the operation

            if (op.equals("insert")) { // If the operation is to insert a node
                int a = scanner.nextInt(); // Read the key value of the node to be inserted
                list.insert(a); // Call the insert function
            } else if (op.equals("delete")) { // If the operation is to delete a node
                int a = scanner.nextInt(); // Read the key value of the node to be deleted
                list.delete(a); // Call the delete function
            } else if (op.equals("deleteFirst")) { // If the operation is to delete the first node
                list.deleteFirst(); // Call the deleteFirst function
            } else if (op.equals("deleteLast")) { // If the operation is to delete the last node
                list.deleteLast(); // Call the deleteLast function
            }
        }

        list.printList(); // Print the list

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
