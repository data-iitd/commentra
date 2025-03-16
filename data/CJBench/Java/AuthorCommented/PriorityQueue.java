import java.util.Scanner;

/**
 * This class implements a PriorityQueue.
 *
 * <p>
 * A priority queue adds elements into positions based on their priority. So the
 * most important elements are placed at the front/on the top. In this example I
 * give numbers that are bigger, a higher priority. Queues in theory have no
 * fixed size but when using an array implementation it does.
 * <p>
 * Additional contibutions made by: PuneetTri(https://github.com/PuneetTri)
 */
public class PriorityQueue {
    /**
     * The max size of the queue
     */
    private int maxSize;
    /**
     * The array for the queue
     */
    private int[] queueArray;
    /**
     * How many items are in the queue
     */
    private int nItems;

    public PriorityQueue(int size) {
        /* If capacity is not defined, default size of 11 would be used
         *  capacity=max+1 because we cant access 0th element of PQ, and to
         *  accomodate (max)th elements we need capacity to be max+1.
         *  Parent is at position k, child at position (k*2,k*2+1), if we
         *  use position 0 in our queue, its child would be at:
         *  (0*2, 0*2+1) -> (0,0). This is why we start at position 1
         */
        maxSize = size + 1;
        queueArray = new int[maxSize];
        nItems = 0;
    }

    /**
     * Helper function for the max-heap implementation of PQ
     * Function would help demote parent node to their correct
     * position
     *
     * @param pos Position of newly added element at bottom
     */
    private void swim(int pos) {
        while (pos > 1 && (queueArray[pos / 2] < queueArray[pos])) {
            int temp = queueArray[pos];
            queueArray[pos] = queueArray[pos / 2];
            queueArray[pos / 2] = temp;
            pos = pos / 2;
        }
    }

    /**
     * Helper function for the max-heap implementation of PQ
     * Function would help demote parent node to their correct
     * position
     *
     * @param pos Position of element at top
     */
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

    /**
     * Inserts an element in it's appropriate place
     *
     * @param value Value to be inserted
     */
    public void insert(int value) {
        if (isFull()) {
            throw new RuntimeException("Queue is full");
        } else {
            queueArray[++nItems] = value;
            swim(nItems);
        }
    }

    /**
     * Dequeue the element with the max priority from PQ
     *
     * @return The element removed
     */
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

    /**
     * Checks what's at the front of the queue
     *
     * @return element at the front of the queue
     */
    public int peek() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is Empty");
        }
        return queueArray[1];
    }

    /**
     * Returns true if the queue is empty
     *
     * @return true if the queue is empty
     */
    public boolean isEmpty() {
        return (nItems == 0);
    }

    /**
     * Returns true if the queue is full
     *
     * @return true if the queue is full
     */
    public boolean isFull() {
        return (nItems == maxSize - 1);
    }

    /**
     * Returns the number of elements in the queue
     *
     * @return number of elements in the queue
     */
    public int getSize() {
        return nItems;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        PriorityQueue pq = new PriorityQueue(size);

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
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close();
    }
}
