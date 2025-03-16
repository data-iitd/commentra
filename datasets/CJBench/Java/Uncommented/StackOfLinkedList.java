import java.util.NoSuchElementException;
import java.util.Scanner;
public class StackOfLinkedList {
    public static void main(String[] args) {
        LinkedListStack stack = new LinkedListStack();
        Scanner scanner = new Scanner(System.in);
        int operations = scanner.nextInt();
        for (int i = 0; i < operations; i++) {
            int choice = scanner.nextInt();
            switch (choice) {
                case 1: 
                    int value = scanner.nextInt();
                    stack.push(value);
                    System.out.println("Pushed " + value);
                    break;
                case 2: 
                    try {
                        int popped = stack.pop();
                        System.out.println("Popped " + popped);
                    } catch (NoSuchElementException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 3: 
                    try {
                        int peeked = stack.peek();
                        System.out.println("Top element: " + peeked);
                    } catch (NoSuchElementException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 4: 
                    System.out.println("Stack size: " + stack.getSize());
                    break;
                case 5: 
                    System.out.println("Is stack empty? " + stack.isEmpty());
                    break;
                case 6: 
                    stack.makeEmpty();
                    System.out.println("Stack cleared.");
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        }
        scanner.close();
    }
}
class LinkedListStack {
    private Node head; 
    private int size; 
    LinkedListStack() {
        head = null;
        size = 0;
    }
    public void push(int x) {
        Node newNode = new Node(x);
        newNode.next = head;
        head = newNode;
        size++;
    }
    public int pop() {
        if (size == 0) {
            throw new NoSuchElementException("Empty stack. Nothing to pop");
        }
        int value = head.data;
        head = head.next;
        size--;
        return value;
    }
    public int peek() {
        if (size == 0) {
            throw new NoSuchElementException("Empty stack. Nothing to peek");
        }
        return head.data;
    }
    public boolean isEmpty() {
        return size == 0;
    }
    public int getSize() {
        return size;
    }
    public void makeEmpty() {
        head = null;
        size = 0;
    }
    private static class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
}
