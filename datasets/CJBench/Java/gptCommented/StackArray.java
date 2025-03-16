import java.util.Scanner;

public class Main {
    // Default capacity for the stack
    private static final int DEFAULT_CAPACITY = 10;
    private int maxSize; // Maximum size of the stack
    private T[] stackArray; // Array to hold stack elements
    private int top; // Index of the top element in the stack

    // Default constructor initializing stack with default capacity
    @SuppressWarnings("unchecked")
    public Main() {
        this(DEFAULT_CAPACITY);
    }

    // Constructor to initialize stack with a specified size
    @SuppressWarnings("unchecked")
    public Main(int size) {
        // Validate the size to ensure it's greater than 0
        if (size <= 0) {
            throw new IllegalArgumentException("Stack size must be greater than 0");
        }
        this.maxSize = size; // Set the maximum size
        this.stackArray = (T[]) new Object[size]; // Initialize the stack array
        this.top = -1; // Initialize top index
    }

    // Method to add an element to the top of the stack
    public void push(T value) {
        // Resize the stack if it is full
        if (isFull()) {
            resize(maxSize * 2);
        }
        stackArray[++top] = value; // Add the new value and increment top
    }

    // Method to remove and return the top element of the stack
    public T pop() {
        // Check if the stack is empty before popping
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty, cannot pop element");
        }
        T value = stackArray[top--]; // Retrieve the top value and decrement top
        // Resize the stack if it is less than a quarter full
        if (top + 1 < maxSize / 4 && maxSize > DEFAULT_CAPACITY) {
            resize(maxSize / 2);
        }
        return value; // Return the popped value
    }

    // Method to return the top element without removing it
    public T peek() {
        // Check if the stack is empty before peeking
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty, cannot peek element");
        }
        return stackArray[top]; // Return the top value
    }

    // Method to resize the stack array to a new size
    private void resize(int newSize) {
        @SuppressWarnings("unchecked") T[] newArray = (T[]) new Object[newSize]; // Create a new array
        System.arraycopy(stackArray, 0, newArray, 0, top + 1); // Copy elements to the new array
        stackArray = newArray; // Update the stack array reference
        maxSize = newSize; // Update the maximum size
    }

    // Method to check if the stack is full
    public boolean isFull() {
        return top + 1 == maxSize; // Return true if top index is equal to max size
    }

    // Method to check if the stack is empty
    public boolean isEmpty() {
        return top == -1; // Return true if top index is -1
    }

    // Method to clear the stack
    public void makeEmpty() {
        top = -1; // Reset top index to -1
    }

    // Method to return the current size of the stack
    public int size() {
        return top + 1; // Return the number of elements in the stack
    }

    // Method to return a string representation of the stack
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Main [");
        // Append each element in the stack to the string builder
        for (int i = 0; i <= top; i++) {
            sb.append(stackArray[i]);
            if (i < top) {
                sb.append(", "); // Add a comma if not the last element
            }
        }
        sb.append("]");
        return sb.toString(); // Return the string representation
    }

    // Main method to run the stack operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        Main<Integer> stack = new Main<>(); // Create a new stack instance
        // Loop to process user commands
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read the command
            if (command.equalsIgnoreCase("exit")) {
                break; // Exit the loop if the command is "exit"
            }
            try {
                String[] parts = command.split(" "); // Split command into parts
                switch (parts[0]) {
                    case "push":
                        // Check for missing value in push command
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for push");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]); // Parse the value to push
                        stack.push(value); // Push the value onto the stack
                        System.out.println("Pushed: " + value); // Confirm the push
                        break;
                    case "pop":
                        System.out.println("Popped: " + stack.pop()); // Pop and display the top value
                        break;
                    case "peek":
                        System.out.println("Top: " + stack.peek()); // Display the top value without popping
                        break;
                    case "size":
                        System.out.println("Size: " + stack.size()); // Display the current size of the stack
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + stack.isEmpty()); // Check if the stack is empty
                        break;
                    default:
                        System.out.println("Error: Unknown command"); // Handle unknown commands
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage()); // Handle exceptions and display error messages
            }
        }
        scanner.close(); // Close the scanner resource
    }
}
