
import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.Scanner;
public class StackArrayListDemo {
    private final ArrayList<Integer> stack;
    public StackArrayListDemo() {
        stack = new ArrayList<>();
    }
    public void push(int value) {
        stack.add(value);
        System.out.println("Pushed " + value);
    }
    public int pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        int removed = stack.remove(stack.size() - 1);
        System.out.println("Popped " + removed);
        return removed;
    }
    public int peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        int top = stack.get(stack.size() - 1);
        System.out.println("Top element: " + top);
        return top;
    }
    public boolean isEmpty() {
        return stack.isEmpty();
    }
    public void makeEmpty() {
        stack.clear();
        System.out.println("Stack cleared.");
    }
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
