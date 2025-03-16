import java.util.Scanner;

class Node {
    int key;
    Node next;
    Node prev;
}

class DoublyLinkedList {
    private Node nil;

    public DoublyLinkedList() {
        nil = new Node();
        nil.next = nil;
        nil.prev = nil;
    }

    public Node listSearch(int key) {
        Node cur = nil.next;
        while (cur != nil) {
            if (cur.key == key) break;
            cur = cur.next;
        }
        return cur;
    }

    public void insert(int key) {
        Node x = new Node();
        x.key = key;
        x.prev = nil;
        x.next = nil.next;
        x.next.prev = x;
        nil.next = x;
    }

    public void deleteNode(Node t) {
        if (t == nil) return;
        t.prev.next = t.next;
        t.next.prev = t.prev;
    }

    public void deleteFirst() {
        deleteNode(nil.next);
    }

    public void deleteLast() {
        deleteNode(nil.prev);
    }

    public void deleteKey(int key) {
        Node t = listSearch(key);
        if (t != nil) deleteNode(t);
    }

    public void printList() {
        Node cur = nil.next;
        boolean isf = true;
        while (cur != nil) {
            if (!isf) System.out.print(" ");
            System.out.print(cur.key);
            cur = cur.next;
            isf = false;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        DoublyLinkedList list = new DoublyLinkedList();
        int size = 0;

        for (int i = 0; i < n; i++) {
            String com = scanner.next();
            int key = scanner.nextInt();
            if (com.equals("insert")) {
                list.insert(key);
                size++;
            } else if (com.equals("delete")) {
                if (com.length() > 6) {
                    if (com.charAt(6) == 'F') list.deleteFirst();
                    else if (com.charAt(6) == 'L') list.deleteLast();
                } else {
                    list.deleteKey(key);
                    size--;
                }
            }
        }

        list.printList();
    }
}
