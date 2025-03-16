
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        Node first = null;
        Node last = null;

        while (stdin.hasNext()) {
            String cmd = stdin.nextLine();
            switch (cmd) {
                case "deleteFirst":
                    first = deleteFirst(first, last);
                    break;
                case "deleteLast":
                    first = deleteLast(first, last);
                    break;
                default:
                    String[] xcmd = cmd.split(" ");
                    int k = Integer.parseInt(xcmd[1]);
                    switch (xcmd[0]) {
                        case "delete":
                            first = delete(first, last, k);
                            break;
                        case "insert":
                            first = insert(first, last, k);
                            break;
                    }
                    break;
            }
        }
        printReverse(first);
    }

    private static Node deleteFirst(Node first, Node last) {
        if (first == null) {
            return null;
        }
        if (first.next == null) {
            last = null;
        }
        first = first.next;
        if (first != null) {
            first.prev = null;
        }
        return first;
    }

    private static Node deleteLast(Node first, Node last) {
        if (last == null) {
            return null;
        }
        if (last.prev == null) {
            first = null;
        }
        last = last.prev;
        if (last != null) {
            last.next = null;
        }
        return first;
    }

    private static Node delete(Node first, Node last, int k) {
        for (Node a = first; a != null; a = a.next) {
            if (a.key == k) {
                first = delete(first, last, a);
                break;
            }
        }
        return first;
    }

    private static Node delete(Node first, Node last, Node a) {
        if (a.prev == null) {
            first = a.next;
        } else {
            a.prev.next = a.next;
        }
        if (a.next == null) {
            last = a.prev;
        } else {
            a.next.prev = a.prev;
        }
        return first;
    }

    private static Node insert(Node first, Node last, int k) {
        Node n = new Node(k);
        n.next = first;
        if (first != null) {
            first.prev = n;
        }
        if (last == null) {
            last = n;
        }
        first = n;
        return first;
    }

    private static void printReverse(Node first) {
        if (first == null) {
            return;
        }
        printReverse(first.next);
        System.out.print(first.key + " ");
    }

    private static class Node {
        int key;
        Node prev;
        Node next;

        public Node(int key) {
            this.key = key;
        }
    }
}

