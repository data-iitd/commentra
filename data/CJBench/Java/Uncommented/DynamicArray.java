
import java.util.Arrays;
import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.Scanner;
import java.util.function.Consumer;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;
public class DynamicArray<E> implements Iterable<E> {
    private static final int DEFAULT_CAPACITY = 16;
    private int size;
    private int modCount; 
    private Object[] elements;
    public DynamicArray(final int capacity) {
        if (capacity < 0) {
            throw new IllegalArgumentException("Capacity cannot be negative.");
        }
        this.size = 0;
        this.modCount = 0;
        this.elements = new Object[capacity];
    }
    public DynamicArray() {
        this(DEFAULT_CAPACITY);
    }
    public void add(final E element) {
        ensureCapacity(size + 1);
        elements[size++] = element;
        modCount++; 
    }
    @SuppressWarnings("unchecked")
    public E get(final int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        return (E) elements[index];
    }
    public E remove(final int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }
        @SuppressWarnings("unchecked") E oldElement = (E) elements[index];
        fastRemove(index);
        modCount++; 
        return oldElement;
    }
    public int getSize() {
        return size;
    }
    public boolean isEmpty() {
        return size == 0;
    }
    private void ensureCapacity(int minCapacity) {
        if (minCapacity > elements.length) {
            int newCapacity = Math.max(elements.length * 2, minCapacity);
            elements = Arrays.copyOf(elements, newCapacity);
        }
    }
    private void fastRemove(int index) {
        int numMoved = size - index - 1;
        if (numMoved > 0) {
            System.arraycopy(elements, index + 1, elements, index, numMoved);
        }
        elements[--size] = null; 
    }
    @Override
    public String toString() {
        return Arrays.toString(Arrays.copyOf(elements, size));
    }
    @Override
    public Iterator<E> iterator() {
        return new DynamicArrayIterator();
    }
    private final class DynamicArrayIterator implements Iterator<E> {
        private int cursor;
        private int expectedModCount;
        DynamicArrayIterator() {
            this.expectedModCount = modCount;
        }
        @Override
        public boolean hasNext() {
            checkForComodification();
            return cursor < size;
        }
        @Override
        @SuppressWarnings("unchecked")
        public E next() {
            checkForComodification();
            if (cursor >= size) {
                throw new NoSuchElementException();
            }
            return (E) elements[cursor++];
        }
        private void checkForComodification() {
            if (modCount != expectedModCount) {
                throw new ConcurrentModificationException();
            }
        }
    }
    public static class DynamicArrayDemo {
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            DynamicArray<Integer> dynamicArray = new DynamicArray<>();
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
