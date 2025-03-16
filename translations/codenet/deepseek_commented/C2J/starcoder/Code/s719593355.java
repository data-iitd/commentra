
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int key, i;
        int size = 0; // Keeps track of the number of elements in the list
        String com;
        int np = 0, nd = 0; // Counters for insertions and deletions

        NodePointer nil = new NodePointer(); // A dummy node used for easier list manipulation
        nil.next = nil;
        nil.prev = nil;

        for (i = 0; i < n; i++) {
            com = sc.next();
            key = sc.nextInt();

            if (com.charAt(0) == 'i') { // Insert a new node with the specified key
                insert(key);
                np++;
                size++;
            }

            else if (com.charAt(0) == 'd') { // Delete a node with the specified key or the first/last node
                if (com.length() > 6) {
                    if (com.charAt(6) == 'F') // Delete the first node
                        deleteFirst();

                    else if (com.charAt(6) == 'L') // Delete the last node
                        deleteLast();
                }

                else
                    delete(key);
                nd++;

                size--;
            }
        }

        printList(); // Print the final list
    }

    // Searches for a node with the specified key in the list
    static NodePointer listSearch(int key) {
        NodePointer cur = nil.next;

        while (cur!= nil && cur.key!= key)
            cur = cur.next;

        return cur;
    }

    // Initializes the list by creating a dummy node and setting its next and prev pointers to point to itself
    static void init() {
        nil = new NodePointer();
        nil.next = nil;
        nil.prev = nil;
    }

    // Prints the entire list from the first node to the last node
    static void printList() {
        NodePointer cur = nil.next;
        int isf = 1;
        while (1) {
            if (cur == nil)
                break;
            if (isf == 0)
                System.out.print(" ");
            System.out.print(cur.key);
            cur = cur.next;
            isf = 0;
        }
        System.out.println();
    }

    // Deletes the specified node from the list
    static void deleteNode(NodePointer t) {
        t.prev.next = t.next;
        t.next.prev = t.prev;
        free(t);
    }

    // Deletes the first node in the list
    static void deleteFirst() {
        NodePointer t = nil.next;
        if (t == nil)
            return;

        deleteNode(t);
    }

    // Deletes the last node in the list
    static void deleteLast() {
        NodePointer t = nil.prev;
        if (t == nil)
            return;

        deleteNode(t);
    }

    // Deletes the node with the specified key from the list
    static void delete(int key) {
        NodePointer t = listSearch(key);

        if (t == nil)
            return;

        deleteNode(t);
    }

    // Inserts a new node with the given key at the beginning of the list
    static void insert(int key) {
        NodePointer x = new NodePointer();
        x.key = key;

        x.next = nil.next;
        nil.next.prev = x;
        nil.next = x;
        x.prev = nil;
    }
}

