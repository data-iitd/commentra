import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
public class Main {
    private final ArrayList<T> data = new ArrayList<>(); // ArrayList to store heap elements
    private final HashMap<T, Integer> map = new HashMap<>(); // HashMap to quickly find element index
    public void add(T item) {
        if (item == null) {
            throw new IllegalArgumentException("Cannot insert null into the heap."); // Check for null insertion
        }
        this.data.add(item); // Add item to the heap
        map.put(item, this.data.size() - 1); // Update the map with the item's index
        upHeapify(this.data.size() - 1); // Maintain heap property by moving the item up
    }
    private void upHeapify(int ci) {
        int pi = (ci - 1) / 2; // Calculate parent index
        if (ci > 0 && isLarger(this.data.get(ci), this.data.get(pi)) > 0) { // Compare with parent
            swap(pi, ci); // Swap if necessary
            upHeapify(pi); // Recursively call upHeapify
        }
    }
    public int size() {
        return this.data.size(); // Return the number of elements in the heap
    }
    public boolean isEmpty() {
        return this.size() == 0; // Check if the heap is empty
    }
    public T remove() {
        if (isEmpty()) {
            throw new IllegalStateException("Heap is empty"); // Check if heap is empty
        }
        swap(0, this.size() - 1); // Swap root with last element
        T rv = this.data.remove(this.size() - 1); // Remove last element
        map.remove(rv); // Remove from map
        downHeapify(0); // Maintain heap property by moving the new root down
        return rv; // Return the removed element
    }
    private void downHeapify(int pi) {
        int lci = 2 * pi + 1; // Calculate left child index
        int rci = 2 * pi + 2; // Calculate right child index
        int maxi = pi; // Assume parent is largest
        if (lci < this.size() && isLarger(this.data.get(lci), this.data.get(maxi)) > 0) { // Compare with left child
            maxi = lci; // Update largest index
        }
        if (rci < this.size() && isLarger(this.data.get(rci), this.data.get(maxi)) > 0) { // Compare with right child
            maxi = rci; // Update largest index
        }
        if (maxi != pi) {
            swap(pi, maxi); // Swap if necessary
            downHeapify(maxi); // Recursively call downHeapify
        }
    }
    public T get() {
        if (isEmpty()) {
            throw new IllegalStateException("Heap is empty"); // Check if heap is empty
        }
        return this.data.get(0); // Return the root element
    }
    private int isLarger(T t, T o) {
        return t.compareTo(o); // Compare two elements
    }
    private void swap(int i, int j) {
        T ith = this.data.get(i);
        T jth = this.data.get(j);
        this.data.set(i, jth); // Swap elements in data list
        this.data.set(j, ith);
        map.put(ith, j); // Update map with new indices
        map.put(jth, i);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main<Integer> heap = new Main<>();
        int operations = scanner.nextInt();
        for (int i = 0; i < operations; i++) {
            int choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    int element = scanner.nextInt();
                    heap.add(element);
                    System.out.println("Added: " + element); // Print added element
                    break;
                case 2:
                    try {
                        System.out.println("Removed: " + heap.remove()); // Print removed element
                    } catch (IllegalStateException e) {
                        System.out.println("Heap is empty.");
                    }
                    break;
                case 3:
                    try {
                        System.out.println("Max element: " + heap.get()); // Print max element
                    } catch (IllegalStateException e) {
                        System.out.println("Heap is empty.");
                    }
                    break;
                case 4:
                    System.out.println("Heap size: " + heap.size()); // Print heap size
                    break;
                case 5:
                    System.out.println("Heap is empty: " + heap.isEmpty()); // Print if heap is empty
                    break;
                default:
                    System.out.println("Invalid operation.");
            }
        }
        scanner.close();
    }
}
