import java.util.NoSuchElementException;
import java.util.Scanner;
public class Main {
    // Represents a node in the doubly linked list
    private static class MainNode<S> {
        S val;
        MainNode<S> next = null; // Reference to the next node
        MainNode<S> prev = null; // Reference to the previous node
        // Constructor to initialize the node with a value
        MainNode(S val) {
            this.val = val;
        }
    }
    // Head of the doubly linked list
    private MainNode<T> head = null;
    // Tail of the doubly linked list
    private MainNode<T> tail = null;
    // Number of elements in the deque
    private int size = 0;
    // Adds a new element to the front of the deque
    public void addFirst(T val) {
        MainNode<T> newNode = new MainNode<>(val);
        if (isEmpty()) { // If the deque is empty, set both head and tail to the new node
            head = newNode;
            tail = newNode;
        } else { // Otherwise, adjust the pointers to insert at the front
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
        size++; // Increment the size of the deque
    }
    // Adds a new element to the rear of the deque
    public void addLast(T val) {
        MainNode<T> newNode = new MainNode<>(val);
        if (tail == null) { // If the deque is empty, set both head and tail to the new node
            head = newNode;
            tail = newNode;
        } else { // Otherwise, adjust the pointers to insert at the rear
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
        }
        size++; // Increment the size of the deque
    }
    // Removes and returns the first element from the deque
    public T pollFirst() {
        if (head == null) { // If the deque is empty, throw an exception
            throw new NoSuchElementException("Main is empty");
        }
        T oldHeadVal = head.val; // Store the value of the head node
        if (head == tail) { // If there's only one element, set both head and tail to null
            head = null;
            tail = null;
        } else { // Otherwise, adjust the pointers to remove the head node
            head = head.next;
            head.prev = null;
        }
        size--; // Decrement the size of the deque
        return oldHeadVal; // Return the value of the removed node
    }
    // Removes and returns the last element from the deque
    public T pollLast() {
        if (tail == null) { // If the deque is empty, throw an exception
            throw new NoSuchElementException("Main is empty");
        }
        T oldTailVal = tail.val; // Store the value of the tail node
        if (head == tail) { // If there's only one element, set both head and tail to null
            head = null;
            tail = null;
        } else { // Otherwise, adjust the pointers to remove the tail node
            tail = tail.prev;
            tail.next = null;
        }
        size--; // Decrement the size of the deque
        return oldTailVal; // Return the value of the removed node
    }
    // Returns the first element of the deque without removing it
    public T peekFirst() {
        return head != null ? head.val : null; // Return the value of the head node, or null if empty
    }
    // Returns the last element of the deque without removing it
    public T peekLast() {
        return tail != null ? tail.val : null; // Return the value of the tail node, or null if empty
    }
    // Returns the number of elements in the deque
    public int size() {
        return size;
    }
    // Checks if the deque is empty
    public boolean isEmpty() {
        return size == 0;
    }
    // Returns a string representation of the deque
    @Override
    public String toString() {
        StringBuilder dequeString = new StringBuilder("Head -> ");
        MainNode<T> currNode = head;
        while (currNode != null) {
            dequeString.append(currNode.val);
            if (currNode.next != null) {
                dequeString.append(" <-> ");
            }
            currNode = currNode.next;
        }
        dequeString.append(" <- Tail");
        return dequeString.toString();
    }
    // Main method to run the deque through a command-line interface
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main<Integer> deque = new Main<>();
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.equalsIgnoreCase("exit")) {
                break;
            }
            try {
                String[] parts = command.split(" ");
                switch (parts[0]) {
                    case "addFirst":
                        int addFirstValue = Integer.parseInt(parts[1]);
                        deque.addFirst(addFirstValue);
                        System.out.println("Added to front: " + addFirstValue);
                        break;
                    case "addLast":
                        int addLastValue = Integer.parseInt(parts[1]);
                        deque.addLast(addLastValue);
                        System.out.println("Added to rear: " + addLastValue);
                        break;
                    case "pollFirst":
                        System.out.println("Removed from front: " + deque.pollFirst());
                        break;
                    case "pollLast":
                        System.out.println("Removed from rear: " + deque.pollLast());
                        break;
                    case "peekFirst":
                        System.out.println("Front element: " + deque.peekFirst());
                        break;
                    case "peekLast":
                        System.out.println("Rear element: " + deque.peekLast());
                        break;
                    case "size":
                        System.out.println("Size: " + deque.size());
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + deque.isEmpty());
                        break;
                    case "print":
                        System.out.println(deque);
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
