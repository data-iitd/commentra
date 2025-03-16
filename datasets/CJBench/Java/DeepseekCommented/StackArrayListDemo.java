import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.Scanner;
public class Main {
    private final ArrayList<Integer> stack; // Initialize the stack as an ArrayList

    // Constructor to initialize the stack
    public Main() {
        stack = new ArrayList<>();
    }

    // Method to push a value onto the stack
    public void push(int value) {
        stack.add(value); // Add the value to the stack
        System.out.println("Pushed " + value); // Print the value that was pushed
    }

    // Method to pop a value from the stack
    public int pop() {
        if (isEmpty()) { // Check if the stack is empty
            throw new EmptyStackException(); // Throw an exception if the stack is empty
        }
        int removed = stack.remove(stack.size() - 1); // Remove and return the top element
        System.out.println("Popped " + removed); // Print the value that was popped
        return removed;
    }

    // Method to peek at the top element of the stack
    public int peek() {
        if (isEmpty()) { // Check if the stack is empty
            throw new EmptyStackException(); // Throw an exception if the stack is empty
        }
        int top = stack.get(stack.size() - 1); // Get the top element
        System.out.println("Top element: " + top); // Print the top element
        return top;
    }

    // Method to check if the stack is empty
    public boolean isEmpty() {
        return stack.isEmpty(); // Return true if the stack is empty, otherwise false
    }

    // Method to clear the stack
    public void makeEmpty() {
        stack.clear(); // Clear the stack
        System.out.println("Stack cleared."); // Print a message indicating the stack has been cleared
    }

    // Method to get the size of the stack
    public int size() {
        int size = stack.size(); // Get the size of the stack
        System.out.println("Stack size: " + size); // Print the size of the stack
        return size;
    }

    // Main method to run the stack operations based on user input
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a scanner to read user input
        Main stack = new Main(); // Create an instance of the Main class
        int operations = scanner.nextInt(); // Read the number of operations
        for (int i = 0; i < operations; i++) {
            int choice = scanner.nextInt(); // Read the choice of operation
            switch (choice) {
                case 1:
                    int value = scanner.nextInt(); // Read the value to be pushed
                    stack.push(value); // Push the value onto the stack
                    break;
                case 2:
                    try {
                        stack.pop(); // Attempt to pop a value from the stack
                    } catch (EmptyStackException e) {
                        System.out.println("Stack is empty. Cannot pop."); // Print a message if the stack is empty
                    }
                    break;
                case 3:
                    try {
                        stack.peek(); // Attempt to peek at the top element of the stack
                    } catch (EmptyStackException e) {
                        System.out.println("Stack is empty. Cannot peek."); // Print a message if the stack is empty
                    }
                    break;
                case 4:
                    stack.size(); // Get the size of the stack
                    break;
                case 5:
                    stack.makeEmpty(); // Clear the stack
                    break;
                case 6:
                    System.out.println("Is stack empty? " + stack.isEmpty()); // Check if the stack is empty and print the result
                    break;
                default:
                    System.out.println("Invalid choice. Try again."); // Print a message for an invalid choice
                    break;
            }
        }
        scanner.close(); // Close the scanner
    }
}
