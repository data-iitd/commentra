
import java.util.NoSuchElementException;
import java.util.Scanner;

public class LinkedQueue<T> {

    /**
     * Node class representing each element in the queue.
     */

    private static class Node<T> {
        T data;
        Node<T> next;

        Node(T data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node<T> front;
    private Node<T> rear;
    private int size;

    /**
     * Initializes an empty LinkedQueue.
     */
    public LinkedQueue() {
        front = null;
        rear = null;
        size = 0;
    }

    /**
     * Checks if the queue is empty.
     *
     * @return true if the queue is empty, otherwise false.
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * Adds an element to the rear of the queue.
     *
     * @param data the element to insert.
     * @throws IllegalArgumentException if data is null.
     */
    public void enqueue(T data) {
        if (data == null) {
            throw new IllegalArgumentException("Cannot enqueue null data");
        }

        Node<T> newNode = new Node<>(data);

        if (isEmpty()) {
            front = newNode;
        } else {
            rear.next = newNode;
        }
        rear = newNode;
        size++;
    }

    /**
     * Removes and returns the element at the front of the queue.
     *
     * @return the element at the front of the queue.
     * @throws NoSuchElementException if the queue is empty.
     */
    public T dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }

        T retValue = front.data;
        front = front.next;
        size--;

        if (isEmpty()) {
            rear = null;
        }

        return retValue;
    }

    /**
     * Returns the element at the front of the queue without removing it.
     *
     * @return the element at the front of the queue.
     * @throws NoSuchElementException if the queue is empty.
     */
    public T peekFront() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        return front.data;
    }

    /**
     * Returns the element at the rear of the queue without removing it.
     *
     * @return the element at the rear of the queue.
     * @throws NoSuchElementException if the queue is empty.
     */
    public T peekRear() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        return rear.data;
    }

    /**
     * Returns the size of the queue.
     *
     * @return the size of the queue.
     */
    public int size() {
        return size;
    }

    /**
     * Clears all elements from the queue.
     */
    public void clear() {
        front = null;
        rear = null;
        size = 0;
    }

    /**
     * Returns a string representation of the queue.
     *
     * @return a string representation of the queue.
     */
    @Override
    public String toString() {
        if (isEmpty()) {
            return "[]";
        }

        StringBuilder sb = new StringBuilder("[");
        Node<T> current = front;
        while (current != null) {
            sb.append(current.data);
            if (current.next != null) {
                sb.append(", ");
            }
            current = current.next;
        }
        sb.append(']');
        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LinkedQueue<Integer> queue = new LinkedQueue<>();


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
                            System.out.println("Error: Missing value for enqueue");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]);
                        queue.enqueue(value);
                        System.out.println("Enqueued: " + value);
                        break;

                    case "dequeue":
                        System.out.println("Dequeued: " + queue.dequeue());
                        break;

                    case "peekFront":
                        System.out.println("Front element: " + queue.peekFront());
                        break;

                    case "peekRear":
                        System.out.println("Rear element: " + queue.peekRear());
                        break;

                    case "size":
                        System.out.println("Size: " + queue.size());
                        break;

                    case "isEmpty":
                        System.out.println("Is empty: " + queue.isEmpty());
                        break;

                    case "print":
                        System.out.println(queue);
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
