
import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.Scanner;

/**
 * A stack implementation backed by an {@link ArrayList}, offering dynamic resizing
 * and LIFO (Last-In-First-Out) behavior.
 *
 * <p>The stack grows dynamically as elements are added, and elements are removed
 * in reverse order of their addition.
 *
 * @param <T> the type of elements stored in this stack
 */
public class StackArrayListDemo {

    private final ArrayList<Integer> stack;

    /**
     * Constructs an empty stack.
     */
    public StackArrayListDemo() {
        stack = new ArrayList<>();
    }

    /**
     * Adds an element to the top of the stack.
     *
     * @param value the element to be added
     */
    public void push(int value) {
        stack.add(value);
        System.out.println("Pushed " + value);
    }

    /**
     * Removes and returns the element from the top of the stack.
     *
     * @return the element removed from the top of the stack
     * @throws EmptyStackException if the stack is empty
     */
    public int pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        int removed = stack.remove(stack.size() - 1);
        System.out.println("Popped " + removed);
        return removed;
    }

    /**
     * Returns the element at the top of the stack without removing it.
     *
     * @return the top element of the stack
     * @throws EmptyStackException if the stack is empty
     */
    public int peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        int top = stack.get(stack.size() - 1);
        System.out.println("Top element: " + top);
        return top;
    }

    /**
     * Checks if the stack is empty.
     *
     * @return {@code true} if the stack is empty, {@code false} otherwise
     */
    public boolean isEmpty() {
        return stack.isEmpty();
    }

    /**
     * Empties the stack, removing all elements.
     */
    public void makeEmpty() {
        stack.clear();
        System.out.println("Stack cleared.");
    }

    /**
     * Returns the number of elements in the stack.
     *
     * @return the current size of the stack
     */
    public int size() {
        int size = stack.size();
        System.out.println("Stack size: " + size);
        return size;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StackArrayListDemo stack = new StackArrayListDemo();

        int operations = scanner.nextInt();

        for (int i = 0; i < operations; i++) {
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    int value = scanner.nextInt();
                    stack.push(value);
                    break;
                case 2:
                    try {
                        stack.pop();
                    } catch (EmptyStackException e) {
                        System.out.println("Stack is empty. Cannot pop.");
                    }
                    break;
                case 3:
                    try {
                        stack.peek();
                    } catch (EmptyStackException e) {
                        System.out.println("Stack is empty. Cannot peek.");
                    }
                    break;
                case 4:
                    stack.size();
                    break;
                case 5:
                    stack.makeEmpty();
                    break;
                case 6:
                    System.out.println("Is stack empty? " + stack.isEmpty());
                    break;
                default:
                    System.out.println("Invalid choice. Try again.");
                    break;
            }
        }

        scanner.close();
    }
}
