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

    public void init() {
        head = new Node(0); // Dummy node
        head.next = head;
        head.prev = head;
    }

    public void printList() {
        Node cur = head.next;
        boolean first = true;
        while (cur != head) {
            if (!first) {
                System.out.print(" ");
            }
            System.out.print(cur.key);
            cur = cur.next;
            first = false;
        }
        System.out.println();
    }

    public void deleteFirst() {
        if (head.next != head) {
            Node t = head.next;
            head.next = t.next;
            t.next.prev = head;
        }
    }

    public void deleteLast() {
        if (head.prev != head) {
            Node delNode = head.prev;
            head.prev = delNode.prev;
            delNode.prev.next = head;
            delNode = null; // Allow garbage collection
        }
    }

    public void delete(int skey) {
        Node n = head.next;
        while (n != head) {
            if (n.key == skey) {
                n.prev.next = n.next;
                n.next.prev = n.prev;
                n = null; // Allow garbage collection
                return;
            }
            n = n.next;
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
        list.init();
        for (int i = 0; i < n; i++) {
            String command = scanner.next();
            if (command.equals("insert")) {
                int key = scanner.nextInt();
                list.insert(key);
            } else if (command.equals("deleteFirst")) {
                list.deleteFirst();
            } else if (command.equals("deleteLast")) {
                list.deleteLast();
            } else {
                int key = scanner.nextInt();
                list.delete(key);
            }
        }
        list.printList();
        scanner.close();
    }
}

// <END-OF-CODE>
