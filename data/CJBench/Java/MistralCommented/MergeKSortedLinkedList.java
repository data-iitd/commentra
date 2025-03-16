
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    // Merge k sorted linked lists into one sorted linked list
    Node mergeKList(Node[] lists, int n) {
        if (lists == null || n == 0) { // Base case: if the input is empty or null, return null
            return null;
        }

        PriorityQueue<Node> minHeap = new PriorityQueue<>(Comparator.comparingInt(x -> x.data));
        // Initialize the min heap with the heads of the input linked lists
        for (Node node : lists) {
            if (node != null) { // If the current linked list is not empty, add its head to the min heap
                minHeap.add(node);
            }
        }

        Node dummy = new Node(-1); // Create a dummy node to store the head of the merged linked list
        Node curr = dummy; // Initialize a current node to traverse the merged linked list

        while (!minHeap.isEmpty()) { // Merge the linked lists until the min heap is empty
            Node temp = minHeap.poll(); // Get the node with the minimum data from the min heap
            curr.next = temp; // Connect the current node to the merged list with the new node
            curr = temp; // Move the current node to the next node
            if (temp.next != null) { // If the current node has a next node, add it to the min heap
                minHeap.add(temp.next);
            }
        }

        return dummy.next; // Return the head of the merged linked list
    }

    static class Node {
        int data;
        Node next;

        // Constructor for a new node with given data
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read input from the console

        int k = scanner.nextInt(); // Read the number of linked lists from the console
        Node[] lists = new Node[k]; // Create an array to store the heads of the input linked lists

        for (int i = 0; i < k; i++) { // Read the data of each node in the input linked lists and store them in the array
            int n = scanner.nextInt();
            Node head = null, tail = null;
            for (int j = 0; j < n; j++) {
                int value = scanner.nextInt();
                Node newNode = new Node(value); // Create a new node with the given data
                if (head == null) { // If the linked list is empty, set the head and tail to the new node
                    head = newNode;
                    tail = newNode;
                } else { // Otherwise, connect the new node to the tail of the linked list and update the tail
                    tail.next = newNode;
                    tail = newNode;
                }
            }
            lists[i] = head; // Store the head of the linked list in the array
        }

        Node mergedHead = new Main().mergeKList(lists, k); // Call the mergeKList method to merge the linked lists
        System.out.println("Merged sorted linked list:"); // Print the header for the output
        Node current = mergedHead; // Initialize a current node to traverse the merged linked list
        while (current != null) { // Print the data of each node in the merged linked list
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println(); // Print a newline character at the end of the output
        scanner.close(); // Close the Scanner object
    }
}