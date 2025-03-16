import java.util.Scanner;

class Node {
    int key;
    Node next;
    Node prev;
}

public class DoublyLinkedList {
    private Node nil;

    public DoublyLinkedList() {
        init();
    }

    private void init() {
        nil = new Node();
        nil.next = nil;
        nil.prev = nil;
    }

    private Node listSearch(int key) {
        Node cur = nil.next;
        while (cur != nil) {
            if (cur.key == key) {
                return cur;
            }
            cur = cur.next;
        }
        return nil; // Return nil if not found
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
        if (t == nil) return;
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

    public void deleteKey(int key) {
        Node t = listSearch(key);
        if (t != nil) deleteNode(t);
    }

    public void insert(int key) {
        Node x = new Node();
        x.key = key;
        x.prev = nil;
        x.next = nil.next;
        x.next.prev = x;
        nil.next = x;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int key, n;
        String command;
        int size = 0;

        n = scanner.nextInt();
        DoublyLinkedList list = new DoublyLinkedList();

        for (int i = 0; i < n; i++) {
            command = scanner.next();
            key = scanner.nextInt();
            if (command.charAt(0) == 'i') {
                list.insert(key);
                size++;
            } else if (command.charAt(0) == 'd') {
                if (command.length() > 6) {
                    if (command.charAt(6) == 'F') {
                        list.deleteFirst();
                    } else if (command.charAt(6) == 'L') {
                        list.deleteLast();
                    }
                } else {
                    list.deleteKey(key);
                    size--;
                }
            }
        }

        list.printList();
        scanner.close();
    }
}

// <END-OF-CODE>
