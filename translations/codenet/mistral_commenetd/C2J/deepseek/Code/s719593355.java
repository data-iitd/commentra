import java.util.*;

class Node {
    int key;
    Node next;
    Node prev;

    Node(int key) {
        this.key = key;
    }
}

class DoublyLinkedList {
    Node nil;

    DoublyLinkedList() {
        nil = new Node(-1); // Nil node with a dummy key
        nil.next = nil;
        nil.prev = nil;
    }

    Node listSearch(int key) {
        Node cur = nil.next;
        while (cur != nil && cur.key != key) {
            cur = cur.next;
        }
        return cur;
    }

    void insert(int key) {
        Node x = new Node(key);
        x.next = nil.next;
        nil.next.prev = x;
        nil.next = x;
        x.prev = nil;
    }

    void deleteNode(Node t) {
        t.prev.next = t.next;
        t.next.prev = t.prev;
    }

    void deleteFirst() {
        if (nil.next == nil) return;
        deleteNode(nil.next);
    }

    void deleteLast() {
        if (nil.next == nil) return;
        deleteNode(nil.prev);
    }

    void delete(int key) {
        Node t = listSearch(key);
        if (t == nil) return;
        deleteNode(t);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DoublyLinkedList list = new DoublyLinkedList();
        int n = scanner.nextInt();
        int size = 0;
        int np = 0, nd = 0;

        for (int i = 0; i < n; i++) {
            String com = scanner.next();
            int key = scanner.nextInt();

            if (com.equals("i")) {
                list.insert(key);
                np++;
                size++;
            } else if (com.equals("d")) {
                if (com.length() > 6) {
                    if (com.charAt(6) == 'F') {
                        list.deleteFirst();
                    } else if (com.charAt(6) == 'L') {
                        list.deleteLast();
                    }
                } else {
                    list.delete(key);
                    nd++;
                }
                size--;
            }
        }

        System.out.println("Size: " + size + ", Number of insert operations: " + np + ", Number of delete operations: " + nd);

        // Free the memory occupied by the linked list (not necessary in Java, but good practice)
        while (list.nil.next != list.nil) {
            Node t = list.nil.next;
            list.nil.next = list.nil.next.next;
            t = null; // Help the garbage collector
        }
    }
}
