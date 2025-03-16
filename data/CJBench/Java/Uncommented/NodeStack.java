import java.util.Scanner;
public class NodeStack<Item> {
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
    public NodeStack() {
        head = null;
        size = 0;
    }
    public void push(Item item) {
        Node newNode = new Node(item);
        newNode.previous = head;
        head = newNode;
        size++;
    }
    public Item pop() {
        if (isEmpty()) {
            throw new IllegalStateException("Cannot pop from an empty stack.");
        }
        Item data = head.data;
        head = head.previous;
        size--;
        return data;
    }
    public Item peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Cannot peek from an empty stack.");
        }
        return head.data;
    }
    public boolean isEmpty() {
        return head == null;
    }
    public int size() {
        return size;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        NodeStack<Integer> stack = new NodeStack<>();
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
