import java.util.Scanner;
public class Main<T> {
    private static final int DEFAULT_CAPACITY = 10;
    private int maxSize;
    private T[] stackArray;
    private int top;
    @SuppressWarnings("unchecked")
    public Main() {
        this(DEFAULT_CAPACITY); // Initialize with default capacity
    }
    @SuppressWarnings("unchecked")
    public Main(int size) {
        if (size <= 0) {
            throw new IllegalArgumentException("Stack size must be greater than 0"); // Validate size
        }
        this.maxSize = size;
        this.stackArray = (T[]) new Object[size]; // Initialize stack array
        this.top = -1; // Initialize top index
    }
    public void push(T value) {
        if (isFull()) {
            resize(maxSize * 2); // Double the size if full
        }
        stackArray[++top] = value; // Add value to stack
    }
    public T pop() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty, cannot pop element"); // Check for empty stack
        }
        T value = stackArray[top--]; // Remove and return top element
        if (top + 1 < maxSize / 4 && maxSize > DEFAULT_CAPACITY) {
            resize(maxSize / 2); // Shrink the size if necessary
        }
        return value;
    }
    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty, cannot peek element"); // Check for empty stack
        }
        return stackArray[top]; // Return top element without removing it
    }
    private void resize(int newSize) {
        @SuppressWarnings("unchecked") T[] newArray = (T[]) new Object[newSize];
        System.arraycopy(stackArray, 0, newArray, 0, top + 1); // Copy elements to new array
        stackArray = newArray;
        maxSize = newSize; // Update stack size
    }
    public boolean isFull() {
        return top + 1 == maxSize; // Check if stack is full
    }
    public boolean isEmpty() {
        return top == -1; // Check if stack is empty
    }
    public void makeEmpty() {
        top = -1; // Reset top index to empty the stack
    }
    public int size() {
        return top + 1; // Return number of elements in the stack
    }
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Main [");
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
        Main<Integer> stack = new Main<>();
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
                        System.out.println("Error: Invalid command");
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close();
    }
}
