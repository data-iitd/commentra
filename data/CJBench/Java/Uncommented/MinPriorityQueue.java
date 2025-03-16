
import java.util.Scanner;
public class MinPriorityQueue {
    private final int[] heap;
    private final int capacity;
    private int size;
    public MinPriorityQueue(int c) {
        this.capacity = c;
        this.size = 0;
        this.heap = new int[c + 1];
    }
    public void insert(int key) {
        if (this.isFull()) {
            throw new IllegalStateException("MinPriorityQueue is full. Cannot insert new element.");
        }
        this.heap[this.size + 1] = key;
        int k = this.size + 1;
        while (k > 1) {
            if (this.heap[k] < this.heap[k / 2]) {
                int temp = this.heap[k];
                this.heap[k] = this.heap[k / 2];
                this.heap[k / 2] = temp;
            }
            k = k / 2;
        }
        this.size++;
    }
    public int peek() {
        if (isEmpty()) {
            throw new IllegalStateException("MinPriorityQueue is empty. Cannot peek.");
        }
        return this.heap[1];
    }
    public boolean isEmpty() {
        return size == 0;
    }
    public boolean isFull() {
        return size == capacity;
    }
    public void print() {
        for (int i = 1; i <= this.size; i++) {
            System.out.print(this.heap[i] + " ");
        }
        System.out.println();
    }
    public void heapSort() {
        for (int i = 1; i <= this.size; i++) {
            this.delete();
        }
    }
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
    public int delete() {
        if (isEmpty()) {
            throw new IllegalStateException("MinPriorityQueue is empty. Cannot delete.");
        }
        int min = this.heap[1];
        this.heap[1] = this.heap[this.size];
        this.size--;
        this.sink();
        return min;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the capacity of the MinPriorityQueue:");
        int capacity = scanner.nextInt();
        MinPriorityQueue queue = new MinPriorityQueue(capacity);
        System.out.println("Enter commands (insert <value>, delete, peek, print, isEmpty):");
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
