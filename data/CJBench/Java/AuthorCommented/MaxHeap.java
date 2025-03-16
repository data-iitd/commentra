
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * A Max Heap implementation where each node's key is higher than or equal to its children's keys.
 * This data structure provides O(log n) time complexity for insertion and deletion operations,
 * and O(1) for retrieving the maximum element.
 *
 * Properties:
 * 1. Complete Binary Tree
 * 2. Parent node's key ≥ Children nodes' keys
 * 3. Root contains the maximum element
 *
 * Example usage:
 * <pre>
 * List<HeapElement> elements = Arrays.asList(
 *     new HeapElement(5, "Five"),
 *     new HeapElement(2, "Two")
 * );
 * MaxHeap heap = new MaxHeap(elements);
 * heap.insertElement(new HeapElement(7, "Seven"));
 * HeapElement max = heap.getElement(); // Returns and removes the maximum element
 * </pre>
 *
 * @author Nicolas Renard
 */
public class MaxHeap {

    /** The internal list that stores heap elements */
    private final List<HeapElement> maxHeap;

    public MaxHeap() {
        maxHeap = new ArrayList<>();
    }

    /**
     * Maintains heap properties by moving an element down the heap.
     * Similar to toggleDown but used specifically during initialization.
     *
     * @param elementIndex 1-based index of the element to heapify
     */
    private void heapifyDown(int elementIndex) {
        int largest = elementIndex - 1;
        int leftChild = 2 * elementIndex - 1;
        int rightChild = 2 * elementIndex;

        if (leftChild < maxHeap.size() && maxHeap.get(leftChild).getKey() > maxHeap.get(largest).getKey()) {
            largest = leftChild;
        }

        if (rightChild < maxHeap.size() && maxHeap.get(rightChild).getKey() > maxHeap.get(largest).getKey()) {
            largest = rightChild;
        }

        if (largest != elementIndex - 1) {
            HeapElement temp = maxHeap.get(elementIndex - 1);
            maxHeap.set(elementIndex - 1, maxHeap.get(largest));
            maxHeap.set(largest, temp);

            heapifyDown(largest + 1);
        }
    }

    /**
     * Moves an element up the heap until heap properties are satisfied.
     * This operation is called after insertion to maintain heap properties.
     *
     * @param elementIndex 1-based index of the element to move up
     */
    private void toggleUp(int elementIndex) {
        double key = maxHeap.get(elementIndex - 1).getKey();
        while (elementIndex > 1 && maxHeap.get((elementIndex / 2) - 1).getKey() < key) {
            HeapElement temp = maxHeap.get(elementIndex - 1);
            maxHeap.set(elementIndex - 1, maxHeap.get((elementIndex / 2) - 1));
            maxHeap.set((elementIndex / 2) - 1, temp);

            elementIndex /= 2;
        }
    }

    /**
     * {@inheritDoc}
     */
    public void insertElement(HeapElement element) {
        if (element == null) {
            throw new IllegalArgumentException("Cannot insert null element");
        }
        maxHeap.add(element);
        toggleUp(maxHeap.size());
    }

    public HeapElement extractMax() {
        if (maxHeap.isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }

        HeapElement max = maxHeap.get(0);
        maxHeap.set(0, maxHeap.get(maxHeap.size() - 1));
        maxHeap.remove(maxHeap.size() - 1);

        if (!maxHeap.isEmpty()) {
            heapifyDown(1);
        }

        return max;
    }

    public HeapElement getMax() {
        if (maxHeap.isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }
        return maxHeap.get(0);
    }

    /**
     * Returns the current size of the heap.
     *
     * @return number of elements in the heap
     */
    public int size() {
        return maxHeap.size();
    }

    /**
     * Checks if the heap is empty.
     *
     * @return true if the heap contains no elements
     */
    public boolean isEmpty() {
        return maxHeap.isEmpty();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        MaxHeap heap = new MaxHeap();

        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.isEmpty()) break;

            String[] parts = command.split(" ");
            String operation = parts[0];

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
