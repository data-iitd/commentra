import java.util.Scanner;

// Define the `Node` class
// This class represents a node in a doubly linked list.
// It contains an integer key, and references to the previous and next nodes.
class Node {
    int key;
    Node prev;
    Node next;

    // Node Initialization
    // The constructor creates a new node with the given key.
    public Node(int key) {
        this.key = key;
    }

    // Recursive Print Function
    // The `rPrint` method prints the keys of the nodes in the list from the current node to the last node.
    public void rPrint(StringBuilder buf) {
        buf.append(key);
        if (next != null) {
            buf.append(" ");
            next.rPrint(buf);
        }
    }

    // Delete Method
    // The `delete` method removes the current node from the list and adjusts the references of the surrounding nodes.
    public Node[] delete(Node first, Node last) {
        if (prev != null && next != null) {
            // Swap
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

// Main Class
public class Main {
    // Main Function
    // The main function reads commands from standard input, performs operations on the doubly linked list, and prints the final list.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Node first = null, last = null;

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
