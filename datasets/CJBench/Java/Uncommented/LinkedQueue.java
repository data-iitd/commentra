
import java.util.NoSuchElementException;
import java.util.Scanner;
public class LinkedQueue<T> {
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
    public LinkedQueue() {
        front = null;
        rear = null;
        size = 0;
    }
    public boolean isEmpty() {
        return size == 0;
    }
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
    public T peekFront() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        return front.data;
    }
    public T peekRear() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        return rear.data;
    }
    public int size() {
        return size;
    }
    public void clear() {
        front = null;
        rear = null;
        size = 0;
    }
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
        System.out.println("Enter commands (enqueue <value>, dequeue, peekFront, peekRear, size, isEmpty, print, exit):");
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
