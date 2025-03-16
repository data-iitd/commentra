import java.util.Scanner;

class Node {
    int key;
    Node next;
    Node prev;

    Node(int key) {
        this.key = key;
    }
}

public class DoublyLinkedList {
    private Node head;

    public DoublyLinkedList() {
        head = new Node(0);
        head.next = head;
        head.prev = head;
    }

    public void insert(int a) {
        Node x = new Node(a);
        x.next = head.next;
        head.next.prev = x;
        head.next = x;
        x.prev = head;
    }

    public void delete(int a) {
        Node x = head;
        while (x.next != head) {
            x = x.next;
            if (x.key == a) {
                x.prev.next = x.next;
                x.next.prev = x.prev;
                break;
            }
        }
    }

    public void deleteFirst() {
        if (head.next != head) {
            Node x = head.next;
            head.next = x.next;
            x.next.prev = head;
        }
    }

    public void deleteLast() {
        if (head.prev != head) {
            Node x = head.prev;
            head.prev = x.prev;
            x.prev.next = head;
        }
    }

    public void printList() {
        Node x = head;
        while (x.next != head) {
            x = x.next;
            System.out.print(x.key);
            if (x.next != head) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DoublyLinkedList list = new DoublyLinkedList();

        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            String op = scanner.next();
            if (op.equals("insert")) {
                int a = scanner.nextInt();
                list.insert(a);
            } else if (op.equals("delete")) {
                int a = scanner.nextInt();
                list.delete(a);
            } else if (op.equals("deleteFirst")) {
                list.deleteFirst();
            } else if (op.equals("deleteLast")) {
                list.deleteLast();
            }
        }

        list.printList();
        scanner.close();
    }
}

// <END-OF-CODE>
