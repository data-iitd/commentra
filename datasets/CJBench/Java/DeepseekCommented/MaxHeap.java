import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private final List<HeapElement> maxHeap; // 1. Class Initialization: The `Main` class initializes a `List<HeapElement>` called `maxHeap` and provides a constructor to initialize it.

    public Main() {
        maxHeap = new ArrayList<>();
    }

    private void heapifyDown(int elementIndex) { // 2. Heapify Down: The `heapifyDown` method adjusts the heap structure after extracting the maximum element.
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

    private void toggleUp(int elementIndex) { // 3. Toggle Up: The `toggleUp` method adjusts the heap structure after inserting a new element.
        double key = maxHeap.get(elementIndex - 1).getKey();
        while (elementIndex > 1 && maxHeap.get((elementIndex / 2) - 1).getKey() < key) {
            HeapElement temp = maxHeap.get(elementIndex - 1);
            maxHeap.set(elementIndex - 1, maxHeap.get((elementIndex / 2) - 1));
            maxHeap.set((elementIndex / 2) - 1, temp);
            elementIndex /= 2;
        }
    }

    public void insertElement(HeapElement element) { // 4. Insert Element: The `insertElement` method adds a new element to the heap and adjusts the heap structure.
        if (element == null) {
            throw new IllegalArgumentException("Cannot insert null element");
        }
        maxHeap.add(element);
        toggleUp(maxHeap.size());
    }

    public HeapElement extractMax() { // 5. Extract Maximum: The `extractMax` method removes and returns the maximum element from the heap.
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

    public HeapElement getMax() { // 6. Get Maximum: The `getMax` method returns the maximum element without removing it.
        if (maxHeap.isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }
        return maxHeap.get(0);
    }

    public int size() { // 7. Size and Empty Check: The `size` and `isEmpty` methods provide the current size of the heap and check if the heap is empty, respectively.
        return maxHeap.size();
    }

    public boolean isEmpty() {
        return maxHeap.isEmpty();
    }

    public static void main(String[] args) { // 8. Main Method: The `main` method handles user input to perform operations on the heap.
        Scanner scanner = new Scanner(System.in);
        Main heap = new Main();
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
