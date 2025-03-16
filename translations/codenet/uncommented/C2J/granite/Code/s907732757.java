
import java.util.Scanner;

class Node {
    int key;
    Node next;
    Node prev;

    Node(int key) {
        this.key = key;
    }
}

public class s907732757{
    static Node head;

    static Node makeNode(int a) {
        Node x = new Node(a);
        return x;
    }

    static void insert(int a) {
        Node x = makeNode(a);
        x.next = head.next;
        head.next.prev = x;
        head.next = x;
        x.prev = head;
    }

    static void delete(int a) {
        Node x = head;

        while (x.next!= head) {
            x = x.next;
            if (x.key == a) {
                x.prev.next = x.next;
                x.next.prev = x.prev;
                break;
            }
        }
    }

    static void deleteFirst() {
        Node x = head.next;
        head.next = x.next;
        x.next.prev = head;
    }

    static void deleteLast() {
        Node x = head.prev;
        head.prev = x.prev;
        x.prev.next = head;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        head = makeNode(0);
        head.next = head;
        head.prev = head;

        for (int i = 0; i < n; i++) {
            String op = scanner.next();
            if (op.equals("insert")) {
                int a = scanner.nextInt();
                insert(a);
            } else if (op.equals("delete")) {
                int a = scanner.nextInt();
                delete(a);
            } else if (op.equals("deleteFirst")) {
                deleteFirst();
            } else if (op.equals("deleteLast")) {
                deleteLast();
            }
        }

        Node x = head;
        while (x.next!= head) {
            System.out.print(x.next.key);
            x = x.next;
            if (x.next!= head) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}
