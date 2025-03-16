
import java.util.*;

public final class Main {
    private Main() {
        throw new UnsupportedOperationException("Utility class");
    }

    // Define a static inner class Node to represent a node in the singly linked list
    static final class Node {
        int data;
        Node next;

        // Constructor for Node with given data and null next reference
        Node(int data) {
            this.data = data;
            next = null;
        }
    }

    // Initialize the head of the linked list to null
    static Node head = null;

    // Method to add a new node with given data to the end of the linked list
    static void addNode(int data) {
        Node newNode = new Node(data); // Create a new Node with the given data

        if (head == null) { // If the linked list is empty
            head = newNode; // Make the new Node the head
        } else {
            Node temp = head; // Initialize a temporary Node to traverse the linked list
            while (temp.next != null) { // Traverse the linked list until the end is reached
                temp = temp.next;
            }
            temp.next = newNode; // Attach the new Node to the end of the linked list
        }
    }

    // Method to print the first 20 elements of the linked list
    static void printList() {
        Node temp = head; // Initialize a temporary Node to traverse the linked list
        int count = 0; // Initialize a counter to keep track of the number of elements printed

        while (temp != null && count < 20) { // Traverse the linked list and print the first 20 elements
            System.out.print(temp.data + " -> ");
            temp = temp.next;
            count++;
        }

        if (temp != null) { // If more than 20 elements are present in the linked list
            System.out.print("... (loop detected)"); // Print a message indicating that a loop was detected
        } else {
            System.out.print("null"); // If the linked list is empty or contains fewer than 20 elements, print "null"
        }

        System.out.println(); // Print a newline character to separate the output from the previous command
    }

    // Method to create a loop in the linked list by connecting the nodes at the given positions
    static void createLoop(int position1, int position2) {
        if (position1 == 0 || position2 == 0) { // Check if the positions are valid
            return;
        }

        Node node1 = head; // Initialize two Node variables to traverse the linked list
        Node node2 = head;

        int count1 = 1; // Initialize two counters to keep track of the number of nodes traversed
        int count2 = 1;

        while (count1 < position1 && node1 != null) { // Traverse the linked list until the first node is reached
            node1 = node1.next;
            count1++;
        }

        while (count2 < position2 && node2 != null) { // Traverse the linked list until the second node is reached
            node2 = node2.next;
            count2++;
        }

        if (node1 != null && node2 != null) { // Check if both nodes are valid and not null
            node2.next = node1; // Connect the second node to the first node to create a loop
        }
    }

    // Method to detect a loop in the linked list by using Floyd's cycle-finding algorithm
    static boolean detectLoop() {
        Node sptr = head; // Initialize two Node variables to traverse the linked list at different speeds
        Node fptr = head;

        while (fptr != null && fptr.next != null) { // Traverse the linked list until the fast pointer reaches null or a loop is detected
            sptr = sptr.next; // Move the slow pointer one node forward
            fptr = fptr.next.next; // Move the fast pointer two nodes forward

            if (sptr == fptr) { // If the slow and fast pointers meet, a loop has been detected
                return true;
            }
        }

        return false; // If no loop was detected, return false
    }

    // Main method to read user input and execute the corresponding command
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read user input

        while (scanner.hasNextLine()) { // Read user input until the end of the input stream is reached
            String command = scanner.nextLine().trim(); // Read a line of user input and remove any leading or trailing whitespace

            if (command.isEmpty()) { // If the user input is empty, skip it
                continue;
            }

            if (command.equalsIgnoreCase("exit")) { // If the user input is "exit", terminate the program
                break;
            }

            try { // Try to parse the user input as a command and execute it
                String[] parts = command.split(" ");
                switch (parts[0]) {
                    case "add": // If the command is "add", add a new node to the linked list
                        if (parts.length < 2) { // Check if the command has the required number of arguments
                            System.out.println("Error: Missing value for add");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]); // Parse the value argument as an integer
                        addNode(value); // Add the new node to the linked list
                        System.out.println("Added: " + value); // Print a message indicating that the node was added
                        break;
                    case "createLoop": // If the command is "createLoop", create a loop in the linked list
                        if (parts.length < 3) { // Check if the command has the required number of arguments
                            System.out.println("Error: Missing positions for createLoop");
                            break;
                        }
                        int pos1 = Integer.parseInt(parts[1]); // Parse the first position argument as an integer
                        int pos2 = Integer.parseInt(parts[2]); // Parse the second position argument as an integer
                        createLoop(pos1, pos2); // Create a loop in the linked list at the given positions
                        System.out.println("Loop created between positions " + pos1 + " and " + pos2); // Print a message indicating that the loop was created
                        break;
                    case "detectLoop": // If the command is "detectLoop", detect a loop in the linked list
                        System.out.println("Loop detected: " + detectLoop()); // Print the result of the detectLoop() method
                        break;
                    case "print": // If the command is "print", print the first 20 elements of the linked list
                        printList(); // Call the printList() method to print the linked list
                        break;
                    default: // If the command is not recognized, print an error message
                        System.out.println("Unknown command: " + parts[0]);
                }
            } catch (Exception e) { // Catch any exceptions that may be thrown during command execution
                System.out.println("Error: " + e.getMessage()); // Print an error message indicating the cause of the exception
            }
        }

        scanner.close(); // Close the Scanner object when the program terminates
    }
}