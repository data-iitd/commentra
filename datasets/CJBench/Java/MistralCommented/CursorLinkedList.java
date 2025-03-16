
import java.util.Scanner;
import java.util.Objects;
import java.util.Arrays;

public class Main {
    // Declare a private nested class Node with generic type T
    private static class Node<T> {
        // Declare an element of generic type T and an integer next
        T element;
        int next;

        // Constructor for Node with two arguments: an element of generic type T and an integer next
        Node(T element, int next) {
            this.element = element;
            this.next = next;
        }
    }

    // Declare instance variables for the linked list: an integer operating system stack index (os),
    // an integer head index, an array of Node objects named cursorSpace, an integer count,
    // a constant integer CURSOR_SPACE_SIZE, and an integer overflow size
    private final int os;
    private int head;
    private Node<T>[] cursorSpace;
    private int count;
    private static final int CURSOR_SPACE_SIZE = 100;
    private static final int OVERFLOW_SIZE = CURSOR_SPACE_SIZE + 1;

    {
        // Initialize cursorSpace array with default values
        cursorSpace = new Node[CURSOR_SPACE_SIZE];
        for (int i = 0; i < CURSOR_SPACE_SIZE; i++) {
            cursorSpace[i] = new Node<>(null, i + 1);
        }
        cursorSpace[CURSOR_SPACE_SIZE - 1].next = 0;
    }

    // Constructor for Main class with no arguments
    public Main() {
        // Initialize operating system stack index, head index, and count to 0
        os = 0;
        head = -1;
        count = 0;
    }

    // Method to print the elements in the linked list
    public void printList() {
        // Check if the head index is not equal to -1
        if (head != -1) {
            // Initialize start index to head
            int start = head;
            // Use a while loop to iterate through the linked list and print each element
            while (start != -1) {
                // Get the element at the current index
                T element = cursorSpace[start].element;
                // Print the element followed by " -> "
                System.out.print(element + " -> ");
                // Update the start index to the next index
                start = cursorSpace[start].next;
            }
        }
        // Print "null" at the end of the list
        System.out.println("null");
    }

    // Method to find the index of a given element in the linked list
    public int indexOf(T element) {
        // Check if the given element is null
        if (element == null) {
            // Throw a NullPointerException with the message "Element cannot be null"
            throw new NullPointerException("Element cannot be null");
        }
        // Initialize current index to head and index to 0
        int current = head;
        int index = 0;
        // Use a while loop to iterate through the linked list and find the index of the given element
        while (current != -1) {
            // Check if the element at the current index is equal to the given element
            if (Objects.equals(cursorSpace[current].element, element)) {
                // Return the index
                return index;
            }
            // Update the current index to the next index and increment the index
            current = cursorSpace[current].next;
            index++;
        }
        // If the given element is not found in the list, return -1
        return -1;
    }

    // Method to get the element at a given position in the linked list
    public T get(int position) {
        // Check if the position is valid (i.e., within the bounds of the list)
        if (position >= 0 && position < count) {
            // Initialize start index to head and counter to 0
            int start = head;
            int counter = 0;
            // Use a while loop to iterate through the linked list and find the element at the given position
            while (start != -1) {
                // Check if the counter is equal to the given position
                if (counter == position) {
                    // Return the element at the current index
                    return cursorSpace[start].element;
                }
                // Update the start index to the next index and increment the counter
                start = cursorSpace[start].next;
                counter++;
            }
        }
        // If the position is invalid, return null
        return null;
    }

    // Method to remove an element by index from the linked list
    public void removeByIndex(int index) {
        // Check if the index is valid (i.e., within the bounds of the list)
        if (index >= 0 && index < count) {
            // Get the element to be removed using the get method
            T element = get(index);
            // Remove the element using the remove method with the given element as an argument
            remove(element);
        }
    }

    // Method to remove an element with a given value from the linked list
    public void remove(T element) {
        // Check if the given element is null
        Objects.requireNonNull(element);
        // Check if the head index is equal to -1 (i.e., the list is empty)
        if (head == -1) return;
        // Check if the element at the head index is equal to the given element
        if (Objects.equals(cursorSpace[head].element, element)) {
            // Free the head node and update the head index
            free(head);
            head = cursorSpace[head].next;
        } else {
            // Initialize previous index to head and current index to the next index of the head index
            int prev = head;
            int current = cursorSpace[prev].next;
            // Use a while loop to iterate through the linked list and find the node containing the given element
            while (current != -1) {
                // Check if the element at the current index is equal to the given element
                if (Objects.equals(cursorSpace[current].element, element)) {
                    // Free the current node and update the previous node's next index to the next node of the current node
                    free(current);
                    cursorSpace[prev].next = cursorSpace[current].next;
                    break;
                }
                // Update the previous and current indices
                prev = current;
                current = cursorSpace[prev].next;
            }
        }
        // Decrement the count by 1
        count--;
    }

    // Method to allocate a new node in the cursorSpace array
    private int alloc() {
        // Get the index of the first available node in the cursorSpace array
        int availableNodeIndex = cursorSpace[os].next;
        // Check if the next index of the operating system stack index is 0 (i.e., the list is full)
        if (availableNodeIndex == 0) {
            // Throw an OutOfMemoryError with the default message
            throw new OutOfMemoryError();
        }
        // Free the next index of the operating system stack index and set it to the index of the available node
        cursorSpace[os].next = cursorSpace[availableNodeIndex].next;
        // Set the next index of the available node to -1 and return its index
        cursorSpace[availableNodeIndex].next = -1;
        return availableNodeIndex;
    }

    // Method to free a node in the cursorSpace array
    private void free(int index) {
        // Set the element of the node at the given index to null
        cursorSpace[index].element = null;
        // Set the next index of the node to the next available index in the cursorSpace array
        cursorSpace[index].next = cursorSpace[os].next;
        // Set the next available index in the cursorSpace array to the index of the freed node
        cursorSpace[os].next = index;
    }

    // Method to append an element to the end of the linked list
    public void append(T element) {
        // Check if the given element is null
        Objects.requireNonNull(element);
        // Allocate a new node for the given element using the alloc method
        int availableIndex = alloc();
        // Set the element of the new node to the given element
        cursorSpace[availableIndex].element = element;
        // If the list is empty, set the head index to the index of the new node
        if (head == -1) {
            head = availableIndex;
        } else {
            // Use a while loop to find the last node in the list and set its next index to the index of the new node
            int iterator = head;
            while (cursorSpace[iterator].next != -1) {
                iterator = cursorSpace[iterator].next.next;
            }
            cursorSpace[iterator].next = availableIndex;
        }
        // Increment the count by 1
        count++;
    }

    // Main method to read user input and execute commands on the linked list
    public static void main(String[] args) {
        // Create an instance of the Main class with generic type String
        Main<String> list = new Main<>();
        // Create a Scanner object to read user input from the standard input stream
        Scanner scanner = new Scanner(System.in);
        // Use a while loop to read user input and execute commands until the user enters the "exit" command
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            // Check if the command is empty
            if (command.isEmpty()) {
                continue;
            }
            // Split the command into parts using the " " (space) character as a delimiter
            String[] parts = command.split(" ");
            // Switch on the first part of the command (i.e., the command name)
            switch (parts[0].toLowerCase()) {
                case "append":
                    // Check if the command has exactly two parts
              