
import java.util.Scanner;
public class Main {
    // Represents a node in a singly linked list
    static class Node {
        int value;
        Node next;
        Node(int value) {
            this.value = value;
        }
    }
    // Calculates the length of the linked list
    public int length(Node head) {
        Node curr = head;
        int count = 0;
        while (curr != null) {
            curr = curr.next;
            count++;
        }
        return count;
    }
    // Reverses a sublist of the linked list of size k
    public Node reverse(Node head, int count, int k) {
        if (count < k) {
            return head;
        }
        Node prev = null;
        int count1 = 0;
        Node curr = head;
        Node next = null;
        while (curr != null && count1 < k) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            count1++;
        }
        if (next != null) {
            head.next = reverse(next, count - k, k);
        }
        return prev;
    }
    // Reverses the linked list in groups of k
    public Node reverseKGroup(Node head, int k) {
        int count = length(head);
        return reverse(head, count, k);
    }
    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of nodes in the linked list
        int n = scanner.nextInt();
        if (n <= 0) {
            System.out.println("The linked list must contain at least one node.");
            return;
        }
        // Create the linked list from the input
        Node head = new Node(scanner.nextInt());
        Node temp = head;
        for (int i = 1; i < n; i++) {
            temp.next = new Node(scanner.nextInt());
            temp = temp.next;
        }
        // Read the group size k
        int k = scanner.nextInt();
        Main reverseKGroup = new Main();
        // Reverse the linked list in groups of k
        head = reverseKGroup.reverseKGroup(head, k);
        // Print the modified linked list
        System.out.println("Modified linked list:");
        temp = head;
        while (temp != null) {
            System.out.print(temp.value + " ");
            temp = temp.next;
        }
        System.out.println();
        scanner.close();
    }
}