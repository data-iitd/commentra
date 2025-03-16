
package main;

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

    Node[] Delete(Node[] first, Node[] last) {
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
        Node[] first = null;
        Node[] last = null;
        stdin.nextLine();

        while (stdin.hasNextLine()) {
            String cmd = stdin.nextLine();
            switch (cmd) {
                case "deleteFirst":
                    first = first[0].Delete(first, last);
                    break;
                case "deleteLast":
                    last = last[0].Delete(first, last);
                    break;
                default:
                    String[] xcmd = cmd.split(" ");
                    int k = Integer.parseInt(xcmd[1]);
                    switch (xcmd[0]) {
                        case "delete":
                            for (Node a = first[0]; a != null; a = a.next) {
                                if (a.key == k) {
                                    first = a.Delete(first, last);
                                    break;
                                }
                            }
                            break;
                        case "insert":
                            Node n = new Node(k);
                            n.next = first[0];
                            if (first[0] != null) {
                                first[0].prev = n;
                            }

                            first[0] = n;
                            if (last[0] == null) {
                                last[0] = n;
                            }
                            break;
                    }
                    break;
            }
        }
        StringBuilder buf = new StringBuilder();
        first[0].rPrint(buf);
        System.out.println(buf.toString());
    }
}

