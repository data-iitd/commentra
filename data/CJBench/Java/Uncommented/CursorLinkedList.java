
import java.util.Scanner;
import java.util.Objects;
public class CursorLinkedList<T> {
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
        cursorSpace = new Node[CURSOR_SPACE_SIZE];
        for (int i = 0; i < CURSOR_SPACE_SIZE; i++) {
            cursorSpace[i] = new Node<>(null, i + 1);
        }
        cursorSpace[CURSOR_SPACE_SIZE - 1].next = 0;
    }
    public CursorLinkedList() {
        os = 0;
        count = 0;
        head = -1;
    }
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
    public void removeByIndex(int index) {
        if (index >= 0 && index < count) {
            T element = get(index);
            remove(element);
        }
    }
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
    private int alloc() {
        int availableNodeIndex = cursorSpace[os].next;
        if (availableNodeIndex == 0) {
            throw new OutOfMemoryError();
        }
        cursorSpace[os].next = cursorSpace[availableNodeIndex].next;
        cursorSpace[availableNodeIndex].next = -1;
        return availableNodeIndex;
    }
    private void free(int index) {
        cursorSpace[index].element = null;
        cursorSpace[index].next = cursorSpace[os].next;
        cursorSpace[os].next = index;
    }
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
        System.out.println("Enter commands (append <value>, get <index>, removeByIndex <index>, indexOf <value>, print, exit):");
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
