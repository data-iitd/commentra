
import java.util.Scanner;

public class Main<T> {
    // Declare instance variables
    private T[] array;
    private int topOfQueue;
    private int beginningOfQueue;
    private final int size;
    private int currentSize;

    @SuppressWarnings("unchecked")
    // Constructor initializes array, sets initial values for topOfQueue, beginningOfQueue, size, and currentSize
    public Main(int size) {
        if (size < 1) {
            throw new IllegalArgumentException("Size must be greater than 0");
        }
        this.array = (T[]) new Object[size];
        this.topOfQueue = -1;
        this.beginningOfQueue = -1;
        this.size = size;
        this.currentSize = 0;
    }

    // Checks if queue is empty
    public boolean isEmpty() {
        return currentSize == 0;
    }

    // Checks if queue is full
    public boolean isFull() {
        return currentSize == size;
    }

    // Enqueues a value into the queue
    public void enQueue(T value) {
        if (isFull()) {
            throw new IllegalStateException("Queue is full");
        }
        if (isEmpty()) {
            beginningOfQueue = 0;
        }
        topOfQueue = (topOfQueue + 1) % size;
        array[topOfQueue] = value;
        currentSize++;
    }

    // Dequeues a value from the queue
    public T deQueue() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        T removedValue = array[beginningOfQueue];
        array[beginningOfQueue] = null;
        beginningOfQueue = (beginningOfQueue + 1) % size;
        currentSize--;
        if (isEmpty()) {
            beginningOfQueue = -1;
            topOfQueue = -1;
        }
        return removedValue;
    }

    // Returns the value at the front of the queue
    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        return array[beginningOfQueue];
    }

    // Frees up memory used by the queue
    public void deleteQueue() {
        array = null;
        beginningOfQueue = -1;
        topOfQueue = -1;
        currentSize = 0;
    }

    // Returns the current size of the queue
    public int size() {
        return currentSize;
    }

    // Main method reads user input and processes commands
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int queueSize = scanner.nextInt();
        scanner.nextLine(); // Consume newline character

        // Create a new queue of the given size
        Main<Integer> queue = new Main<>(queueSize);

        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();

            if (command.equalsIgnoreCase("exit")) {
                break;
            }

            try {
                String[] parts = command.split(" ");

                // Process command based on its first word
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