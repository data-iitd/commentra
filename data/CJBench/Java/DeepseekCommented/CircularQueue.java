import java.util.Scanner;
public class Main<T> {
    // Array to hold the queue elements
    private T[] array;
    // Index of the top of the queue
    private int topOfQueue;
    // Index of the beginning of the queue
    private int beginningOfQueue;
    // Size of the queue
    private final int size;
    // Current number of elements in the queue
    private int currentSize;
    
    // Constructor to initialize the queue with a given size
    @SuppressWarnings("unchecked")
    public Main(int size) {
        // Check if the size is valid
        if (size < 1) {
            throw new IllegalArgumentException("Size must be greater than 0");
        }
        // Initialize the array with the given size
        this.array = (T[]) new Object[size];
        // Initialize indices and sizes
        this.topOfQueue = -1;
        this.beginningOfQueue = -1;
        this.size = size;
        this.currentSize = 0;
    }
    
    // Check if the queue is empty
    public boolean isEmpty() {
        return currentSize == 0;
    }
    
    // Check if the queue is full
    public boolean isFull() {
        return currentSize == size;
    }
    
    // Add an element to the queue
    public void enQueue(T value) {
        if (isFull()) {
            throw new IllegalStateException("Queue is full");
        }
        // Set beginning of queue if it's the first element
        if (isEmpty()) {
            beginningOfQueue = 0;
        }
        // Update the top of the queue and add the value
        topOfQueue = (topOfQueue + 1) % size;
        array[topOfQueue] = value;
        currentSize++;
    }
    
    // Remove and return the front element from the queue
    public T deQueue() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        // Get the value to be removed
        T removedValue = array[beginningOfQueue];
        // Clear the position and update the beginning of the queue
        array[beginningOfQueue] = null;
        beginningOfQueue = (beginningOfQueue + 1) % size;
        currentSize--;
        // If the queue is empty, reset the beginning and top indices
        if (isEmpty()) {
            beginningOfQueue = -1;
            topOfQueue = -1;
        }
        return removedValue;
    }
    
    // Return the front element without removing it
    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        return array[beginningOfQueue];
    }
    
    // Delete the queue
    public void deleteQueue() {
        array = null;
        beginningOfQueue = -1;
        topOfQueue = -1;
        currentSize = 0;
    }
    
    // Return the current size of the queue
    public int size() {
        return currentSize;
    }
    
    // Main method to interact with the queue via command line
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int queueSize = scanner.nextInt();
        scanner.nextLine(); 
        Main<Integer> queue = new Main<>(queueSize);
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.equalsIgnoreCase("exit")) {
                break;
            }
            try {
                String[] parts = command.split(" ");
                switch (parts[0]) {
                    case "enQueue":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for enQueue");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]);
                        queue.enQueue(value);
                        System.out.println("Enqueued: " + value);
                        break;
                    case "deQueue":
                        System.out.println("Dequeued: " + queue.deQueue());
                        break;
                    case "peek":
                        System.out.println("Front of queue: " + queue.peek());
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + queue.isEmpty());
                        break;
                    case "isFull":
                        System.out.println("Is full: " + queue.isFull());
                        break;
                    case "size":
                        System.out.println("Current size: " + queue.size());
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]);
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close();
    }
}
