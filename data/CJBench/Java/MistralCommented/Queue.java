
import java.util.Scanner; // Import Scanner class for user input

public final class Main<T> { // Define a generic class named Main
    private static final int DEFAULT_CAPACITY = 10; // Set default capacity of the queue
    private final int maxSize; // Declare maxSize variable to store the capacity of the queue
    private final Object[] queueArray; // Declare queueArray to store the elements of the queue
    private int front; // Declare front variable to store the index of the front element
    private int rear; // Declare rear variable to store the index of the rear element
    private int nItems; // Declare nItems variable to store the number of elements in the queue

    public Main() { // Constructor with no arguments, initializes the queue with default capacity
        this(DEFAULT_CAPACITY);
    }

    public Main(int capacity) { // Constructor with an integer argument, initializes the queue with the given capacity
        if (capacity <= 0) { // Check if the capacity is less than or equal to zero
            throw new IllegalArgumentException("Main capacity must be greater than 0"); // Throw an exception if it is
        }
        this.maxSize = capacity; // Set the maxSize to the given capacity
        this.queueArray = new Object[capacity]; // Create an array of the given size to store the queue elements
        this.front = 0; // Set the front index to zero
        this.rear = -1; // Set the rear index to -1, indicating an empty queue
        this.nItems = 0; // Set the number of elements to zero
    }

    // ... (insert, remove, peekFront, peekRear, isEmpty, isFull, getSize, and print methods)

    public static void main(String[] args) { // Main method to run the program
        Scanner scanner = new Scanner(System.in); // Create a new Scanner object to read user input

        int size = scanner.nextInt(); // Read the size of the queue from the user
        Main<Integer> queue = new Main<>(size); // Create a new Main object with the given size

        while (scanner.hasNextLine()) { // Read user commands until the end of the input
            String command = scanner.nextLine().trim(); // Read and trim the command string

            if (command.equalsIgnoreCase("exit")) { // Check if the command is "exit"
                break; // If it is, exit the loop and close the scanner
            }

            String[] parts = command.split(" "); // Split the command string into parts based on space

            switch (parts[0]) { // Switch on the command type
                case "insert": // If the command is "insert", process the insertion
                    if (parts.length < 2) { // Check if the command has a value
                        System.out.println("Error: Missing value for insert"); // Print an error message if it doesn't
                        break;
                    }
                    int value = Integer.parseInt(parts[1]); // Parse the value from the command
                    if (queue.insert(value)) { // Try to insert the value into the queue
                        System.out.println("Inserted: " + value); // Print a success message if it's successful
                    } else {
                        System.out.println("Main is full"); // Print a full message if the queue is full
                    }
                    break;
                // ... (other cases for "remove", "peekFront", "peekRear", "getSize", "isEmpty", and "print")
            }
        }

        scanner.close(); // Close the scanner when finished
    }
}

