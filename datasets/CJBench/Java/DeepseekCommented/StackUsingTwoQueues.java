
import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    private Queue<Integer> mainQueue; // Queue to hold the main stack elements
    private Queue<Integer> tempQueue; // Temporary queue used during push operation

    // Constructor to initialize the main and temporary queues
    public Main() {
        mainQueue = new LinkedList<>();
        tempQueue = new LinkedList<>();
    }

    // Method to add an item to the stack
    public void push(int item) {
        // Add the item to the tempQueue
        tempQueue.add(item);
        // Transfer all items from mainQueue to tempQueue
        while (!mainQueue.isEmpty()) {
            tempQueue.add(mainQueue.remove());
        }
        // Swap mainQueue and tempQueue to maintain the correct order
        Queue<Integer> swap = mainQueue;
        mainQueue = tempQueue;
        tempQueue = swap;
    }

    // Method to remove and return the top element of the stack
    public int pop() {
        if (mainQueue.isEmpty()) {
            throw new NoSuchElementException("Stack is empty");
        }
        return mainQueue.remove();
    }

    // Method to return the top element of the stack without removing it
    public Integer peek() {
        if (mainQueue.isEmpty()) {
            return null;
        }
        return mainQueue.peek();
    }

    // Method to check if the stack is empty
    public boolean isEmpty() {
        return mainQueue.isEmpty();
    }

    // Method to return the size of the stack
    public int size() {
        return mainQueue.size();
    }

    // Main method to provide a command-line interface for interacting with the stack
    public static void main(String[] args) {
        Main stack = new Main();
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of operations
        for (int i = 0; i < n; i++) {
            String operation = scanner.next(); // Read the operation type
            switch (operation) {
                case "push":
                    int value = scanner.nextInt(); // Read the value to push
                    stack.push(value);
                    System.out.println("Pushed: " + value); // Print the pushed value
                    break;
                case "pop":
                    try {
                        System.out.println("Popped: " + stack.pop()); // Print the popped value
                    } catch (NoSuchElementException e) {
                        System.out.println("Error: " + e.getMessage()); // Print the error message
                    }
                    break;
                case "peek":
                    Integer top = stack.peek(); // Get the top element
                    if (top != null) {
                        System.out.println("Top element: " + top); // Print the top element
                    } else {
                        System.out.println("Stack is empty"); // Print stack empty message
                    }
                    break;
                case "isEmpty":
                    System.out.println("Is stack empty? " + stack.isEmpty()); // Print if stack is empty
                    break;
                case "size":
                    System.out.println("Stack size: " + stack.size()); // Print the stack size
                    break;
                default:
                    System.out.println("Invalid operation"); // Print invalid operation message
                    break;
            }
        }
        scanner.close(); // Close the scanner
    }
}

This code now includes comments that explain each logical block, making it easier to understand the functionality of the `Main` class.