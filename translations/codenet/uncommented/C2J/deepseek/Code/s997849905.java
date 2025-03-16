public class DoublyLinkedList {
    static class Node {
        int key;
        Node next;
        Node prev;
    }

    private Node N;

    public void init() {
        N = new Node();
        N.next = N;
        N.prev = N;
    }

    public void printList() {
        Node cur = N.next;
        boolean snl = true;
        while (cur != N) {
            if (!snl) System.out.print(" ");
            System.out.print(cur.key);
            cur = cur.next;
            snl = false;
        }
        System.out.println();
    }

    public void deleteFirst() {
        Node t = N.next;
        N.next = t.next;
        t.next.prev = N;
    }

    public void deleteLast() {
        Node delnode = N.prev;
        N.prev = delnode.prev;
        delnode.prev.next = N;
    }

    public void delete(int skey) {
        boolean judge = false;
        Node t;
        Node n;

        for (n = N.next; n != N; n = n.next) {
            if (n.key == skey) {
                judge = true;
            }
        }

        if (judge) {
            n = N.next;
            while (n != N) {
                if (n.key == skey) break;
                n = n.next;
            }
            t = n.prev;
            t.next = n.next;
            t.next.prev = t;
        }
    }

    public void insert(int skey) {
        Node newNode = new Node();
        newNode.key = skey;

        if (N == null) {
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
        DoublyLinkedList list = new DoublyLinkedList();
        java.util.Scanner scanner = new java.util.Scanner(System.in);
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
    }
}
