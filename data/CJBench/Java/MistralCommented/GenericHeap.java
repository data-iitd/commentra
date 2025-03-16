
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    // Declare a private ArrayList to store the data in the heap
    private final ArrayList<T> data = new ArrayList<>();
    
    // Declare a private HashMap to maintain the mapping between the data and their indices
    private final HashMap<T, Integer> map = new HashMap<>();
    
    // Add method to insert an item into the heap
    public void add(T item) {
        if (item == null) { // Check if the item is null
            throw new IllegalArgumentException("Cannot insert null into the heap."); // Throw an exception if it is
        }
        // Add the item to the data list
        this.data.add(item);
        // Add the mapping of the item to its index in the data list
        map.put(item, this.data.size() - 1);
        // Call upHeapify method to maintain the heap property after insertion
        upHeapify(this.data.size() - 1);
    }
    
    // upHeapify method to maintain the heap property after insertion or deletion
    private void upHeapify(int ci) {
        int pi = (ci - 1) / 2; // Calculate the index of the parent node
        // Check if the current node is the root node or its parent node is larger
        if (ci > 0 && isLarger(this.data.get(ci), this.data.get(pi)) > 0) {
            // Swap the current node with its parent node if the condition is true
            swap(pi, ci);
            // Recursively call upHeapify method for the parent node
            upHeapify(pi);
        }
    }
    
    // Get the size of the heap
    public int size() {
        return this.data.size();
    }
    
    // Check if the heap is empty
    public boolean isEmpty() {
        return this.size() == 0;
    }
    
    // Remove the maximum element from the heap
    public T remove() {
        if (isEmpty()) { // Check if the heap is empty
            throw new IllegalStateException("Heap is empty"); // Throw an exception if it is
        }
        // Swap the first and last elements
        swap(0, this.size() - 1);
        // Remove the last element from the data list
        T rv = this.data.remove(this.size() - 1);
        // Remove the mapping of the removed element from the HashMap
        map.remove(rv);
        // Call downHeapify method to maintain the heap property after deletion
        downHeapify(0);
        // Return the removed element
        return rv;
    }
    
    // downHeapify method to maintain the heap property after deletion
    private void downHeapify(int pi) {
        int lci = 2 * pi + 1; // Calculate the indices of the left and right child nodes
        int rci = 2 * pi + 2;
        int maxi = pi; // Initialize the index of the maximum node as the parent node index
        // Check if the left child node exists and is larger than the parent node
        if (lci < this.size() && isLarger(this.data.get(lci), this.data.get(maxi)) > 0) {
            maxi = lci; // Update the index of the maximum node if the condition is true
        }
        // Check if the right child node exists and is larger than the parent node
        if (rci < this.size() && isLarger(this.data.get(rci), this.data.get(maxi)) > 0) {
            maxi = rci; // Update the index of the maximum node if the condition is true
        }
        // Swap the parent node with the maximum node if they are not the same
        if (maxi != pi) {
            swap(pi, maxi);
            // Recursively call downHeapify method for the maximum node
            downHeapify(maxi);
        }
    }
    
    // Get the maximum element from the heap
    public T get() {
        if (isEmpty()) { // Check if the heap is empty
            throw new IllegalStateException("Heap is empty"); // Throw an exception if it is
        }
        // Return the maximum element from the data list
        return this.data.get(0);
    }
    
    // Compare two elements to determine which one is larger
    private int isLarger(T t, T o) {
        return t.compareTo(o);
    }
    
    // Swap two elements in the data list and in the HashMap
    private void swap(int i, int j) {
        T ith = this.data.get(i);
        T jth = this.data.get(j);
        // Swap the elements in the data list
        this.data.set(i, jth);
        this.data.set(j, ith);
        // Update the mapping of the swapped elements in the HashMap
        map.put(ith, j);
        map.put(jth, i);
    }
    
    // Main method to read user input and perform the required operations on the heap
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main<Integer> heap = new Main<>(); // Create an instance of the Main class for an integer heap
        int operations = scanner.nextInt(); // Read the number of operations from the user
        for (int i = 0; i < operations; i++) {
            int choice = scanner.nextInt(); // Read the choice of operation from the user
            switch (choice) {
                case 1:
                    int element = scanner.nextInt(); // Read the element to be added from the user
                    heap.add(element); // Add the element to the heap
                    System.out.println("Added: " + element); // Print a message to confirm the addition
                    break;
                case 2:
                    try {
                        System.out.println("Removed: " + heap.remove()); // Remove the maximum element from the heap and print a message to confirm the removal
                    } catch (IllegalStateException e) {
                        System.out.println("Heap is empty."); // Print a message if the heap is empty and an exception is thrown
                    }
                    break;
                case 3:
                    try {
                        System.out.println("Max element: " + heap.get()); // Get the maximum element from the heap and print it
                    } catch (IllegalStateException e) {
                        System.out.println("Heap is empty."); // Print a message if the heap is empty and an exception is thrown
                    }
                    break;
                case 4:
                    System.out.println("Heap size: " + heap.size()); // Print the size of the heap
                    break;
                case 5:
                    System.out.println("Heap is empty: " + heap.isEmpty()); // Print a message to confirm if the heap is empty or not
                    break;
                default:
                    System.out.println("Invalid operation."); // Print a message for an invalid choice of operation
            }
        }
        scanner.close(); // Close the scanner after the operations are completed
    }
}