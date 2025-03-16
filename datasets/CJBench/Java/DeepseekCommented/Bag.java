import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main<E> {
    // The first element of the list
    private Node<E> firstElement; 
    // The number of elements in the list
    private int size; 

    // Inner class to represent a node in the list
    private static final class Node<E> {
        // The content stored in the node
        private E content;
        // Reference to the next node in the list
        private Node<E> nextElement;
    }

    // Constructor to initialize an empty list
    public Main() {
        firstElement = null;
        size = 0;
    }

    // Returns true if the list is empty, false otherwise
    public boolean isEmpty() {
        return size == 0;
    }

    // Returns the number of elements in the list
    public int size() {
        return size;
    }

    // Adds a new element to the front of the list
    public void add(E element) {
        Node<E> newNode = new Node<>();
        newNode.content = element;
        newNode.nextElement = firstElement;
        firstElement = newNode;
        size++;
    }

    // Checks if the list contains a specific element
    public boolean contains(E element) {
        // Iterate through the list to check for the element
        for (E value : this) {
            if (value.equals(element)) {
                return true;
            }
        }
        return false;
    }

    // Returns an iterator for the list
    @Override
    public Iterator<E> iterator() {
        return new ListIterator<>(firstElement);
    }

    // Inner class to implement the iterator for the list
    private static class ListIterator<E> implements Iterator<E> {
        // The current node in the iteration
        private Node<E> currentElement;

        // Constructor to initialize the iterator with the first node
        ListIterator(Node<E> firstElement) {
            this.currentElement = firstElement;
        }

        // Returns true if there is a next element in the iteration
        @Override
        public boolean hasNext() {
            return currentElement != null;
        }

        // Returns the next element in the iteration
        @Override
        public E next() {
            if (!hasNext()) {
                throw new NoSuchElementException("No more elements in the bag.");
            }
            E element = currentElement.content;
            currentElement = currentElement.nextElement;
            return element;
        }
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main<String> bag = new Main<>();
        int n = scanner.nextInt();
        scanner.nextLine(); 
        // Read n elements and add them to the list
        for (int i = 0; i < n; i++) {
            String element = scanner.nextLine();
            bag.add(element);
        }
        // Print all elements in the list
        System.out.println("Main contents:");
        for (String element : bag) {
            System.out.println(element);
        }
        // Read an element to check if it is in the list
        String checkElement = scanner.nextLine();
        System.out.println("Contains " + checkElement + ": " + bag.contains(checkElement));
        System.out.println("Main size: " + bag.size());
        System.out.println("Is bag empty: " + bag.isEmpty());
    }
}
