
import java.util.Scanner;

/**
 * The SortedLinkedList class represents a singly linked list that maintains its elements in sorted order.
 * Elements are ordered based on their natural ordering, with smaller elements at the head and larger elements toward the tail.
 * The class provides methods for inserting, deleting, and searching elements, as well as checking if the list is empty.
 * <p>
 * This implementation utilizes a singly linked list to maintain a dynamically sorted list.
 * </p>
 * <p>
 * Further information can be found here:
 * https://runestone.academy/ns/books/published/cppds/LinearLinked/ImplementinganOrderedList.html
 * </p>
 *
 * <b>Usage Example:</b>
 * <pre>
 *     SortedLinkedList list = new SortedLinkedList();
 *     list.insert(10);
 *     list.insert(5);
 *     list.insert(20);
 *     System.out.println(list); // Outputs: [5, 10, 20]
 * </pre>
 */
public class SortedLinkedList {
    private Node head;
    private Node tail;

    /**
     * Initializes an empty sorted linked list.
     */
    public SortedLinkedList() {
        this.head = null;
        this.tail = null;
    }

    /**
     * Inserts a new integer into the list, maintaining sorted order.
     *
     * @param value the integer to insert
     */
    public void insert(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            this.head = newNode;
            this.tail = newNode;
        } else if (value < head.value) {
            newNode.next = this.head;
            this.head = newNode;
        } else if (value > tail.value) {
            this.tail.next = newNode;
            this.tail = newNode;
        } else {
            Node temp = head;
            while (temp.next != null && temp.next.value < value) {
                temp = temp.next;
            }
            newNode.next = temp.next;
            temp.next = newNode;
            if (newNode.next == null) {
                this.tail = newNode;
            }
        }
    }

    /**
     * Deletes the first occurrence of a specified integer in the list.
     *
     * @param value the integer to delete
     * @return {@code true} if the element was found and deleted; {@code false} otherwise
     */
    public boolean delete(int value) {
        if (this.head == null) {
            return false;
        } else if (this.head.value == value) {
            if (this.head.next == null) {
                this.head = null;
                this.tail = null;
            } else {
                this.head = this.head.next;
            }
            return true;
        } else {
            Node temp = this.head;
            while (temp.next != null) {
                if (temp.next.value == value) {
                    if (temp.next == this.tail) {
                        this.tail = temp;
                    }
                    temp.next = temp.next.next;
                    return true;
                }
                temp = temp.next;
            }
            return false;
        }
    }

    /**
     * Searches for a specified integer in the list.
     *
     * @param value the integer to search for
     * @return {@code true} if the value is present in the list; {@code false} otherwise
     */
    public boolean search(int value) {
        Node temp = this.head;
        while (temp != null) {
            if (temp.value == value) {
                return true;
            }
            temp = temp.next;
        }
        return false;
    }

    /**
     * Checks if the list is empty.
     *
     * @return {@code true} if the list is empty; {@code false} otherwise
     */
    public boolean isEmpty() {
        return head == null;
    }

    /**
     * Returns a string representation of the sorted linked list in the format [element1, element2, ...].
     *
     * @return a string representation of the sorted linked list
     */
    @Override
    public String toString() {
        if (this.head != null) {
            StringBuilder sb = new StringBuilder("[");
            Node temp = this.head;
            while (temp != null) {
                sb.append(temp.value);
                if (temp.next != null) {
                    sb.append(", ");
                }
                temp = temp.next;
            }
            sb.append("]");
            return sb.toString();
        } else {
            return "[]";
        }
    }

    /**
     * Node represents an element in the sorted linked list.
     */
    public final class Node {
        public final int value;
        public Node next;

        public Node(int value) {
            this.value = value;
            this.next = null;
        }
    }

    public static void main(String[] args) {
        SortedLinkedList list = new SortedLinkedList();
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
                    case "insert":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for insert");
                            break;
                        }
                        int insertValue = Integer.parseInt(parts[1]);
                        list.insert(insertValue);
                        System.out.println("Inserted: " + insertValue);
                        break;

                    case "delete":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for delete");
                            break;
                        }
                        int deleteValue = Integer.parseInt(parts[1]);
                        boolean deleted = list.delete(deleteValue);
                        System.out.println(deleted ? "Deleted: " + deleteValue : "Value not found: " + deleteValue);
                        break;

                    case "search":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for search");
                            break;
                        }
                        int searchValue = Integer.parseInt(parts[1]);
                        boolean found = list.search(searchValue);
                        System.out.println(found ? "Found: " + searchValue : "Not found: " + searchValue);
                        break;

                    case "isEmpty":
                        System.out.println("Is empty: " + list.isEmpty());
                        break;

                    case "print":
                        System.out.println("List: " + list);
                        break;

                    default:
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }

        scanner.close();
    }
}
