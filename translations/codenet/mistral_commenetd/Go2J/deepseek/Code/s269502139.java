import java.util.Scanner;

class Node {
    int key;
    Node prev;
    Node next;

    Node(int key) {
        this.key = key;
    }

    // Recursive function to print the linked list in reverse order
    void rPrint(StringBuilder buf) {
        buf.append(key);
        if (next != null) {
            buf.append(" ");
            next.rPrint(buf);
        }
    }

    // Function to delete a node from the linked list
    Node delete(Node first, Node last) {
        // Base case: if node is the first and last node
        if (prev == null && next == null) {
            return null;
        }

        // Base case: if node is the first node
        if (prev == null) {
            first = next;
            if (next != null) {
                next.prev = null;
            }
            return first;
        }

        // Base case: if node is the last node
        if (next == null) {
            last = prev;
            prev.next = null;
            return first;
        }

        // General case: swap the pointers of previous and next nodes
        prev.next = next;
        next.prev = prev;
        // Return the first and last nodes after deletion
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

            if (cmd.equals("deleteFirst")) {
                first = first.delete(first, last);
            } else if (cmd.equals("deleteLast")) {
                if (last != null) {
                    last = last.delete(first, last);
                }
            } else {
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
            }
        }

        StringBuilder buf = new StringBuilder();
        if (first != null) {
            first.rPrint(buf);
        }
        System.out.println(buf.toString());
    }
}
