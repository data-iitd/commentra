import java.util.Scanner;
public class Main {
    private int maxSize; // Maximum size of the queue
    private int[] queueArray; // Array to hold the queue elements
    private int nItems; // Number of items in the queue

    // Constructor to initialize the queue with a given size
    public Main(int size) {
        maxSize = size + 1; // Add 1 to accommodate 1-based indexing
        queueArray = new int[maxSize]; // Initialize the array
        nItems = 0; // No items initially
    }

    // Swim method to maintain the heap property by moving an item up
    private void swim(int pos) {
        while (pos > 1 && (queueArray[pos / 2] < queueArray[pos])) {
            int temp = queueArray[pos];
            queueArray[pos] = queueArray[pos / 2];
            queueArray[pos / 2] = temp;
            pos = pos / 2;
        }
    }

    // Sink method to maintain the heap property by moving an item down
    private void sink(int pos) {
        while (2 * pos <= nItems) {
            int current = 2 * pos;
            if (current < nItems && queueArray[current] < queueArray[current + 1]) {
                current++;
            }
            if (queueArray[pos] >= queueArray[current]) {
                break;
            }
            int temp = queueArray[pos];
            queueArray[pos] = queueArray[current];
            queueArray[current] = temp;
            pos = current;
        }
    }

    // Method to insert a new value into the priority queue
    public void insert(int value) {
        if (isFull()) {
            throw new RuntimeException("Queue is full");
        } else {
            queueArray[++nItems] = value; // Insert the value at the end and increment nItems
            swim(nItems); // Swim the value up to maintain heap property
        }
    }

    // Method to remove and return the maximum value from the priority queue
    public int remove() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is Empty");
        } else {
            int max = queueArray[1]; // Get the maximum value
            int temp = queueArray[1];
            queueArray[1] = queueArray[nItems]; // Replace the root with the last item
            queueArray[nItems] = temp;
            queueArray[nItems--] = 0; // Decrement nItems and clear the last position
            sink(1); // Sink the new root down to maintain heap property
            return max;
        }
    }

    // Method to return the maximum value without removing it
    public int peek() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is Empty");
        }
        return queueArray[1];
    }

    // Method to check if the queue is empty
    public boolean isEmpty() {
        return (nItems == 0);
    }

    // Method to check if the queue is full
    public boolean isFull() {
        return (nItems == maxSize - 1);
    }

    // Method to get the number of items in the queue
    public int getSize() {
        return nItems;
    }

    // Main method to allow user interaction via command line
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        Main pq = new Main(size);
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
                        pq.insert(value);
                        System.out.println("Inserted: " + value);
                        break;
                    case "remove":
                        System.out.println("Removed: " + pq.remove());
                        break;
                    case "peek":
                        System.out.println("Peek: " + pq.peek());
                        break;
                    case "getSize":
                        System.out.println("Size: " + pq.getSize());
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + pq.isEmpty());
                        break;
                    default:
                        System.out.println("Error: Invalid command");
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close();
    }
}
