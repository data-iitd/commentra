
import java.util.Scanner;

public class s269502139{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Node first = null, last = null;
        scanner.nextLine();

        while (scanner.hasNextLine()) {
            String cmd = scanner.nextLine();
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
                            for (Node a = first; a!= null; a = a.next) {
                                if (a.key == k) {
                                    first = a.delete(first, last);
                                    break;
                                }
                            }
                            break;
                        case "insert":
                            Node n = new Node(k);
                            n.next = first;
                            if (first!= null) {
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

class Node {
    int key;
    Node prev, next;

    public Node(int key) {
        this.key = key;
    }

    public Node delete(Node first, Node last) {
        if (prev!= null && next!= null) {
            // Node is in the middle; update pointers of adjacent nodes
            prev.next = next;
            next.prev = prev;
            return first;
        }

        if (next == null && prev == null) {
            // Node is the only node in the list
            return null;
        }

        if (prev == null) {
            // Node is the first node
            first = next;
            next.prev = null;
        }

        if (next == null) {
            // Node is the last node
            last = prev;
            prev.next = null;
        }

        return first;
    }

    public void rPrint(StringBuilder buf) {
        buf.append(key);
        if (next!= null) {
            buf.append(" ");
            next.rPrint(buf);
        }
    }
}

// Translate the above Java code to C++ and end with comment "