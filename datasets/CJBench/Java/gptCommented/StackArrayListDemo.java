import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.Scanner;

public class Main {
    // Declare an ArrayList to represent the stack
    private final ArrayList<Integer> stack;

    // Constructor to initialize the stack
    public Main() {
        stack = new ArrayList<>();
    }

    // Method to push a value onto the stack
    public void push(int value) {
        stack.add(value); // Add the value to the end of the list
        System.out.println("Pushed " + value); // Print confirmation of the push operation
    }

    // Method to pop a value from the stack
    public int pop() {
        // Check if the stack is empty before popping
        if (isEmpty()) {
            throw new EmptyStackException(); // Throw exception if stack is empty
        }
        int removed = stack.remove(stack.size() - 1); // Remove the last element
        System.out.println("Popped " + removed); // Print confirmation of the pop operation
        return removed; // Return the removed value
    }

    // Method to peek at the top value of the stack without removing it
    public int peek() {
        // Check if the stack is empty before peeking
        if (isEmpty()) {
            throw new EmptyStackException(); // Throw exception if stack is empty
        }
        int top = stack.get(stack.size() - 1); // Get the last element
        System.out.println("Top element: " + top); // Print the top element
        return top; // Return the top element
    }

    // Method to check if the stack is empty
    public boolean isEmpty() {
        return stack.isEmpty(); // Return true if the stack is empty
    }

    // Method to clear the stack
    public void makeEmpty() {
        stack.clear(); // Clear all elements from the stack
        System.out.println("Stack cleared."); // Print confirmation of the clear operation
    }

    // Method to get the current size of the stack
    public int size() {
        int size = stack.size(); // Get the size of the stack
        System.out.println("Stack size: " + size); // Print the size of the stack
        return size; // Return the size
    }

    // Main method to execute the stack operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        Main stack = new Main(); // Create an instance of the stack
        int operations = scanner.nextInt(); // Read the number of operations to perform

        // Loop through the number of operations
        for (int i = 0; i < operations; i++) {
            int choice = scanner.nextInt(); // Read the user's choice of operation
            switch (choice) {
                case 1: // Push operation
                    int value = scanner.nextInt(); // Read the value to push
                    stack.push(value); // Call the push method
                    break;
                case 2: // Pop operation
                    try {
                        stack.pop(); // Attempt to pop the top value
                    } catch (EmptyStackException e) {
                        System.out.println("Stack is empty. Cannot pop."); // Handle empty stack case
                    }
                    break;
                case 3: // Peek operation
                    try {
                        stack.peek(); // Attempt to peek at the top value
                    } catch (EmptyStackException e) {
                        System.out.println("Stack is empty. Cannot peek."); // Handle empty stack case
                    }
                    break;
                case 4: // Size operation
                    stack.size(); // Call the size method
                    break;
                case 5: // Clear operation
                    stack.makeEmpty(); // Call the makeEmpty method
                    break;
                case 6: // Check if the stack is empty
                    System.out.println("Is stack empty? " + stack.isEmpty()); // Print whether the stack is empty
                    break;
                default: // Handle invalid choices
                    System.out.println("Invalid choice. Try again."); // Print error message for invalid choice
                    break;
            }
        }
        scanner.close(); // Close the scanner to free resources
    }
}
