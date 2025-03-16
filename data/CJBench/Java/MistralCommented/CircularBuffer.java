
import java.util.Scanner;

public class Main {
    // Declare instance variables
    private final Item[] buffer;
    private final CircularPointer putPointer;
    private final CircularPointer getPointer;
    private int size;

    // Constructor
    public Main(int size) {
        // Check if size is positive
        if (size <= 0) {
            throw new IllegalArgumentException("Buffer size must be positive");
        }

        // Initialize buffer with given size
        this.buffer = (Item[]) new Object[size];

        // Initialize putPointer and getPointer with given size
        this.putPointer = new CircularPointer(0, size);
        this.getPointer = new CircularPointer(0, size);

        // Initialize size to 0
        this.size = 0;
    }

    // Check if buffer is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Check if buffer is full
    public boolean isFull() {
        return size == buffer.length;
    }

    // Get an item from buffer
    public Item get() {
        if (isEmpty()) {
            // Return null if buffer is empty
            return null;
        }

        // Get the item at the current getPointer position
        Item item = buffer[getPointer.getAndIncrement()];

        // Decrement size
        size--;

        // Return the item
        return item;
    }

    // Put an item into buffer
    public boolean put(Item item) {
        if (item == null) {
            // Throw an exception if item is null
            throw new IllegalArgumentException("Null items are not allowed");
        }

        if (isFull()) {
            // Increment getPointer to make room for new item
            getPointer.getAndIncrement();
        } else {
            // Increment size and put the item at the current putPointer position
            size++;
            buffer[putPointer.getAndIncrement()] = item;
        }

        // Return true to indicate successful put
        return true;
    }

    // Inner class CircularPointer
    private static class CircularPointer {
        // Declare instance variables
        private int pointer;
        private final int max;

        // Constructor
        CircularPointer(int pointer, int max) {
            this.pointer = pointer;
            this.max = max;
        }

        // Get and increment pointer
        public int getAndIncrement() {
            int tmp = pointer;
            pointer = (pointer + 1) % max;
            return tmp;
        }
    }

    // Main method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read buffer size from standard input
        int bufferSize = scanner.nextInt();

        // Read number of operations from standard input
        int numberOfOperations = scanner.nextInt();

        // Create a new Main instance with given buffer size
        Main<String> buffer = new Main<>(bufferSize);

        // Perform given number of operations
        for (int i = 0; i < numberOfOperations; i++) {
            String operation = scanner.next();

            if (operation.equals("PUT")) {
                // Read the element to be put from standard input
                String element = scanner.next();

                // Put the element into the buffer
                buffer.put(element);

                // Print a message indicating successful put
                System.out.println("Added: " + element);
            } else if (operation.equals("GET")) {
                // Get an item from the buffer and print its value
                String result = buffer.get();
                System.out.println("Retrieved: " + (result != null ? result : "null"));
            } else if (operation.equals("ISEMPTY")) {
                // Print a message indicating if the buffer is empty
                System.out.println("Is Empty: " + buffer.isEmpty());
            } else if (operation.equals("ISFULL")) {
                // Print a message indicating if the buffer is full
                System.out.println("Is Full: " + buffer.isFull());
            }
        }

        // Close the scanner
        scanner.close();
    }
}