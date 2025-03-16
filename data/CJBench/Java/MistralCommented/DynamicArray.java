
import java.util.Arrays;
import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.Scanner;
import java.util.function.Consumer;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

/**
 * A generic array implementation of a dynamic array.
 */
public class Main<E> {

    private static final int DEFAULT_CAPACITY = 16;
    /**
     * The current size of the array.
     */
    private int size;
    /**
     * A counter for modifications.
     */
    private int modCount;
    /**
     * The underlying array storing the elements.
     */
    private Object[] elements;

    /**
     * Initializes a new instance of the Main class with the specified capacity.
     *
     * @param capacity The initial capacity of the array.
     */
    public Main(final int capacity) {
        if (capacity < 0) {
            throw new IllegalArgumentException("Capacity cannot be negative.");
        }
        this.size = 0;
        this.modCount = 0;
        this.elements = new Object[capacity];
        // Initialize the array with the given capacity.
    }

    /**
     * Initializes a new instance of the Main class with the default capacity.
     */
    public Main() {
        this(DEFAULT_CAPACITY);
        // Initialize the array with the default capacity.
    }

    /**
     * Adds the specified element to this array.
     *
     * @param element The element to be added.
     */
    public void add(final E element) {
        ensureCapacity(size + 1);
        elements[size++] = element;
        modCount++;          // Increment the modification counter.
    }

    /**
     * Returns the element at the specified index in this list.
     *
     * @param index The index of the element to return.
     * @return The element at the specified index.
     * @throws IndexOutOfBoundsException if the index is out of range (<0 or >= size).
     */
    @SuppressWarnings("unchecked")
    public E get(final int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        return (E) elements[index];
        // Return the element at the specified index.
    }

    /**
     * Removes the element at the specified index from this list.
     *
     * @param index The index of the element to be removed.
     * @return The removed element.
     * @throws IndexOutOfBoundsException if the index is out of range (<0 or >= size).
     */
    public E remove(final int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        @SuppressWarnings("unchecked") E oldElement = (E) elements[index];
        fastRemove(index);
        modCount++;          // Increment the modification counter.
        return oldElement;
        // Remove the element at the specified index and return it.
    }

    /**
     * Returns the size of this list.
     *
     * @return The size of this list.
     */
    public int getSize() {
        return size;
    }

    /**
     * Returns true if this list contains no elements.
     *
     * @return true if this list contains no elements.
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * Ensures that this list has the specified capacity.
     *
     * @param minCapacity The minimum capacity desired.
     */
    private void ensureCapacity(int minCapacity) {
        if (minCapacity > elements.length) {
            int newCapacity = Math.max(elements.length * 2, minCapacity);
            elements = Arrays.copyOf(elements, newCapacity);
            // Increase the capacity of the array if needed.
        }
    }

    /**
     * Removes the element at the specified index and shifts the subsequent elements left.
     *
     * @param index The index of the element to be removed.
     */
    private void fastRemove(int index) {
        int numMoved = size - index - 1;
        if (numMoved > 0) {
            System.arraycopy(elements, index + 1, elements, index, numMoved);
        }
        elements[--size] = null;          // Set the removed element to null.
    }

    /**
     * Returns a string representation of this list.
     *
     * @return A string representation of this list.
     */
    @Override
    public String toString() {
        return Arrays.toString(Arrays.copyOf(elements, size));
        // Return a string representation of the underlying array.
    }

    /**
     * Returns an iterator over the elements in this list.
     *
     * @return An iterator over the elements in this list.
     */
    @Override
    public Iterator<E> iterator() {
        return new MainIterator();
        // Return an iterator to traverse the elements in this list.
    }

    /**
     * A private nested class representing an iterator over the elements in this list.
     */
    private final class MainIterator implements Iterator<E> {
        private int cursor;
        private int expectedModCount;

        MainIterator() {
            this.expectedModCount = modCount;
            // Initialize the cursor and the expected modification counter.
        }

        @Override
        public boolean hasNext() {
            checkForComodification();
            return cursor < size;
            // Check if there are more elements to iterate.
        }

        @Override
        @SuppressWarnings("unchecked")
        public E next() {
            checkForComodification();
            if (cursor >= size) {
                throw new NoSuchElementException();
            }
            return (E) elements[cursor++];
            // Return the next element and increment the cursor.
        }

        private void checkForComodification() {
            if (modCount != expectedModCount) {
                throw new ConcurrentModificationException();
            }
            // Throw a ConcurrentModificationException if the list has been modified.
        }
    }

    /**
     * A static nested class demonstrating the usage of the Main class.
     */
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
            // Demonstrate the usage of the Main class by reading commands from the standard input.
        }
    }
}