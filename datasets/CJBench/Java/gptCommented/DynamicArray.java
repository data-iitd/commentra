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
    // Default capacity for the dynamic array
    private static final int DEFAULT_CAPACITY = 16;
    private int size; // Current number of elements in the array
    private int modCount; // Modification count for tracking changes
    private Object[] elements; // Array to store the elements

    // Constructor with specified capacity
    public Main(final int capacity) {
        if (capacity < 0) {
            throw new IllegalArgumentException("Capacity cannot be negative.");
        }
        this.size = 0; // Initialize size to 0
        this.modCount = 0; // Initialize modification count to 0
        this.elements = new Object[capacity]; // Create an array with the specified capacity
    }

    // Default constructor that uses the default capacity
    public Main() {
        this(DEFAULT_CAPACITY);
    }

    // Method to add an element to the dynamic array
    public void add(final E element) {
        ensureCapacity(size + 1); // Ensure there is enough capacity
        elements[size++] = element; // Add the element and increment size
        modCount++; // Increment modification count
    }

    // Method to retrieve an element at a specific index
    @SuppressWarnings("unchecked")
    public E get(final int index) {
        // Check if the index is within bounds
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        return (E) elements[index]; // Return the element at the specified index
    }

    // Method to remove an element at a specific index
    public E remove(final int index) {
        // Check if the index is within bounds
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        @SuppressWarnings("unchecked") E oldElement = (E) elements[index]; // Store the element to be removed
        fastRemove(index); // Remove the element
        modCount++; // Increment modification count
        return oldElement; // Return the removed element
    }

    // Method to get the current size of the dynamic array
    public int getSize() {
        return size; // Return the size
    }

    // Method to check if the dynamic array is empty
    public boolean isEmpty() {
        return size == 0; // Return true if size is 0, otherwise false
    }

    // Method to ensure the array has enough capacity to accommodate new elements
    private void ensureCapacity(int minCapacity) {
        // If the current capacity is less than the minimum required capacity
        if (minCapacity > elements.length) {
            // Calculate new capacity (double the current or minimum required)
            int newCapacity = Math.max(elements.length * 2, minCapacity);
            elements = Arrays.copyOf(elements, newCapacity); // Resize the array
        }
    }

    // Method to remove an element quickly without shifting all elements
    private void fastRemove(int index) {
        int numMoved = size - index - 1; // Calculate number of elements to move
        if (numMoved > 0) {
            // Shift elements to fill the gap
            System.arraycopy(elements, index + 1, elements, index, numMoved);
        }
        elements[--size] = null; // Null out the last element and decrement size
    }

    // Override toString method to display the dynamic array
    @Override
    public String toString() {
        return Arrays.toString(Arrays.copyOf(elements, size)); // Return a string representation of the array
    }

    // Override iterator method to return an instance of the custom iterator
    @Override
    public Iterator<E> iterator() {
        return new MainIterator(); // Return a new iterator instance
    }

    // Inner class for the custom iterator
    private final class MainIterator implements Iterator<E> {
        private int cursor; // Current position in the iteration
        private int expectedModCount; // Expected modification count for fail-fast behavior

        // Constructor for the iterator
        MainIterator() {
            this.expectedModCount = modCount; // Initialize expected modification count
        }

        // Method to check if there are more elements to iterate over
        @Override
        public boolean hasNext() {
            checkForComodification(); // Check for concurrent modifications
            return cursor < size; // Return true if there are more elements
        }

        // Method to retrieve the next element in the iteration
        @Override
        @SuppressWarnings("unchecked")
        public E next() {
            checkForComodification(); // Check for concurrent modifications
            if (cursor >= size) {
                throw new NoSuchElementException(); // Throw exception if no more elements
            }
            return (E) elements[cursor++]; // Return the current element and increment cursor
        }

        // Method to check for concurrent modifications
        private void checkForComodification() {
            if (modCount != expectedModCount) {
                throw new ConcurrentModificationException(); // Throw exception if modification count has changed
            }
        }
    }

    // Main class for demonstration
    public static class MainDemo {
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in); // Create a scanner for input
            Main<Integer> dynamicArray = new Main<>(); // Create a new dynamic array instance
            int operations = scanner.nextInt(); // Read the number of operations
            scanner.nextLine(); // Consume the newline character

            // Loop through the number of operations
            for (int i = 0; i < operations; i++) {
                String[] input = scanner.nextLine().split(" "); // Read and split the input line
                String command = input[0]; // Get the command
                switch (command.toUpperCase()) { // Switch based on the command
                    case "ADD":
                        int value = Integer.parseInt(input[1]); // Parse the value to add
                        dynamicArray.add(value); // Add the value to the dynamic array
                        break;
                    case "REMOVE":
                        int removeIndex = Integer.parseInt(input[1]); // Parse the index to remove
                        try {
                            dynamicArray.remove(removeIndex); // Attempt to remove the element
                        } catch (IndexOutOfBoundsException e) {
                            System.out.println("Error: " + e.getMessage()); // Handle index out of bounds
                        }
                        break;
                    case "GET":
                        int getIndex = Integer.parseInt(input[1]); // Parse the index to get
                        try {
                            System.out.println("Value at index " + getIndex + ": " + dynamicArray.get(getIndex)); // Retrieve and print the value
                        } catch (IndexOutOfBoundsException e) {
                            System.out.println("Error: " + e.getMessage()); // Handle index out of bounds
                        }
                        break;
                    default:
                        System.out.println("Invalid command."); // Handle invalid commands
                }
            }
            // Print the final state of the dynamic array and its size
            System.out.println("Final array: " + dynamicArray);
            System.out.println("Array size: " + dynamicArray.getSize());
        }
    }
}
