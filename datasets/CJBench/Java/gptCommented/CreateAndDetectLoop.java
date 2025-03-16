import java.util.*;

public final class Main {
    // Private constructor to prevent instantiation of the utility class
    private Main() {
        throw new UnsupportedOperationException("Utility class");
    }

    // Node class representing each element in the linked list
    static final class Node {
        int data; // Data stored in the node
        Node next; // Reference to the next node in the list

        // Constructor to initialize a new node with data
        Node(int data) {
            this.data = data;
            next = null; // Initially, the next node is null
        }
    }

    // Head of the linked list
    static Node head = null;

    // Method to add a new node with the specified data to the end of the list
    static void addNode(int data) {
        Node newNode = new Node(data); // Create a new node
        if (head == null) { // If the list is empty
            head = newNode; // Set the new node as the head
        } else {
            Node temp = head; // Start from the head
            // Traverse to the end of the list
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode; // Link the new node at the end
        }
    }

    // Method to print the linked list up to 20 nodes or indicate a loop
    static void printList() {
        Node temp = head; // Start from the head
        int count = 0; // Counter to limit the number of printed nodes
        // Traverse the list and print each node's data
        while (temp != null && count < 20) {
            System.out.print(temp.data + " -> ");
            temp = temp.next; // Move to the next node
            count++;
        }
        // Check if there are more nodes after the first 20
        if (temp != null) {
            System.out.print("... (loop detected)"); // Indicate loop if exists
        } else {
            System.out.print("null"); // Indicate end of the list
        }
        System.out.println(); // New line after printing the list
    }

    // Method to create a loop in the linked list between two specified positions
    static void createLoop(int position1, int position2) {
        // Return if either position is invalid
        if (position1 == 0 || position2 == 0) {
            return;
        }
        Node node1 = head; // Pointer to find the first node for the loop
        Node node2 = head; // Pointer to find the second node for the loop
        int count1 = 1; // Counter for the first position
        int count2 = 1; // Counter for the second position

        // Traverse to the first position
        while (count1 < position1 && node1 != null) {
            node1 = node1.next;
            count1++;
        }
        // Traverse to the second position
        while (count2 < position2 && node2 != null) {
            node2 = node2.next;
            count2++;
        }
        // Create a loop by linking the second node to the first node
        if (node1 != null && node2 != null) {
            node2.next = node1; // Create the loop
        }
    }

    // Method to detect if there is a loop in the linked list using Floyd's cycle-finding algorithm
    static boolean detectLoop() {
        Node sptr = head; // Slow pointer
        Node fptr = head; // Fast pointer
        // Traverse the list with two pointers
        while (fptr != null && fptr.next != null) {
            sptr = sptr.next; // Move slow pointer by one
            fptr = fptr.next.next; // Move fast pointer by two
            // If the two pointers meet, a loop is detected
            if (sptr == fptr) {
                return true; // Loop detected
            }
        }
        return false; // No loop detected
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Scanner for user input
        // Loop to process user commands
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read and trim the command
            if (command.isEmpty()) { // Skip empty commands
                continue;
            }
            if (command.equalsIgnoreCase("exit")) { // Exit command
                break;
            }
            try {
                String[] parts = command.split(" "); // Split command into parts
                switch (parts[0]) { // Determine the command type
                    case "add": // Command to add a node
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for add");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]); // Parse the value to add
                        addNode(value); // Add the node
                        System.out.println("Added: " + value); // Confirmation message
                        break;
                    case "createLoop": // Command to create a loop
                        if (parts.length < 3) {
                            System.out.println("Error: Missing positions for createLoop");
                            break;
                        }
                        int pos1 = Integer.parseInt(parts[1]); // Parse the first position
                        int pos2 = Integer.parseInt(parts[2]); // Parse the second position
                        createLoop(pos1, pos2); // Create the loop
                        System.out.println("Loop created between positions " + pos1 + " and " + pos2);
                        break;
                    case "detectLoop": // Command to detect a loop
                        System.out.println("Loop detected: " + detectLoop()); // Output result of loop detection
                        break;
                    case "print": // Command to print the list
                        printList(); // Print the linked list
                        break;
                    default: // Handle unknown commands
                        System.out.println("Unknown command: " + parts[0]);
                }
            } catch (Exception e) { // Handle exceptions
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close(); // Close the scanner
    }
}
