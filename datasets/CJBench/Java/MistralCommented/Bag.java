
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Scanner;

// Class definition for the Main generic linked list
public class Main<E> {
    // Declare instance variables for the first element and size of the list
    private Node<E> firstElement;
    private int size;

    // Constructor for the Main class, initializes firstElement and size to null and 0 respectively
    public Main() {
        firstElement = null;
        size = 0;
    }

    // Check if the list is empty or not
    public boolean isEmpty() {
        // Return true if size is equal to 0, indicating an empty list
        return size == 0;
    }

    // Get the size of the list
    public int size() {
        // Return the current size of the list
        return size;
    }

    // Add an element to the list
    public void add(E element) {
        // Create a new Node with the given element
        Node<E> newNode = new Node<>();
        newNode.content = element;

        // Set the nextElement of the new Node to the current firstElement
        newNode.nextElement = firstElement;

        // Update the firstElement to point to the new Node
        firstElement = newNode;

        // Increment the size of the list
        size++;
    }

    // Check if an element exists in the list
    public boolean contains(E element) {
        // Iterate through each element in the list using the iterator
        for (E value : this) {
            // If the current element matches the given element, return true
            if (value.equals(element)) {
                return true;
            }
        }

        // If no matching element is found, return false
        return false;
    }

    // Override the iterator() method to return a ListIterator for the list
    @Override
    public Iterator<E> iterator() {
        // Create a new ListIterator instance with the firstElement as its initial value
        return new ListIterator<>(firstElement);
    }

    // Inner class definition for the ListIterator
    private static class ListIterator<E> implements Iterator<E> {
        // Declare an instance variable for the currentElement
        private Node<E> currentElement;

        // Constructor for the ListIterator, initializes currentElement with the given firstElement
        ListIterator(Node<E> firstElement) {
            this.currentElement = firstElement;
        }

        // Check if there is a next element to iterate to
        @Override
        public boolean hasNext() {
            // Return true if currentElement is not null, indicating there is a next element
            return currentElement != null;
        }

        // Get the next element in the list
        @Override
        public E next() {
            // If there is no next element, throw a NoSuchElementException
            if (!hasNext()) {
                throw new NoSuchElementException("No more elements in the bag.");
            }

            // Get the content of the currentElement and update currentElement to point to the next element
            E element = currentElement.content;
            currentElement = currentElement.nextElement;

            // Return the next element
            return element;
        }
    }

    // Main method for testing the Main class
    public static void main(String[] args) {
        // Create a new Scanner instance for reading input from the console
        Scanner scanner = new Scanner(System.in);

        // Create a new instance of the Main class for strings
        Main<String> bag = new Main<>();

        // Read the number of elements to add to the list from the console
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character left after reading int

        // Add each element to the list
        for (int i = 0; i < n; i++) {
            String element = scanner.nextLine();
            bag.add(element);
        }

        // Print the contents of the list
        System.out.println("Main contents:");
        for (String element : bag) {
            System.out.println(element);
        }

        // Read a string from the console to check for existence in the list
        String checkElement = scanner.nextLine();

        // Print whether the given string is present in the list or not
        System.out.println("Contains " + checkElement + ": " + bag.contains(checkElement));

        // Print the size of the list
        System.out.println("Main size: " + bag.size());

        // Print whether the list is empty or not
        System.out.println("Is bag empty: " + bag.isEmpty());

        // Close the Scanner instance
        scanner.close();
    }
}

