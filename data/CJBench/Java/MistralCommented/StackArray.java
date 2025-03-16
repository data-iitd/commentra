
import java.util.Scanner;

// Class definition for Main with generic type T
public class Main<T> {

    // Declare private constants and instance variables
    private static final int DEFAULT_CAPACITY = 10;
    private int maxSize;
    private T[] stackArray;
    private int top;

    // Constructor without arguments
    @SuppressWarnings("unchecked")
    public Main() {
        this(DEFAULT_CAPACITY);
    }

    // Constructor with given size
    @SuppressWarnings("unchecked")
    public Main(int size) {
        // Validate size argument
        if (size <= 0) {
            throw new IllegalArgumentException("Stack size must be greater than 0");
        }

        // Initialize instance variables
        this.maxSize = size;
        this.stackArray = (T[]) new Object[size];
        this.top = -1;
    }

    // Push method to add an element to the stack
    public void push(T value) {
        // Check if stack is full and resize if necessary
        if (isFull()) {
            resize(maxSize * 2);
        }

        // Increment top and add value to the stack
        stackArray[++top] = value;
    }

    // Pop method to remove and return the top element from the stack
    public T pop() {
        // Check if stack is empty and throw an exception if it is
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty, cannot pop element");
        }

        // Get the top element and decrement top
        T value = stackArray[top--];

        // Check if stack size is less than half of the maximum size and resize if necessary
        if (top + 1 < maxSize / 4 && maxSize > DEFAULT_CAPACITY) {
            resize(maxSize / 2);
        }

        // Return the popped value
        return value;
    }

    // Peek method to return the top element without removing it from the stack
    public T peek() {
        // Check if stack is empty and throw an exception if it is
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty, cannot peek element");
        }

        // Return the top element
        return stackArray[top];
    }

    // Resize method to increase the size of the stackArray
    private void resize(int newSize) {
        // Allocate a new array with the given size
        @SuppressWarnings("unchecked") T[] newArray = (T[]) new Object[newSize];

        // Copy the elements from the old array to the new array
        System.arraycopy(stackArray, 0, newArray, 0, top + 1);

        // Update the stackArray and maxSize
        stackArray = newArray;
        maxSize = newSize;
    }

    // Check if the stack is full
    private boolean isFull() {
        return top + 1 == maxSize;
    }

    // Check if the stack is empty
    private boolean isEmpty() {
        return top == -1;
    }

    // Make the stack empty
    public void makeEmpty() {
        top = -1;
    }

    // Get the size of the stack
    public int size() {
        return top + 1;
    }

    // Override toString method to print the stack elements
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Main [");

        // Iterate through the stack and append each element to the StringBuilder
        for (int i = 0; i <= top; i++) {
            sb.append(stackArray[i]);
            if (i < top) {
                sb.append(", ");
            }
        }

        sb.append("]");
        return sb.toString();
    }

    // Main method to test the stack implementation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main<Integer> stack = new Main<>(); // Create an instance of the Main class with Integer type

        // Read user input and process the commands
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.equalsIgnoreCase("exit")) {
                break;
            }
            try {
                String[] parts = command.split(" ");
                switch (parts[0]) {
                    case "push":
                        // Validate command arguments and push the value to the stack
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for push");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]);
                        stack.push(value);
                        System.out.println("Pushed: " + value);
                        break;
                    case "pop":
                        // Pop the top element from the stack and print it
                        System.out.println("Popped: " + stack.pop());
                        break;
                    case "peek":
                        // Print the top element of the stack
                        System.out.println("Top: " + stack.peek());
                        break;
                    case "size":
                        // Print the size of the stack
                        System.out.println("Size: " + stack.size());
                        break;
                    case "isEmpty":
                        // Print whether the stack is empty or not
                        System.out.println("Is empty: " + stack.isEmpty());
                        break;
                    default:
                        // Handle unknown commands
                }
            } catch (Exception e) {
                // Print error messages for exceptions
                System.out.println("Error: " + e.getMessage());
            }
        }

        // Close the scanner
        scanner.close();
    }
}