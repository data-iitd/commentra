
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        NodePointer N = new NodePointer();
        init(N);
        for (int i = 0; i < n; i++) {
            String com = in.next();
            if (com.equals("insert")) {
                int key = in.nextInt();
                insert(N, key);
            } else if (com.equals("deleteFirst")) {
                deleteFirst(N);
            } else if (com.equals("deleteLast")) {
                deleteLast(N);
            } else {
                int key = in.nextInt();
                delete(N, key);
            }
        }
        printList(N);
    }

    // Define the structure for a node in the circular doubly linked list
    static class NodePointer {
        int key;
        NodePointer next;
        NodePointer prev;
    }

    // Initialize the circular doubly linked list
    static void init(NodePointer N) {
        N = new NodePointer();
        N.next = N;
        N.prev = N;
    }

    // Print the elements of the circular doubly linked list
    static void printList(NodePointer N) {
        NodePointer cur = N.next;
        int snl = 1;
        while (cur!= N) {
            if (snl == 0)
                System.out.print(" ");
            System.out.print(cur.key);
            cur = cur.next;
            snl = 0;
        }
        System.out.println();
    }

    // Delete the first node in the circular doubly linked list
    static void deleteFirst(NodePointer N) {
        NodePointer t = N.next;
        N.next = t.next;
        t.next.prev = N;
        t = null;
    }

    // Delete the last node in the circular doubly linked list
    static void deleteLast(NodePointer N) {
        NodePointer delnode = N.prev;
        N.prev = delnode.prev;
        delnode.prev.next = N;
        delnode = null;
    }

    // Delete a node with a specific key from the circular doubly linked list
    static void delete(NodePointer N, int skey) {
        int judge = 0;
        NodePointer t;
        NodePointer n;
        for (n = N.next; n!= N; n = n.next) {
            if (n.key == skey) {
                judge = 1;
            }
        }
        if (judge == 1) {
            n = N.next;
            while (n!= N) {
                if (n.key == skey)
                    break;
                n = n.next;
            }
            t = n.prev;
            t.next = n.next;
            t.next.prev = t;
            n = null;
        }
    }

    // Insert a new node with a specific key into the circular doubly linked list
    static void insert(NodePointer N, int skey) {
        NodePointer new = new NodePointer();
        new.key = skey;
        static int count = 0;
        if (count == 0) {
            new.next = N;
            N.next = new;
            new.prev = N;
            N.prev = new;
            count++;
        } else {
            new.next = N.next;
            N.next.prev = new;
            N.next = new;
            new.prev = N;
            count++;
        }
    }
}

