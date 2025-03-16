import java.util.Scanner;

/**
 * A stack implementation using linked nodes, supporting unlimited size without an ArrayList.
 *
 * <p>Each node in the stack contains data of generic type {@code Item}, along with references
 * to the next and previous nodes, supporting typical stack operations.
 *
 * <p>The stack follows a Last-In-First-Out (LIFO) order where elements added last are
 * removed first. Supported operations include push, pop, and peek.
 *
 * @param <Item> the type of elements held in this stack
 */
public class NodeStack<Item> {

    /**
     * Node class representing each element in the stack.
     */
    private class Node {
        Item data;
        Node previous;

        Node(Item data) {
            this.data = data;
            this.previous = null;
        }
    }

    private Node head;
    private int size;

    /**
     * Constructs an empty NodeStack.
     */
    public NodeStack() {
        head = null;
        size = 0;
    }

    /**
     * Pushes an item onto the stack.
     *
     * @param item the item to be pushed onto the stack
     */
    public void push(Item item) {
        Node newNode = new Node(item);
        newNode.previous = head;
        head = newNode;
        size++;
    }

    /**
     * Removes and returns the item at the top of the stack.
     *
     * @return the item at the top of the stack, or {@code null} if the stack is empty
     * @throws IllegalStateException if the stack is empty
     */
    public Item pop() {
        if (isEmpty()) {
            throw new IllegalStateException("Cannot pop from an empty stack.");
        }
        Item data = head.data;
        head = head.previous;
        size--;
        return data;
    }

    /**
     * Returns the item at the top of the stack without removing it.
     *
     * @return the item at the top of the stack, or {@code null} if the stack is empty
     * @throws IllegalStateException if the stack is empty
     */
    public Item peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Cannot peek from an empty stack.");
        }
        return head.data;
    }

    /**
     * Checks whether the stack is empty.
     *
     * @return {@code true} if the stack has no elements, {@code false} otherwise
     */
    public boolean isEmpty() {
        return head == null;
    }

    /**
     * Returns the number of elements currently in the stack.
     *
     * @return the size of the stack
     */
    public int size() {
        return size;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        NodeStack<Integer> stack = new NodeStack<>();

        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.equalsIgnoreCase("exit")) {
                break;
            }

            try {
                String[] parts = command.split(" ");
                switch (parts[0]) {
                    case "push":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for push");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]);
                        stack.push(value);
                        System.out.println("Pushed: " + value);
                        break;

                    case "pop":
                        System.out.println("Popped: " + stack.pop());
                        break;

                    case "peek":
                        System.out.println("Top: " + stack.peek());
                        break;

                    case "size":
                        System.out.println("Size: " + stack.size());
                        break;

                    case "isEmpty":
                        System.out.println("Is empty: " + stack.isEmpty());
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
