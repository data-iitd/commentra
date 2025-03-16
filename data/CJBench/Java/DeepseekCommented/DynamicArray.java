import java.util.Arrays;
import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.Scanner;
import java.util.function.Consumer;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

public class Main {
    private static final int DEFAULT_CAPACITY = 16; // Default capacity for the array
    private int size; // Number of elements in the array
    private int modCount; // Tracks the number of modifications to the array
    private Object[] elements; // Array to store the elements

    // Constructor to initialize the array with a given capacity
    public Main(final int capacity) {
        if (capacity < 0) {
            throw new IllegalArgumentException("Capacity cannot be negative.");
        }
        this.size = 0;
        this.modCount = 0;
        this.elements = new Object[capacity];
    }

    // Default constructor to initialize the array with the default capacity
    public Main() {
        this(DEFAULT_CAPACITY);
    }

    // Method to add an element to the array
    public void add(final E element) {
        ensureCapacity(size + 1); // Ensure the array has sufficient capacity
        elements[size++] = element; // Add the element and increment the size
        modCount++; // Increment the modification count
    }

    // Method to get an element at a specified index
    @SuppressWarnings("unchecked")
    public E get(final int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        return (E) elements[index]; // Return the element at the specified index
    }

    // Method to remove an element at a specified index
    public E remove(final int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        @SuppressWarnings("unchecked") E oldElement = (E) elements[index]; // Store the old element
        fastRemove(index); // Remove the element without maintaining order
        modCount++; // Increment the modification count
        return oldElement; // Return the removed element
    }

    // Method to get the number of elements in the array
    public int getSize() {
        return size;
    }

    // Method to check if the array is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Method to ensure the array has sufficient capacity
    private void ensureCapacity(int minCapacity) {
        if (minCapacity > elements.length) {
            int newCapacity = Math.max(elements.length * 2, minCapacity);
            elements = Arrays.copyOf(elements, newCapacity); // Copy the array to a new larger array
        }
    }

    // Method to remove an element without maintaining order
    private void fastRemove(int index) {
        int numMoved = size - index - 1;
        if (numMoved > 0) {
            System.arraycopy(elements, index + 1, elements, index, numMoved); // Shift elements to the left
        }
        elements[--size] = null; // Set the last element to null
    }

    // Method to provide a string representation of the array
    @Override
    public String toString() {
        return Arrays.toString(Arrays.copyOf(elements, size));
    }

    // Method to return an iterator for the array
    @Override
    public Iterator<E> iterator() {
        return new MainIterator();
    }

    // Inner class to implement the iterator for the array
    private final class MainIterator implements Iterator<E> {
        private int cursor; // The index of the next element to return
        private int expectedModCount; // The expected modification count

        MainIterator() {
            this.expectedModCount = modCount;
        }

        // Method to check if there is a next element
        @Override
        public boolean hasNext() {
            checkForComodification(); // Check for concurrent modification
            return cursor < size; // Return true if there is a next element
        }

        // Method to return the next element
        @Override
        @SuppressWarnings("unchecked")
        public E next() {
            checkForComodification(); // Check for concurrent modification
            if (cursor >= size) {
                throw new NoSuchElementException(); // Throw an exception if there is no next element
            }
            return (E) elements[cursor++]; // Return the next element and increment the cursor
        }

        // Method to check for concurrent modification
        private void checkForComodification() {
            if (modCount != expectedModCount) {
                throw new ConcurrentModificationException(); // Throw an exception if there is a concurrent modification
            }
        }
    }

    // Class to demonstrate the usage of the Main class
    public static class MainDemo {
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            Main<Integer> dynamicArray = new Main<>();
            int operations = scanner.nextInt();
            scanner.nextLine();
            for (int i = 0; i < operations; i++) {
                String[] input = scanner.nextLine().split(" ");
                String command = input[0];
                switch (command.toUpperCase()) {
                    case "ADD":
                        int value = Integer.parseInt(input[1]);
                        dynamicArray.add(value);
                        break;
                    case "REMOVE":
                        int removeIndex = Integer.parseInt(input[1]);
                        try {
                            dynamicArray.remove(removeIndex);
                        } catch (IndexOutOfBoundsException e) {
                            System.out.println("Error: " + e.getMessage());
                        }
                        break;
                    case "GET":
                        int getIndex = Integer.parseInt(input[1]);
                        try {
                            System.out.println("Value at index " + getIndex + ": " + dynamicArray.get(getIndex));
                        } catch (IndexOutOfBoundsException e) {
                            System.out.println("Error: " + e.getMessage());
                        }
                        break;
                    default:
                        System.out.println("Invalid command.");
                }
            }
            System.out.println("Final array: " + dynamicArray);
            System.out.println("Array size: " + dynamicArray.getSize());
        }
    }
}
