
import java.util.Scanner;

public class s997849905{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node head = new Node(0);
        head.next = head;
        head.prev = head;
        for (int i = 0; i < n; i++) {
            String command = scanner.next();
            if (command.equals("insert")) {
                int key = scanner.nextInt();
                insert(head, key);
            } else if (command.equals("deleteFirst")) {
                deleteFirst(head);
            } else if (command.equals("deleteLast")) {
                deleteLast(head);
            } else {
                int key = scanner.nextInt();
                delete(head, key);
            }
        }
        printList(head);
    }

    private static void insert(Node head, int key) {
        Node newNode = new Node(key);
        Node temp = head.next;
        newNode.next = temp;
        temp.prev = newNode;
        head.next = newNode;
        newNode.prev = head;
    }

    private static void deleteFirst(Node head) {
        Node temp = head.next;
        head.next = temp.next;
        temp.next.prev = head;
        free(temp);
    }

    private static void deleteLast(Node head) {
        Node temp = head.prev;
        head.prev = temp.prev;
        temp.prev.next = head;
        free(temp);
    }

    private static void delete(Node head, int key) {
        boolean found = false;
        Node temp = head.next;
        while (temp!= head) {
            if (temp.key == key) {
                found = true;
                break;
            }
            temp = temp.next;
        }
        if (found) {
            Node prev = temp.prev;
            Node next = temp.next;
            prev.next = next;
            next.prev = prev;
            free(temp);
        }
    }

    private static void printList(Node head) {
        Node temp = head.next;
        boolean first = true;
        while (temp!= head) {
            if (!first) {
                System.out.print(" ");
            }
            System.out.print(temp.key);
            temp = temp.next;
            first = false;
        }
        System.out.println();
    }

    private static class Node {
        int key;
        Node next;
        Node prev;

        public Node(int key) {
            this.key = key;
        }
    }
}

