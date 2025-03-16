import java.util.Scanner;

public class Main {
    // Maximum size of the priority queue
    private int maxSize;
    // Array to hold the elements of the priority queue
    private int[] queueArray;
    // Current number of items in the priority queue
    private int nItems;

    // Constructor to initialize the priority queue with a given size
    public Main(int size) {
        maxSize = size + 1; // +1 to accommodate the unused index 0
        queueArray = new int[maxSize]; // Initialize the queue array
        nItems = 0; // Start with zero items
    }

    // Method to maintain the heap property by swimming up the newly added element
    private void swim(int pos) {
        // Continue until the position is valid and the parent is less than the current node
        while (pos > 1 && (queueArray[pos / 2] < queueArray[pos])) {
            // Swap the current node with its parent
            int temp = queueArray[pos];
            queueArray[pos] = queueArray[pos / 2];
            queueArray[pos / 2] = temp;
            pos = pos / 2; // Move up to the parent's position
        }
    }

    // Method to maintain the heap property by sinking down the removed element
    private void sink(int pos) {
        // Continue until the position is valid for sinking
        while (2 * pos <= nItems) {
            int current = 2 * pos; // Left child position
            // Check if the right child exists and is greater than the left child
            if (current < nItems && queueArray[current] < queueArray[current + 1]) {
                current++; // Move to the right child
            }
            // If the current node is greater than or equal to the largest child, break
            if (queueArray[pos] >= queueArray[current]) {
                break;
            }
            // Swap the current node with the largest child
            int temp = queueArray[pos];
            queueArray[pos] = queueArray[current];
            queueArray[current] = temp;
            pos = current; // Move down to the child's position
        }
    }

    // Method to insert a new value into the priority queue
    public void insert(int value) {
        // Check if the queue is full
        if (isFull()) {
            throw new RuntimeException("Queue is full");
        } else {
            // Insert the new value and swim it up to maintain heap property
            queueArray[++nItems] = value;
            swim(nItems);
        }
    }

    // Method to remove and return the maximum value from the priority queue
    public int remove() {
        // Check if the queue is empty
        if (isEmpty()) {
            throw new RuntimeException("Queue is Empty");
        } else {
            // Store the maximum value to return
            int max = queueArray[1];
            // Swap the root with the last element
            int temp = queueArray[1];
            queueArray[1] = queueArray[nItems];
            queueArray[nItems] = temp;
            queueArray[nItems--] = 0; // Remove the last element
            // Sink the new root to maintain heap property
            sink(1);
            return max; // Return the maximum value
        }
    }

    // Method to peek at the maximum value without removing it
    public int peek() {
        // Check if the queue is empty
        if (isEmpty()) {
            throw new RuntimeException("Queue is Empty");
        }
        return queueArray[1]; // Return the maximum value
    }

    // Method to check if the queue is empty
    public boolean isEmpty() {
        return (nItems == 0); // Return true if there are no items
    }

    // Method to check if the queue is full
    public boolean isFull() {
        return (nItems == maxSize - 1); // Return true if the queue is full
    }

    // Method to get the current size of the queue
    public int getSize() {
        return nItems; // Return the number of items in the queue
    }

    // Main method to run the priority queue operations based on user input
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt(); // Read the size of the queue from input
        Main pq = new Main(size); // Create a new priority queue

        // Loop to process user commands until "exit" is entered
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read the command
            if (command.equalsIgnoreCase("exit")) {
                break; // Exit the loop if the command is "exit"
            }
            try {
                String[] parts = command.split(" "); // Split the command into parts
                switch (parts[0]) {
                    case "insert":
                        // Check if a value is provided for insertion
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for insert");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]); // Parse the value to insert
                        pq.insert(value); // Insert the value into the queue
                        System.out.println("Inserted: " + value);
                        break;
                    case "remove":
                        // Remove and print the maximum value
                        System.out.println("Removed: " + pq.remove());
                        break;
                    case "peek":
                        // Print the maximum value without removing it
                        System.out.println("Peek: " + pq.peek());
                        break;
                    case "getSize":
                        // Print the current size of the queue
                        System.out.println("Size: " + pq.getSize());
                        break;
                    case "isEmpty":
                        // Check and print if the queue is empty
                        System.out.println("Is empty: " + pq.isEmpty());
                        break;
                    default:
                        // Handle unknown commands
                }
            } catch (Exception e) {
                // Print any errors that occur during command processing
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close(); // Close the scanner resource
    }
}
