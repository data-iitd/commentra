class Node {
    int key;
    Node next;
    Node prev;

    Node(int key) {
        this.key = key;
    }
}

class DoublyLinkedList {
    Node head;

    DoublyLinkedList() {
        head = new Node(0);
        head.next = head;
        head.prev = head;
    }

    void insert(int key) {
        Node x = new Node(key);
        x.next = head.next;
        head.next.prev = x;
        head.next = x;
        x.prev = head;
    }

    void delete(int key) {
        Node x = head;
        while (x.next != head) {
            x = x.next;
            if (x.key == key) {
                Node prev = x.prev;
                prev.next = x.next;
                x.next.prev = prev;
                x = null;
                break;
            }
        }
    }

    void deleteFirst() {
        Node x = head.next;
        head.next = x.next;
        x.next.prev = head;
        x = null;
    }

    void deleteLast() {
        Node x = head;
        while (x.next != head) {
            x = x.next;
        }
        Node prev = x.prev;
        prev.next = null;
        head.prev = prev;
        x = null;
    }
}

public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        DoublyLinkedList list = new DoublyLinkedList();

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

        Node x = list.head;
        while (x.next != null) {
            System.out.print(x.next.key + " ");
            x = x.next;
        }
        System.out.println();
    }
}
