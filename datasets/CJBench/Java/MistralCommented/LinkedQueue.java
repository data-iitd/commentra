
import java.util.NoSuchElementException;
import java.util.Scanner;

// Class definition for a generic linked list queue
public class Main<T> {

    // Inner class definition for a node in the queue
    private static class Node<T> {
        T data;        // Data stored in the node
        Node<T> next;  // Reference to the next node

        // Constructor for a new node with given data
        Node(T data) {
            this.data = data;
            this.next = null;
        }
    }

    // Instance variables for the front and rear pointers, and the size of the queue
    private Node<T> front;
    private Node<T> rear;
    private int size;

    // Constructor for an empty queue
    public Main() {
        front = null;
        rear = null;
        size = 0;
    }

    // Check if the queue is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Add an element to the queue
    public void enqueue(T data) {
        if (data == null) { // Check if the data is null
            throw new IllegalArgumentException("Cannot enqueue null data");
        }

        Node<T> newNode = new Node<>(data); // Create a new node with the data

        if (isEmpty()) { // If the queue is empty
            front = newNode;
        } else {
            rear.next = newNode; // Else, make the new node the next of the rear node
        }

        rear = newNode; // Update the rear pointer
        size++; // Increment the size of the queue
    }

    // Remove and return the front element from the queue
    public T dequeue() {
        if (isEmpty()) { // Check if the queue is empty
            throw new NoSuchElementException("Queue is empty");
        }

        T retValue = front.data; // Store the data of the front node in a variable

        front = front.next; // Update the front pointer to the next node

        size--; // Decrement the size of the queue

        if (isEmpty()) { // If the queue is now empty
            rear = null; // Set the rear pointer to null
        }

        return retValue; // Return the dequeued element
    }

    // Return the front element of the queue without removing it
    public T peekFront() {
        if (isEmpty()) { // Check if the queue is empty
            throw new NoSuchElementException("Queue is empty");
        }

        return front.data; // Return the data of the front node
    }

    // Return the rear element of the queue without removing it
    public T peekRear() {
        if (isEmpty()) { // Check if the queue is empty
            throw new NoSuchElementException("Queue is empty");
        }

        return rear.data; // Return the data of the rear node
    }

    // Return the size of the queue
    public int size() {
        return size;
    }

    // Clear the queue
    public void clear() {
        front = null;
        rear = null;
        size = 0;
    }

    // Override the toString method to print the queue as a string
    @Override
    public String toString() {
        if (isEmpty()) {
            return "[]";
        }

        StringBuilder sb = new StringBuilder("[");
        Node<T> current = front; // Initialize a pointer to the front node

        while (current != null) { // Traverse the queue and add each element to the string
            sb.append(current.data);
            if (current.next != null) {
                sb.append(", ");
            }
            current = current.next;
        }

        sb.append(']'); // Add the closing bracket
        return sb.toString();
    }

    // Main method for testing the queue implementation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input

        Main<Integer> queue = new Main<>(); // Create an instance of the queue for integers

        while (scanner.hasNextLine()) { // Read commands from the standard input until the end
            String command = scanner.nextLine().trim(); // Read a command line

            if (command.equalsIgnoreCase("exit")) { // Check if the command is "exit"
                break; // If so, exit the loop
            }

            try {
                String[] parts = command.split(" "); // Split the command into parts

                switch (parts[0]) { // Perform the specified command based on the command name
                    case "enqueue":
                        if (parts.length < 2) { // Check if the command has a required argument
                            System.out.println("Error: Missing value for enqueue");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]); // Parse the value from the argument
                        queue.enqueue(value); // Enqueue the value
                        System.out.println("Enqueued: " + value); // Print a message
                        break;
                    case "dequeue":
                        System.out.println("Dequeued: " + queue.dequeue()); // Dequeue and print the front element
                        break;
                    case "peekFront":
                        System.out.println("Front element: " + queue.peekFront()); // Print the front element
                        break;
                    case "peekRear":
                        System.out.println("Rear element: " + queue.peekRear()); // Print the rear element
                        break;
                    case "size":
                        System.out.println("Size: " + queue.size()); // Print the size of the queue
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + queue.isEmpty()); // Print whether the queue is empty or not
                        break;
                    case "print":
                        System.out.println(queue); // Print the entire queue
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]); // Print an error message for unknown commands
                }
            } catch (Exception e) { // Catch any exceptions and print an error message
                System.out.println("Error: " + e.getMessage());
            }
        }

        scanner.close(); // Close the Scanner object
    }
}