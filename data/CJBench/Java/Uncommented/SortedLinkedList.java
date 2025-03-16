
import java.util.Scanner;
public class SortedLinkedList {
    private Node head;
    private Node tail;
    public SortedLinkedList() {
        this.head = null;
        this.tail = null;
    }
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
    public boolean isEmpty() {
        return head == null;
    }
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
        System.out.println("Enter commands (insert <value>, delete <value>, search <value>, isEmpty, print, exit):");
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
                        System.out.println("Unknown command: " + parts[0]);
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close();
    }
}
