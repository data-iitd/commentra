
import java.util.Scanner; // Importing Scanner class for user input

public class Main {
    private int maxSize; // Maximum size of the queue
    private int[] queueArray; // Array to store queue elements
    private int nItems; // Number of items in the queue

    public Main(int size) { // Constructor to initialize queue with given size
        maxSize = size + 1;
        queueArray = new int[maxSize];
        nItems = 0;
    }

    // Swim function to bring element up in heap if it is less than its parent
    private void swim(int pos) {
        while (pos > 1 && (queueArray[pos / 2] < queueArray[pos])) {
            int temp = queueArray[pos];
            queueArray[pos] = queueArray[pos / 2];
            queueArray[pos / 2] = temp;
            pos = pos / 2;
        }
    }

    // Sink function to bring element down in heap if it is greater than its children
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

    // Insert function to add new element in the queue
    public void insert(int value) {
        if (isFull()) { // Checking if queue is full before inserting new element
            throw new RuntimeException("Queue is full");
        } else {
            queueArray[++nItems] = value; // Adding new element at the end of the queue
            swim(nItems); // Swimming up the new element to maintain heap property
        }
    }

    // Remove function to remove and return the maximum element from the queue
    public int remove() {
        if (isEmpty()) { // Checking if queue is empty before removing an element
            throw new RuntimeException("Queue is Empty");
        } else {
            int max = queueArray[1]; // Storing the maximum element at the root of the heap
            int temp = queueArray[1];
            queueArray[1] = queueArray[nItems]; // Replacing the maximum element with the last element
            queueArray[nItems--] = 0; // Decreasing the size of the queue by one
            sink(1); // Sinking down the new root element to maintain heap property
            return max;
        }
    }

    // Peek function to return the maximum element from the queue without removing it
    public int peek() {
        if (isEmpty()) { // Checking if queue is empty before returning the maximum element
            throw new RuntimeException("Queue is Empty");
        }
        return queueArray[1]; // Returning the maximum element at the root of the heap
    }

    // Checking if the queue is empty or not
    public boolean isEmpty() {
        return (nItems == 0);
    }

    // Checking if the queue is full or not
    public boolean isFull() {
        return (nItems == maxSize - 1);
    }

    // Function to get the current size of the queue
    public int getSize() {
        return nItems;
    }

    // Main function to read user input and perform corresponding actions
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a new Scanner object for user input
        int size = scanner.nextInt(); // Reading the size of the queue from user input
        Main pq = new Main(size); // Creating a new instance of the Main class with given size

        while (scanner.hasNextLine()) { // Reading user input line by line
            String command = scanner.nextLine().trim(); // Trimming leading and trailing whitespaces from user input

            if (command.equalsIgnoreCase("exit")) { // Checking if user wants to exit the program
                break;
            }

            try {
                String[] parts = command.split(" "); // Splitting user input into parts based on space
                switch (parts[0]) { // Performing corresponding action based on user input
                    case "insert":
                        if (parts.length < 2) { // Checking if user has provided value for insertion
                            System.out.println("Error: Missing value for insert");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]); // Parsing user input into integer value
                        pq.insert(value); // Inserting the value into the queue
                        System.out.println("Inserted: " + value); // Printing the confirmation message
                        break;
                    case "remove":
                        System.out.println("Removed: " + pq.remove()); // Printing the removed element
                        break;
                    case "peek":
                        System.out.println("Peek: " + pq.peek()); // Printing the maximum element in the queue
                        break;
                    case "getSize":
                        System.out.println("Size: " + pq.getSize()); // Printing the current size of the queue
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + pq.isEmpty()); // Printing whether the queue is empty or not
                        break;
                    default:
                        // Handling unknown user input
                }
            } catch (Exception e) { // Handling exceptions thrown during input processing
                System.out.println("Error: " + e.getMessage());
            }
        }

        scanner.close(); // Closing the Scanner object after processing all user input
    }
}