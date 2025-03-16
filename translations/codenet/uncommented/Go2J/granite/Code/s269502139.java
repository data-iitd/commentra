
import java.util.Scanner;

class Node {
    int key;
    Node prev;
    Node next;

    public Node(int key) {
        this.key = key;
    }

    public void rPrint(StringBuilder buf) {
        buf.append(String.valueOf(key));
        if (next!= null) {
            buf.append(" ");
            next.rPrint(buf);
        }
    }

    public Node[] Delete(Node first, Node last) {
        if (prev!= null && next!= null) {
            //swap
            prev.next = next;
            next.prev = prev;
            return new Node[]{first, last};
        }

        if (next == null && prev == null) {
            return new Node[]{null, null};
        }

        if (prev == null) {
            first = next;
            next.prev = null;
        }

        if (next == null) {
            last = prev;
            prev.next = null;
        }

        return new Node[]{first, last};
    }
}

public class s269502139{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Node first = null, last = null;
        scanner.nextLine();

        while (scanner.hasNextLine()) {
            String cmd = scanner.nextLine();
            switch (cmd) {
                case "deleteFirst":
                    Node[] res = first.Delete(first, last);
                    first = res[0];
                    last = res[1];
                    break;
                case "deleteLast":
                    res = last.Delete(first, last);
                    first = res[0];
                    last = res[1];
                    break;
                default:
                    String[] xcmd = cmd.split(" ");
                    int k = Integer.parseInt(xcmd[1]);
                    Node n = new Node(k);
                    switch (xcmd[0]) {
                        case "delete":
                            for (Node a = first; a!= null; a = a.next) {
                                if (a.key == k) {
                                    res = a.Delete(first, last);
                                    first = res[0];
                                    last = res[1];
                                    break;
                                }
                            }
                            break;
                        case "insert":
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
            }
        }
        StringBuilder buf = new StringBuilder();
        first.rPrint(buf);
        System.out.println(buf.toString());
    }
}

