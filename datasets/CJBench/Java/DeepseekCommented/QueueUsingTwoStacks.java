import java.util.Scanner;
import java.util.Stack;
public class Main {
    private final Stack<Object> inStack; // Initialize the stack for incoming elements
    private final Stack<Object> outStack; // Initialize the stack for outgoing elements
    
    // Constructor to initialize the stacks
    public Main() {
        this.inStack = new Stack<>();
        this.outStack = new Stack<>();
    }
    
    // Method to insert an element into the queue
    public void insert(Object x) {
        this.inStack.push(x); // Add the element to the inStack
    }
    
    // Method to remove an element from the queue
    public Object remove() {
        if (this.outStack.isEmpty()) { // If outStack is empty, transfer elements from inStack
            while (!this.inStack.isEmpty()) {
                this.outStack.push(this.inStack.pop());
            }
        }
        if (!this.outStack.isEmpty()) { // If outStack is not empty, remove and return the top element
            return this.outStack.pop();
        }
        return "Queue is empty"; // Return a message if the queue is empty
    }
    
    // Method to peek the front element of the queue
    public Object peekFront() {
        if (this.outStack.isEmpty()) { // If outStack is empty, transfer elements from inStack
            while (!this.inStack.isEmpty()) {
                this.outStack.push(this.inStack.pop());
            }
        }
        if (!this.outStack.isEmpty()) { // If outStack is not empty, return the top element without removing it
            return this.outStack.peek();
        }
        return "Queue is empty"; // Return a message if the queue is empty
    }
    
    // Method to peek the back element of the queue
    public Object peekBack() {
        if (!this.inStack.isEmpty()) { // If inStack is not empty, return the top element
            return this.inStack.peek();
        }
        return "Queue is empty"; // Return a message if the queue is empty
    }
    
    // Method to check if the queue is empty
    public boolean isEmpty() {
        return (this.inStack.isEmpty() && this.outStack.isEmpty()); // Return true if both stacks are empty
    }
    
    // Main method to handle user input for queue operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main queue = new Main();
        int operations = scanner.nextInt(); // Read the number of operations
        scanner.nextLine();
        for (int i = 0; i < operations; i++) {
            String[] command = scanner.nextLine().split(" "); // Read each command
            switch (command[0]) {
                case "INSERT":
                    queue.insert(Integer.parseInt(command[1])); // Insert an integer
                    break;
                case "REMOVE":
                    System.out.println(queue.remove()); // Remove and print the element
                    break;
                case "PEEK_FRONT":
                    System.out.println(queue.peekFront()); // Peek and print the front element
                    break;
                case "PEEK_BACK":
                    System.out.println(queue.peekBack()); // Peek and print the back element
                    break;
                case "IS_EMPTY":
                    System.out.println(queue.isEmpty()); // Check if the queue is empty and print the result
                    break;
                default:
                    System.out.println("Invalid command"); // Print an error message for invalid commands
            }
        }
        scanner.close(); // Close the scanner
    }
}
