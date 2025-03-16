import java.util.*;
public final class Main {
    private Main() {
        throw new UnsupportedOperationException("Utility class");
    }
    // Define a node class with data and next pointers
    static final class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
            next = null;
        }
    }
    // Head node of the linked list
    static Node head = null;
    // Method to add a new node to the end of the list
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
    // Method to print the list up to 20 nodes or until the end of the list
    static void printList() {
        Node temp = head;
        int count = 0; 
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
    // Method to create a loop in the list at specified positions
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
    // Method to detect if there is a loop in the list using Floyd's Tortoise and Hare algorithm
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
    // Main method to handle user input for adding nodes, creating loops, detecting loops, and printing the list
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
