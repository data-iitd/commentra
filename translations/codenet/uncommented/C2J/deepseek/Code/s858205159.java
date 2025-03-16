public class DoublyLinkedList {
    static class Node {
        int key;
        Node next;
        Node prev;
    }

    private Node nil;

    public DoublyLinkedList() {
        init();
    }

    public void init() {
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

    public void printList() {
        Node cur = nil.next;
        boolean isf = true;
        while (true) {
            if (cur == nil) break;
            if (!isf) System.out.print(" ");
            System.out.print(cur.key);
            cur = cur.next;
            isf = false;
        }
        System.out.println();
    }

    public void deleteNode(Node t) {
        if (t == nil) return;
        t.prev.next = t.next;
        t.next.prev = t.prev;
        t = null; // Help the garbage collector
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
        DoublyLinkedList dll = new DoublyLinkedList();
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        for (int i = 0; i < n; i++) {
            String com = scanner.next();
            int key = scanner.nextInt();
            if (com.equals("i")) {
                dll.insert(key);
            } else if (com.equals("d")) {
                if (com.length() > 6) {
                    if (com.substring(6).equals("F")) {
                        dll.deleteFirst();
                    } else if (com.substring(6).equals("L")) {
                        dll.deleteLast();
                    }
                } else {
                    dll.deleteKey(key);
                }
            }
        }
        dll.printList();
    }
}
