import java.util.Scanner;
import java.util.Objects;

public class Main {
    // Node class representing each element in the linked list
    private static class Node<T> {
        T element; // The value stored in the node
        int next;  // Index of the next node in the list

        // Constructor to initialize the node with an element and next index
        Node(T element, int next) {
            this.element = element;
            this.next = next;
        }
    }

    private final int os; // Index of the first free node in the cursor space
    private int head; // Index of the first node in the linked list
    private final Node<T>[] cursorSpace; // Array to hold the nodes
    private int count; // Number of elements in the linked list
    private static final int CURSOR_SPACE_SIZE = 100; // Size of the cursor space

    // Static initializer block to set up the cursor space
    {
        cursorSpace = new Node[CURSOR_SPACE_SIZE];
        for (int i = 0; i < CURSOR_SPACE_SIZE; i++) {
            cursorSpace[i] = new Node<>(null, i + 1); // Initialize each node
        }
        cursorSpace[CURSOR_SPACE_SIZE - 1].next = 0; // Last node points to the first
    }

    // Constructor to initialize the linked list
    public Main() {
        os = 0; // Start of the free space
        count = 0; // Initial count of elements
        head = -1; // Indicates the list is empty
    }

    // Method to print the elements of the linked list
    public void printList() {
        if (head != -1) { // Check if the list is not empty
            int start = head; // Start from the head
            while (start != -1) { // Traverse until the end of the list
                T element = cursorSpace[start].element; // Get the element
                System.out.print(element + " -> "); // Print the element
                start = cursorSpace[start].next; // Move to the next node
            }
        }
        System.out.println("null"); // Indicate the end of the list
    }

    // Method to find the index of a specific element in the list
    public int indexOf(T element) {
        if (element == null) {
            throw new NullPointerException("Element cannot be null"); // Check for null
        }
        int current = head; // Start from the head
        int index = 0; // Initialize index
        while (current != -1) { // Traverse the list
            if (Objects.equals(cursorSpace[current].element, element)) { // Check for equality
                return index; // Return the index if found
            }
            current = cursorSpace[current].next; // Move to the next node
            index++; // Increment index
        }
        return -1; // Return -1 if not found
    }

    // Method to get the element at a specific position
    public T get(int position) {
        if (position >= 0 && position < count) { // Check if position is valid
            int start = head; // Start from the head
            int counter = 0; // Initialize counter
            while (start != -1) { // Traverse the list
                if (counter == position) { // Check if counter matches position
                    return cursorSpace[start].element; // Return the element
                }
                start = cursorSpace[start].next; // Move to the next node
                counter++; // Increment counter
            }
        }
        return null; // Return null if position is invalid
    }

    // Method to remove an element by its index
    public void removeByIndex(int index) {
        if (index >= 0 && index < count) { // Check if index is valid
            T element = get(index); // Get the element at the index
            remove(element); // Remove the element
        }
    }

    // Method to remove a specific element from the list
    public void remove(T element) {
        Objects.requireNonNull(element); // Ensure element is not null
        if (head == -1) return; // Return if the list is empty
        if (Objects.equals(cursorSpace[head].element, element)) { // Check if head is the element
            free(head); // Free the head node
            head = cursorSpace[head].next; // Update head to the next node
        } else {
            int prev = head; // Previous node
            int current = cursorSpace[prev].next; // Current node
            while (current != -1) { // Traverse the list
                if (Objects.equals(cursorSpace[current].element, element)) { // Check for equality
                    cursorSpace[prev].next = cursorSpace[current].next; // Bypass the current node
                    free(current); // Free the current node
                    break; // Exit the loop
                }
                prev = current; // Move previous to current
                current = cursorSpace[prev].next; // Move to the next node
            }
        }
        count--; // Decrement the count of elements
    }

    // Method to allocate a new node from the cursor space
    private int alloc() {
        int availableNodeIndex = cursorSpace[os].next; // Get the next available node
        if (availableNodeIndex == 0) {
            throw new OutOfMemoryError(); // Throw error if no space is available
        }
        cursorSpace[os].next = cursorSpace[availableNodeIndex].next; // Update the free list
        cursorSpace[availableNodeIndex].next = -1; // Mark the node as used
        return availableNodeIndex; // Return the index of the allocated node
    }

    // Method to free a node and return it to the cursor space
    private void free(int index) {
        cursorSpace[index].element = null; // Clear the element
        cursorSpace[index].next = cursorSpace[os].next; // Link it back to the free list
        cursorSpace[os].next = index; // Update the free list head
    }

    // Method to append an element to the end of the list
    public void append(T element) {
        Objects.requireNonNull(element); // Ensure element is not null
        int availableIndex = alloc(); // Allocate a new node
        cursorSpace[availableIndex].element = element; // Set the element
        if (head == -1) { // If the list is empty
            head = availableIndex; // Set head to the new node
        } else {
            int iterator = head; // Start from the head
            while (cursorSpace[iterator].next != -1) { // Traverse to the end
                iterator = cursorSpace[iterator].next; // Move to the next node
            }
            cursorSpace[iterator].next = availableIndex; // Link the new node at the end
        }
        count++; // Increment the count of elements
    }

    // Main method to interact with the user and execute commands
    public static void main(String[] args) {
        Main<String> list = new Main<>(); // Create a new linked list
        Scanner scanner = new Scanner(System.in); // Scanner for user input
        while (scanner.hasNextLine()) { // Loop until there is no more input
            String command = scanner.nextLine().trim(); // Read and trim the command
            if (command.isEmpty()) {
                continue; // Skip empty commands
            }
            if (command.equalsIgnoreCase("exit")) {
                break; // Exit the loop on "exit" command
            }
            try {
                String[] parts = command.split(" "); // Split command into parts
                switch (parts[0]) { // Determine the command type
                    case "append":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for append"); // Error for missing value
                            break;
                        }
                        list.append(parts[1]); // Append the value to the list
                        System.out.println("Appended: " + parts[1]); // Confirmation message
                        break;
                    case "get":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing index for get"); // Error for missing index
                            break;
                        }
                        int index = Integer.parseInt(parts[1]); // Parse the index
                        String value = list.get(index); // Get the value at the index
                        System.out.println("Value at index " + index + ": " + value); // Display the value
                        break;
                    case "removeByIndex":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing index for removeByIndex"); // Error for missing index
                            break;
                        }
                        int removeIndex = Integer.parseInt(parts[1]); // Parse the index
                        list.removeByIndex(removeIndex); // Remove the value at the index
                        System.out.println("Removed value at index " + removeIndex); // Confirmation message
                        break;
                    case "indexOf":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for indexOf"); // Error for missing value
                            break;
                        }
                        int idx = list.indexOf(parts[1]); // Find the index of the value
                        System.out.println("Index of " + parts[1] + ": " + idx); // Display the index
                        break;
                    case "print":
                        list.printList(); // Print the linked list
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]); // Error for unknown command
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage()); // Display any errors
            }
        }
        scanner.close(); // Close the scanner
    }
}
