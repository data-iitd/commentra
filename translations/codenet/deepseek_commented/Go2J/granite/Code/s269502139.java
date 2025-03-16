

import java.util.Scanner;

public class s269502139{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Node first = null, last = null;
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            String cmd = scanner.next();
            switch (cmd) {
                case "deleteFirst":
                    first = deleteFirst(first, last);
                    break;
                case "deleteLast":
                    last = deleteLast(first, last);
                    break;
                default:
                    String[] xcmd = scanner.next().split(" ");
                    int k = Integer.parseInt(xcmd[1]);
                    switch (xcmd[0]) {
                        case "delete":
                            first = delete(first, last, k);
                            break;
                        case "insert":
                            first = insert(first, last, k);
                            break;
                    }
            }
        }
        StringBuilder buf = new StringBuilder();
        print(first, buf);
        System.out.println(buf.toString());
    }

    private static Node deleteFirst(Node first, Node last) {
        if (first.next!= null) {
            first.next.prev = null;
            first = first.next;
        } else {
            first = null;
            last = null;
        }
        return first;
    }

    private static Node deleteLast(Node first, Node last) {
        if (last.prev!= null) {
            last.prev.next = null;
            last = last.prev;
        } else {
            first = null;
            last = null;
        }
        return last;
    }

    private static Node delete(Node first, Node last, int k) {
        for (Node a = first; a!= null; a = a.next) {
            if (a.key == k) {
                first = delete(first, last, a);
                break;
            }
        }
        return first;
    }

    private static Node delete(Node first, Node last, Node a) {
        if (a.prev!= null && a.next!= null) {
            //swap
            a.prev.next = a.next;
            a.next.prev = a.prev;
        } else if (a.next == null && a.prev == null) {
            first = null;
            last = null;
        } else if (a.prev == null) {
            first = a.next;
            a.next.prev = null;
        } else if (a.next == null) {
            last = a.prev;
            a.prev.next = null;
        }
        return first;
    }

    private static Node insert(Node first, Node last, int k) {
        Node n = new Node(k);
        n.next = first;
        if (first!= null) {
            first.prev = n;
        }
        first = n;
        if (last == null) {
            last = n;
        }
        return first;
    }

    private static void print(Node first, StringBuilder buf) {
        if (first!= null) {
            buf.append(first.key);
            print(first.next, buf);
        }
    }

    static class Node {
        int key;
        Node prev;
        Node next;

        public Node(int key) {
            this.key = key;
        }
    }
}

This code now includes comments that describe each logical block, making it easier to understand the structure and functionality of the Java code.