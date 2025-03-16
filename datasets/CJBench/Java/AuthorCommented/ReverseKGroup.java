import java.util.Scanner;

/**
 * The ReverseKGroup class provides functionality to reverse nodes in a
 * linked list in groups of k nodes.
 * <p>
 * This algorithm follows the approach of reversing the linked list in segments of
 * size k. If the remaining nodes are fewer than k, they remain unchanged.
 * </p>
 * <p>
 * Example:
 * Given a linked list: 1 -> 2 -> 3 -> 4 -> 5 and k = 3,
 * the output will be: 3 -> 2 -> 1 -> 4 -> 5.
 * </p>
 * <p>
 * The implementation contains:
 * - {@code length(Node head)}: A method to calculate the length of the linked list.
 * - {@code reverse(Node head, int count, int k)}: A helper method that reverses the nodes
 *   in the linked list in groups of k.
 * - {@code reverseKGroup(Node head, int k)}: The main method that initiates the reversal
 *   process by calling the reverse method.
 * </p>
 * <p>
 * Complexity:
 * <ul>
 *   <li>Time Complexity: O(n), where n is the number of nodes in the linked list.</li>
 *   <li>Space Complexity: O(1), as we are reversing in place.</li>
 * </ul>
 * </p>
 *
 * Author: Bama Charan Chhandogi (https://github.com/BamaCharanChhandogi)
 */
public class ReverseKGroup {

    static class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;
        }
    }

    /**
     * Calculates the length of the linked list.
     *
     * @param head The head node of the linked list.
     * @return The total number of nodes in the linked list.
     */
    public int length(Node head) {
        Node curr = head;
        int count = 0;
        while (curr != null) {
            curr = curr.next;
            count++;
        }
        return count;
    }

    /**
     * Reverses the linked list in groups of k nodes.
     *
     * @param head The head node of the linked list.
     * @param count The remaining number of nodes.
     * @param k The size of the group to reverse.
     * @return The new head of the reversed linked list segment.
     */
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

    /**
     * Reverses the linked list in groups of k nodes.
     *
     * @param head The head node of the linked list.
     * @param k The size of the group to reverse.
     * @return The head of the modified linked list after reversal.
     */
    public Node reverseKGroup(Node head, int k) {
        int count = length(head);
        return reverse(head, count, k);
    }

    /**
     * Main method for testing the ReverseKGroup functionality.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the number of nodes
        int n = scanner.nextInt();

        if (n <= 0) {
            System.out.println("The linked list must contain at least one node.");
            return;
        }

        // Input the linked list elements
        Node head = new Node(scanner.nextInt());
        Node temp = head;
        for (int i = 1; i < n; i++) {
            temp.next = new Node(scanner.nextInt());
            temp = temp.next;
        }

        // Input the value of k
        int k = scanner.nextInt();

        // Reverse the linked list in groups of k
        ReverseKGroup reverseKGroup = new ReverseKGroup();
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
