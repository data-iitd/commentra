
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class MaxHeap {
    private final List<HeapElement> maxHeap;
    public MaxHeap() {
        maxHeap = new ArrayList<>();
    }
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
    private void toggleUp(int elementIndex) {
        double key = maxHeap.get(elementIndex - 1).getKey();
        while (elementIndex > 1 && maxHeap.get((elementIndex / 2) - 1).getKey() < key) {
            HeapElement temp = maxHeap.get(elementIndex - 1);
            maxHeap.set(elementIndex - 1, maxHeap.get((elementIndex / 2) - 1));
            maxHeap.set((elementIndex / 2) - 1, temp);
            elementIndex /= 2;
        }
    }
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
    public int size() {
        return maxHeap.size();
    }
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
