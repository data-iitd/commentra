
import java.util.Scanner;
import java.util.Stack;

public class Main {
    // Initialize two stacks for input and output elements
    private final Stack<Object> inStack;
    private final Stack<Object> outStack;

    public Main() {
        this.inStack = new Stack<>();
        this.outStack = new Stack<>();
        // Initialize the constructor
    }

    public void insert(Object x) {
        // Push the given object into the input stack
        this.inStack.push(x);
    }

    public Object remove() {
        // If the output stack is empty, transfer all elements from input stack to output stack
        if (this.outStack.isEmpty()) {
            while (!this.inStack.isEmpty()) {
                this.outStack.push(this.inStack.pop());
            }
        }
        // If there is an element in the output stack, pop it and return it
        if (!this.outStack.isEmpty()) {
            return this.outStack.pop();
        }
        // If the queue is empty, return a message
        return "Queue is empty";
    }

    public Object peekFront() {
        // If the output stack is empty, transfer all elements from input stack to output stack
        if (this.outStack.isEmpty()) {
            while (!this.inStack.isEmpty()) {
                this.outStack.push(this.inStack.pop());
            }
        }
        // If there is an element in the output stack, return a reference to it without popping it
        if (!this.outStack.isEmpty()) {
            return this.outStack.peek();
        }
        // If the queue is empty, return a message
        return "Queue is empty";
    }

    public Object peekBack() {
        // If the input stack is not empty, return a reference to the top element
        if (!this.inStack.isEmpty()) {
            return this.inStack.peek();
        }
        // If the queue is empty, return a message
        return "Queue is empty";
    }

    public boolean isEmpty() {
        // Return true if both input and output stacks are empty
        return (this.inStack.isEmpty() && this.outStack.isEmpty());
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main queue = new Main(); // Create an instance of the Main class
        int operations = scanner.nextInt(); // Read the number of operations from the standard input
        scanner.nextLine(); // Consume the newline character

        for (int i = 0; i < operations; i++) {
            String[] command = scanner.nextLine().split(" "); // Read a line from the standard input and split it into words
            String cmd = command[0]; // Get the command name

            switch (cmd) { // Based on the command name, execute the corresponding method
                case "INSERT":
                    queue.insert(Integer.parseInt(command[1]));
                    break;
                case "REMOVE":
                    System.out.println(queue.remove());
                    break;
                case "PEEK_FRONT":
                    System.out.println(queue.peekFront());
                    break;
                case "PEEK_BACK":
                    System.out.println(queue.peekBack());
                    break;
                case "IS_EMPTY":
                    System.out.println(queue.isEmpty());
                    break;
                default:
                    System.out.println("Invalid command");
            }
        }

        scanner.close(); // Close the scanner
    }
}