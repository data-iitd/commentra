import java.util.Scanner;
public class StackArray<T> {
    private static final int DEFAULT_CAPACITY = 10;
    private int maxSize;
    private T[] stackArray;
    private int top;
    @SuppressWarnings("unchecked")
    public StackArray() {
        this(DEFAULT_CAPACITY);
    }
    @SuppressWarnings("unchecked")
    public StackArray(int size) {
        if (size <= 0) {
            throw new IllegalArgumentException("Stack size must be greater than 0");
        }
        this.maxSize = size;
        this.stackArray = (T[]) new Object[size];
        this.top = -1;
    }
    public void push(T value) {
        if (isFull()) {
            resize(maxSize * 2);
        }
        stackArray[++top] = value;
    }
    public T pop() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty, cannot pop element");
        }
        T value = stackArray[top--];
        if (top + 1 < maxSize / 4 && maxSize > DEFAULT_CAPACITY) {
            resize(maxSize / 2);
        }
        return value;
    }
    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty, cannot peek element");
        }
        return stackArray[top];
    }
    private void resize(int newSize) {
        @SuppressWarnings("unchecked") T[] newArray = (T[]) new Object[newSize];
        System.arraycopy(stackArray, 0, newArray, 0, top + 1);
        stackArray = newArray;
        maxSize = newSize;
    }
    public boolean isFull() {
        return top + 1 == maxSize;
    }
    public boolean isEmpty() {
        return top == -1;
    }
    public void makeEmpty() {
        top = -1;
    }
    public int size() {
        return top + 1;
    }
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("StackArray [");
        for (int i = 0; i <= top; i++) {
            sb.append(stackArray[i]);
            if (i < top) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StackArray<Integer> stack = new StackArray<>();
        System.out.println("Enter commands (push <value>, pop, peek, size, isEmpty, exit):");
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
