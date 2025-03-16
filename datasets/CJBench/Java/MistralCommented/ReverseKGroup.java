
import java.util.Scanner; // Importing Scanner class for taking input from the user

public class Main {
    static class Node { // Defining a static inner class Node to represent each node in the linked list
        int value;
        Node next;
        Node(int value) { // Constructor of Node class to initialize the value and next pointer of a node
            this.value = value;
            this.next = null;
        }
    }

    public int length(Node head) { // Method to find the length of the linked list
        Node curr = head; // Initialize a pointer to traverse the linked list
        int count = 0; // Initialize a counter to keep track of the number of nodes in the list
        while (curr != null) { // Traverse the linked list until the end is reached
            curr = curr.next;
            count++;
        }
        return count; // Return the total number of nodes in the list
    }

    public Node reverse(Node head, int count, int k) { // Method to reverse a sublist of length k starting from the head of the linked list
        if (count < k) { // Base case: if the length of the list is less than the required sublist length, return the original head
            return head;
        }
        Node prev = null; // Initialize a pointer to keep track of the previous node in the reversed sublist
        int count1 = 0; // Initialize a counter to keep track of the number of nodes reversed in this iteration
        Node curr = head; // Initialize a pointer to traverse the linked list starting from the head
        Node next = null; // Initialize a pointer to keep track of the next node in the original list
        while (curr != null && count1 < k) { // Traverse the linked list and reverse the sublist of length k
            next = curr.next; // Save the next node in the original list
            curr.next = prev; // Reverse the next pointer of the current node
            prev = curr; // Move the pointer prev to the current node
            curr = next; // Move the pointer curr to the next node in the original list
            count1++; // Increment the counter for the number of nodes reversed in this iteration
        }
        if (next != null) { // If there are more nodes in the original list after the reversed sublist, recursively reverse the remaining part
            head.next = reverse(next, count - k, k);
        }
        return prev; // Return the head of the reversed sublist
    }

    public Node reverseKGroup(Node head, int k) { // Method to reverse a group of k nodes in the linked list starting from the head
        int count = length(head); // Find the length of the linked list
        return reverse(head, count, k); // Call the reverse() method with the head, length, and group size as arguments
    }

    public static void main(String[] args) { // Main method to take input from the user and print the reversed linked list
        Scanner scanner = new Scanner(System.in); // Initialize the Scanner object to read input from the user
        int n = scanner.nextInt(); // Read the number of nodes in the linked list from the user
        if (n <= 0) { // Check if the number of nodes is valid
            System.out.println("The linked list must contain at least one node."); // Print an error message and exit the program
            return;
        }
        Node head = new Node(scanner.nextInt()); // Create the first node of the linked list and assign its value
        Node temp = head; // Initialize a pointer to traverse the linked list
        for (int i = 1; i < n; i++) { // Traverse the linked list and create new nodes, connecting them to the previous node
            temp.next = new Node(scanner.nextInt());
            temp = temp.next;
        }
        int k = scanner.nextInt(); // Read the group size from the user
        Main reverseKGroup = new Main(); // Create an instance of the Main class to call the reverseKGroup() method
        head = reverseKGroup.reverseKGroup(head, k); // Call the reverseKGroup() method with the head and group size as arguments
        System.out.println("Modified linked list:"); // Print the header for the output
        temp = head; // Initialize a pointer to traverse the reversed linked list and print its elements
        while (temp != null) { // Traverse the linked list and print its elements until the end is reached
            System.out.print(temp.value + " ");
            temp = temp.next;
        }
        System.out.println(); // Print a newline character at the end of the output
        scanner.close(); // Close the Scanner object to release the system resources
    }
}