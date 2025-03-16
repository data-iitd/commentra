import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Queue;
import java.util.Scanner;

/**
 * A class that implements a stack using two queues.
 * This approach ensures that the stack's LIFO (Last In, First Out) behavior
 * is maintained by utilizing two queues for storage.
 * The mainQueue is used to store the elements of the stack, while the tempQueue
 * is used to temporarily store elements during the push operation.
 */
public class StackUsingTwoQueues {

    private Queue<Integer> mainQueue;
    private Queue<Integer> tempQueue;

    /**
     * Constructs an empty stack using two queues.
     */
    public StackUsingTwoQueues() {
        mainQueue = new LinkedList<>();
        tempQueue = new LinkedList<>();
    }

    /**
     * Pushes an element onto the top of the stack.
     * The newly pushed element becomes the top of the stack.
     *
     * @param item The element to be pushed onto the stack.
     */
    public void push(int item) {
        tempQueue.add(item);
        while (!mainQueue.isEmpty()) {
            tempQueue.add(mainQueue.remove());
        }
        Queue<Integer> swap = mainQueue;
        mainQueue = tempQueue;
        tempQueue = swap;
    }

    /**
     * Removes and returns the element at the top of the stack.
     * Throws an exception if the stack is empty.
     *
     * @return The element at the top of the stack.
     * @throws NoSuchElementException if the stack is empty.
     */
    public int pop() {
        if (mainQueue.isEmpty()) {
            throw new NoSuchElementException("Stack is empty");
        }
        return mainQueue.remove();
    }

    /**
     * Returns the element at the top of the stack without removing it.
     * Returns null if the stack is empty.
     *
     * @return The element at the top of the stack, or null if the stack is empty.
     */
    public Integer peek() {
        if (mainQueue.isEmpty()) {
            return null;
        }
        return mainQueue.peek();
    }

    /**
     * Returns true if the stack is empty.
     *
     * @return true if the stack is empty; false otherwise.
     */
    public boolean isEmpty() {
        return mainQueue.isEmpty();
    }

    /**
     * Returns the number of elements in the stack.
     *
     * @return The size of the stack.
     */
    public int size() {
        return mainQueue.size();
    }

    public static void main(String[] args) {
        StackUsingTwoQueues stack = new StackUsingTwoQueues();
        Scanner scanner = new Scanner(System.in);


        int n = scanner.nextInt(); // Number of operations

        for (int i = 0; i < n; i++) {

            String operation = scanner.next();

            switch (operation) {
                case "push":
                    int value = scanner.nextInt();
                    stack.push(value);
                    System.out.println("Pushed: " + value);
                    break;
                case "pop":
                    try {
                        System.out.println("Popped: " + stack.pop());
                    } catch (NoSuchElementException e) {
                        System.out.println("Error: " + e.getMessage());
                    }
                    break;
                case "peek":
                    Integer top = stack.peek();
                    if (top != null) {
                        System.out.println("Top element: " + top);
                    } else {
                        System.out.println("Stack is empty");
                    }
                    break;
                case "isEmpty":
                    System.out.println("Is stack empty? " + stack.isEmpty());
                    break;
                case "size":
                    System.out.println("Stack size: " + stack.size());
                    break;
                default:
                    System.out.println("Invalid operation");
                    break;
            }
        }

        scanner.close();
    }
}
