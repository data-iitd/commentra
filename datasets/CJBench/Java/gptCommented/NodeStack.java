import java.util.Scanner;

public class Main {
    // Node class representing each element in the stack
    private class Node {
        Item data; // Data stored in the node
        Node previous; // Reference to the previous node in the stack

        // Constructor to initialize a new node with data
        Node(Item data) {
            this.data = data;
            this.previous = null; // Initially, previous is null
        }
    }

    private Node head; // Head of the stack (top element)
    private int size; // Size of the stack

    // Constructor to initialize an empty stack
    public Main() {
        head = null; // No elements in the stack
        size = 0; // Size is zero
    }

    // Method to add an item to the top of the stack
    public void push(Item item) {
        Node newNode = new Node(item); // Create a new node with the given item
        newNode.previous = head; // Link the new node to the current head
        head = newNode; // Update head to the new node
        size++; // Increment the size of the stack
    }

    // Method to remove and return the top item from the stack
    public Item pop() {
        // Check if the stack is empty before popping
        if (isEmpty()) {
            throw new IllegalStateException("Cannot pop from an empty stack.");
        }
        Item data = head.data; // Get the data from the head node
        head = head.previous; // Move head to the previous node
        size--; // Decrement the size of the stack
        return data; // Return the popped data
    }

    // Method to return the top item without removing it from the stack
    public Item peek() {
        // Check if the stack is empty before peeking
        if (isEmpty()) {
            throw new IllegalStateException("Cannot peek from an empty stack.");
        }
        return head.data; // Return the data from the head node
    }

    // Method to check if the stack is empty
    public boolean isEmpty() {
        return head == null; // Returns true if head is null, indicating an empty stack
    }

    // Method to return the current size of the stack
    public int size() {
        return size; // Return the size of the stack
    }

    // Main method to run the stack operations based on user input
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        Main<Integer> stack = new Main<>(); // Create a new stack instance for Integer type

        // Loop to continuously read commands until "exit" is entered
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read and trim the input command
            if (command.equalsIgnoreCase("exit")) { // Check for exit command
                break; // Exit the loop
            }
            try {
                String[] parts = command.split(" "); // Split the command into parts
                switch (parts[0]) { // Determine the command type
                    case "push":
                        // Check if a value is provided for push
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for push");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]); // Parse the value to an integer
                        stack.push(value); // Push the value onto the stack
                        System.out.println("Pushed: " + value); // Confirm the push operation
                        break;
                    case "pop":
                        System.out.println("Popped: " + stack.pop()); // Pop and display the top value
                        break;
                    case "peek":
                        System.out.println("Top: " + stack.peek()); // Peek and display the top value
                        break;
                    case "size":
                        System.out.println("Size: " + stack.size()); // Display the current size of the stack
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + stack.isEmpty()); // Check and display if the stack is empty
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]); // Handle unknown commands
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage()); // Handle exceptions and display error messages
            }
        }
        scanner.close(); // Close the scanner resource
    }
}
