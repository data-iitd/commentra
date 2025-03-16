
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int key, i;
        int size = 0;
        String com;
        int np = 0, nd = 0;

        NodePointer nil = new NodePointer();
        nil.next = nil;
        nil.prev = nil;

        for (i = 0; i < n; i++) {
            com = sc.next();
            key = sc.nextInt();

            if (com.charAt(0) == 'i') {
                insert(key);
                np++;
                size++;
            } else if (com.charAt(0) == 'd') {
                if (com.length() > 6) {
                    if (com.charAt(6) == 'F')
                        deleteFirst();
                    else if (com.charAt(6) == 'L')
                        deleteLast();
                } else
                    delete(key);
                nd++;
                size--;
            }
        }

        printList();
    }

    static class NodePointer {

        int key;
        NodePointer next;
        NodePointer prev;
    }

    static NodePointer listSearch(int key) {
        NodePointer cur = nil.next;

        while (cur!= nil && cur.key!= key)
            cur = cur.next;

        return cur;
    }

    static void init() {
        nil = new NodePointer();
        nil.next = nil;
        nil.prev = nil;
    }

    static void printList() {
        NodePointer cur = nil.next;
        int isf = 1;
        while (1) {
            if (cur == nil)
                break;
            if (isf == 0)
                System.out.print(" ");
            System.out.print(cur.key);
            cur = cur.next;
            isf = 0;
        }
        System.out.println();
    }

    static void deleteNode(NodePointer t) {
        t.prev.next = t.next;
        t.next.prev = t.prev;
        t = null;
    }

    static void deleteFirst() {
        NodePointer t = nil.next;
        if (t == nil)
            return;

        deleteNode(t);
    }

    static void deleteLast() {
        NodePointer t = nil.prev;
        if (t == nil)
            return;

        deleteNode(t);
    }

    static void delete(int key) {
        NodePointer t = listSearch(key);

        if (t == nil)
            return;

        deleteNode(t);
    }

    static void insert(int key) {
        NodePointer x = new NodePointer();
        x.key = key;

        x.next = nil.next;
        nil.next.prev = x;
        nil.next = x;
        x.prev = nil;
    }
}

