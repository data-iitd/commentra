
import java.util.NoSuchElementException;
import java.util.Scanner;
public class Deque<T> {
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
    public T peekFirst() {
        return head != null ? head.val : null;
    }
    public T peekLast() {
        return tail != null ? tail.val : null;
    }
    public int size() {
        return size;
    }
    public boolean isEmpty() {
        return size == 0;
    }
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
        System.out.println("Enter commands (addFirst <value>, addLast <value>, pollFirst, pollLast, peekFirst, peekLast, size, isEmpty, print, exit):");
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
