import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * A stack implementation using a singly linked list.
 *
 * <p>This class provides methods to push, pop, and peek elements in a Last-In-First-Out (LIFO) manner.
 * It keeps track of the number of elements in the stack and allows checking if the stack is empty.
 *
 * <p>This implementation does not allow null elements to be pushed onto the stack.
 */
public class StackOfLinkedList {

    public static void main(String[] args) {
        LinkedListStack stack = new LinkedListStack();
        Scanner scanner = new Scanner(System.in);

        int operations = scanner.nextInt();

        for (int i = 0; i < operations; i++) {
            int choice = scanner.nextInt();
            switch (choice) {
                case 1: // Push
                    int value = scanner.nextInt();
                    stack.push(value);
                    System.out.println("Pushed " + value);
                    break;
                case 2: // Pop
                    try {
                        int popped = stack.pop();
                        System.out.println("Popped " + popped);
                    } catch (NoSuchElementException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 3: // Peek
                    try {
                        int peeked = stack.peek();
                        System.out.println("Top element: " + peeked);
                    } catch (NoSuchElementException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 4: // Size
                    System.out.println("Stack size: " + stack.getSize());
                    break;
                case 5: // Is Empty
                    System.out.println("Is stack empty? " + stack.isEmpty());
                    break;
                case 6: // Make Empty
                    stack.makeEmpty();
                    System.out.println("Stack cleared.");
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        }
        scanner.close();
    }
}

/**
 * A class that implements a stack using a linked list.
 *
 * <p>This stack supports basic operations:
 * <ul>
 * <li>push: Adds an element to the top of the stack</li>
 * <li>pop: Removes and returns the top element of the stack</li>
 * <li>peek: Returns the top element without removing it</li>
 * <li>isEmpty: Checks if the stack is empty</li>
 * <li>getSize: Returns the current size of the stack</li>
 * </ul>
 */
class LinkedListStack {

    private Node head; // Top of the stack
    private int size; // Number of elements in the stack

    /**
     * Initializes an empty stack.
     */
    LinkedListStack() {
        head = null;
        size = 0;
    }

    /**
     * Adds an element to the top of the stack.
     *
     * @param x the element to be added
     * @return <tt>true</tt> if the element is added successfully
     */
    public void push(int x) {
        Node newNode = new Node(x);
        newNode.next = head;
        head = newNode;
        size++;
    }

    /**
     * Removes and returns the top element of the stack.
     *
     * @return the element at the top of the stack
     * @throws NoSuchElementException if the stack is empty
     */
    public int pop() {
        if (size == 0) {
            throw new NoSuchElementException("Empty stack. Nothing to pop");
        }
        int value = head.data;
        head = head.next;
        size--;
        return value;
    }

    /**
     * Returns the top element of the stack without removing it.
     *
     * @return the element at the top of the stack
     * @throws NoSuchElementException if the stack is empty
     */
    public int peek() {
        if (size == 0) {
            throw new NoSuchElementException("Empty stack. Nothing to peek");
        }
        return head.data;
    }

    /**
     * Checks if the stack is empty.
     *
     * @return <tt>true</tt> if the stack is empty, <tt>false</tt> otherwise
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * Returns the current size of the stack.
     *
     * @return the number of elements in the stack
     */
    public int getSize() {
        return size;
    }

    /**
     * Removes all elements from the stack.
     */
    public void makeEmpty() {
        head = null;
        size = 0;
    }

    /**
     * A helper class representing a node in the linked list.
     */
    private static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
}
