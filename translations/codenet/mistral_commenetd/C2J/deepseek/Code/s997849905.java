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

class DoublyLinkedList {
    Node head;

    DoublyLinkedList() {
        head = new Node(0); // Dummy node
        head.next = head;
        head.prev = head;
    }

    void printList() {
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

    void deleteFirst() {
        Node temp = head.next;
        head.next = temp.next;
        temp.next.prev = head;
    }

    void deleteLast() {
        Node delNode = head.prev;
        head.prev = delNode.prev;
        delNode.prev.next = head;
    }

    void delete(int skey) {
        Node current = head.next;
        boolean found = false;

        while (current != head) {
            if (current.key == skey) {
                found = true;
                break;
            }
            current = current.next;
        }

        if (found) {
            current.prev.next = current.next;
            current.next.prev = current.prev;
        }
    }

    void insert(int skey) {
        Node newNode = new Node(skey);

        if (head.next == head) {
            newNode.next = head;
            head.next = newNode;
            newNode.prev = head;
            head.prev = newNode;
        } else {
            newNode.next = head.next;
            head.next.prev = newNode;
            head.next = newNode;
            newNode.prev = head;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        DoublyLinkedList list = new DoublyLinkedList();

        for (int i = 0; i < n; i++) {
            String com = scanner.next();
            if (com.equals("insert")) {
                int key = scanner.nextInt();
                list.insert(key);
            } else if (com.equals("deleteFirst")) {
                list.deleteFirst();
            } else if (com.equals("deleteLast")) {
                list.deleteLast();
            } else {
                int key = scanner.nextInt();
                list.delete(key);
            }
        }
        list.printList();
    }
}
