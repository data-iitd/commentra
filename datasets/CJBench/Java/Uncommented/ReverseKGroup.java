import java.util.Scanner;
public class ReverseKGroup {
    static class Node {
        int value;
        Node next;
        Node(int value) {
            this.value = value;
        }
    }
    public int length(Node head) {
        Node curr = head;
        int count = 0;
        while (curr != null) {
            curr = curr.next;
            count++;
        }
        return count;
    }
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
    public Node reverseKGroup(Node head, int k) {
        int count = length(head);
        return reverse(head, count, k);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        if (n <= 0) {
            System.out.println("The linked list must contain at least one node.");
            return;
        }
        Node head = new Node(scanner.nextInt());
        Node temp = head;
        for (int i = 1; i < n; i++) {
            temp.next = new Node(scanner.nextInt());
            temp = temp.next;
        }
        int k = scanner.nextInt();
        ReverseKGroup reverseKGroup = new ReverseKGroup();
        head = reverseKGroup.reverseKGroup(head, k);
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
