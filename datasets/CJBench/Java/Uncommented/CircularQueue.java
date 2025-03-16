
import java.util.Scanner;
public class CircularQueue<T> {
    private T[] array;
    private int topOfQueue;
    private int beginningOfQueue;
    private final int size;
    private int currentSize;
    @SuppressWarnings("unchecked")
    public CircularQueue(int size) {
        if (size < 1) {
            throw new IllegalArgumentException("Size must be greater than 0");
        }
        this.array = (T[]) new Object[size];
        this.topOfQueue = -1;
        this.beginningOfQueue = -1;
        this.size = size;
        this.currentSize = 0;
    }
    public boolean isEmpty() {
        return currentSize == 0;
    }
    public boolean isFull() {
        return currentSize == size;
    }
    public void enQueue(T value) {
        if (isFull()) {
            throw new IllegalStateException("Queue is full");
        }
        if (isEmpty()) {
            beginningOfQueue = 0;
        }
        topOfQueue = (topOfQueue + 1) % size;
        array[topOfQueue] = value;
        currentSize++;
    }
    public T deQueue() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        T removedValue = array[beginningOfQueue];
        array[beginningOfQueue] = null;
        beginningOfQueue = (beginningOfQueue + 1) % size;
        currentSize--;
        if (isEmpty()) {
            beginningOfQueue = -1;
            topOfQueue = -1;
        }
        return removedValue;
    }
    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        return array[beginningOfQueue];
    }
    public void deleteQueue() {
        array = null;
        beginningOfQueue = -1;
        topOfQueue = -1;
        currentSize = 0;
    }
    public int size() {
        return currentSize;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of the CircularQueue:");
        int queueSize = scanner.nextInt();
        scanner.nextLine(); 
        CircularQueue<Integer> queue = new CircularQueue<>(queueSize);
        System.out.println("Enter commands (enQueue <value>, deQueue, peek, isEmpty, isFull, size, exit):");
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.equalsIgnoreCase("exit")) {
                break;
            }
            try {
                String[] parts = command.split(" ");
                switch (parts[0]) {
                    case "enQueue":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for enQueue");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]);
                        queue.enQueue(value);
                        System.out.println("Enqueued: " + value);
                        break;
                    case "deQueue":
                        System.out.println("Dequeued: " + queue.deQueue());
                        break;
                    case "peek":
                        System.out.println("Front of queue: " + queue.peek());
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + queue.isEmpty());
                        break;
                    case "isFull":
                        System.out.println("Is full: " + queue.isFull());
                        break;
                    case "size":
                        System.out.println("Current size: " + queue.size());
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]);
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close();
    }
}
