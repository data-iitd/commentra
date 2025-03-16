import java.util.Scanner;
public final class Queue<T> {
    private static final int DEFAULT_CAPACITY = 10;
    private final int maxSize;
    private final Object[] queueArray;
    private int front;
    private int rear;
    private int nItems;
    public Queue() {
        this(DEFAULT_CAPACITY);
    }
    public Queue(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Queue capacity must be greater than 0");
        }
        this.maxSize = capacity;
        this.queueArray = new Object[capacity];
        this.front = 0;
        this.rear = -1;
        this.nItems = 0;
    }
    public boolean insert(T element) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % maxSize;
        queueArray[rear] = element;
        nItems++;
        return true;
    }
    @SuppressWarnings("unchecked")
    public T remove() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty, cannot remove element");
        }
        T removedElement = (T) queueArray[front];
        queueArray[front] = null;
        front = (front + 1) % maxSize;
        nItems--;
        return removedElement;
    }
    @SuppressWarnings("unchecked")
    public T peekFront() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty, cannot peek front");
        }
        return (T) queueArray[front];
    }
    @SuppressWarnings("unchecked")
    public T peekRear() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty, cannot peek rear");
        }
        return (T) queueArray[rear];
    }
    public boolean isEmpty() {
        return nItems == 0;
    }
    public boolean isFull() {
        return nItems == maxSize;
    }
    public int getSize() {
        return nItems;
    }
    @Override
    public String toString() {
        if (isEmpty()) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < nItems; i++) {
            int index = (front + i) % maxSize;
            sb.append(queueArray[index]).append(", ");
        }
        sb.setLength(sb.length() - 2);
        sb.append("]");
        return sb.toString();
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the queue: ");
        int size = scanner.nextInt();
        Queue<Integer> queue = new Queue<>(size);
        System.out.println("Enter commands (insert <value>, remove, peekFront, peekRear, getSize, isEmpty, print, exit):");
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.equalsIgnoreCase("exit")) {
                break;
            }
            try {
                String[] parts = command.split(" ");
                switch (parts[0]) {
                    case "insert":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for insert");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]);
                        if (queue.insert(value)) {
                            System.out.println("Inserted: " + value);
                        } else {
                            System.out.println("Queue is full");
                        }
                        break;
                    case "remove":
                        System.out.println("Removed: " + queue.remove());
                        break;
                    case "peekFront":
                        System.out.println("Front: " + queue.peekFront());
                        break;
                    case "peekRear":
                        System.out.println("Rear: " + queue.peekRear());
                        break;
                    case "getSize":
                        System.out.println("Size: " + queue.getSize());
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + queue.isEmpty());
                        break;
                    case "print":
                        System.out.println("Queue: " + queue);
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
