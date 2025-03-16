import java.util.*;

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
        nil = new Node(-1); // Use a dummy node to simplify boundary conditions
        nil.next = nil;
        nil.prev = nil;
    }

    public Node listSearch(int key) {
        Node cur = nil.next;
        while (cur != nil) {
            if (cur.key == key) {
                break;
            }
            cur = cur.next;
        }
        return cur;
    }

    public void insert(int key) {
        Node x = new Node(key);
        x.next = nil.next;
        nil.next.prev = x;
        nil.next = x;
        x.prev = nil;
    }

    public void deleteNode(Node t) {
        if (t == nil) return;
        t.prev.next = t.next;
        t.next.prev = t.prev;
    }

    public void deleteFirst() {
        if (nil.next == nil) return;
        deleteNode(nil.next);
    }

    public void deleteLast() {
        if (nil.prev == nil) return;
        deleteNode(nil.prev);
    }

    public void deleteKey(int key) {
        Node t = listSearch(key);
        if (t != nil) {
            deleteNode(t);
        }
    }

    public void printList() {
        Node cur = nil.next;
        boolean isFirst = true;
        while (cur != nil) {
            if (isFirst) {
                System.out.print("[" + cur.key + "] ");
                isFirst = false;
            } else {
                System.out.print(cur.key + " ");
            }
            cur = cur.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        DoublyLinkedList list = new DoublyLinkedList();
        int size = 0;

        for (int i = 0; i < n; i++) {
            String com = scanner.next();
            int key = scanner.nextInt();

            if (com.equals("i")) {
                list.insert(key);
                size++;
            } else if (com.equals("d")) {
                if (com.length() > 6) {
                    if (com.substring(6).equals("F")) {
                        list.deleteFirst();
                    } else if (com.substring(6).equals("L")) {
                        list.deleteLast();
                    }
                } else {
                    list.deleteKey(key);
                    size--;
                }
            }
        }

        list.printList();
    }
}
