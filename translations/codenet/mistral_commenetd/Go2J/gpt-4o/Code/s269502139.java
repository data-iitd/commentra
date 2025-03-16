import java.util.Scanner;

// Define a node class with key, previous and next pointers
class Node {
    int key;
    Node prev;
    Node next;

    // Constructor to initialize a new node with given key
    public Node(int key) {
        this.key = key;
    }

    // Recursive method to print the linked list in reverse order
    public void rPrint(StringBuilder buf) {
        buf.append(this.key);
        if (this.next != null) {
            buf.append(" ");
            this.next.rPrint(buf);
        }
    }

    // Method to delete a node from the linked list
    public Node[] delete(Node first, Node last) {
        // Base case: if node is the first and last node
        if (this.prev == null && this.next == null) {
            return new Node[]{null, null};
        }

        // Base case: if node is the first node
        if (this.prev == null) {
            first = this.next;
            if (this.next != null) {
                this.next.prev = null;
            }
            return new Node[]{first, last};
        }

        // Base case: if node is the last node
        if (this.next == null) {
            last = this.prev;
            this.prev.next = null;
            return new Node[]{first, last};
        }

        // General case: swap the pointers of previous and next nodes
        this.prev.next = this.next;
        this.next.prev = this.prev;
        // Return the first and last nodes after deletion
        return new Node[]{first, last};
    }
}

public class Main {
    public static void main(String[] args) {
        // Initialize scanner for standard input
        Scanner scanner = new Scanner(System.in);
        // Initialize first and last pointers to null
        Node first = null, last = null;

        // Read the first command from stdin
        String command = scanner.nextLine();

        // Process each command until EOF is reached
        while (scanner.hasNextLine()) {
            command = scanner.nextLine(); // Read the command from stdin

            // Switch statement to perform the corresponding action based on the command
            switch (command) {
                case "deleteFirst":
                    // Delete the first node from the linked list
                    if (first != null) {
                        Node[] result = first.delete(first, last);
                        first = result[0];
                        last = result[1];
                    }
                    break;
                case "deleteLast":
                    // Delete the last node from the linked list
                    if (last != null) {
                        Node[] result = last.delete(first, last);
                        first = result[0];
                        last = result[1];
                    }
                    break;
                default:
                    // Split the command into parts using space as delimiter
                    String[] xcmd = command.split(" ");
                    // Parse the key from the second part of the command
                    int k = Integer.parseInt(xcmd[1]);
                    // Switch statement to perform the corresponding action based on the command prefix
                    switch (xcmd[0]) {
                        case "delete":
                            // Search for the node with the given key in the linked list
                            for (Node a = first; a != null; a = a.next) {
                                // If the current node matches the given key, delete it
                                if (a.key == k) {
                                    Node[] result = a.delete(first, last);
                                    first = result[0];
                                    last = result[1];
                                    break;
                                }
                            }
                            break;
                        case "insert":
                            // Create a new node with the given key
                            Node n = new Node(k);
                            // Insert the new node at the beginning of the linked list
                            n.next = first;
                            if (first != null) {
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
        if (first != null) {
            first.rPrint(buf);
        }
        // Print the reversed linked list on the console
        System.out.println(buf.toString());
        // End of the code
    }
}
// <END-OF-CODE>
