
package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        Node first = null;
        Node last = null;
        stdin.nextLine();

        while (stdin.hasNextLine()) {
            String cmd = stdin.nextLine();
            switch (cmd) {
                case "deleteFirst":
                    first = first.deleteFirst(first, last);
                    break;
                case "deleteLast":
                    last = last.deleteLast(first, last);
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

class Node {

    int key;
    Node prev;
    Node next;

    public Node(int key) {
        this.key = key;
    }

    public Node deleteFirst(Node first, Node last) {
        if (this.prev != null && this.next != null) {
            //swap
            this.prev.next = this.next;
            this.next.prev = this.prev;
            return first;
        }

        if (this.next == null && this.prev == null) {
            return null;
        }

        if (this.prev == null) {
            first = this.next;
            this.next.prev = null;
        }

        if (this.next == null) {
            last = this.prev;
            this.prev.next = null;
        }

        return first;
    }

    public Node deleteLast(Node first, Node last) {
        if (this.prev != null && this.next != null) {
            //swap
            this.prev.next = this.next;
            this.next.prev = this.prev;
            return last;
        }

        if (this.next == null && this.prev == null) {
            return null;
        }

        if (this.prev == null) {
            first = this.next;
            this.next.prev = null;
        }

        if (this.next == null) {
            last = this.prev;
            this.prev.next = null;
        }

        return last;
    }

    public Node delete(Node first, Node last) {
        if (this.prev != null && this.next != null) {
            //swap
            this.prev.next = this.next;
            this.next.prev = this.prev;
            return first;
        }

        if (this.next == null && this.prev == null) {
            return null;
        }

        if (this.prev == null) {
            first = this.next;
            this.next.prev = null;
        }

        if (this.next == null) {
            last = this.prev;
            this.prev.next = null;
        }

        return first;
    }

    public void rPrint(StringBuilder buf) {
        buf.append(this.key);
        if (this.next != null) {
            buf.append(" ");
            this.next.rPrint(buf);
        }
    }
}

