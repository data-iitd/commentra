import java.util.Scanner;
import java.util.Objects;
public class Main {
    // Represents a node in the linked list
    private static class Node<T> {
        T element; // The element stored in the node
        int next; // Index of the next node
        Node(T element, int next) {
            this.element = element;
            this.next = next;
        }
    }

    // The offset for the free list
    private final int os;
    // Index of the head node
    private int head;
    // Array of nodes representing the cursor space
    private final Node<T>[] cursorSpace;
    // Number of elements in the list
    private int count;
    // Size of the cursor space
    private static final int CURSOR_SPACE_SIZE = 100;

    // Initializes the cursor space and sets the initial values for os, head, and count
    {
        cursorSpace = new Node[CURSOR_SPACE_SIZE];
        for (int i = 0; i < CURSOR_SPACE_SIZE; i++) {
            cursorSpace[i] = new Node<>(null, i + 1);
        }
        cursorSpace[CURSOR_SPACE_SIZE - 1].next = 0;
    }

    // Constructor to initialize the list
    public Main() {
        os = 0;
        count = 0;
        head = -1;
    }

    // Prints the entire list starting from the head
    public void printList() {
        if (head != -1) {
            int start = head;
            while (start != -1) {
                T element = cursorSpace[start].element;
                System.out.print(element + " -> ");
                start = cursorSpace[start].next;
            }
        }
        System.out.println("null");
    }

    // Returns the index of a given element in the list
    public int indexOf(T element) {
        if (element == null) {
            throw new NullPointerException("Element cannot be null");
        }
        int current = head;
        int index = 0;
        while (current != -1) {
            if (Objects.equals(cursorSpace[current].element, element)) {
                return index;
            }
            current = cursorSpace[current].next;
            index++;
        }
        return -1;
    }

    // Returns the element at a specified position in the list
    public T get(int position) {
        if (position >= 0 && position < count) {
            int start = head;
            int counter = 0;
            while (start != -1) {
                if (counter == position) {
                    return cursorSpace[start].element;
                }
                start = cursorSpace[start].next;
                counter++;
            }
        }
        return null;
    }

    // Removes the element at a specified index
    public void removeByIndex(int index) {
        if (index >= 0 && index < count) {
            T element = get(index);
            remove(element);
        }
    }

    // Removes the first occurrence of a given element in the list
    public void remove(T element) {
        Objects.requireNonNull(element);
        if (head == -1) return;
        if (Objects.equals(cursorSpace[head].element, element)) {
            free(head);
            head = cursorSpace[head].next;
        } else {
            int prev = head;
            int current = cursorSpace[prev].next;
            while (current != -1) {
                if (Objects.equals(cursorSpace[current].element, element)) {
                    cursorSpace[prev].next = cursorSpace[current].next;
                    free(current);
                    break;
                }
                prev = current;
                current = cursorSpace[prev].next;
            }
        }
        count--;
    }

    // Finds an available node in the cursor space
    private int alloc() {
        int availableNodeIndex = cursorSpace[os].next;
        if (availableNodeIndex == 0) {
            throw new OutOfMemoryError();
        }
        cursorSpace[os].next = cursorSpace[availableNodeIndex].next;
        cursorSpace[availableNodeIndex].next = -1;
        return availableNodeIndex;
    }

    // Frees a node in the cursor space
    private void free(int index) {
        cursorSpace[index].element = null;
        cursorSpace[index].next = cursorSpace[os].next;
        cursorSpace[os].next = index;
    }

    // Adds a new element to the end of the list
    public void append(T element) {
        Objects.requireNonNull(element);
        int availableIndex = alloc();
        cursorSpace[availableIndex].element = element;
        if (head == -1) {
            head = availableIndex;
        } else {
            int iterator = head;
            while (cursorSpace[iterator].next != -1) {
                iterator = cursorSpace[iterator].next;
            }
            cursorSpace[iterator].next = availableIndex;
        }
        count++;
    }

    // Main method to handle user input
    public static void main(String[] args) {
        Main<String> list = new Main<>();
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
                    case "append":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for append");
                            break;
                        }
                        list.append(parts[1]);
                        System.out.println("Appended: " + parts[1]);
                        break;
                    case "get":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing index for get");
                            break;
                        }
                        int index = Integer.parseInt(parts[1]);
                        String value = list.get(index);
                        System.out.println("Value at index " + index + ": " + value);
                        break;
                    case "removeByIndex":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing index for removeByIndex");
                            break;
                        }
                        int removeIndex = Integer.parseInt(parts[1]);
                        list.removeByIndex(removeIndex);
                        System.out.println("Removed value at index " + removeIndex);
                        break;
                    case "indexOf":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for indexOf");
                            break;
                        }
                        int idx = list.indexOf(parts[1]);
                        System.out.println("Index of " + parts[1] + ": " + idx);
                        break;
                    case "print":
                        list.printList();
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
