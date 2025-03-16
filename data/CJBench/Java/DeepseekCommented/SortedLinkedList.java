import java.util.Scanner;
public class Main {
    private Node head; // Head of the linked list
    private Node tail; // Tail of the linked list
    
    // Constructor initializes head and tail to null
    public Main() {
        this.head = null;
        this.tail = null;
    }
    
    // Inserts a new node with the specified value in the correct position
    public void insert(int value) {
        Node newNode = new Node(value); // Create a new node
        if (head == null) {
            this.head = newNode; // If list is empty, new node is head and tail
            this.tail = newNode;
        } else if (value < head.value) {
            newNode.next = this.head; // If value is less than head, new node becomes head
            this.head = newNode;
        } else if (value > tail.value) {
            this.tail.next = newNode; // If value is greater than tail, new node becomes tail
            this.tail = newNode;
        } else {
            Node temp = head;
            while (temp.next != null && temp.next.value < value) { // Find the correct position
                temp = temp.next;
            }
            newNode.next = temp.next; // Insert the new node
            temp.next = newNode;
            if (newNode.next == null) {
                this.tail = newNode; // Update tail if new node is the new tail
            }
        }
    }
    
    // Deletes the node with the specified value from the linked list
    public boolean delete(int value) {
        if (this.head == null) {
            return false; // Return false if list is empty
        } else if (this.head.value == value) {
            if (this.head.next == null) {
                this.head = null; // If only one node, set head and tail to null
                this.tail = null;
            } else {
                this.head = this.head.next; // Update head if head is the node to delete
            }
            return true;
        } else {
            Node temp = this.head;
            while (temp.next != null) {
                if (temp.next.value == value) {
                    if (temp.next == this.tail) {
                        this.tail = temp; // Update tail if tail is the node to delete
                    }
                    temp.next = temp.next.next; // Remove the node
                    return true;
                }
                temp = temp.next;
            }
            return false; // Return false if value not found
        }
    }
    
    // Searches for a node with the specified value in the linked list
    public boolean search(int value) {
        Node temp = this.head;
        while (temp != null) {
            if (temp.value == value) {
                return true; // Return true if value is found
            }
            temp = temp.next;
        }
        return false; // Return false if value is not found
    }
    
    // Checks if the linked list is empty
    public boolean isEmpty() {
        return head == null;
    }
    
    // Returns a string representation of the linked list
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
    
    // Inner class representing a node in the linked list
    public final class Node {
        public final int value; // Value stored in the node
        public Node next; // Reference to the next node
        
        // Constructor initializes the node with the specified value
        public Node(int value) {
            this.value = value;
            this.next = null;
        }
    }
    
    // Main method providing a simple command-line interface
    public static void main(String[] args) {
        Main list = new Main();
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
                        System.out.println("Error: Unknown command");
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close();
    }
}
