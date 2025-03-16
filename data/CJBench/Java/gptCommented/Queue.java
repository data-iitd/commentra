import java.util.Scanner;

public final class Main<T> {
    // Default capacity for the queue
    private static final int DEFAULT_CAPACITY = 10;
    // Maximum size of the queue
    private final int maxSize;
    // Array to hold the queue elements
    private final Object[] queueArray;
    // Index of the front of the queue
    private int front;
    // Index of the rear of the queue
    private int rear;
    // Current number of items in the queue
    private int nItems;

    // Default constructor initializing with default capacity
    public Main() {
        this(DEFAULT_CAPACITY);
    }

    // Constructor that initializes the queue with a specified capacity
    public Main(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Main capacity must be greater than 0");
        }
        this.maxSize = capacity;
        this.queueArray = new Object[capacity];
        this.front = 0;
        this.rear = -1;
        this.nItems = 0;
    }

    // Method to insert an element into the queue
    public boolean insert(T element) {
        // Check if the queue is full
        if (isFull()) {
            return false;
        }
        // Update rear index in a circular manner and add the element
        rear = (rear + 1) % maxSize;
        queueArray[rear] = element;
        nItems++;
        return true;
    }

    // Method to remove and return the front element of the queue
    @SuppressWarnings("unchecked")
    public T remove() {
        // Check if the queue is empty
        if (isEmpty()) {
            throw new IllegalStateException("Main is empty, cannot remove element");
        }
        // Retrieve the front element and update the front index
        T removedElement = (T) queueArray[front];
        queueArray[front] = null; // Clear the reference
        front = (front + 1) % maxSize;
        nItems--;
        return removedElement;
    }

    // Method to peek at the front element without removing it
    @SuppressWarnings("unchecked")
    public T peekFront() {
        // Check if the queue is empty
        if (isEmpty()) {
            throw new IllegalStateException("Main is empty, cannot peek front");
        }
        return (T) queueArray[front];
    }

    // Method to peek at the rear element without removing it
    @SuppressWarnings("unchecked")
    public T peekRear() {
        // Check if the queue is empty
        if (isEmpty()) {
            throw new IllegalStateException("Main is empty, cannot peek rear");
        }
        return (T) queueArray[rear];
    }

    // Method to check if the queue is empty
    public boolean isEmpty() {
        return nItems == 0;
    }

    // Method to check if the queue is full
    public boolean isFull() {
        return nItems == maxSize;
    }

    // Method to get the current size of the queue
    public int getSize() {
        return nItems;
    }

    // Method to return a string representation of the queue
    @Override
    public String toString() {
        if (isEmpty()) {
            return "[]"; // Return empty representation if queue is empty
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        // Iterate through the queue elements in order
        for (int i = 0; i < nItems; i++) {
            int index = (front + i) % maxSize; // Calculate index in a circular manner
            sb.append(queueArray[index]).append(", ");
        }
        sb.setLength(sb.length() - 2); // Remove the last comma and space
        sb.append("]");
        return sb.toString();
    }

    // Main method to execute the queue operations based on user input
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the size of the queue from user input
        int size = scanner.nextInt();
        Main<Integer> queue = new Main<>(size); // Create a queue with specified size

        // Process user commands until "exit" is entered
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.equalsIgnoreCase("exit")) {
                break; // Exit the loop if the command is "exit"
            }
            try {
                String[] parts = command.split(" ");
                // Handle different commands for queue operations
                switch (parts[0]) {
                    case "insert":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for insert");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]);
                        if (queue.insert(value)) {
                            System.out.println("Inserted: " + value);
                        } else {
                            System.out.println("Main is full");
                        }
                        break;
                    case "remove":
                        System.out.println("Removed: " + queue.remove());
                        break;
                    case "peekFront":
                        System.out.println("Front: " + queue.peekFront());
                        break;
                    case "peekRear":
                        System.out.println("Rear: " + queue.peekRear());
                        break;
                    case "getSize":
                        System.out.println("Size: " + queue.getSize());
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + queue.isEmpty());
                        break;
                    case "print":
                        System.out.println("Main: " + queue);
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]);
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close(); // Close the scanner resource
    }
}
