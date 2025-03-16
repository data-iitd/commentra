import java.util.Scanner;

public class Main {
    // Array to represent the heap
    private final int[] heap;
    // Maximum capacity of the heap
    private final int capacity;
    // Current size of the heap
    private int size;

    // Constructor to initialize the heap with a given capacity
    public Main(int c) {
        this.capacity = c;
        this.size = 0;
        this.heap = new int[c + 1]; // Heap is 1-indexed
    }

    // Method to insert a new key into the heap
    public void insert(int key) {
        // Check if the heap is full before inserting
        if (this.isFull()) {
            throw new IllegalStateException("Main is full. Cannot insert new element.");
        }
        // Place the new key at the end of the heap
        this.heap[this.size + 1] = key;
        int k = this.size + 1;

        // Bubble up the new key to maintain heap property
        while (k > 1) {
            if (this.heap[k] < this.heap[k / 2]) {
                // Swap if the current key is smaller than its parent
                int temp = this.heap[k];
                this.heap[k] = this.heap[k / 2];
                this.heap[k / 2] = temp;
            }
            k = k / 2; // Move to the parent index
        }
        this.size++; // Increase the size of the heap
    }

    // Method to get the minimum element without removing it
    public int peek() {
        // Check if the heap is empty before peeking
        if (isEmpty()) {
            throw new IllegalStateException("Main is empty. Cannot peek.");
        }
        return this.heap[1]; // Return the root of the heap
    }

    // Method to check if the heap is empty
    public boolean isEmpty() {
        return size == 0; // Returns true if size is 0
    }

    // Method to check if the heap is full
    public boolean isFull() {
        return size == capacity; // Returns true if size equals capacity
    }

    // Method to print the elements of the heap
    public void print() {
        for (int i = 1; i <= this.size; i++) {
            System.out.print(this.heap[i] + " "); // Print each element
        }
        System.out.println(); // New line after printing all elements
    }

    // Method to perform heap sort by deleting all elements
    public void heapSort() {
        for (int i = 1; i <= this.size; i++) {
            this.delete(); // Delete elements one by one
        }
    }

    // Method to maintain the heap property after deletion
    private void sink() {
        int k = 1; // Start from the root
        while (2 * k <= this.size) { // While there is at least one child
            int minIndex = k; // Assume current index is the smallest
            // Check left child
            if (2 * k <= this.size && this.heap[2 * k] < this.heap[minIndex]) {
                minIndex = 2 * k; // Update minIndex if left child is smaller
            }
            // Check right child
            if (2 * k + 1 <= this.size && this.heap[2 * k + 1] < this.heap[minIndex]) {
                minIndex = 2 * k + 1; // Update minIndex if right child is smaller
            }
            // If the current index is the smallest, break
            if (minIndex == k) {
                break;
            }
            // Swap current index with the smallest child
            int temp = this.heap[k];
            this.heap[k] = this.heap[minIndex];
            this.heap[minIndex] = temp;
            k = minIndex; // Move down to the smallest child
        }
    }

    // Method to delete and return the minimum element from the heap
    public int delete() {
        // Check if the heap is empty before deleting
        if (isEmpty()) {
            throw new IllegalStateException("Main is empty. Cannot delete.");
        }
        int min = this.heap[1]; // Store the minimum element
        this.heap[1] = this.heap[this.size]; // Replace root with the last element
        this.size--; // Decrease the size of the heap
        this.sink(); // Restore heap property
        return min; // Return the minimum element
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int capacity = scanner.nextInt(); // Read the capacity of the heap
        Main queue = new Main(capacity); // Create a new heap with the specified capacity

        // Process commands until the user decides to exit
        while (scanner.hasNext()) {
            String command = scanner.next(); // Read the command
            try {
                switch (command) {
                    case "insert":
                        int value = scanner.nextInt(); // Read the value to insert
                        queue.insert(value); // Insert the value into the heap
                        System.out.println("Inserted: " + value);
                        break;
                    case "delete":
                        System.out.println("Deleted: " + queue.delete()); // Delete and print the minimum element
                        break;
                    case "peek":
                        System.out.println("Peek: " + queue.peek()); // Print the minimum element without deleting
                        break;
                    case "print":
                        System.out.print("Heap: ");
                        queue.print(); // Print all elements in the heap
                        break;
                    case "isEmpty":
                        System.out.println("Is Empty: " + queue.isEmpty()); // Check if the heap is empty
                        break;
                    case "exit":
                        System.out.println("Exiting..."); // Exit the program
                        return;
                    default:
                        System.out.println("Unknown command: " + command); // Handle unknown commands
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage()); // Handle exceptions
            }
        }
        scanner.close(); // Close the scanner
    }
}
