import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Queue;
import java.util.Scanner;
public class StackUsingTwoQueues {
    private Queue<Integer> mainQueue;
    private Queue<Integer> tempQueue;
    public StackUsingTwoQueues() {
        mainQueue = new LinkedList<>();
        tempQueue = new LinkedList<>();
    }
    public void push(int item) {
        tempQueue.add(item);
        while (!mainQueue.isEmpty()) {
            tempQueue.add(mainQueue.remove());
        }
        Queue<Integer> swap = mainQueue;
        mainQueue = tempQueue;
        tempQueue = swap;
    }
    public int pop() {
        if (mainQueue.isEmpty()) {
            throw new NoSuchElementException("Stack is empty");
        }
        return mainQueue.remove();
    }
    public Integer peek() {
        if (mainQueue.isEmpty()) {
            return null;
        }
        return mainQueue.peek();
    }
    public boolean isEmpty() {
        return mainQueue.isEmpty();
    }
    public int size() {
        return mainQueue.size();
    }
    public static void main(String[] args) {
        StackUsingTwoQueues stack = new StackUsingTwoQueues();
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); 
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
