import java.util.Scanner;

// Define a doubly linked list node structure
class Node {
    int key;      // The value of the node
    Node prev;   // Pointer to the previous node
    Node next;   // Pointer to the next node

    // Constructor to initialize a new node with a given key
    public Node(int key) {
        this.key = key;
    }

    // Method to recursively print the keys of the linked list starting from the current node
    public void rPrint(StringBuilder buf) {
        buf.append(key); // Append the current node's key to the buffer
        if (next != null) {
            buf.append(" "); // Add a space if there is a next node
            next.rPrint(buf); // Recursively print the next node
        }
    }

    // Method to delete the current node from the linked list
    public Node[] delete(Node first, Node last) {
        if (prev != null && next != null) {
            // Node is in the middle; update pointers of adjacent nodes
            prev.next = next;
            next.prev = prev;
            return new Node[]{first, last}; // Return unchanged first and last pointers
        }

        if (next == null && prev == null) {
            // Node is the only node in the list
            return new Node[]{null, null}; // Return null for both first and last
        }

        if (prev == null) {
            // Node is the first node
            first = next; // Update first to the next node
            if (next != null) {
                next.prev = null; // Set the previous pointer of the new first node to null
            }
        }

        if (next == null) {
            // Node is the last node
            last = prev; // Update last to the previous node
            if (prev != null) {
                prev.next = null; // Set the next pointer of the new last node to null
            }
        }

        return new Node[]{first, last}; // Return updated first and last pointers
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner to read input from standard input
        Node first = null; // Initialize pointers for the first and last nodes of the list
        Node last = null;

        // Read the first line of input (not used)
        scanner.nextLine();

        // Loop to process each command from the input
        while (scanner.hasNextLine()) {
            String cmd = scanner.nextLine(); // Get the current command
            switch (cmd) {
                case "deleteFirst":
                    // Command to delete the first node
                    if (first != null) {
                        Node[] updatedNodes = first.delete(first, last);
                        first = updatedNodes[0];
                        last = updatedNodes[1];
                    }
                    break;
                case "deleteLast":
                    // Command to delete the last node
                    if (last != null) {
                        Node[] updatedNodes = last.delete(first, last);
                        first = updatedNodes[0];
                        last = updatedNodes[1];
                    }
                    break;
                default:
                    // Handle commands that involve inserting or deleting specific keys
                    String[] xcmd = cmd.split(" "); // Split the command into parts
                    int k = Integer.parseInt(xcmd[1]); // Convert the second part to an integer
                    switch (xcmd[0]) {
                        case "delete":
                            // Command to delete a node with a specific key
                            for (Node a = first; a != null; a = a.next) {
                                if (a.key == k) {
                                    Node[] updatedNodes = a.delete(first, last); // Delete the node and update first and last
                                    first = updatedNodes[0];
                                    last = updatedNodes[1];
                                    break;
                                }
                            }
                            break;
                        case "insert":
                            // Command to insert a new node at the beginning of the list
                            Node n = new Node(k); // Initialize a new node
                            n.next = first; // Set the new node's next pointer to the current first node
                            if (first != null) {
                                first.prev = n; // Update the previous pointer of the current first node
                            }
                            first = n; // Update first to the new node
                            if (last == null) {
                                last = n; // If the list was empty, set last to the new node
                            }
                            break;
                    }
            }
        }

        StringBuilder buf = new StringBuilder();
        if (first != null) {
            first.rPrint(buf); // Print the keys of the linked list starting from the first node
        }
        System.out.println(buf.toString()); // Output the result
    }
}

// <END-OF-CODE>
