import java.util.NoSuchElementException;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        // Initialize a stack and a scanner for user input
        LinkedListStack stack = new LinkedListStack();
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of operations
        int operations = scanner.nextInt();
        
        // Loop through each operation
        for (int i = 0; i < operations; i++) {
            int choice = scanner.nextInt();
            switch (choice) {
                case 1: 
                    // Push a value onto the stack
                    int value = scanner.nextInt();
                    stack.push(value);
                    System.out.println("Pushed " + value);
                    break;
                case 2: 
                    // Pop a value from the stack
                    try {
                        int popped = stack.pop();
                        System.out.println("Popped " + popped);
                    } catch (NoSuchElementException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 3: 
                    // Peek at the top value of the stack
                    try {
                        int peeked = stack.peek();
                        System.out.println("Top element: " + peeked);
                    } catch (NoSuchElementException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 4: 
                    // Get the size of the stack
                    System.out.println("Stack size: " + stack.getSize());
                    break;
                case 5: 
                    // Check if the stack is empty
                    System.out.println("Is stack empty? " + stack.isEmpty());
                    break;
                case 6: 
                    // Clear the stack
                    stack.makeEmpty();
                    System.out.println("Stack cleared.");
                    break;
                default:
                    // Handle invalid choice
                    System.out.println("Invalid choice.");
            }
        }
        scanner.close();
    }
}
class LinkedListStack {
    private Node head; 
    private int size; 
    LinkedListStack() {
        head = null;
        size = 0;
    }
    public void push(int x) {
        // Create a new node with the given value
        Node newNode = new Node(x);
        // Set the new node's next reference to the current head
        newNode.next = head;
        // Update the head to be the new node
        head = newNode;
        // Increment the size of the stack
        size++;
    }
    public int pop() {
        // Check if the stack is empty and throw an exception if it is
        if (size == 0) {
            throw new NoSuchElementException("Empty stack. Nothing to pop");
        }
        // Store the value of the head node
        int value = head.data;
        // Update the head to be the next node in the stack
        head = head.next;
        // Decrement the size of the stack
        size--;
        // Return the stored value
        return value;
    }
    public int peek() {
        // Check if the stack is empty and throw an exception if it is
        if (size == 0) {
            throw new NoSuchElementException("Empty stack. Nothing to peek");
        }
        // Return the value of the head node
        return head.data;
    }
    public boolean isEmpty() {
        // Return true if the stack is empty, false otherwise
        return size == 0;
    }
    public int getSize() {
        // Return the size of the stack
        return size;
    }
    public void makeEmpty() {
        // Set the head to null and the size to 0 to clear the stack
        head = null;
        size = 0;
    }
    private static class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
}
