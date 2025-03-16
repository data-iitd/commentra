import java.util.Scanner;

class Node {
    int key;
    Node next;
    Node prev;

    Node(int key) {
        this.key = key;
        this.next = null;
        this.prev = null;
    }
}

public class DoublyLinkedList {
    private Node head;

    public DoublyLinkedList() {
        head = new Node(-1); // Sentinel node
        head.next = head;
        head.prev = head;
    }

    public void init() {
        head = new Node(-1); // Sentinel node
        head.next = head;
        head.prev = head;
    }

    public void printList() {
        Node current = head.next;
        boolean first = true;
        while (current != head) {
            if (!first) {
                System.out.print(" ");
            }
            System.out.print(current.key);
            current = current.next;
            first = false;
        }
        System.out.println();
    }

    public void deleteFirst() {
        if (head.next != head) {
            head.next = head.next.next;
            head.next.prev = head;
        }
    }

    public void deleteLast() {
        if (head.prev != head) {
            head.prev = head.prev.prev;
            head.prev.next = head;
        }
    }

    public void delete(int skey) {
        Node current = head.next;
        while (current != head) {
            if (current.key == skey) {
                current.prev.next = current.next;
                current.next.prev = current.prev;
                return;
            }
            current = current.next;
        }
    }

    public void insert(int skey) {
        Node newNode = new Node(skey);
        newNode.next = head.next;
        head.next.prev = newNode;
        head.next = newNode;
        newNode.prev = head;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        DoublyLinkedList list = new DoublyLinkedList();

        for (int i = 0; i < n; i++) {
            String command = scanner.next();
            if (command.equals("insert")) {
                int key = scanner.nextInt();
                list.insert(key);
            } else if (command.equals("deleteFirst")) {
                list.deleteFirst();
            } else if (command.equals("deleteLast")) {
                list.deleteLast();
            } else if (command.equals("delete")) {
                int key = scanner.nextInt();
                list.delete(key);
            }
        }
        list.printList();
    }
}
