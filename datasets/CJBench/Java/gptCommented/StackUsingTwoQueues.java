import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    // Declare two queues to simulate stack behavior
    private Queue<Integer> mainQueue;
    private Queue<Integer> tempQueue;

    // Constructor to initialize the queues
    public Main() {
        mainQueue = new LinkedList<>();
        tempQueue = new LinkedList<>();
    }

    // Method to push an item onto the stack
    public void push(int item) {
        // Add the new item to the temporary queue
        tempQueue.add(item);
        
        // Move all elements from the main queue to the temporary queue
        while (!mainQueue.isEmpty()) {
            tempQueue.add(mainQueue.remove());
        }
        
        // Swap the references of the main queue and the temporary queue
        Queue<Integer> swap = mainQueue;
        mainQueue = tempQueue;
        tempQueue = swap;
    }

    // Method to pop an item from the stack
    public int pop() {
        // Check if the main queue is empty and throw an exception if it is
        if (mainQueue.isEmpty()) {
            throw new NoSuchElementException("Stack is empty");
        }
        // Remove and return the top item from the main queue
        return mainQueue.remove();
    }

    // Method to peek at the top item of the stack without removing it
    public Integer peek() {
        // If the main queue is empty, return null
        if (mainQueue.isEmpty()) {
            return null;
        }
        // Return the top item of the main queue
        return mainQueue.peek();
    }

    // Method to check if the stack is empty
    public boolean isEmpty() {
        // Return true if the main queue is empty, false otherwise
        return mainQueue.isEmpty();
    }

    // Method to get the size of the stack
    public int size() {
        // Return the size of the main queue
        return mainQueue.size();
    }

    // Main method to run the program
    public static void main(String[] args) {
        // Create an instance of the Main class (stack)
        Main stack = new Main();
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of operations to perform
        int n = scanner.nextInt(); 
        
        // Loop through the number of operations
        for (int i = 0; i < n; i++) {
            // Read the operation type
            String operation = scanner.next();
            switch (operation) {
                case "push":
                    // Read the value to push onto the stack
                    int value = scanner.nextInt();
                    stack.push(value);
                    System.out.println("Pushed: " + value);
                    break;
                case "pop":
                    // Attempt to pop an item from the stack and handle exceptions
                    try {
                        System.out.println("Popped: " + stack.pop());
                    } catch (NoSuchElementException e) {
                        System.out.println("Error: " + e.getMessage());
                    }
                    break;
                case "peek":
                    // Peek at the top item of the stack
                    Integer top = stack.peek();
                    if (top != null) {
                        System.out.println("Top element: " + top);
                    } else {
                        System.out.println("Stack is empty");
                    }
                    break;
                case "isEmpty":
                    // Check if the stack is empty
                    System.out.println("Is stack empty? " + stack.isEmpty());
                    break;
                case "size":
                    // Get the size of the stack
                    System.out.println("Stack size: " + stack.size());
                    break;
                default:
                    // Handle invalid operations
                    System.out.println("Invalid operation");
                    break;
            }
        }
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
