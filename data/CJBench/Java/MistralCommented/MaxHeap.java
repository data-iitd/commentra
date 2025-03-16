
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Initialize an empty max heap using an ArrayList
    private final List<HeapElement> maxHeap;

    public Main() {
        maxHeap = new ArrayList<>();
    }

    // Helper method to maintain heap property by swapping elements if condition is met
    private void heapifyDown(int elementIndex) {
        int largest = elementIndex - 1;
        int leftChild = 2 * elementIndex - 1;
        int rightChild = 2 * elementIndex;

        // Find the index of the largest element among the current node, its left and right children
        if (leftChild < maxHeap.size() && maxHeap.get(leftChild).getKey() > maxHeap.get(largest).getKey()) {
            largest = leftChild;
        }
        if (rightChild < maxHeap.size() && maxHeap.get(rightChild).getKey() > maxHeap.get(largest).getKey()) {
            largest = rightChild;
        }

        // Swap elements if the largest element is not the current node
        if (largest != elementIndex - 1) {
            HeapElement temp = maxHeap.get(elementIndex - 1);
            maxHeap.set(elementIndex - 1, maxHeap.get(largest));
            maxHeap.set(largest, temp);
            // Recursively call heapifyDown for the new largest node
            heapifyDown(largest + 1);
        }
    }

    // Helper method to move an element up in the heap until it reaches its correct position
    private void toggleUp(int elementIndex) {
        double key = maxHeap.get(elementIndex - 1).getKey();
        int parentIndex = (elementIndex / 2) - 1;

        // Continue swapping parent and child nodes until the current node is in its correct position
        while (elementIndex > 1 && maxHeap.get(parentIndex).getKey() < key) {
            HeapElement temp = maxHeap.get(elementIndex - 1);
            maxHeap.set(elementIndex - 1, maxHeap.get(parentIndex));
            maxHeap.set(parentIndex, temp);
            elementIndex /= 2;
            parentIndex = (elementIndex / 2) - 1;
        }
    }

    // Method to insert a new HeapElement into the max heap
    public void insertElement(HeapElement element) {
        if (element == null) {
            throw new IllegalArgumentException("Cannot insert null element");
        }
        // Add the new element to the max heap
        maxHeap.add(element);
        // Call toggleUp method to move the new element to its correct position in the heap
        toggleUp(maxHeap.size());
    }

    // Method to extract and return the maximum HeapElement from the max heap
    public HeapElement extractMax() {
        if (maxHeap.isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }
        // Store the maximum HeapElement in a variable
        HeapElement max = maxHeap.get(0);
        // Replace the root node with the last node in the max heap and remove the last node
        maxHeap.set(0, maxHeap.get(maxHeap.size() - 1));
        maxHeap.remove(maxHeap.size() - 1);
        // Call heapifyDown method to maintain heap property after extracting the maximum element
        heapifyDown(1);
        // Return the extracted maximum HeapElement
        return max;
    }

    // Method to return the maximum HeapElement without extracting it from the max heap
    public HeapElement getMax() {
        if (maxHeap.isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }
        // Return the maximum HeapElement stored at the root node
        return maxHeap.get(0);
    }

    // Method to return the size of the max heap
    public int size() {
        return maxHeap.size();
    }

    // Method to check if the max heap is empty
    public boolean isEmpty() {
        return maxHeap.isEmpty();
    }

    // Main method to read user input and perform the corresponding heap operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main heap = new Main();
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.isEmpty()) break;
            String[] parts = command.split(" ");
            String operation = parts[0];

            // Perform the specified heap operation based on the user input
            try {
                switch (operation) {
                    case "insert":
                        double key = Double.parseDouble(parts[1]);
                        String info = parts.length > 2 ? parts[2] : null;
                        heap.insertElement(new HeapElement(key, info));
                        System.out.println("Inserted: " + key);
                        break;
                    case "extractMax":
                        System.out.println("Extracted Max: " + heap.extractMax());
                        break;
                    case "getMax":
                        System.out.println("Max Element: " + heap.getMax());
                        break;
                    case "size":
                        System.out.println("Size: " + heap.size());
                        break;
                    case "isEmpty":
                        System.out.println("Is Empty: " + heap.isEmpty());
                        break;
                    default:
                        System.out.println("Unknown operation: " + operation);
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close();
    }
}

