
import java.util.*;

/**
 * CreateAndDetectLoop provides utility methods for creating and detecting loops
 * (cycles) in a singly linked list. Loops in a linked list are created by
 * connecting the "next" pointer of one node to a previous node in the list,
 * forming a cycle.
 */
public final class CreateAndDetectLoop {

    /**
     * Private constructor to prevent instantiation of this utility class.
     */
    private CreateAndDetectLoop() {
        throw new UnsupportedOperationException("Utility class");
    }

    /**
     * Node represents an individual element in the linked list, containing
     * data and a reference to the next node.
     */
    static final class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            next = null;
        }
    }

    static Node head = null;

    /**
     * Adds a new node to the linked list.
     *
     * @param data the value of the new node
     */
    static void addNode(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }

    /**
     * Prints the linked list up to a specified limit to avoid infinite loops.
     */
    static void printList() {
        Node temp = head;
        int count = 0; // Limit output to 20 nodes for safety
        while (temp != null && count < 20) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
            count++;
        }
        if (temp != null) {
            System.out.print("... (loop detected)");
        } else {
            System.out.print("null");
        }
        System.out.println();
    }

    /**
     * Creates a loop in a linked list by connecting the next pointer of a node
     * at a specified starting position (position2) to another node at a specified
     * destination position (position1). If either position is invalid, no loop
     * will be created.
     *
     * @param head the head node of the linked list
     * @param position1 the position in the list where the loop should end
     * @param position2 the position in the list where the loop should start
     */
    static void createLoop(int position1, int position2) {
        if (position1 == 0 || position2 == 0) {
            return;
        }

        Node node1 = head;
        Node node2 = head;

        int count1 = 1;
        int count2 = 1;

        while (count1 < position1 && node1 != null) {
            node1 = node1.next;
            count1++;
        }

        while (count2 < position2 && node2 != null) {
            node2 = node2.next;
            count2++;
        }

        if (node1 != null && node2 != null) {
            node2.next = node1;
        }
    }

    /**
     * Detects the presence of a loop in the linked list using Floyd's cycle-finding
     * algorithm, also known as the "tortoise and hare" method.
     *
     * @param head the head node of the linked list
     * @return true if a loop is detected, false otherwise
     * @see <a href="https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_tortoise_and_hare">
     *     Floyd's Cycle Detection Algorithm</a>
     */
    static boolean detectLoop() {
        Node sptr = head;
        Node fptr = head;

        while (fptr != null && fptr.next != null) {
            sptr = sptr.next;
            fptr = fptr.next.next;
            if (sptr == fptr) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();

            if (command.isEmpty()) {
                continue;
            }

            if (command.equalsIgnoreCase("exit")) {
                break;
            }

            try {
                String[] parts = command.split(" ");
                switch (parts[0]) {
                    case "add":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for add");
                            break;
                        }
                        int value = Integer.parseInt(parts[1]);
                        addNode(value);
                        System.out.println("Added: " + value);
                        break;

                    case "createLoop":
                        if (parts.length < 3) {
                            System.out.println("Error: Missing positions for createLoop");
                            break;
                        }
                        int pos1 = Integer.parseInt(parts[1]);
                        int pos2 = Integer.parseInt(parts[2]);
                        createLoop(pos1, pos2);
                        System.out.println("Loop created between positions " + pos1 + " and " + pos2);
                        break;

                    case "detectLoop":
                        System.out.println("Loop detected: " + detectLoop());
                        break;

                    case "print":
                        printList();
                        break;

                    default:
                        System.out.println("Unknown command: " + parts[0]);
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }

        scanner.close();
    }
}
