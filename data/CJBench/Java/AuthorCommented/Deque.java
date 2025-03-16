
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * A [deque](https://en.wikipedia.org/wiki/Double-ended_queue) is short for a
 * double ended queue pronounced "deck" and sometimes referred to as a head-tail
 * linked list. A deque is a data structure based on a doubly linked list, but
 * only supports adding and removal of nodes from the beginning and the end of
 * the list.
 *
 * @author [Ian Cowan](https://github.com/iccowan)
 */
public class Deque<T> {

    /**
     * Node for the deque
     */
    private static class DequeNode<S> {
        S val;
        DequeNode<S> next = null;
        DequeNode<S> prev = null;

        DequeNode(S val) {
            this.val = val;
        }
    }

    private DequeNode<T> head = null;
    private DequeNode<T> tail = null;
    private int size = 0;

    /**
     * Adds the specified value to the head of the deque
     *
     * @param val Value to add to the deque
     */
    public void addFirst(T val) {
        DequeNode<T> newNode = new DequeNode<>(val);

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }

        size++;
    }

    /**
     * Adds the specified value to the tail of the deque
     *
     * @param val Value to add to the deque
     */
    public void addLast(T val) {
        DequeNode<T> newNode = new DequeNode<>(val);
        if (tail == null) {
            head = newNode;
            tail = newNode;
        } else {
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
        }
        size++;
    }

    /**
     * Removes and returns the first (head) value in the deque
     *
     * @return the value of the head of the deque
     * @throws NoSuchElementException if the deque is empty
     */
    public T pollFirst() {
        if (head == null) {
            throw new NoSuchElementException("Deque is empty");
        }

        T oldHeadVal = head.val;
        if (head == tail) {
            head = null;
            tail = null;
        } else {
            head = head.next;
            head.prev = null;
        }
        size--;
        return oldHeadVal;
    }

    /**
     * Removes and returns the last (tail) value in the deque
     *
     * @return the value of the tail of the deque
     * @throws NoSuchElementException if the deque is empty
     */
    public T pollLast() {
        if (tail == null) {
            throw new NoSuchElementException("Deque is empty");
        }

        T oldTailVal = tail.val;
        if (head == tail) {
            head = null;
            tail = null;
        } else {
            tail = tail.prev;
            tail.next = null;
        }
        size--;
        return oldTailVal;
    }

    /**
     * Returns the first (head) value of the deque WITHOUT removing
     *
     * @return the value of the head of the deque, or null if empty
     */
    public T peekFirst() {
        return head != null ? head.val : null;
    }

    /**
     * Returns the last (tail) value of the deque WITHOUT removing
     *
     * @return the value of the tail of the deque, or null if empty
     */
    public T peekLast() {
        return tail != null ? tail.val : null;
    }

    /**
     * Returns the size of the deque
     *
     * @return the size of the deque
     */
    public int size() {
        return size;
    }

    /**
     * Returns whether or not the deque is empty
     *
     * @return whether or not the deque is empty
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * Returns a stringified deque in a pretty form:
     *
     * <p>
     * Head -> 1 <-> 2 <-> 3 <- Tail
     *
     * @return the stringified deque
     */
    @Override
    public String toString() {
        StringBuilder dequeString = new StringBuilder("Head -> ");
        DequeNode<T> currNode = head;
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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Deque<Integer> deque = new Deque<>();

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
