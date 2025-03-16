
import java.util.Scanner;
import java.util.Objects;

/**
 * CursorLinkedList is an array-based implementation of a singly linked list.
 * Each node in the array simulates a linked list node, storing an element and
 * the index of the next node. This structure allows for efficient list operations
 * without relying on traditional pointers.
 *
 * @param <T> the type of elements in this list
 */
public class CursorLinkedList<T> {

    /**
     * Node represents an individual element in the list, containing the element
     * itself and a pointer (index) to the next node.
     */
    private static class Node<T> {
        T element;
        int next;

        Node(T element, int next) {
            this.element = element;
            this.next = next;
        }
    }

    private final int os;
    private int head;
    private final Node<T>[] cursorSpace;
    private int count;
    private static final int CURSOR_SPACE_SIZE = 100;

    {
        // Initialize cursor space array and free list pointers
        cursorSpace = new Node[CURSOR_SPACE_SIZE];
        for (int i = 0; i < CURSOR_SPACE_SIZE; i++) {
            cursorSpace[i] = new Node<>(null, i + 1);
        }
        cursorSpace[CURSOR_SPACE_SIZE - 1].next = 0;
    }

    /**
     * Constructs an empty CursorLinkedList with the default capacity.
     */
    public CursorLinkedList() {
        os = 0;
        count = 0;
        head = -1;
    }

    /**
     * Prints all elements in the list in their current order.
     */
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

    /**
     * Finds the logical index of a specified element in the list.
     *
     * @param element the element to search for in the list
     * @return the logical index of the element, or -1 if not found
     * @throws NullPointerException if element is null
     */
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

    /**
     * Retrieves an element at a specified logical index in the list.
     *
     * @param position the logical index of the element
     * @return the element at the specified position, or null if index is out of bounds
     */
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

    /**
     * Removes the element at a specified logical index from the list.
     *
     * @param index the logical index of the element to remove
     */
    public void removeByIndex(int index) {
        if (index >= 0 && index < count) {
            T element = get(index);
            remove(element);
        }
    }

    /**
     * Removes the element at a specified logical index from the list.
     *
     * @param index the logical index of the element to remove
     */
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

    /**
     * Allocates a new node index for storing an element.
     *
     * @return the index of the newly allocated node
     * @throws OutOfMemoryError if no space is available in cursor space
     */
    private int alloc() {
        int availableNodeIndex = cursorSpace[os].next;
        if (availableNodeIndex == 0) {
            throw new OutOfMemoryError();
        }
        cursorSpace[os].next = cursorSpace[availableNodeIndex].next;
        cursorSpace[availableNodeIndex].next = -1;
        return availableNodeIndex;
    }

    /**
     * Releases a node back to the free list.
     *
     * @param index the index of the node to release
     */
    private void free(int index) {
        cursorSpace[index].element = null;
        cursorSpace[index].next = cursorSpace[os].next;
        cursorSpace[os].next = index;
    }

    /**
     * Appends an element to the end of the list.
     *
     * @param element the element to append
     * @throws NullPointerException if element is null
     */
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

    public static void main(String[] args) {
        CursorLinkedList<String> list = new CursorLinkedList<>();
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
