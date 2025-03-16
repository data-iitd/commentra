import java.util.Scanner;
import java.util.Stack;

public class Main {
    // Declare two stacks to simulate queue behavior
    private final Stack<Object> inStack;  // Stack for incoming elements
    private final Stack<Object> outStack; // Stack for outgoing elements

    // Constructor to initialize the stacks
    public Main() {
        this.inStack = new Stack<>();
        this.outStack = new Stack<>();
    }

    // Method to insert an element into the queue
    public void insert(Object x) {
        this.inStack.push(x); // Push the element onto the inStack
    }

    // Method to remove and return the front element of the queue
    public Object remove() {
        // If outStack is empty, transfer elements from inStack to outStack
        if (this.outStack.isEmpty()) {
            while (!this.inStack.isEmpty()) {
                this.outStack.push(this.inStack.pop());
            }
        }
        // If outStack is not empty, pop and return the top element
        if (!this.outStack.isEmpty()) {
            return this.outStack.pop();
        }
        return "Queue is empty"; // Return message if queue is empty
    }

    // Method to peek at the front element of the queue without removing it
    public Object peekFront() {
        // If outStack is empty, transfer elements from inStack to outStack
        if (this.outStack.isEmpty()) {
            while (!this.inStack.isEmpty()) {
                this.outStack.push(this.inStack.pop());
            }
        }
        // If outStack is not empty, return the top element without removing it
        if (!this.outStack.isEmpty()) {
            return this.outStack.peek();
        }
        return "Queue is empty"; // Return message if queue is empty
    }

    // Method to peek at the back element of the queue without removing it
    public Object peekBack() {
        // Return the top element of inStack if it is not empty
        if (!this.inStack.isEmpty()) {
            return this.inStack.peek();
        }
        return "Queue is empty"; // Return message if queue is empty
    }

    // Method to check if the queue is empty
    public boolean isEmpty() {
        return (this.inStack.isEmpty() && this.outStack.isEmpty()); // Return true if both stacks are empty
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        Main queue = new Main(); // Create an instance of the queue
        int operations = scanner.nextInt(); // Read the number of operations to perform
        scanner.nextLine(); // Consume the newline character

        // Loop through the number of operations
        for (int i = 0; i < operations; i++) {
            String[] command = scanner.nextLine().split(" "); // Read and split the command input
            switch (command[0]) {
                case "INSERT":
                    queue.insert(Integer.parseInt(command[1])); // Insert the specified element
                    break;
                case "REMOVE":
                    System.out.println(queue.remove()); // Remove and print the front element
                    break;
                case "PEEK_FRONT":
                    System.out.println(queue.peekFront()); // Print the front element without removing it
                    break;
                case "PEEK_BACK":
                    System.out.println(queue.peekBack()); // Print the back element without removing it
                    break;
                case "IS_EMPTY":
                    System.out.println(queue.isEmpty()); // Print whether the queue is empty
                    break;
                default:
                    System.out.println("Invalid command"); // Handle invalid commands
            }
        }
        scanner.close(); // Close the scanner to free resources
    }
}
