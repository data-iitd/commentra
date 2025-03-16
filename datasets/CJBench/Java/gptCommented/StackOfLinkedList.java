import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new instance of LinkedListStack to use for stack operations
        LinkedListStack stack = new LinkedListStack();
        
        // Initialize a Scanner to read user input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of operations to perform on the stack
        int operations = scanner.nextInt();
        
        // Loop through the number of operations specified by the user
        for (int i = 0; i < operations; i++) {
            // Read the user's choice of operation
            int choice = scanner.nextInt();
            switch (choice) {
                case 1: 
                    // Push a new value onto the stack
                    int value = scanner.nextInt();
                    stack.push(value);
                    System.out.println("Pushed " + value);
                    break;
                case 2: 
                    // Pop the top value from the stack and handle potential exceptions
                    try {
                        int popped = stack.pop();
                        System.out.println("Popped " + popped);
                    } catch (NoSuchElementException e) {
                        // Print error message if the stack is empty
                        System.out.println(e.getMessage());
                    }
                    break;
                case 3: 
                    // Peek at the top value of the stack without removing it
                    try {
                        int peeked = stack.peek();
                        System.out.println("Top element: " + peeked);
                    } catch (NoSuchElementException e) {
                        // Print error message if the stack is empty
                        System.out.println(e.getMessage());
                    }
                    break;
                case 4: 
                    // Get and print the current size of the stack
                    System.out.println("Stack size: " + stack.getSize());
                    break;
                case 5: 
                    // Check if the stack is empty and print the result
                    System.out.println("Is stack empty? " + stack.isEmpty());
                    break;
                case 6: 
                    // Clear the stack of all elements
                    stack.makeEmpty();
                    System.out.println("Stack cleared.");
                    break;
                default:
                    // Handle invalid choices
                    System.out.println("Invalid choice.");
            }
        }
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}

class LinkedListStack {
    private Node head; // Head of the linked list representing the stack
    private int size;  // Current size of the stack
    
    // Constructor to initialize an empty stack
    LinkedListStack() {
        head = null;
        size = 0;
    }
    
    // Method to push a new value onto the stack
    public void push(int x) {
        Node newNode = new Node(x); // Create a new node with the given value
        newNode.next = head;        // Point the new node to the current head
        head = newNode;             // Update the head to the new node
        size++;                     // Increment the size of the stack
    }
    
    // Method to pop the top value from the stack
    public int pop() {
        // Check if the stack is empty and throw an exception if it is
        if (size == 0) {
            throw new NoSuchElementException("Empty stack. Nothing to pop");
        }
        int value = head.data; // Get the value of the top node
        head = head.next;      // Update the head to the next node
        size--;                // Decrement the size of the stack
        return value;         // Return the popped value
    }
    
    // Method to peek at the top value of the stack
    public int peek() {
        // Check if the stack is empty and throw an exception if it is
        if (size == 0) {
            throw new NoSuchElementException("Empty stack. Nothing to peek");
        }
        return head.data; // Return the value of the top node without removing it
    }
    
    // Method to check if the stack is empty
    public boolean isEmpty() {
        return size == 0; // Return true if size is 0, otherwise false
    }
    
    // Method to get the current size of the stack
    public int getSize() {
        return size; // Return the current size of the stack
    }
    
    // Method to clear the stack
    public void makeEmpty() {
        head = null; // Set head to null to remove all nodes
        size = 0;    // Reset size to 0
    }
    
    // Private static class representing a node in the linked list
    private static class Node {
        int data; // Data stored in the node
        Node next; // Reference to the next node in the stack
        
        // Constructor to create a new node with given data
        Node(int data) {
            this.data = data;
            this.next = null; // Initialize next to null
        }
    }
}
