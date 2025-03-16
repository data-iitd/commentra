import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;
public class Main {
    // This method merges k sorted linked lists into one sorted linked list.
    Node mergeKList(Node[] lists, int n) {
        if (lists == null || n == 0) {
            return null;
        }
        // A priority queue (min-heap) is used to store the heads of the k linked lists.
        PriorityQueue<Node> minHeap = new PriorityQueue<>(Comparator.comparingInt(x -> x.data));
        for (Node node : lists) {
            if (node != null) {
                // Add the head of each non-null linked list to the min-heap.
                minHeap.add(node);
            }
        }
        // Create a dummy node to help with the merging process.
        Node dummy = new Node(-1);
        Node curr = dummy;
        while (!minHeap.isEmpty()) {
            // Extract the node with the smallest value from the min-heap.
            Node temp = minHeap.poll();
            // Link the current node to the extracted node.
            curr.next = temp;
            // Move the current node pointer to the extracted node.
            curr = temp;
            // If the extracted node has a next node, add it to the min-heap.
            if (temp.next != null) {
                minHeap.add(temp.next);
            }
        }
        // Return the merged linked list starting from the next node of the dummy node.
        return dummy.next;
    }
    static class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
    // The main method is the entry point of the program.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main merger = new Main();
        int k = scanner.nextInt();
        Node[] lists = new Node[k];
        for (int i = 0; i < k; i++) {
            int n = scanner.nextInt();
            Node head = null, tail = null;
            for (int j = 0; j < n; j++) {
                int value = scanner.nextInt();
                Node newNode = new Node(value);
                if (head == null) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail.next = newNode;
                    tail = newNode;
                }
            }
            lists[i] = head;
        }
        Node mergedHead = merger.mergeKList(lists, k);
        System.out.println("Merged sorted linked list:");
        Node current = mergedHead;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
        scanner.close();
    }
}
