import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
    // Node class representing each element in the queue
    private static class Node<T> {
        T data; // Data stored in the node
        Node<T> next; // Reference to the next node in the queue

        // Constructor to initialize the node with data
        Node(T data) {
            this.data = data;
            this.next = null; // Next is initially null
        }
    }

    // Front and rear pointers for the queue
    private Node<T> front; // Points to the front of the queue
    private Node<T> rear; // Points to the rear of the queue
    private int size; // Keeps track of the number of elements in the queue

    // Constructor to initialize the queue
    public Main() {
        front = null; // Initially, the queue is empty
        rear = null;
        size = 0; // Size is zero
    }

    // Method to check if the queue is empty
    public boolean isEmpty() {
        return size == 0; // Returns true if size is zero
    }

    // Method to add an element to the end of the queue
    public void enqueue(T data) {
        if (data == null) {
            throw new IllegalArgumentException("Cannot enqueue null data"); // Prevent null data
        }
        Node<T> newNode = new Node<>(data); // Create a new node with the given data
        if (isEmpty()) {
            front = newNode; // If the queue is empty, set front to the new node
        } else {
            rear.next = newNode; // Link the new node to the end of the queue
        }
        rear = newNode; // Update the rear to the new node
        size++; // Increment the size of the queue
    }

    // Method to remove and return the front element of the queue
    public T dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty"); // Prevent dequeue from an empty queue
        }
        T retValue = front.data; // Store the data of the front node
        front = front.next; // Move the front pointer to the next node
        size--; // Decrement the size of the queue
        if (isEmpty()) {
            rear = null; // If the queue is now empty, set rear to null
        }
        return retValue; // Return the dequeued value
    }

    // Method to get the front element without removing it
    public T peekFront() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty"); // Prevent peek from an empty queue
        }
        return front.data; // Return the data of the front node
    }

    // Method to get the rear element without removing it
    public T peekRear() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty"); // Prevent peek from an empty queue
        }
        return rear.data; // Return the data of the rear node
    }

    // Method to get the current size of the queue
    public int size() {
        return size; // Return the size of the queue
    }

    // Method to clear the queue
    public void clear() {
        front = null; // Set front to null
        rear = null; // Set rear to null
        size = 0; // Reset size to zero
    }

    // Method to return a string representation of the queue
    @Override
    public String toString() {
        if (isEmpty()) {
            return "[]"; // Return empty representation if the queue is empty
        }
        StringBuilder sb = new StringBuilder("["); // Start building the string
        Node<T> current = front; // Start from the front of the queue
        while (current != null) {
            sb.append(current.data); // Append the current node's data
            if (current.next != null) {
                sb.append(", "); // Append a comma if there is a next node
            }
            current = current.next; // Move to the next node
        }
        sb.append(']'); // Close the string representation
        return sb.toString(); // Return the final string
    }

    // Main method to run the queue operations based on user input
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        Main<Integer> queue = new Main<>(); // Create a new queue instance for integers

        // Loop to process user commands
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read the command from user input
            if (command.equalsIgnoreCase("exit")) {
                break; // Exit the loop if the command is "exit"
            }
            try {
                String[] parts = command.split(" "); // Split the command into parts
                switch (parts[0]) {
                    case "enqueue":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for enqueue"); // Error for missing value
                            break;
                        }
                        int value = Integer.parseInt(parts[1]); // Parse the value to enqueue
                        queue.enqueue(value); // Enqueue the value
                        System.out.println("Enqueued: " + value); // Confirm enqueue operation
                        break;
                    case "dequeue":
                        System.out.println("Dequeued: " + queue.dequeue()); // Dequeue and print the result
                        break;
                    case "peekFront":
                        System.out.println("Front element: " + queue.peekFront()); // Print the front element
                        break;
                    case "peekRear":
                        System.out.println("Rear element: " + queue.peekRear()); // Print the rear element
                        break;
                    case "size":
                        System.out.println("Size: " + queue.size()); // Print the current size of the queue
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + queue.isEmpty()); // Check if the queue is empty
                        break;
                    case "print":
                        System.out.println(queue); // Print the string representation of the queue
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]); // Handle unknown commands
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage()); // Print any errors encountered
            }
        }
        scanner.close(); // Close the scanner when done
    }
}
