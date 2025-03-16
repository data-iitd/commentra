
import java.util.Scanner;

public class Main {
    // Initialize the heap with given capacity
    private final int[] heap;
    private final int capacity;
    private int size;

    public Main(int c) {
        this.capacity = c;
        this.size = 0;
        this.heap = new int[c + 1]; // Allocate memory for the heap array with given capacity
    }

    // Insert a new element into the heap
    public void insert(int key) {
        if (isFull()) { // Check if the heap is full before inserting a new element
            throw new IllegalStateException("Main is full. Cannot insert new element.");
        }
        this.heap[this.size + 1] = key; // Add the new element to the last position of the heap
        int k = this.size + 1; // Initialize the index of the newly added element

        while (k > 1) { // Perform the heapify operation to maintain the heap property
            if (this.heap[k] < this.heap[k / 2]) {
                int temp = this.heap[k];
                this.heap[k] = this.heap[k / 2];
                this.heap[k / 2] = temp;
            }
            k = k / 2;
        }
        this.size++; // Increment the size of the heap after successful insertion
    }

    // Return the minimum element from the heap
    public int peek() {
        if (isEmpty()) { // Check if the heap is empty before returning the minimum element
            throw new IllegalStateException("Main is empty. Cannot peek.");
        }
        return this.heap[1]; // Return the minimum element, which is the first element in the heap
    }

    // Check if the heap is empty
    public boolean isEmpty() {
        return size == 0; // Return true if the size of the heap is zero, indicating an empty heap
    }

    // Check if the heap is full
    public boolean isFull() {
        return size == capacity; // Return true if the size of the heap reaches the given capacity, indicating a full heap
    }

    // Print the elements of the heap
    public void print() {
        for (int i = 1; i <= this.size; i++) {
            System.out.print(this.heap[i] + " "); // Print each element in the heap, starting from the first element
        }
        System.out.println(); // Print a newline character after printing all the elements
    }

    // Sort the elements of the heap using heap sort algorithm
    public void heapSort() {
        for (int i = 1; i <= this.size; i++) {
            this.delete(); // Delete the minimum element from the heap after each iteration
        }
    }

    // Perform the sink operation to maintain the heap property
    private void sink() {
        int k = 1; // Initialize the index of the root node
        while (2 * k <= this.size) { // Continue the sink operation until the last level of the heap is reached
            int minIndex = k; // Initialize the index of the minimum element
            if (2 * k <= this.size && this.heap[2 * k] < this.heap[minIndex]) {
                minIndex = 2 * k; // Update the index of the minimum element if a left child exists and its value is smaller
            }
            if (2 * k + 1 <= this.size && this.heap[2 * k + 1] < this.heap[minIndex]) {
                minIndex = 2 * k + 1; // Update the index of the minimum element if a right child exists and its value is smaller
            }
            if (minIndex == k) { // If the minimum element is already at the current position, break the loop
                break;
            }
            int temp = this.heap[k]; // Swap the elements if the minimum element is not at the current position
            this.heap[k] = this.heap[minIndex];
            this.heap[minIndex] = temp;
            k = minIndex; // Move to the next level of the heap
        }
    }

    // Delete and return the minimum element from the heap
    public int delete() {
        if (isEmpty()) { // Check if the heap is empty before deleting an element
            throw new IllegalStateException("Main is empty. Cannot delete.");
        }
        int min = this.heap[1]; // Store the minimum element in a variable
        this.heap[1] = this.heap[this.size]; // Replace the minimum element with the last element of the heap
        this.size--; // Decrement the size of the heap after successful deletion
        this.sink(); // Perform the sink operation to maintain the heap property after deletion
        return min; // Return the deleted minimum element
    }

    // Main method to read user input and perform the required operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize the Scanner object to read user input

        int capacity = scanner.nextInt(); // Read the capacity of the heap from the user input
        Main queue = new Main(capacity); // Create a new instance of the Main class with the given capacity

        while (scanner.hasNext()) { // Read user input until the end of the file is reached
            String command = scanner.next(); // Read the command from the user input
            try {
                switch (command) { // Perform the required operation based on the user command
                    case "insert":
                        int value = scanner.nextInt();
                        queue.insert(value);
                        System.out.println("Inserted: " + value);
                        break;
                    case "delete":
                        System.out.println("Deleted: " + queue.delete());
                        break;
                    case "peek":
                        System.out.println("Peek: " + queue.peek());
                        break;
                    case "print":
                        System.out.print("Heap: ");
                        queue.print();
                        break;
                    case "isEmpty":
                        System.out.println("Is Empty: " + queue.isEmpty());
                        break;
                    case "exit":
                        System.out.println("Exiting...");
                        return;
                    default:
                        System.out.println("Unknown command: " + command);
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }

        scanner.close(); // Close the Scanner object after reading all the user input
    }
}