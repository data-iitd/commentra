
import java.util.NoSuchElementException;
import java.util.Scanner;

// Custom node class for the doubly linked list
private static class MainNode<S> {
    S val; // Value of the node
    MainNode<S> next; // Reference to the next node
    MainNode<S> prev; // Reference to the previous node

    // Constructor for the node
    MainNode(S val) {
        this.val = val;
    }

    // Getter for the value of the node
    S getValue() {
        return val;
    }

    // Setter for the next reference of the node
    void setNext(MainNode<S> nextNode) {
        next = nextNode;
    }

    // Setter for the prev reference of the node
    void setPrev(MainNode<S> prevNode) {
        prev = prevNode;
    }
}

// The main class for the doubly linked list
public class Main<T> {
    // Head and tail references for the doubly linked list
    private MainNode<T> head;
    private MainNode<T> tail;

    // Size of the doubly linked list
    private int size;

    // Add a new node to the front of the doubly linked list
    public void addFirst(T val) {
        MainNode<T> newNode = new MainNode<>(val); // Create a new node with the given value

        if (isEmpty()) { // If the doubly linked list is empty
            head = newNode; // Set head and tail to the new node
            tail = newNode;
        } else { // If the doubly linked list is not empty
            newNode.next = head; // Set the next reference of the new node to the current head
            head.prev = newNode; // Set the prev reference of the current head to the new node
            head = newNode; // Set head to the new node
        }
        size++; // Increment the size of the doubly linked list
    }

    // Add a new node to the end of the doubly linked list
    public void addLast(T val) {
        MainNode<T> newNode = new MainNode<>(val); // Create a new node with the given value

        if (tail == null) { // If the doubly linked list is empty
            head = newNode;
            tail = newNode;
        } else { // If the doubly linked list is not empty
            newNode.prev = tail; // Set the prev reference of the new node to the current tail
            tail.next = newNode; // Set the next reference of the current tail to the new node
            tail = newNode; // Set tail to the new node
        }
        size++; // Increment the size of the doubly linked list
    }

    // Remove and return the node at the front of the doubly linked list
    public T pollFirst() {
        if (head == null) { // If the doubly linked list is empty
            throw new NoSuchElementException("Main is empty");
        }

        T oldHeadVal = head.getValue(); // Get the value of the current head node

        if (head == tail) { // If the doubly linked list has only one node
            head = null;
            tail = null;
        } else { // If the doubly linked list has more than one node
            head = head.next; // Set head to the next node
            head.prev = null; // Set the prev reference of the new head to null
        }
        size--; // Decrement the size of the doubly linked list

        return oldHeadVal; // Return the value of the removed node
    }

    // Remove and return the node at the end of the doubly linked list
    public T pollLast() {
        if (tail == null) { // If the doubly linked list is empty
            throw new NoSuchElementException("Main is empty");
        }

        T oldTailVal = tail.getValue(); // Get the value of the current tail node

        if (head == tail) { // If the doubly linked list has only one node
            head = null;
            tail = null;
        } else { // If the doubly linked list has more than one node
            tail = tail.prev; // Set tail to the previous node
            tail.next = null; // Set the next reference of the new tail to null
        }
        size--; // Decrement the size of the doubly linked list

        return oldTailVal; // Return the value of the removed node
    }

    // Return the value of the node at the front of the doubly linked list without removing it
    public T peekFirst() {
        return head != null ? head.getValue() : null; // Return the value of the current head node if it exists, otherwise return null
    }

    // Return the value of the node at the end of the doubly linked list without removing it
    public T peekLast() {
        return tail != null ? tail.getValue() : null; // Return the value of the current tail node if it exists, otherwise return null
    }

    // Return the size of the doubly linked list
    public int size() {
        return size;
    }

    // Check if the doubly linked list is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Override the toString method to print the doubly linked list in a readable format
    @Override
    public String toString() {
        StringBuilder dequeString = new StringBuilder("Head -> ");
        MainNode<T> currNode = head;
        while (currNode != null) {
            dequeString.append(currNode.getValue());
            if (currNode.next != null) {
                dequeString.append(" <-> ");
            }
            currNode = currNode.next;
        }
        dequeString.append(" <- Tail");
        return dequeString.toString();
    }

    // Main method to test the doubly linked list implementation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main<Integer> deque = new Main<>(); // Create an instance of the Main class for integers

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
                        deque.addFirst(addFirstValue); // Add a new node to the front of the doubly linked list
                        System.out.println("Added to front: " + addFirstValue);
                        break;
                    case "addLast":
                        int addLastValue = Integer.parseInt(parts[1]);
                        deque.addLast(addLastValue); // Add a new node to the end of the doubly linked list
                        System.out.println("Added to rear: " + addLastValue);
                        break;
                    case "pollFirst":
                        System.out.println("Removed from front: " + deque.pollFirst()); // Remove and print the node at the front of the doubly linked list
                        break;
                    case "pollLast":
                        System.out.println("Removed from rear: " + deque.pollLast()); // Remove and print the node at the end of the doubly linked list
                        break;
                    case "peekFirst":
                        System.out.println("Front element: " + deque.peekFirst()); // Print the value of the node at the front of the doubly linked list without removing it
                        break;
                    case "peekLast":
                        System.out.println("Rear element: " + deque.peekLast()); // Print the value of the node at the end of the doubly linked list without removing it
                        break;
                    case "size":
                        System.out.println("Size: " + deque.size()); // Print the size of the doubly linked list
                        break;
                    case "isEmpty":
                        System.out.println("Is empty: " + deque.isEmpty()); // Print whether the doubly linked list is empty or not
                        break;
                    case "print":
                        System.out.println(deque); // Print the doubly linked list in a readable format
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]); // Print an error message for unknown commands
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage()); // Print an error message for any exceptions thrown
            }
        }
        scanner.close();
    }
}