import java.util.Scanner;
public final class Main<T> {
    private static final int DEFAULT_CAPACITY = 10;
    private final int maxSize;
    private final Object[] queueArray;
    private int front;
    private int rear;
    private int nItems;

    // Constructor without parameters initializes the queue with the default capacity.
    public Main() {
        this(DEFAULT_CAPACITY);
    }

    // Constructor with a specified capacity initializes the queue with the given capacity.
    public Main(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Main capacity must be greater than 0");
        }
        this.maxSize = capacity;
        this.queueArray = new Object[capacity];
        this.front = 0;
        this.rear = -1;
        this.nItems = 0;
    }

    // Inserts an element into the rear of the queue if there's space.
    public boolean insert(T element) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % maxSize;
        queueArray[rear] = element;
        nItems++;
        return true;
    }

    // Removes and returns the element from the front of the queue.
    @SuppressWarnings("unchecked")
    public T remove() {
        if (isEmpty()) {
            throw new IllegalStateException("Main is empty, cannot remove element");
        }
        T removedElement = (T) queueArray[front];
        queueArray[front] = null;
        front = (front + 1) % maxSize;
        nItems--;
        return removedElement;
    }

    // Returns the front element without removing it.
    @SuppressWarnings("unchecked")
    public T peekFront() {
        if (isEmpty()) {
            throw new IllegalStateException("Main is empty, cannot peek front");
        }
        return (T) queueArray[front];
    }

    // Returns the rear element without removing it.
    @SuppressWarnings("unchecked")
    public T peekRear() {
        if (isEmpty()) {
            throw new IllegalStateException("Main is empty, cannot peek rear");
        }
        return (T) queueArray[rear];
    }

    // Checks if the queue is empty.
    public boolean isEmpty() {
        return nItems == 0;
    }

    // Checks if the queue is full.
    public boolean isFull() {
        return nItems == maxSize;
    }

    // Returns the number of elements in the queue.
    public int getSize() {
        return nItems;
    }

    // Provides a string representation of the queue.
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

    // Main method for user interaction.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        Main<Integer> queue = new Main<>(size);
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
                            System.out.println("Main is full");
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
                        System.out.println("Main: " + queue);
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
