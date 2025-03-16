

import java.util.Scanner;

public class s269502139{
    // Define a node structure with key, previous and next pointers
    static class Node {
        int key;
        Node prev;
        Node next;

        public Node(int key) {
            this.key = key;
        }
    }

    // Recursive function to print the linked list in reverse order
    static void rPrint(Node n, StringBuilder buf) {
        buf.append(n.key);
        if (n.next!= null) {
            // Recursively call rPrint function for next node
            buf.append(" ");
            rPrint(n.next, buf);
        }
    }

    // Function to delete a node from the linked list
    static void delete(Node n, Node first, Node last) {
        // Base case: if node is the first and last node
        if (n.prev == null && n.next == null) {
            first = null;
            last = null;
            return;
        }

        // Base case: if node is the first node
        if (n.prev == null) {
            first = n.next;
            n.next.prev = null;
            return;
        }

        // Base case: if node is the last node
        if (n.next == null) {
            last = n.prev;
            n.prev.next = null;
            return;
        }

        // General case: swap the pointers of previous and next nodes
        n.prev.next = n.next;
        n.next.prev = n.prev;
    }

    // s269502139 function to read commands from stdin and perform the corresponding actions
    public static void main(String[] args) {
        // Initialize standard input scanner
        Scanner scanner = new Scanner(System.in);
        // Initialize first and last pointers to null
        Node first = null;
        Node last = null;

        // Read the first command from stdin
        scanner.nextLine();

        // Process each command until EOF is reached
        while (scanner.hasNextLine()) {
            String cmd = scanner.nextLine(); // Read the command from stdin

            // Switch statement to perform the corresponding action based on the command
            switch (cmd) {
                case "deleteFirst":
                    // Delete the first node from the linked list
                    delete(first, first, last);
                    break;
                case "deleteLast":
                    // Delete the last node from the linked list
                    delete(last, first, last);
                    break;
                default:
                    // Split the command into parts using space as delimiter
                    String[] xcmd = cmd.split(" ");
                    // Parse the key from the second part of the command
                    int k = Integer.parseInt(xcmd[1]);
                    // Create a new node with the given key
                    Node n = new Node(k);
                    // Switch statement to perform the corresponding action based on the command prefix
                    switch (xcmd[0]) {
                        case "delete":
                            // Search for the node with the given key in the linked list
                            for (Node a = first; a!= null; a = a.next) {
                                // If the current node matches the given key, delete it
                                if (a.key == k) {
                                    delete(a, first, last);
                                    break;
                                }
                            }
                            break;
                        case "insert":
                            // Insert the new node at the beginning of the linked list
                            n.next = first;
                            if (first!= null) {
                                first.prev = n;
                            }

                            // Update the first and last pointers
                            first = n;
                            if (last == null) {
                                last = n;
                            }
                            break;
                    }
            }
        }
        // Print the linked list in reverse order
        StringBuilder buf = new StringBuilder();
        rPrint(first, buf);
        // Print the reversed linked list on the console
        System.out.println(buf.toString());
        // End of the code
    }
}

