import java.util.Scanner;

public class Main {
    // Node class representing each element in the linked list
    static class Node {
        int value; // Value of the node
        Node next; // Pointer to the next node in the list

        // Constructor to initialize the node with a value
        Node(int value) {
            this.value = value;
        }
    }

    // Method to calculate the length of the linked list
    public int length(Node head) {
        Node curr = head; // Start from the head of the list
        int count = 0; // Initialize count of nodes
        // Traverse the list until the end
        while (curr != null) {
            curr = curr.next; // Move to the next node
            count++; // Increment the count
        }
        return count; // Return the total count of nodes
    }

    // Method to reverse the linked list in groups of k nodes
    public Node reverse(Node head, int count, int k) {
        // If the remaining nodes are less than k, return the head as is
        if (count < k) {
            return head;
        }

        Node prev = null; // Previous node initialized to null
        int count1 = 0; // Counter for the current group
        Node curr = head; // Current node starts at head
        Node next = null; // Next node placeholder

        // Reverse k nodes in the current group
        while (curr != null && count1 < k) {
            next = curr.next; // Store the next node
            curr.next = prev; // Reverse the link
            prev = curr; // Move prev to current node
            curr = next; // Move to the next node
            count1++; // Increment the count for the current group
        }

        // Recursively reverse the next groups and link them
        if (next != null) {
            head.next = reverse(next, count - k, k);
        }
        return prev; // Return the new head of the reversed group
    }

    // Method to initiate the reversal of the linked list in k-sized groups
    public Node reverseKGroup(Node head, int k) {
        int count = length(head); // Get the total length of the list
        return reverse(head, count, k); // Call the reverse method
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int n = scanner.nextInt(); // Read the number of nodes

        // Check if the number of nodes is valid
        if (n <= 0) {
            System.out.println("The linked list must contain at least one node.");
            return; // Exit if the list is empty
        }

        // Create the head of the linked list
        Node head = new Node(scanner.nextInt());
        Node temp = head; // Temporary pointer for building the list

        // Build the linked list from the input values
        for (int i = 1; i < n; i++) {
            temp.next = new Node(scanner.nextInt()); // Create new node and link it
            temp = temp.next; // Move the temporary pointer to the new node
        }

        int k = scanner.nextInt(); // Read the value of k for group reversal
        Main reverseKGroup = new Main(); // Create an instance of Main
        head = reverseKGroup.reverseKGroup(head, k); // Reverse the linked list in k groups

        // Print the modified linked list
        System.out.println("Modified linked list:");
        temp = head; // Reset temp to the head of the modified list
        while (temp != null) {
            System.out.print(temp.value + " "); // Print the value of each node
            temp = temp.next; // Move to the next node
        }
        System.out.println(); // Print a new line after the list
        scanner.close(); // Close the scanner to free resources
    }
}
