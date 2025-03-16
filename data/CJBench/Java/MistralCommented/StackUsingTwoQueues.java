
import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    // Initialize two queues, mainQueue and tempQueue
    private Queue<Integer> mainQueue;
    private Queue<Integer> tempQueue;
    
    public Main() {
        mainQueue = new LinkedList<>();
        tempQueue = new LinkedList<>();
        // Constructor initializes the mainQueue and tempQueue
    }
    
    public void push(int item) {
        // Add the new item to the tempQueue
        tempQueue.add(item);
        
        // Swap the queues
        Queue<Integer> swap = mainQueue;
        mainQueue = tempQueue;
        tempQueue = swap;
        
        // Update the comments accordingly
        // Swap the mainQueue and tempQueue
    }
    
    public int pop() {
        // Check if the mainQueue is empty
        if (mainQueue.isEmpty()) {
            throw new NoSuchElementException("Stack is empty");
        }
        
        // Remove and return the head of the mainQueue
        return mainQueue.remove();
    }
    
    public Integer peek() {
        // Check if the mainQueue is empty
        if (mainQueue.isEmpty()) {
            return null;
        }
        
        // Return the head of the mainQueue without removing it
        return mainQueue.peek();
    }
    
    public boolean isEmpty() {
        // Check if the mainQueue is empty
        return mainQueue.isEmpty();
    }
    
    public int size() {
        // Return the size of the mainQueue
        return mainQueue.size();
    }
    
    public static void main(String[] args) {
        // Create an instance of the Main class
        Main stack = new Main();
        
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of operations from the user
        int n = scanner.nextInt();
        
        // Process each operation
        for (int i = 0; i < n; i++) {
            String operation = scanner.next();
            
            switch (operation) {
                case "push":
                    // Read the value to be pushed from the user
                    int value = scanner.nextInt();
                    
                    // Call the push method with the value
                    stack.push(value);
                    
                    // Print the message to the user
                    System.out.println("Pushed: " + value);
                    break;
                case "pop":
                    try {
                        // Call the pop method and print the popped value to the user
                        System.out.println("Popped: " + stack.pop());
                    } catch (NoSuchElementException e) {
                        // Print the error message to the user
                        System.out.println("Error: " + e.getMessage());
                    }
                    break;
                case "peek":
                    // Call the peek method and print the top element to the user
                    Integer top = stack.peek();
                    if (top != null) {
                        System.out.println("Top element: " + top);
                    } else {
                        // Print the message if the stack is empty
                        System.out.println("Stack is empty");
                    }
                    break;
                case "isEmpty":
                    // Print the result of the isEmpty method to the user
                    System.out.println("Is stack empty? " + stack.isEmpty());
                    break;
                case "size":
                    // Print the result of the size method to the user
                    System.out.println("Stack size: " + stack.size());
                    break;
                default:
                    // Print the message for invalid operations
                    System.out.println("Invalid operation");
                    break;
            }
        }
        
        // Close the scanner
        scanner.close();
    }
}