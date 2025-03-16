import java.util.Scanner;

// Define the class for a node in the doubly linked list
class Node {
    int key;          // The value stored in the node
    Node next;       // Pointer to the next node
    Node prev;       // Pointer to the previous node

    // Constructor to create a new node
    Node(int key) {
        this.key = key;
        this.next = null;
        this.prev = null;
    }
}

public class DoublyLinkedList {
    private Node head; // Pointer to the head of the doubly linked list

    // Constructor to initialize the head node
    public DoublyLinkedList() {
        head = new Node(0);
        head.next = head;
        head.prev = head;
    }

    // Function to insert a new node with the given key after the head node
    public void insert(int a) {
        Node newNode = new Node(a); // Create a new node
        newNode.next = head.next; // Set the next pointer of the new node
        head.next.prev = newNode; // Set the prev pointer of the current head->next
        head.next = newNode; // Set the next pointer of the head to the new node
        newNode.prev = head; // Set the prev pointer of the new node to the head
    }

    // Function to delete the node with the given key
    public void delete(int a) {
        Node current = head;

        // Traverse the list to find the node with the given key
        while (current.next != head) {
            current = current.next;
            if (current.key == a) {
                current.prev.next = current.next; // Update the next pointer of the previous node
                current.next.prev = current.prev; // Update the prev pointer of the next node
                break; // Exit the loop after deleting the node
            }
        }
    }

    // Function to delete the first node after the head node
    public void deleteFirst() {
        Node firstNode = head.next; // Get the first node
        head.next = firstNode.next; // Update the next pointer of the head
        firstNode.next.prev = head; // Update the prev pointer of the node after the first node
    }

    // Function to delete the last node before the head node
    public void deleteLast() {
        Node lastNode = head.prev; // Get the last node
        head.prev = lastNode.prev; // Update the prev pointer of the head
        lastNode.prev.next = head; // Update the next pointer of the node before the last node
    }

    // Function to print the list
    public void printList() {
        Node current = head;
        while (current.next != head) {
            current = current.next;
            System.out.print(current.key);
            if (current.next != head) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DoublyLinkedList list = new DoublyLinkedList();
        
        // Read the number of operations
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            String op = scanner.next();
            if (op.equals("insert")) {
                int a = scanner.nextInt();
                list.insert(a);
            } else if (op.equals("delete")) {
                int a = scanner.nextInt();
                list.delete(a);
            } else if (op.equals("deleteFirst")) {
                list.deleteFirst();
            } else if (op.equals("deleteLast")) {
                list.deleteLast();
            }
        }
        
        // Print the list
        list.printList();
        scanner.close();
    }
}

// <END-OF-CODE>
