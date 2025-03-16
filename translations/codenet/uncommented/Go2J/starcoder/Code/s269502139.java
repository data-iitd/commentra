package main;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node first = null, last = null;
        for (int i = 0; i < n; i++) {
            String cmd = sc.next();
            switch (cmd) {
                case "deleteFirst":
                    first = deleteFirst(first, last);
                    break;
                case "deleteLast":
                    last = deleteLast(first, last);
                    break;
                default:
                    String[] xcmd = cmd.split(" ");
                    int k = Integer.parseInt(xcmd[1]);
                    Node n = new Node(k);
                    switch (xcmd[0]) {
                        case "delete":
                            for (Node a = first; a!= null; a = a.next) {
                                if (a.key == n.key) {
                                    first = delete(first, last, a);
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
        for (Node a = first; a!= null; a = a.next) {
            buf.append(a.key);
            if (a.next!= null) {
                buf.append(" ");
            }
        }
        System.out.println(buf.toString());
    }

    static Node deleteFirst(Node first, Node last) {
        if (first == null) {
            return null;
        }
        if (first.next == null) {
            return null;
        }
        first.next.prev = null;
        return first.next;
    }

    static Node deleteLast(Node first, Node last) {
        if (last == null) {
            return null;
        }
        if (last.prev == null) {
            return null;
        }
        last.prev.next = null;
        return last.prev;
    }

    static Node delete(Node first, Node last, Node n) {
        if (n.prev!= null && n.next!= null) {
            //swap
            n.prev.next = n.next;
            n.next.prev = n.prev;
            return first;
        }

        if (n.next == null && n.prev == null) {
            return null;
        }

        if (n.prev == null) {
            first = n.next;
            n.next.prev = null;
        }

        if (n.next == null) {
            last = n.prev;
            n.prev.next = null;
        }

        return first;
    }

    static class Node {
        int key;
        Node prev, next;

        Node(int key) {
            this.key = key;
        }
    }
}

