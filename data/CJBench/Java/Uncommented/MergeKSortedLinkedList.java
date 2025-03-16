import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;
public class MergeKSortedLinkedList {
    Node mergeKList(Node[] lists, int n) {
        if (lists == null || n == 0) {
            return null;
        }
        PriorityQueue<Node> minHeap = new PriorityQueue<>(Comparator.comparingInt(x -> x.data));
        for (Node node : lists) {
            if (node != null) {
                minHeap.add(node);
            }
        }
        Node dummy = new Node(-1);
        Node curr = dummy;
        while (!minHeap.isEmpty()) {
            Node temp = minHeap.poll();
            curr.next = temp;
            curr = temp;
            if (temp.next != null) {
                minHeap.add(temp.next);
            }
        }
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
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        MergeKSortedLinkedList merger = new MergeKSortedLinkedList();
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
