
public class Main {
    public static void main(String[] args) {
        int n, i, key;
        int np = 0, nd = 0;
        String com;
        Node nil = new Node();
        Node head = nil;
        Node tail = nil;

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        for (i = 0; i < n; i++) {
            com = sc.next();
            key = sc.nextInt();

            if (com.equals("i")) {
                insert(key);
                np++;
            } else if (com.equals("d")) {
                if (key == 0) {
                    deleteFirst();
                } else if (key == 1) {
                    deleteLast();
                } else {
                    delete(key);
                }
                nd++;
            }
        }

        printList();
    }

    public static void insert(int key) {
        Node x = new Node();
        x.key = key;
        x.next = head.next;
        head.next.prev = x;
        head.next = x;
        x.prev = head;
    }

    public static void deleteFirst() {
        Node t = head.next;
        if (t == nil) {
            return;
        }
        t.prev.next = t.next;
        t.next.prev = t.prev;
        t = null;
    }

    public static void deleteLast() {
        Node t = tail.prev;
        if (t == nil) {
            return;
        }
        t.prev.next = t.next;
        t.next.prev = t.prev;
        t = null;
    }

    public static void delete(int key) {
        Node t = head.next;
        while (t != nil && t.key != key) {
            t = t.next;
        }
        if (t == nil) {
            return;
        }
        t.prev.next = t.next;
        t.next.prev = t.prev;
        t = null;
    }

    public static void printList() {
        Node cur = head.next;
        boolean isf = true;
        while (cur != nil) {
            if (isf == false) {
                System.out.print(" ");
            }
            System.out.print(cur.key);
            cur = cur.next;
            isf = false;
        }
        System.out.println();
    }
}

class Node {
    int key;
    Node next;
    Node prev;
}

