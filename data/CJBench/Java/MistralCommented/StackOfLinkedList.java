
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize an empty stack using LinkedListStack
        LinkedListStack stack = new LinkedListStack();

        // Initialize a Scanner to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read the number of operations from the user
        int operations = scanner.nextInt();

        // Perform each operation
        for (int i = 0; i < operations; i++) {
            int choice = scanner.nextInt();

            // Switch on the user's choice and perform the corresponding operation
            switch (choice) {
                case 1: 
                    // Read an integer value from the user and push it onto the stack
                    int value = scanner.nextInt();
                    stack.push(value);
                    System.out.println("Pushed " + value);
                    break;
                case 2: 
                    try {
                        // Pop an integer value from the stack and print it
                        int popped = stack.pop();
                        System.out.println("Popped " + popped);
                    } catch (NoSuchElementException e) {
                        // If the stack is empty, print an error message
                        System.out.println(e.getMessage());
                    }
                    break;
                case 3: 
                    try {
                        // Peek at the top element of the stack and print it
                        int peeked = stack.peek();
                        System.out.println("Top element: " + peeked);
                    } catch (NoSuchElementException e) {
                        // If the stack is empty, print an error message
                        System.out.println(e.getMessage());
                    }
                    break;
                case 4: 
                    // Print the size of the stack
                    System.out.println("Stack size: " + stack.getSize());
                    break;
                case 5: 
                    // Print whether the stack is empty or not
                    System.out.println("Is stack empty? " + stack.isEmpty());
                    break;
                case 6: 
                    // Clear the stack
                    stack.makeEmpty();
                    System.out.println("Stack cleared.");
                    break;
                default:
                    // If the user's choice is invalid, print an error message
                    System.out.println("Invalid choice.");
            }
        }

        // Close the Scanner
        scanner.close();
    }
}

class LinkedListStack {
    // Initialize the head node and size of the stack to null and 0, respectively
    private Node head; 
    private int size; 

    // Constructor for an empty stack
    LinkedListStack() {
        head = null;
        size = 0;
    }

    // Add an integer value to the top of the stack
    public void push(int x) {
        Node newNode = new Node(x);

        // Connect the new node to the top of the stack
        newNode.next = head;
        head = newNode;

        // Increment the size of the stack
        size++;
    }

    // Remove and return the top element of the stack
    public int pop() {
        if (size == 0) {
            // If the stack is empty, throw an exception
            throw new NoSuchElementException("Empty stack. Nothing to pop");
        }

        // Store the top element in a variable and remove it from the stack
        int value = head.data;
        head = head.next;

        // Decrement the size of the stack
        size--;

        // Return the popped value
        return value;
    }

    // Return the top element of the stack without removing it
    public int peek() {
        if (size == 0) {
            // If the stack is empty, throw an exception
            throw new NoSuchElementException("Empty stack. Nothing to peek");
        }

        // Return the data of the top node
        return head.data;
    }

    // Check if the stack is empty or not
    public boolean isEmpty() {
        // Return true if the size of the stack is 0, else false
        return size == 0;
    }

    // Return the size of the stack
    public int getSize() {
        // Return the size of the stack
        return size;
    }

    // Clear the stack
    public void makeEmpty() {
        head = null;
        size = 0;
    }

    // Inner class for a node in the stack
    private static class Node {
        int data;
        Node next;

        // Constructor for a node with a given integer value
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
}