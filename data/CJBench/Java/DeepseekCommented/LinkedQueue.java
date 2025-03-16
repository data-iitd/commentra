
import java.util.NoSuchElementException;
import java.util.Scanner;
public class Main {
    private static class Node<T> {
        T data; // The data stored in the node
        Node<T> next; // Reference to the next node in the list
        Node(T data) {
            this.data = data;
            this.next = null; // Initializes the next node to null
        }
    }
    private Node<T> front; // Reference to the front node of the queue
    private Node<T> rear; // Reference to the rear node of the queue
    private int size; // Number of elements in the queue
    public Main() {
        front = null; // Initializes the front of the queue to null
        rear = null; // Initializes the rear of the queue to null
        size = 0; // Initializes the size of the queue to 0
    }
    public boolean isEmpty() {
        return size == 0; // Returns true if the queue is empty, otherwise false
    }
    public void enqueue(T data) {
        if (data == null) {
            throw new IllegalArgumentException("Cannot enqueue null data"); // Throws an exception if the data is null
        }
        Node<T> newNode = new Node<>(data); // Creates a new node with the given data
        if (isEmpty()) {
            front = newNode; // If the queue is empty, the new node becomes the front
        } else {
            rear.next = newNode; // Otherwise, the new node is added after the current rear node
        }
        rear = newNode; // The new node becomes the new rear node
        size++; // Increments the size of the queue
    }
    public T dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty"); // Throws an exception if the queue is empty
        }
        T retValue = front.data; // Stores the data of the front node
        front = front.next; // Moves the front to the next node
        size--; // Decrements the size of the queue
        if (isEmpty()) {
            rear = null; // If the queue is empty, set the rear to null
        }
        return retValue; // Returns the stored data
    }
    public T peekFront() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty"); // Throws an exception if the queue is empty
        }
        return front.data; // Returns the data of the front node
    }
    public T peekRear() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty"); // Throws an exception if the queue is empty
        }
        return rear.data; // Returns the data of the rear node
    }
    public int size() {
        return size; // Returns the size of the queue
    }
    public void clear() {
        front = null; // Sets the front of the queue to null
        rear = null; // Sets the rear of the queue to null
        size = 0; // Sets the size of the queue to 0
    }
    @Override
    public String toString() {
        if (isEmpty()) {
            return "[]"; // Returns "[]" if the queue is empty
        }
        StringBuilder sb = new StringBuilder("["); // Initializes a StringBuilder to build the string representation
        Node<T> current = front; // Starts from the front of the queue
        while (current != null) {
            sb.append(current.data); // Appends the data of the current node
            if (current.next != null) {
                sb.append(", "); // Appends a comma and space if there is a next node
            }
            current = current.next; // Moves to the next node
        }
        sb.append(']'); // Appends the closing bracket
        return sb.toString(); // Returns the built string
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main<Integer> queue = new Main<>();
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.equalsIgnoreCase("exit")) {
                break;
            }
            try {
                String[] parts = command.split(" ");
                switch (parts[0]) {
                    case "enqueue":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for enqueue"); // Prints an error message if no value is provided
                            break;
                        }
                        int value = Integer.parseInt(parts[1]);
                        queue.enqueue(value);
                        System.out.println("Enqueued: " + value); // Prints the enqueued value
                        break;
                    case "dequeue":
                        System.out.println("Dequeued: " + queue.dequeue()); // Prints the dequeued value
                        break;
                    case "peekFront":
                        System.out.println("Front element: " + queue.peekFront()); // Prints the front element
                        break;
                    case "peekRear":
                        System.out.println("Rear element: " + queue.peekRear()); // Prints the rear element
                        break;
                    case "size":
                        System.out.println("Size: " + queue.size()); // Prints the size of the queue
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + queue.isEmpty()); // Prints if the queue is empty
                        break;
                    case "print":
                        System.out.println(queue); // Prints the queue
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]); // Prints an error message for unknown commands
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage()); // Prints the error message
            }
        }
        scanner.close();
    }
}