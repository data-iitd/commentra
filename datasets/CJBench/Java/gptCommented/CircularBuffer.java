import java.util.Scanner;

public class Main {
    // Buffer to hold items
    private final Item[] buffer;
    // Pointers to manage the circular buffer
    private final CircularPointer putPointer;
    private final CircularPointer getPointer;
    // Current size of the buffer
    private int size;

    // Constructor to initialize the buffer with a given size
    public Main(int size) {
        // Validate that the size is positive
        if (size <= 0) {
            throw new IllegalArgumentException("Buffer size must be positive");
        }
        // Initialize the buffer and pointers
        this.buffer = (Item[]) new Object[size];
        this.putPointer = new CircularPointer(0, size);
        this.getPointer = new CircularPointer(0, size);
        this.size = 0; // Start with an empty buffer
    }

    // Check if the buffer is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Check if the buffer is full
    public boolean isFull() {
        return size == buffer.length;
    }

    // Retrieve an item from the buffer
    public Item get() {
        // Return null if the buffer is empty
        if (isEmpty()) {
            return null;
        }
        // Get the item at the current get pointer and decrement size
        Item item = buffer[getPointer.getAndIncrement()];
        size--;
        return item;
    }

    // Add an item to the buffer
    public boolean put(Item item) {
        // Validate that the item is not null
        if (item == null) {
            throw new IllegalArgumentException("Null items are not allowed");
        }
        // If the buffer is full, increment the get pointer to overwrite
        if (isFull()) {
            getPointer.getAndIncrement(); 
        } else {
            size++; // Increment size if not full
        }
        // Place the item at the current put pointer
        buffer[putPointer.getAndIncrement()] = item;
        return true; // Indicate successful addition
    }

    // Inner class to manage circular indexing
    private static class CircularPointer {
        private int pointer; // Current position of the pointer
        private final int max; // Maximum size of the buffer

        // Constructor to initialize the pointer and its maximum
        CircularPointer(int pointer, int max) {
            this.pointer = pointer;
            this.max = max;
        }

        // Get the current pointer value and increment it circularly
        public int getAndIncrement() {
            int tmp = pointer; // Store current pointer
            pointer = (pointer + 1) % max; // Increment circularly
            return tmp; // Return the old pointer value
        }
    }

    // Main method to run the buffer operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read buffer size and number of operations from input
        int bufferSize = scanner.nextInt();
        int numberOfOperations = scanner.nextInt();
        // Create a new buffer instance
        Main<String> buffer = new Main<>(bufferSize);
        
        // Process each operation
        for (int i = 0; i < numberOfOperations; i++) {
            String operation = scanner.next();
            // Handle PUT operation
            if (operation.equals("PUT")) {
                String element = scanner.next();
                buffer.put(element); // Add element to buffer
                System.out.println("Added: " + element);
            } 
            // Handle GET operation
            else if (operation.equals("GET")) {
                String result = buffer.get(); // Retrieve element from buffer
                System.out.println("Retrieved: " + (result != null ? result : "null"));
            } 
            // Check if the buffer is empty
            else if (operation.equals("ISEMPTY")) {
                System.out.println("Is Empty: " + buffer.isEmpty());
            } 
            // Check if the buffer is full
            else if (operation.equals("ISFULL")) {
                System.out.println("Is Full: " + buffer.isFull());
            }
        }
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
