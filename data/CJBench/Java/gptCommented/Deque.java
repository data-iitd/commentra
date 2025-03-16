import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
    // Node class representing each element in the doubly linked list
    private static class MainNode<S> {
        S val; // Value of the node
        MainNode<S> next = null; // Pointer to the next node
        MainNode<S> prev = null; // Pointer to the previous node

        // Constructor to initialize the node with a value
        MainNode(S val) {
            this.val = val;
        }
    }

    // Head and tail pointers for the doubly linked list
    private MainNode<T> head = null;
    private MainNode<T> tail = null;
    private int size = 0; // Size of the deque

    // Method to add a value to the front of the deque
    public void addFirst(T val) {
        MainNode<T> newNode = new MainNode<>(val); // Create a new node
        if (isEmpty()) { // If the deque is empty
            head = newNode; // Set head and tail to the new node
            tail = newNode;
        } else { // If the deque is not empty
            newNode.next = head; // Link new node to the current head
            head.prev = newNode; // Link current head back to the new node
            head = newNode; // Update head to the new node
        }
        size++; // Increment the size of the deque
    }

    // Method to add a value to the end of the deque
    public void addLast(T val) {
        MainNode<T> newNode = new MainNode<>(val); // Create a new node
        if (tail == null) { // If the deque is empty
            head = newNode; // Set head and tail to the new node
            tail = newNode;
        } else { // If the deque is not empty
            newNode.prev = tail; // Link new node back to the current tail
            tail.next = newNode; // Link current tail to the new node
            tail = newNode; // Update tail to the new node
        }
        size++; // Increment the size of the deque
    }

    // Method to remove and return the value from the front of the deque
    public T pollFirst() {
        if (head == null) { // Check if the deque is empty
            throw new NoSuchElementException("Main is empty"); // Throw exception if empty
        }
        T oldHeadVal = head.val; // Store the value of the current head
        if (head == tail) { // If there's only one element
            head = null; // Set head and tail to null
            tail = null;
        } else { // If there are multiple elements
            head = head.next; // Move head to the next node
            head.prev = null; // Clear the previous pointer of the new head
        }
        size--; // Decrement the size of the deque
        return oldHeadVal; // Return the removed value
    }

    // Method to remove and return the value from the end of the deque
    public T pollLast() {
        if (tail == null) { // Check if the deque is empty
            throw new NoSuchElementException("Main is empty"); // Throw exception if empty
        }
        T oldTailVal = tail.val; // Store the value of the current tail
        if (head == tail) { // If there's only one element
            head = null; // Set head and tail to null
            tail = null;
        } else { // If there are multiple elements
            tail = tail.prev; // Move tail to the previous node
            tail.next = null; // Clear the next pointer of the new tail
        }
        size--; // Decrement the size of the deque
        return oldTailVal; // Return the removed value
    }

    // Method to peek at the value at the front of the deque without removing it
    public T peekFirst() {
        return head != null ? head.val : null; // Return head value or null if empty
    }

    // Method to peek at the value at the end of the deque without removing it
    public T peekLast() {
        return tail != null ? tail.val : null; // Return tail value or null if empty
    }

    // Method to get the current size of the deque
    public int size() {
        return size; // Return the size of the deque
    }

    // Method to check if the deque is empty
    public boolean isEmpty() {
        return size == 0; // Return true if size is 0, otherwise false
    }

    // Method to represent the deque as a string
    @Override
    public String toString() {
        StringBuilder dequeString = new StringBuilder("Head -> "); // Initialize string representation
        MainNode<T> currNode = head; // Start from the head
        while (currNode != null) { // Traverse the deque
            dequeString.append(currNode.val); // Append current node's value
            if (currNode.next != null) { // If there is a next node
                dequeString.append(" <-> "); // Append separator
            }
            currNode = currNode.next; // Move to the next node
        }
        dequeString.append(" <- Tail"); // Append tail indication
        return dequeString.toString(); // Return the string representation
    }

    // Main method to run the deque operations based on user input
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        Main<Integer> deque = new Main<>(); // Initialize a new deque for integers

        // Loop to continuously read commands from the user
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read and trim the command
            if (command.equalsIgnoreCase("exit")) { // Check for exit command
                break; // Exit the loop
            }
            try {
                String[] parts = command.split(" "); // Split command into parts
                switch (parts[0]) { // Determine the command type
                    case "addFirst":
                        int addFirstValue = Integer.parseInt(parts[1]); // Parse the value
                        deque.addFirst(addFirstValue); // Add value to the front
                        System.out.println("Added to front: " + addFirstValue); // Confirm addition
                        break;
                    case "addLast":
                        int addLastValue = Integer.parseInt(parts[1]); // Parse the value
                        deque.addLast(addLastValue); // Add value to the rear
                        System.out.println("Added to rear: " + addLastValue); // Confirm addition
                        break;
                    case "pollFirst":
                        System.out.println("Removed from front: " + deque.pollFirst()); // Remove and display front value
                        break;
                    case "pollLast":
                        System.out.println("Removed from rear: " + deque.pollLast()); // Remove and display rear value
                        break;
                    case "peekFirst":
                        System.out.println("Front element: " + deque.peekFirst()); // Display front value without removal
                        break;
                    case "peekLast":
                        System.out.println("Rear element: " + deque.peekLast()); // Display rear value without removal
                        break;
                    case "size":
                        System.out.println("Size: " + deque.size()); // Display current size
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + deque.isEmpty()); // Check if deque is empty
                        break;
                    case "print":
                        System.out.println(deque); // Print the current state of the deque
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]); // Handle unknown commands
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage()); // Handle exceptions and display error message
            }
        }
        scanner.close(); // Close the scanner
    }
}
