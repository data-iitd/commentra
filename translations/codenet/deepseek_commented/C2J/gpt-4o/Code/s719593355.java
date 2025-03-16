import java.util.Scanner;

class Node {
    int key;
    Node next;
    Node prev;

    Node(int key) {
        this.key = key;
    }
}

public class DoublyLinkedList {
    private Node nil; // A dummy node used for easier list manipulation

    // Initializes the list by creating a dummy node and setting its next and prev pointers
    public void init() {
        nil = new Node(0);
        nil.next = nil;
        nil.prev = nil;
    }

    // Searches for a node with the specified key in the list
    public Node listSearch(int key) {
        Node cur = nil.next;

        while (cur != nil && cur.key != key) {
            cur = cur.next;
        }

        return cur;
    }

    // Prints the entire list from the first node to the last node
    public void printList() {
        Node cur = nil.next;
        boolean isFirst = true;

        while (cur != nil) {
            if (!isFirst) {
                System.out.print(" ");
            }
            System.out.print(cur.key);
            cur = cur.next;
            isFirst = false;
        }
        System.out.println();
    }

    // Deletes the specified node from the list
    public void deleteNode(Node t) {
        t.prev.next = t.next;
        t.next.prev = t.prev;
    }

    // Deletes the first node in the list
    public void deleteFirst() {
        Node t = nil.next;
        if (t == nil) return;

        deleteNode(t);
    }

    // Deletes the last node in the list
    public void deleteLast() {
        Node t = nil.prev;
        if (t == nil) return;

        deleteNode(t);
    }

    // Deletes the node with the specified key from the list
    public void delete(int key) {
        Node t = listSearch(key);

        if (t == nil) return;

        deleteNode(t);
    }

    // Inserts a new node with the given key at the beginning of the list
    public void insert(int key) {
        Node x = new Node(key);

        x.next = nil.next;
        nil.next.prev = x;
        nil.next = x;
        x.prev = nil;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DoublyLinkedList list = new DoublyLinkedList();
        list.init();

        int n = scanner.nextInt();
        int size = 0; // Keeps track of the number of elements in the list
        int np = 0, nd = 0; // Counters for insertions and deletions

        for (int i = 0; i < n; i++) {
            String command = scanner.next();
            int key = scanner.nextInt();

            if (command.charAt(0) == 'i') { // Insert a new node with the specified key
                list.insert(key);
                np++;
                size++;
            } else if (command.charAt(0) == 'd') { // Delete a node with the specified key or the first/last node
                if (command.length() > 6) {
                    if (command.charAt(6) == 'F') // Delete the first node
                        list.deleteFirst();
                    else if (command.charAt(6) == 'L') // Delete the last node
                        list.deleteLast();
                } else {
                    list.delete(key);
                    nd++;
                }
                size--;
            }
        }

        list.printList(); // Print the final list
        scanner.close();
    }
}

// <END-OF-CODE>
