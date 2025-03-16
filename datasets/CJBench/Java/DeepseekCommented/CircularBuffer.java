import java.util.Scanner;
public class Main {
    private final Item[] buffer;
    private final CircularPointer putPointer;
    private final CircularPointer getPointer;
    private int size;
    public Main(int size) {
        if (size <= 0) {
            throw new IllegalArgumentException("Buffer size must be positive");
        }
        this.buffer = (Item[]) new Object[size];
        this.putPointer = new CircularPointer(0, size);
        this.getPointer = new CircularPointer(0, size);
        this.size = 0;
    }
    // Checks if the buffer is empty
    public boolean isEmpty() {
        return size == 0;
    }
    // Checks if the buffer is full
    public boolean isFull() {
        return size == buffer.length;
    }
    // Retrieves an item from the buffer
    public Item get() {
        if (isEmpty()) {
            return null;
        }
        Item item = buffer[getPointer.getAndIncrement()];
        size--;
        return item;
    }
    // Adds an item to the buffer
    public boolean put(Item item) {
        if (item == null) {
            throw new IllegalArgumentException("Null items are not allowed");
        }
        if (isFull()) {
            getPointer.getAndIncrement(); 
        } else {
            size++;
        }
        buffer[putPointer.getAndIncrement()] = item;
        return true;
    }
    private static class CircularPointer {
        private int pointer;
        private final int max;
        CircularPointer(int pointer, int max) {
            this.pointer = pointer;
            this.max = max;
        }
        // Increments the pointer and returns the old value
        public int getAndIncrement() {
            int tmp = pointer;
            pointer = (pointer + 1) % max;
            return tmp;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int bufferSize = scanner.nextInt();
        int numberOfOperations = scanner.nextInt();
        Main<String> buffer = new Main<>(bufferSize);
        for (int i = 0; i < numberOfOperations; i++) {
            String operation = scanner.next();
            if (operation.equals("PUT")) {
                String element = scanner.next();
                buffer.put(element);
                System.out.println("Added: " + element);
            } else if (operation.equals("GET")) {
                String result = buffer.get();
                System.out.println("Retrieved: " + (result != null ? result : "null"));
            } else if (operation.equals("ISEMPTY")) {
                System.out.println("Is Empty: " + buffer.isEmpty());
            } else if (operation.equals("ISFULL")) {
                System.out.println("Is Full: " + buffer.isFull());
            }
        }
        scanner.close();
    }
}
