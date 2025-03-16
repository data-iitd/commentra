import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    // List to store the heap elements
    private final ArrayList<T> data = new ArrayList<>();
    // Map to store the index of each element for quick access
    private final HashMap<T, Integer> map = new HashMap<>();

    // Method to add an item to the heap
    public void add(T item) {
        // Validate that the item is not null
        if (item == null) {
            throw new IllegalArgumentException("Cannot insert null into the heap.");
        }
        // Add the item to the data list
        this.data.add(item);
        // Update the map with the index of the newly added item
        map.put(item, this.data.size() - 1);
        // Restore the heap property by moving the item up the heap
        upHeapify(this.data.size() - 1);
    }

    // Method to restore the heap property by moving the item at index ci up
    private void upHeapify(int ci) {
        int pi = (ci - 1) / 2; // Calculate the parent's index
        // If the current item is larger than its parent, swap them
        if (ci > 0 && isLarger(this.data.get(ci), this.data.get(pi)) > 0) {
            swap(pi, ci);
            // Continue upHeapifying from the parent's index
            upHeapify(pi);
        }
    }

    // Method to get the current size of the heap
    public int size() {
        return this.data.size();
    }

    // Method to check if the heap is empty
    public boolean isEmpty() {
        return this.size() == 0;
    }

    // Method to remove and return the maximum item from the heap
    public T remove() {
        // Check if the heap is empty before removing
        if (isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }
        // Swap the root with the last element
        swap(0, this.size() - 1);
        // Remove the last element (which is the maximum)
        T rv = this.data.remove(this.size() - 1);
        // Remove the element from the map
        map.remove(rv);
        // Restore the heap property by moving the new root down
        downHeapify(0);
        return rv;
    }

    // Method to restore the heap property by moving the item at index pi down
    private void downHeapify(int pi) {
        int lci = 2 * pi + 1; // Left child index
        int rci = 2 * pi + 2; // Right child index
        int maxi = pi; // Assume the current index is the largest
        // Check if the left child is larger than the current maximum
        if (lci < this.size() && isLarger(this.data.get(lci), this.data.get(maxi)) > 0) {
            maxi = lci;
        }
        // Check if the right child is larger than the current maximum
        if (rci < this.size() && isLarger(this.data.get(rci), this.data.get(maxi)) > 0) {
            maxi = rci;
        }
        // If the maximum is not the current index, swap and continue downHeapifying
        if (maxi != pi) {
            swap(pi, maxi);
            downHeapify(maxi);
        }
    }

    // Method to get the maximum element from the heap without removing it
    public T get() {
        // Check if the heap is empty before accessing the maximum
        if (isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }
        return this.data.get(0); // Return the root of the heap
    }

    // Method to compare two elements
    private int isLarger(T t, T o) {
        return t.compareTo(o); // Compare using the natural ordering
    }

    // Method to swap two elements in the heap and update their indices in the map
    private void swap(int i, int j) {
        T ith = this.data.get(i);
        T jth = this.data.get(j);
        this.data.set(i, jth); // Swap in the data list
        this.data.set(j, ith);
        // Update the indices in the map
        map.put(ith, j);
        map.put(jth, i);
    }

    // Main method to run the heap operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main<Integer> heap = new Main<>(); // Create a new heap instance
        int operations = scanner.nextInt(); // Read the number of operations
        // Loop through the number of operations
        for (int i = 0; i < operations; i++) {
            int choice = scanner.nextInt(); // Read the operation choice
            switch (choice) {
                case 1: // Add an element to the heap
                    int element = scanner.nextInt();
                    heap.add(element);
                    System.out.println("Added: " + element);
                    break;
                case 2: // Remove the maximum element from the heap
                    try {
                        System.out.println("Removed: " + heap.remove());
                    } catch (IllegalStateException e) {
                        System.out.println("Heap is empty.");
                    }
                    break;
                case 3: // Get the maximum element from the heap
                    try {
                        System.out.println("Max element: " + heap.get());
                    } catch (IllegalStateException e) {
                        System.out.println("Heap is empty.");
                    }
                    break;
                case 4: // Get the size of the heap
                    System.out.println("Heap size: " + heap.size());
                    break;
                case 5: // Check if the heap is empty
                    System.out.println("Heap is empty: " + heap.isEmpty());
                    break;
                default: // Handle invalid operation choices
                    System.out.println("Invalid operation.");
            }
        }
        scanner.close(); // Close the scanner to free resources
    }
}
