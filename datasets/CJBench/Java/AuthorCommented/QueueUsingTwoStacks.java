
import java.util.Scanner;
import java.util.Stack;

/**
 * This implements Queue using two Stacks.
 *
 * <p>
 * Big O Runtime: insert(): O(1) remove(): O(1) amortized isEmpty(): O(1)
 *
 * <p>
 * A queue data structure functions the same as a real world queue. The elements
 * that are added first are the first to be removed. New elements are added to
 * the back/rear of the queue.
 *
 * @author sahilb2 (https://www.github.com/sahilb2)
 */
public class QueueUsingTwoStacks {
    private final Stack<Object> inStack;
    private final Stack<Object> outStack;

    /**
     * Constructor
     */
    public QueueUsingTwoStacks() {
        this.inStack = new Stack<>();
        this.outStack = new Stack<>();
    }

    /**
     * Inserts an element at the rear of the queue
     *
     * @param x element to be added
     */
    public void insert(Object x) {
        this.inStack.push(x);
    }

    /**
     * Remove an element from the front of the queue
     *
     * @return the new front of the queue
     */
    public Object remove() {
        if (this.outStack.isEmpty()) {
            while (!this.inStack.isEmpty()) {
                this.outStack.push(this.inStack.pop());
            }
        }
        if (!this.outStack.isEmpty()) {
            return this.outStack.pop();
        }
        return "Queue is empty";
    }

    /**
     * Peek at the element from the front of the queue
     *
     * @return the front element of the queue
     */
    public Object peekFront() {
        if (this.outStack.isEmpty()) {
            while (!this.inStack.isEmpty()) {
                this.outStack.push(this.inStack.pop());
            }
        }
        if (!this.outStack.isEmpty()) {
            return this.outStack.peek();
        }
        return "Queue is empty";
    }

    /**
     * Peek at the element from the back of the queue
     *
     * @return the back element of the queue
     */
    public Object peekBack() {
        if (!this.inStack.isEmpty()) {
            return this.inStack.peek();
        }
        return "Queue is empty";
    }

    /**
     * Returns true if the queue is empty
     *
     * @return true if the queue is empty
     */
    public boolean isEmpty() {
        return (this.inStack.isEmpty() && this.outStack.isEmpty());
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        QueueUsingTwoStacks queue = new QueueUsingTwoStacks();

        int operations = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < operations; i++) {
            String[] command = scanner.nextLine().split(" ");
            switch (command[0]) {
                case "INSERT":
                    queue.insert(Integer.parseInt(command[1]));
                    break;
                case "REMOVE":
                    System.out.println(queue.remove());
                    break;
                case "PEEK_FRONT":
                    System.out.println(queue.peekFront());
                    break;
                case "PEEK_BACK":
                    System.out.println(queue.peekBack());
                    break;
                case "IS_EMPTY":
                    System.out.println(queue.isEmpty());
                    break;
                default:
                    System.out.println("Invalid command");
            }
        }

        scanner.close();
    }
}
