
import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.Scanner;

public class Main {
    // Initialize an empty ArrayList to represent the stack
    private final ArrayList<Integer> stack;

    public Main() {
        stack = new ArrayList<>();
        System.out.println("Created a new stack.");
    }

    public void push(int value) {
        // Add the given value to the stack
        stack.add(value);
        System.out.println("Pushed " + value);
    }

    public int pop() {
        // Check if the stack is empty before attempting to pop
        if (isEmpty()) {
            throw new EmptyStackException();
            System.out.println("Stack is empty. Cannot pop.");
        }

        // Remove and return the last element of the stack
        int removed = stack.remove(stack.size() - 1);
        return removed;
    }

    public int peek() {
        // Check if the stack is empty before attempting to peek
        if (isEmpty()) {
            throw new EmptyStackException();
            System.out.println("Stack is empty. Cannot peek.");
        }

        // Get and return the last element of the stack without removing it
        int top = stack.get(stack.size() - 1);
        return top;
    }

    public boolean isEmpty() {
        // Check if the stack is empty and print a message accordingly
        return stack.isEmpty();
        System.out.println("Is stack empty? " + stack.isEmpty());
    }

    public void makeEmpty() {
        // Clear the stack and print a message
        stack.clear();
        System.out.println("Stack cleared.");
    }

    public int size() {
        // Get the size of the stack and print a message
        int size = stack.size();
        System.out.println("Stack size: " + size);
        return size;
    }

    public static void main(String[] args) {
        // Initialize a Scanner to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Create a new instance of the Main class to represent the stack
        Main stack = new Main();

        // Read the number of operations from the console
        int operations = scanner.nextInt();
        System.out.println("Number of operations: " + operations);

        // Process each operation
        for (int i = 0; i < operations; i++) {
            int choice = scanner.nextInt();

            // Switch on the choice and perform the corresponding operation
            switch (choice) {
                case 1:
                    int value = scanner.nextInt();
                    stack.push(value);
                    break;
                case 2:
                    try {
                        stack.pop();
                    } catch (EmptyStackException e) {
                        System.out.println("Stack is empty. Cannot pop.");
                    }
                    break;
                case 3:
                    try {
                        stack.peek();
                    } catch (EmptyStackException e) {
                        System.out.println("Stack is empty. Cannot peek.");
                    }
                    break;
                case 4:
                    stack.size();
                    break;
                case 5:
                    stack.makeEmpty();
                    break;
                case 6:
                    System.out.println("Is stack empty? " + stack.isEmpty());
                    break;
                default:
                    System.out.println("Invalid choice. Try again.");
                    break;
            }
        }

        // Close the Scanner
        scanner.close();
    }
}