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
    private Node nil;

    public DoublyLinkedList() {
        init();
    }

    private void init() {
        nil = new Node(0); // Dummy node
        nil.next = nil;
        nil.prev = nil;
    }

    private Node listSearch(int key) {
        Node cur = nil.next;
        while (cur != nil && cur.key != key) {
            cur = cur.next;
        }
        return cur;
    }

    public void printList() {
        Node cur = nil.next;
        boolean isFirst = true;
        while (cur != nil) {
            if (!isFirst) {
                System.out.print(" ");
            }
            System.out.print(cur.key);
            cur = cur.next;
            isFirst = false;
        }
        System.out.println();
    }

    private void deleteNode(Node t) {
        t.prev.next = t.next;
        t.next.prev = t.prev;
    }

    public void deleteFirst() {
        Node t = nil.next;
        if (t == nil) return;
        deleteNode(t);
    }

    public void deleteLast() {
        Node t = nil.prev;
        if (t == nil) return;
        deleteNode(t);
    }

    public void delete(int key) {
        Node t = listSearch(key);
        if (t == nil) return;
        deleteNode(t);
    }

    public void insert(int key) {
        Node x = new Node(key);
        x.next = nil.next;
        nil.next.prev = x;
        nil.next = x;
        x.prev = nil;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        DoublyLinkedList list = new DoublyLinkedList();

        for (int i = 0; i < n; i++) {
            String command = scanner.next();
            int key = scanner.nextInt();

            if (command.charAt(0) == 'i') {
                list.insert(key);
            } else if (command.charAt(0) == 'd') {
                if (command.length() > 6) {
                    if (command.charAt(6) == 'F') {
                        list.deleteFirst();
                    } else if (command.charAt(6) == 'L') {
                        list.deleteLast();
                    }
                } else {
                    list.delete(key);
                }
            }
        }

        list.printList();
        scanner.close();
    }
}

// <END-OF-CODE>
