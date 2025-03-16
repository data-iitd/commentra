
import java.util.Scanner;

class Node {
    int key;
    Node prev;
    Node next;

    Node(int key) {
        this.key = key;
    }

    void rPrint(StringBuilder buf) {
        buf.append(key);
        if (next != null) {
            buf.append(" ");
            next.rPrint(buf);
        }
    }

    Node delete(Node first, Node last) {
        if (prev != null && next != null) {
            //swap
            prev.next = next;
            next.prev = prev;
            return first;
        }

        if (next == null && prev == null) {
            return null;
        }

        if (prev == null) {
            first = next;
            next.prev = null;
        }

        if (next == null) {
            last = prev;
            prev.next = null;
        }

        return first;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        Node first = null;
        Node last = null;
        while (stdin.hasNext()) {
            String cmd = stdin.nextLine();
            switch (cmd) {
                case "deleteFirst":
                    first = first.delete(first, last);
                    break;
                case "deleteLast":
                    last = last.delete(first, last);
                    break;
                default:
                    String[] xcmd = cmd.split(" ");
                    int k = Integer.parseInt(xcmd[1]);
                    switch (xcmd[0]) {
                        case "delete":
                            for (Node a = first; a != null; a = a.next) {
                                if (a.key == k) {
                                    first = a.delete(first, last);
                                    break;
                                }
                            }
                            break;
                        case "insert":
                            Node n = new Node(k);
                            n.next = first;
                            if (first != null) {
                                first.prev = n;
                            }

                            first = n;
                            if (last == null) {
                                last = n;
                            }
                            break;
                    }
                    break;
            }
        }
        StringBuilder buf = new StringBuilder();
        first.rPrint(buf);
        System.out.println(buf.toString());
    }
}

