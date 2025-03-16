import java.util.Scanner;

class Node {
    int key;
    Node next;
    Node prev;

    Node(int key) {
        this.key = key;
    }
}

public class CircularDoublyLinkedList {
    private Node N;

    public void init() {
        N = new Node(0); // Sentinel node
        N.next = N;
        N.prev = N;
    }

    public void printList() {
        Node cur = N.next;
        boolean first = true;
        while (cur != N) {
            if (!first) System.out.print(" ");
            System.out.print(cur.key);
            cur = cur.next;
            first = false;
        }
        System.out.println();
    }

    public void deleteFirst() {
        Node t = N.next;
        N.next = t.next;
        t.next.prev = N;
        t.next = null;
        t.prev = null;
    }

    public void deleteLast() {
        Node delnode = N.prev;
        N.prev = delnode.prev;
        delnode.prev.next = N;
        delnode.next = null;
        delnode.prev = null;
    }

    public void delete(int skey) {
        boolean found = false;
        Node n = N.next;
        while (n != N) {
            if (n.key == skey) {
                found = true;
                break;
            }
            n = n.next;
        }
        if (found) {
            Node t = n.prev;
            t.next = n.next;
            t.next.prev = t;
            n.next = null;
            n.prev = null;
        }
    }

    public void insert(int skey) {
        Node newNode = new Node(skey);
        if (N.next == N) {
            newNode.next = N;
            N.next = newNode;
            newNode.prev = N;
            N.prev = newNode;
        } else {
            newNode.next = N.next;
            N.next.prev = newNode;
            N.next = newNode;
            newNode.prev = N;
        }
    }

    public static void main(String[] args) {
        CircularDoublyLinkedList list = new CircularDoublyLinkedList();
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        list.init();
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
        scanner.close();
    }
}
