import java.util.*;

class Node {
    int key;
    Node prev;
    Node next;

    Node(int key) {
        this.key = key;
    }

    // Recursive Print Function
    void rPrint(StringBuilder buf) {
        buf.append(key);
        if (next != null) {
            buf.append(" ");
            next.rPrint(buf);
        }
    }

    // Delete Method
    Node delete(Node first, Node last) {
        if (prev != null && next != null) {
            prev.next = next;
            next.prev = prev;
            return first;
        }

        if (next == null && prev == null) {
            return null;
        }

        if (prev == null) {
            first = next;
            if (next != null) {
                next.prev = null;
            }
        }

        if (next == null) {
            last = prev;
            if (prev != null) {
                prev.next = null;
            }
        }

        return first;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Node first = null;
        Node last = null;

        while (scanner.hasNextLine()) {
            String cmd = scanner.nextLine();
            String[] xcmd = cmd.split(" ");

            switch (xcmd[0]) {
                case "deleteFirst":
                    first = first.delete(first, last);
                    break;
                case "deleteLast":
                    if (last != null) {
                        last = last.delete(first, last);
                    }
                    break;
                default:
                    int k = Integer.parseInt(xcmd[1]);
                    Node n = new Node(k);

                    switch (xcmd[0]) {
                        case "delete":
                            Node current = first;
                            while (current != null) {
                                if (current.key == k) {
                                    first = current.delete(first, last);
                                    break;
                                }
                                current = current.next;
                            }
                            break;
                        case "insert":
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
            }
        }

        StringBuilder buf = new StringBuilder();
        if (first != null) {
            first.rPrint(buf);
        }
        System.out.println(buf.toString());
    }
}
