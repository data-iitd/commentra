import java.util.Scanner;

public class Main {
    // Head and tail pointers for the linked list
    private Node head;
    private Node tail;

    // Constructor to initialize an empty linked list
    public Main() {
        this.head = null;
        this.tail = null;
    }

    // Method to insert a new value into the linked list
    public void insert(int value) {
        // Create a new node with the given value
        Node newNode = new Node(value);
        
        // If the list is empty, set the new node as both head and tail
        if (head == null) {
            this.head = newNode;
            this.tail = newNode;
        } 
        // If the new value is less than the head's value, insert at the beginning
        else if (value < head.value) {
            newNode.next = this.head;
            this.head = newNode;
        } 
        // If the new value is greater than the tail's value, insert at the end
        else if (value > tail.value) {
            this.tail.next = newNode;
            this.tail = newNode;
        } 
        // Otherwise, find the correct position to insert the new node
        else {
            Node temp = head;
            while (temp.next != null && temp.next.value < value) {
                temp = temp.next;
            }
            // Insert the new node in the correct position
            newNode.next = temp.next;
            temp.next = newNode;
            // Update the tail if the new node is inserted at the end
            if (newNode.next == null) {
                this.tail = newNode;
            }
        }
    }

    // Method to delete a value from the linked list
    public boolean delete(int value) {
        // If the list is empty, return false
        if (this.head == null) {
            return false;
        } 
        // If the value to delete is at the head
        else if (this.head.value == value) {
            // If the list has only one node, reset head and tail
            if (this.head.next == null) {
                this.head = null;
                this.tail = null;
            } else {
                // Move head to the next node
                this.head = this.head.next;
            }
            return true;
        } else {
            Node temp = this.head;
            // Traverse the list to find the value to delete
            while (temp.next != null) {
                if (temp.next.value == value) {
                    // Update tail if the deleted node is the tail
                    if (temp.next == this.tail) {
                        this.tail = temp;
                    }
                    // Bypass the node to delete it
                    temp.next = temp.next.next;
                    return true;
                }
                temp = temp.next;
            }
            return false; // Value not found
        }
    }

    // Method to search for a value in the linked list
    public boolean search(int value) {
        Node temp = this.head;
        // Traverse the list to find the value
        while (temp != null) {
            if (temp.value == value) {
                return true; // Value found
            }
            temp = temp.next;
        }
        return false; // Value not found
    }

    // Method to check if the linked list is empty
    public boolean isEmpty() {
        return head == null; // Returns true if head is null
    }

    // Method to return a string representation of the linked list
    @Override
    public String toString() {
        if (this.head != null) {
            StringBuilder sb = new StringBuilder("[");
            Node temp = this.head;
            // Traverse the list and append values to the StringBuilder
            while (temp != null) {
                sb.append(temp.value);
                if (temp.next != null) {
                    sb.append(", ");
                }
                temp = temp.next;
            }
            sb.append("]");
            return sb.toString(); // Return the string representation
        } else {
            return "[]"; // Return empty list representation
        }
    }

    // Inner class representing a node in the linked list
    public final class Node {
        public final int value; // Value of the node
        public Node next; // Pointer to the next node

        // Constructor to create a new node
        public Node(int value) {
            this.value = value;
            this.next = null; // Initialize next as null
        }
    }

    // Main method to run the linked list operations
    public static void main(String[] args) {
        Main list = new Main(); // Create a new linked list
        Scanner scanner = new Scanner(System.in); // Scanner for user input

        // Loop to continuously accept commands from the user
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read the command
            if (command.isEmpty()) {
                continue; // Skip empty commands
            }
            if (command.equalsIgnoreCase("exit")) {
                break; // Exit the loop on "exit" command
            }
            try {
                String[] parts = command.split(" "); // Split command into parts
                switch (parts[0]) {
                    case "insert":
                        // Check for missing value for insert command
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for insert");
                            break;
                        }
                        int insertValue = Integer.parseInt(parts[1]); // Parse the value
                        list.insert(insertValue); // Insert the value into the list
                        System.out.println("Inserted: " + insertValue);
                        break;
                    case "delete":
                        // Check for missing value for delete command
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for delete");
                            break;
                        }
                        int deleteValue = Integer.parseInt(parts[1]); // Parse the value
                        boolean deleted = list.delete(deleteValue); // Attempt to delete the value
                        System.out.println(deleted ? "Deleted: " + deleteValue : "Value not found: " + deleteValue);
                        break;
                    case "search":
                        // Check for missing value for search command
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for search");
                            break;
                        }
                        int searchValue = Integer.parseInt(parts[1]); // Parse the value
                        boolean found = list.search(searchValue); // Search for the value
                        System.out.println(found ? "Found: " + searchValue : "Not found: " + searchValue);
                        break;
                    case "isEmpty":
                        // Check if the list is empty
                        System.out.println("Is empty: " + list.isEmpty());
                        break;
                    case "print":
                        // Print the current state of the list
                        System.out.println("List: " + list);
                        break;
                    default:
                        // Handle unknown commands
                }
            } catch (Exception e) {
                // Handle any exceptions that occur during command processing
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close(); // Close the scanner
    }
}
