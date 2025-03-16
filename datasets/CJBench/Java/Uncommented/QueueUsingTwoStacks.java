
import java.util.Scanner;
import java.util.Stack;
public class QueueUsingTwoStacks {
    private final Stack<Object> inStack;
    private final Stack<Object> outStack;
    public QueueUsingTwoStacks() {
        this.inStack = new Stack<>();
        this.outStack = new Stack<>();
    }
    public void insert(Object x) {
        this.inStack.push(x);
    }
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
    public Object peekBack() {
        if (!this.inStack.isEmpty()) {
            return this.inStack.peek();
        }
        return "Queue is empty";
    }
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
