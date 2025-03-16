import java.util.Scanner; // Import the Scanner class for reading user input

public class Main {
    // Define the Node class which represents a node in the linked list
    private class Node {
        Item data; // The data stored in the node
        Node previous; // Reference to the previous node in the list

        // Constructor for the Node class
        Node(Item data) {
            this.data = data;
            this.previous = null; // Initialize the previous reference to null
        }
    }

    // The head of the linked list (top of the stack)
    private Node head;
    // The size of the stack
    private int size;

    // Constructor for the Main class, initializes the stack
    public Main() {
        head = null; // Initialize the head to null
        size = 0; // Initialize the size to 0
    }

    // Method to add an item to the top of the stack
    public void push(Item item) {
        Node newNode = new Node(item); // Create a new node with the given item
        newNode.previous = head; // Set the new node's previous reference to the current head
        head = newNode; // Update the head to be the new node
        size++; // Increment the size of the stack
    }

    // Method to remove and return the item from the top of the stack
    public Item pop() {
        if (isEmpty()) { // Check if the stack is empty
            throw new IllegalStateException("Cannot pop from an empty stack."); // Throw an exception if the stack is empty
        }
        Item data = head.data; // Get the data from the top node
        head = head.previous; // Update the head to be the previous node
        size--; // Decrement the size of the stack
        return data; // Return the data from the top node
    }

    // Method to return the item from the top of the stack without removing it
    public Item peek() {
        if (isEmpty()) { // Check if the stack is empty
            throw new IllegalStateException("Cannot peek from an empty stack."); // Throw an exception if the stack is empty
        }
        return head.data; // Return the data from the top node
    }

    // Method to check if the stack is empty
    public boolean isEmpty() {
        return head == null; // Return true if the head is null, indicating the stack is empty
    }

    // Method to return the size of the stack
    public int size() {
        return size; // Return the current size of the stack
    }

    // Main method to run the stack application
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading user input
        Main<Integer> stack = new Main<>(); // Create a new instance of the Main class for integers
        while (scanner.hasNextLine()) { // Continuously read lines from the user
            String command = scanner.nextLine().trim(); // Read the command and trim any extra whitespace
            if (command.equalsIgnoreCase("exit")) { // Check if the user wants to exit
                break; // Exit the loop if the user wants to exit
            }
            try {
                String[] parts = command.split(" "); // Split the command into parts
                switch (parts[0]) { // Switch on the first part of the command
                    case "push":
                        if (parts.length < 2) { // Check if a value was provided
                            System.out.println("Error: Missing value for push"); // Print an error message if no value was provided
                            break;
                        }
                        int value = Integer.parseInt(parts[1]); // Parse the value from a string to an integer
                        stack.push(value); // Push the value onto the stack
                        System.out.println("Pushed: " + value); // Print a confirmation message
                        break;
                    case "pop":
                        System.out.println("Popped: " + stack.pop()); // Pop the top item from the stack and print it
                        break;
                    case "peek":
                        System.out.println("Top: " + stack.peek()); // Peek at the top item of the stack and print it
                        break;
                    case "size":
                        System.out.println("Size: " + stack.size()); // Print the size of the stack
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + stack.isEmpty()); // Print whether the stack is empty
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]); // Print an error message for an unknown command
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage()); // Print an error message if an exception occurs
            }
        }
        scanner.close(); // Close the Scanner object
    }
}
