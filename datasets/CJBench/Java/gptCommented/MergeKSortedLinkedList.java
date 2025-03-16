import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    // Method to merge k sorted linked lists
    Node mergeKList(Node[] lists, int n) {
        // Check if the input lists are null or if there are no lists to merge
        if (lists == null || n == 0) {
            return null; // Return null if there are no lists
        }

        // Create a min-heap (priority queue) to store the nodes of the linked lists
        PriorityQueue<Node> minHeap = new PriorityQueue<>(Comparator.comparingInt(x -> x.data));

        // Add the head nodes of each linked list to the min-heap
        for (Node node : lists) {
            if (node != null) {
                minHeap.add(node); // Only add non-null nodes
            }
        }

        // Create a dummy node to simplify the merging process
        Node dummy = new Node(-1);
        Node curr = dummy; // Pointer to build the merged linked list

        // While there are nodes in the min-heap, continue merging
        while (!minHeap.isEmpty()) {
            // Get the smallest node from the heap
            Node temp = minHeap.poll();
            curr.next = temp; // Link the current node to the merged list
            curr = temp; // Move the current pointer to the newly added node

            // If there is a next node in the list, add it to the min-heap
            if (temp.next != null) {
                minHeap.add(temp.next);
            }
        }
        // Return the head of the merged linked list, which is next to the dummy node
        return dummy.next;
    }

    // Definition of the Node class for the linked list
    static class Node {
        int data; // Data value of the node
        Node next; // Pointer to the next node in the list

        // Constructor to initialize the node with data
        Node(int data) {
            this.data = data;
            this.next = null; // Initialize next as null
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        Main merger = new Main(); // Create an instance of the Main class
        int k = scanner.nextInt(); // Read the number of linked lists
        Node[] lists = new Node[k]; // Array to hold the head nodes of the linked lists

        // Loop to read each linked list
        for (int i = 0; i < k; i++) {
            int n = scanner.nextInt(); // Read the number of nodes in the current list
            Node head = null, tail = null; // Initialize head and tail pointers for the list

            // Loop to read the values of the nodes
            for (int j = 0; j < n; j++) {
                int value = scanner.nextInt(); // Read the value for the new node
                Node newNode = new Node(value); // Create a new node

                // If this is the first node, set head and tail to the new node
                if (head == null) {
                    head = newNode;
                    tail = newNode;
                } else {
                    // Link the new node to the end of the list and update tail
                    tail.next = newNode;
                    tail = newNode;
                }
            }
            lists[i] = head; // Store the head of the current linked list in the array
        }

        // Merge the k linked lists
        Node mergedHead = merger.mergeKList(lists, k);
        System.out.println("Merged sorted linked list:");

        // Print the merged linked list
        Node current = mergedHead;
        while (current != null) {
            System.out.print(current.data + " "); // Print the data of each node
            current = current.next; // Move to the next node
        }
        System.out.println(); // Print a new line after the merged list
        scanner.close(); // Close the scanner
    }
}
