import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // List to store the elements of the max heap
    private final List<HeapElement> maxHeap;

    // Constructor to initialize the max heap
    public Main() {
        maxHeap = new ArrayList<>();
    }

    // Method to maintain the heap property by moving an element down the heap
    private void heapifyDown(int elementIndex) {
        int largest = elementIndex - 1; // Index of the current element
        int leftChild = 2 * elementIndex - 1; // Index of the left child
        int rightChild = 2 * elementIndex; // Index of the right child

        // Check if the left child exists and is greater than the current largest
        if (leftChild < maxHeap.size() && maxHeap.get(leftChild).getKey() > maxHeap.get(largest).getKey()) {
            largest = leftChild; // Update largest to left child
        }

        // Check if the right child exists and is greater than the current largest
        if (rightChild < maxHeap.size() && maxHeap.get(rightChild).getKey() > maxHeap.get(largest).getKey()) {
            largest = rightChild; // Update largest to right child
        }

        // If the largest is not the current element, swap and continue heapifying down
        if (largest != elementIndex - 1) {
            HeapElement temp = maxHeap.get(elementIndex - 1);
            maxHeap.set(elementIndex - 1, maxHeap.get(largest));
            maxHeap.set(largest, temp);
            heapifyDown(largest + 1); // Recursively heapify down
        }
    }

    // Method to maintain the heap property by moving an element up the heap
    private void toggleUp(int elementIndex) {
        double key = maxHeap.get(elementIndex - 1).getKey(); // Get the key of the element to be moved up
        // Move the element up while it is greater than its parent
        while (elementIndex > 1 && maxHeap.get((elementIndex / 2) - 1).getKey() < key) {
            HeapElement temp = maxHeap.get(elementIndex - 1);
            maxHeap.set(elementIndex - 1, maxHeap.get((elementIndex / 2) - 1));
            maxHeap.set((elementIndex / 2) - 1, temp);
            elementIndex /= 2; // Move to the parent's index
        }
    }

    // Method to insert a new element into the max heap
    public void insertElement(HeapElement element) {
        if (element == null) {
            throw new IllegalArgumentException("Cannot insert null element"); // Validate input
        }
        maxHeap.add(element); // Add the new element to the heap
        toggleUp(maxHeap.size()); // Restore heap property by moving the new element up
    }

    // Method to extract the maximum element from the max heap
    public HeapElement extractMax() {
        if (maxHeap.isEmpty()) {
            throw new IllegalStateException("Heap is empty"); // Validate heap is not empty
        }
        HeapElement max = maxHeap.get(0); // Get the maximum element
        maxHeap.set(0, maxHeap.get(maxHeap.size() - 1)); // Replace max with the last element
        maxHeap.remove(maxHeap.size() - 1); // Remove the last element
        if (!maxHeap.isEmpty()) {
            heapifyDown(1); // Restore heap property by moving down the new root
        }
        return max; // Return the extracted maximum element
    }

    // Method to get the maximum element without removing it
    public HeapElement getMax() {
        if (maxHeap.isEmpty()) {
            throw new IllegalStateException("Heap is empty"); // Validate heap is not empty
        }
        return maxHeap.get(0); // Return the maximum element
    }

    // Method to get the size of the heap
    public int size() {
        return maxHeap.size(); // Return the number of elements in the heap
    }

    // Method to check if the heap is empty
    public boolean isEmpty() {
        return maxHeap.isEmpty(); // Return true if the heap is empty
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        Main heap = new Main(); // Create a new instance of the heap

        // Loop to process user commands
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read the command
            if (command.isEmpty()) break; // Exit on empty command
            String[] parts = command.split(" "); // Split command into parts
            String operation = parts[0]; // Get the operation type

            try {
                // Switch case to handle different heap operations
                switch (operation) {
                    case "insert":
                        double key = Double.parseDouble(parts[1]); // Parse the key
                        String info = parts.length > 2 ? parts[2] : null; // Optional info
                        heap.insertElement(new HeapElement(key, info)); // Insert the new element
                        System.out.println("Inserted: " + key); // Confirm insertion
                        break;
                    case "extractMax":
                        System.out.println("Extracted Max: " + heap.extractMax()); // Extract and display max
                        break;
                    case "getMax":
                        System.out.println("Max Element: " + heap.getMax()); // Display max without extraction
                        break;
                    case "size":
                        System.out.println("Size: " + heap.size()); // Display the size of the heap
                        break;
                    case "isEmpty":
                        System.out.println("Is Empty: " + heap.isEmpty()); // Check if the heap is empty
                        break;
                    default:
                        System.out.println("Unknown operation: " + operation); // Handle unknown commands
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage()); // Handle exceptions
            }
        }
        scanner.close(); // Close the scanner
    }
}
