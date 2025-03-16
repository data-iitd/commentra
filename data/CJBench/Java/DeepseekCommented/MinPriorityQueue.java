import java.util.Scanner;
public class Main {
    private final int[] heap; // Array to store the heap elements
    private final int capacity; // Maximum capacity of the heap
    private int size; // Current size of the heap

    // Constructor to initialize the heap with a given capacity
    public Main(int c) {
        this.capacity = c;
        this.size = 0;
        this.heap = new int[c + 1]; // +1 because heap[0] is not used
    }

    // Method to insert a new element into the heap
    public void insert(int key) {
        if (this.isFull()) { // Check if the heap is full
            throw new IllegalStateException("Heap is full. Cannot insert new element.");
        }
        this.heap[this.size + 1] = key; // Insert the key at the next available position
        int k = this.size + 1;
        // Adjust the position of the key to maintain the heap property
        while (k > 1) {
            if (this.heap[k] < this.heap[k / 2]) {
                int temp = this.heap[k];
                this.heap[k] = this.heap[k / 2];
                this.heap[k / 2] = temp;
            }
            k = k / 2;
        }
        this.size++; // Increment the size of the heap
    }

    // Method to return the minimum element in the heap without removing it
    public int peek() {
        if (isEmpty()) { // Check if the heap is empty
            throw new IllegalStateException("Heap is empty. Cannot peek.");
        }
        return this.heap[1]; // The minimum element is at the root of the heap
    }

    // Method to check if the heap is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Method to check if the heap is full
    public boolean isFull() {
        return size == capacity;
    }

    // Method to print the elements of the heap
    public void print() {
        for (int i = 1; i <= this.size; i++) {
            System.out.print(this.heap[i] + " ");
        }
        System.out.println();
    }

    // Method to sort the heap using the delete operation
    public void heapSort() {
        for (int i = 1; i <= this.size; i++) {
            this.delete();
        }
    }

    // Private method to maintain the heap property after deletion
    private void sink() {
        int k = 1;
        while (2 * k <= this.size) {
            int minIndex = k;
            if (2 * k <= this.size && this.heap[2 * k] < this.heap[minIndex]) {
                minIndex = 2 * k;
            }
            if (2 * k + 1 <= this.size && this.heap[2 * k + 1] < this.heap[minIndex]) {
                minIndex = 2 * k + 1;
            }
            if (minIndex == k) {
                break;
            }
            int temp = this.heap[k];
            this.heap[k] = this.heap[minIndex];
            this.heap[minIndex] = temp;
            k = minIndex;
        }
    }

    // Method to delete and return the minimum element from the heap
    public int delete() {
        if (isEmpty()) { // Check if the heap is empty
            throw new IllegalStateException("Heap is empty. Cannot delete.");
        }
        int min = this.heap[1]; // The minimum element is at the root
        this.heap[1] = this.heap[this.size]; // Replace the root with the last element
        this.size--; // Decrement the size of the heap
        this.sink(); // Maintain the heap property
        return min;
    }

    // Main method to handle user input and interact with the heap
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int capacity = scanner.nextInt();
        Main queue = new Main(capacity);
        while (scanner.hasNext()) {
            String command = scanner.next();
            try {
                switch (command) {
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
        scanner.close();
    }
}
