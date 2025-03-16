
import java.util.Scanner; // Import Scanner class for user input

public class Main {
    private class Node { // Define a private inner class Node
        Item data; // Data to be stored in the node
        Node previous; // Previous node in the linked list

        Node(Item data) { // Constructor for Node
            this.data = data;
            this.previous = null;
        }
    }

    private Node head; // Initialize head of the stack as null
    private int size; // Initialize size of the stack as 0

    public Main() { // Constructor for Main class
        head = null;
        size = 0;
    }

    public void push(Item item) { // Method to add an item to the stack
        Node newNode = new Node(item); // Create a new node with the given item
        newNode.previous = head; // Set the new node's previous as the current head
        head = newNode; // Update the head to the new node
        size++; // Increment the size of the stack
    }

    public Item pop() { // Method to remove and return the top item from the stack
        if (isEmpty()) { // Check if the stack is empty
            throw new IllegalStateException("Cannot pop from an empty stack."); // Throw an exception if empty
        }
        Item data = head.data; // Store the data of the top node
        head = head.previous; // Update the head to the previous node
        size--; // Decrement the size of the stack
        return data; // Return the popped item
    }

    public Item peek() { // Method to return the top item from the stack without removing it
        if (isEmpty()) { // Check if the stack is empty
            throw new IllegalStateException("Cannot peek from an empty stack."); // Throw an exception if empty
        }
        return head.data; // Return the data of the top node
    }

    public boolean isEmpty() { // Method to check if the stack is empty or not
        return head == null; // Return true if head is null, else false
    }

    public int size() { // Method to return the size of the stack
        return size; // Return the size of the stack
    }

    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a new Scanner object for user input
        Main<Integer> stack = new Main<>(); // Create an instance of the Main class for the stack

        while (scanner.hasNextLine()) { // Read user input until there is no more input
            String command = scanner.nextLine().trim(); // Read the command from the user

            if (command.equalsIgnoreCase("exit")) { // Check if the command is "exit"
                break; // If yes, exit the loop
            }

            try { // Try to parse the command
                String[] parts = command.split(" "); // Split the command into parts based on space

                switch (parts[0]) { // Switch case based on the command
                    case "push":
                        if (parts.length < 2) { // Check if the command has a value
                            System.out.println("Error: Missing value for push"); // Print an error message if not
                            continue; // Continue to the next iteration
                        }
                        int value = Integer.parseInt(parts[1]); // Parse the value to an integer
                        stack.push(value); // Add the value to the stack
                        System.out.println("Pushed: " + value); // Print a message confirming the push
                        break;
                    case "pop":
                        System.out.println("Popped: " + stack.pop()); // Print the popped item and pop it from the stack
                        break;
                    case "peek":
                        System.out.println("Top: " + stack.peek()); // Print the top item of the stack
                        break;
                    case "size":
                        System.out.println("Size: " + stack.size()); // Print the size of the stack
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + stack.isEmpty()); // Print whether the stack is empty or not
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]); // Print an error message for unknown commands
                }
            } catch (Exception e) { // Catch any exceptions thrown
                System.out.println("Error: " + e.getMessage()); // Print the error message
            }
        }

        scanner.close(); // Close the Scanner object
    }
}