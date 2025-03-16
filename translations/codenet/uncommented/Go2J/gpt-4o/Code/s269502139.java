import java.util.Scanner;

class Node {
    int key;
    Node prev;
    Node next;

    public Node(int key) {
        this.key = key;
    }

    public void rPrint(StringBuilder buf) {
        buf.append(key);
        if (next != null) {
            buf.append(" ");
            next.rPrint(buf);
        }
    }

    public Node[] delete(Node first, Node last) {
        if (prev != null && next != null) {
            // swap
            prev.next = next;
            next.prev = prev;
            return new Node[]{first, last};
        }

        if (next == null && prev == null) {
            return new Node[]{null, null};
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

        return new Node[]{first, last};
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Node first = null;
        Node last = null;

        while (scanner.hasNextLine()) {
            String cmd = scanner.nextLine();
            switch (cmd) {
                case "deleteFirst":
                    if (first != null) {
                        Node[] result = first.delete(first, last);
                        first = result[0];
                        last = result[1];
                    }
                    break;
                case "deleteLast":
                    if (last != null) {
                        Node[] result = last.delete(first, last);
                        first = result[0];
                        last = result[1];
                    }
                    break;
                default:
                    String[] xcmd = cmd.split(" ");
                    int k = Integer.parseInt(xcmd[1]);
                    switch (xcmd[0]) {
                        case "delete":
                            for (Node a = first; a != null; a = a.next) {
                                if (a.key == k) {
                                    Node[] result = a.delete(first, last);
                                    first = result[0];
                                    last = result[1];
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
            }
        }

        StringBuilder buf = new StringBuilder();
        if (first != null) {
            first.rPrint(buf);
        }
        System.out.println(buf.toString());
    }
}

// <END-OF-CODE>
