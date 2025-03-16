import java.util.Scanner;
public class PriorityQueue {
    private int maxSize;
    private int[] queueArray;
    private int nItems;
    public PriorityQueue(int size) {
        maxSize = size + 1;
        queueArray = new int[maxSize];
        nItems = 0;
    }
    private void swim(int pos) {
        while (pos > 1 && (queueArray[pos / 2] < queueArray[pos])) {
            int temp = queueArray[pos];
            queueArray[pos] = queueArray[pos / 2];
            queueArray[pos / 2] = temp;
            pos = pos / 2;
        }
    }
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
    public void insert(int value) {
        if (isFull()) {
            throw new RuntimeException("Queue is full");
        } else {
            queueArray[++nItems] = value;
            swim(nItems);
        }
    }
    public int remove() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is Empty");
        } else {
            int max = queueArray[1];
            int temp = queueArray[1];
            queueArray[1] = queueArray[nItems];
            queueArray[nItems] = temp;
            queueArray[nItems--] = 0;
            sink(1);
            return max;
        }
    }
    public int peek() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is Empty");
        }
        return queueArray[1];
    }
    public boolean isEmpty() {
        return (nItems == 0);
    }
    public boolean isFull() {
        return (nItems == maxSize - 1);
    }
    public int getSize() {
        return nItems;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the priority queue: ");
        int size = scanner.nextInt();
        PriorityQueue pq = new PriorityQueue(size);
        System.out.println("Enter commands (insert <value>, remove, peek, getSize, isEmpty, exit):");
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
                        System.out.println("Unknown command: " + parts[0]);
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close();
    }
}
