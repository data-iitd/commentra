
import java.util.Scanner;

// Class definition for the Main class
public class Main {
    // Node class inner definition
    private class Node {
        public final int value;
        public Node next;

        // Constructor for Node class
        public Node(int value) {
            this.value = value;
            this.next = null;
        }
    }

    // Instance variables for head and tail nodes
    private Node head;
    private Node tail;

    // Constructor for Main class
    public Main() {
        // Initialize head and tail to null
        this.head = null;
        this.tail = null;
    }

    // Method to insert a new node with given value
    public void insert(int value) {
        Node newNode = new Node(value); // Create a new node with the given value

        // Base case: If the list is empty
        if (head == null) {
            this.head = newNode; // Make the new node as the head
            this.tail = newNode; // Make the new node as the tail
        } else {
            // If the new value is less than the head value
            if (value < head.value) {
                newNode.next = head; // Make the new node's next as the head
                this.head = newNode; // Make the new node as the new head
            } else if (value > tail.value) { // If the new value is greater than the tail value
                this.tail.next = newNode; // Make the new node's next as the tail's next
                this.tail = newNode; // Make the new node as the new tail
            } else { // If the new value is between two nodes
                Node temp = head; // Initialize a temporary node to traverse the list
                while (temp.next != null && temp.next.value < value) {
                    temp = temp.next; // Move to the next node
                }
                newNode.next = temp.next; // Make the new node's next as the next node of the current node
                temp.next = newNode; // Make the current node's next as the new node
                if (newNode.next == null) { // If the new node is the last node
                    this.tail = newNode; // Make the new node as the new tail
                }
            }
        }
    }

    // Method to delete a node with the given value
    public boolean delete(int value) {
        // Base case: If the list is empty
        if (head == null) {
            return false;
        }

        // If the head node itself holds the given value
        if (head.value == value) {
            if (head.next == null) { // If the list has only one node
                this.head = null;
                this.tail = null;
            } else { // If the list has more than one node
                this.head = head.next;
            }
            return true;
        }

        Node temp = head; // Initialize a temporary node to traverse the list
        while (temp.next != null) {
            if (temp.next.value == value) { // If the next node holds the given value
                if (temp.next == tail) { // If the deleted node is the last node
                    this.tail = temp; // Make the previous node as the new tail
                }
                temp.next = temp.next.next; // Make the current node's next as the next node of the deleted node
                return true;
            }
            temp = temp.next; // Move to the next node
        }
        return false; // If the given value is not present in the list
    }

    // Method to search for a node with the given value
    public boolean search(int value) {
        Node temp = head; // Initialize a temporary node to traverse the list
        while (temp != null) {
            if (temp.value == value) { // If the current node holds the given value
                return true;
            }
            temp = temp.next; // Move to the next node
        }
        return false; // If the given value is not present in the list
    }

    // Method to check if the list is empty
    public boolean isEmpty() {
        return head == null;
    }

    // Overridden toString method to print the list
    @Override
    public String toString() {
        if (this.head != null) {
            StringBuilder sb = new StringBuilder("[");
            Node temp = this.head;
            while (temp != null) {
                sb.append(temp.value);
                if (temp.next != null) {
                    sb.append(", ");
                }
                temp = temp.next;
            }
            sb.append("]");
            return sb.toString();
        } else {
            return "[]";
        }
    }

    // Main method to take user input and perform operations
    public static void main(String[] args) {
        Main list = new Main(); // Create an instance of the Main class
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read user input

        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read the user command

            if (command.isEmpty()) { // If the command is empty
                continue; // Skip the current iteration
            }

            if (command.equalsIgnoreCase("exit")) { // If the command is "exit"
                break; // Exit the while loop
            }

            try {
                String[] parts = command.split(" "); // Split the command into parts
                String operation = parts[0]; // Get the operation name

                switch (operation) {
                    case "insert": // If the operation is "insert"
                        if (parts.length < 2) { // If the command is missing the value
                            System.out.println("Error: Missing value for insert");
                            break;
                        }
                        int insertValue = Integer.parseInt(parts[1]); // Get the value to be inserted
                        list.insert(insertValue); // Insert the new node
                        System.out.println("Inserted: " + insertValue); // Print the message
                        break;
                    case "delete": // If the operation is "delete"
                        if (parts.length < 2) { // If the command is missing the value
                            System.out.println("Error: Missing value for delete");
                            break;
                        }
                        int deleteValue = Integer.parseInt(parts[1]); // Get the value to be deleted
                        boolean deleted = list.delete(deleteValue); // Delete the node
                        System.out.println(deleted ? "Deleted: " + deleteValue : "Value not found: " + deleteValue); // Print the message
                        break;
                    case "search": // If the operation is "search"
                        if (parts.length < 2) { // If the command is missing the value
                            System.out.println("Error: Missing value for search");
                            break;
                        }
                        int searchValue = Integer.parseInt(parts[1]); // Get the value to be searched
                        boolean found = list.search(searchValue); // Search for the node
                        System.out.println(found ? "Found: " + searchValue : "Not found: " + searchValue); // Print the message
                        break;
                    case "isEmpty": // If the operation is "isEmpty"
                        System.out.println("Is empty: " + list.isEmpty()); // Print the message
                        break;
                    case "print": // If the operation is "print"
                        System.out.println("List: " + list); // Print the list
                        break;
                    default: // If the operation is not recognized
                }
            } catch (Exception e) { // If there is an exception
                System.out.println("Error: " + e.getMessage()); // Print the error message
            }
        }

        scanner.close(); // Close the Scanner object
    }
}