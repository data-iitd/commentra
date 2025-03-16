import java.util.Scanner;

public class Main {
    // Array to hold the elements of the queue
    private T[] array;
    // Index of the top element in the queue
    private int topOfQueue;
    // Index of the beginning element in the queue
    private int beginningOfQueue;
    // Maximum size of the queue
    private final int size;
    // Current number of elements in the queue
    private int currentSize;

    // Constructor to initialize the queue with a specified size
    @SuppressWarnings("unchecked")
    public Main(int size) {
        // Validate that the size is greater than 0
        if (size < 1) {
            throw new IllegalArgumentException("Size must be greater than 0");
        }
        // Initialize the array and other variables
        this.array = (T[]) new Object[size];
        this.topOfQueue = -1;
        this.beginningOfQueue = -1;
        this.size = size;
        this.currentSize = 0;
    }

    // Method to check if the queue is empty
    public boolean isEmpty() {
        return currentSize == 0;
    }

    // Method to check if the queue is full
    public boolean isFull() {
        return currentSize == size;
    }

    // Method to add an element to the queue
    public void enQueue(T value) {
        // Check if the queue is full before adding an element
        if (isFull()) {
            throw new IllegalStateException("Queue is full");
        }
        // If the queue is empty, set the beginning index
        if (isEmpty()) {
            beginningOfQueue = 0;
        }
        // Update the top index in a circular manner and add the new value
        topOfQueue = (topOfQueue + 1) % size;
        array[topOfQueue] = value;
        currentSize++;
    }

    // Method to remove and return the front element of the queue
    public T deQueue() {
        // Check if the queue is empty before removing an element
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        // Store the value to be removed
        T removedValue = array[beginningOfQueue];
        // Clear the position in the array
        array[beginningOfQueue] = null;
        // Update the beginning index in a circular manner
        beginningOfQueue = (beginningOfQueue + 1) % size;
        currentSize--;
        // Reset indices if the queue is empty after removal
        if (isEmpty()) {
            beginningOfQueue = -1;
            topOfQueue = -1;
        }
        return removedValue;
    }

    // Method to view the front element of the queue without removing it
    public T peek() {
        // Check if the queue is empty before peeking
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        return array[beginningOfQueue];
    }

    // Method to delete the queue and free resources
    public void deleteQueue() {
        array = null; // Clear the array reference
        beginningOfQueue = -1; // Reset beginning index
        topOfQueue = -1; // Reset top index
        currentSize = 0; // Reset current size
    }

    // Method to get the current size of the queue
    public int size() {
        return currentSize;
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the size of the queue from user input
        int queueSize = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        // Create a new queue instance
        Main<Integer> queue = new Main<>(queueSize);
        
        // Loop to process user commands until "exit" is entered
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.equalsIgnoreCase("exit")) {
                break; // Exit the loop if the command is "exit"
            }
            try {
                // Split the command into parts for processing
                String[] parts = command.split(" ");
                switch (parts[0]) {
                    case "enQueue":
                        // Check for missing value in the command
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for enQueue");
                            break;
                        }
                        // Parse the value and enqueue it
                        int value = Integer.parseInt(parts[1]);
                        queue.enQueue(value);
                        System.out.println("Enqueued: " + value);
                        break;
                    case "deQueue":
                        // Dequeue an element and print it
                        System.out.println("Dequeued: " + queue.deQueue());
                        break;
                    case "peek":
                        // Peek at the front element of the queue
                        System.out.println("Front of queue: " + queue.peek());
                        break;
                    case "isEmpty":
                        // Check if the queue is empty and print the result
                        System.out.println("Is empty: " + queue.isEmpty());
                        break;
                    case "isFull":
                        // Check if the queue is full and print the result
                        System.out.println("Is full: " + queue.isFull());
                        break;
                    case "size":
                        // Print the current size of the queue
                        System.out.println("Current size: " + queue.size());
                        break;
                    default:
                        // Handle unknown commands
                        System.out.println("Unknown command: " + parts[0]);
                }
            } catch (Exception e) {
                // Handle any exceptions that occur during command processing
                System.out.println("Error: " + e.getMessage());
            }
        }
        // Close the scanner resource
        scanner.close();
    }
}
