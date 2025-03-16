import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
    // The first element of the linked list
    private Node<E> firstElement; 
    // The size of the linked list
    private int size; 

    // Inner class representing a node in the linked list
    private static final class Node<E> {
        private E content; // The content of the node
        private Node<E> nextElement; // Reference to the next node
    }

    // Constructor to initialize the linked list
    public Main() {
        firstElement = null; // Initially, there are no elements
        size = 0; // Size is zero
    }

    // Method to check if the linked list is empty
    public boolean isEmpty() {
        return size == 0; // Returns true if size is zero
    }

    // Method to get the size of the linked list
    public int size() {
        return size; // Returns the current size
    }

    // Method to add an element to the linked list
    public void add(E element) {
        Node<E> newNode = new Node<>(); // Create a new node
        newNode.content = element; // Set the content of the new node
        newNode.nextElement = firstElement; // Link the new node to the first element
        firstElement = newNode; // Update the first element to the new node
        size++; // Increment the size of the linked list
    }

    // Method to check if the linked list contains a specific element
    public boolean contains(E element) {
        for (E value : this) { // Iterate through the linked list
            if (value.equals(element)) { // Check if the current value matches the element
                return true; // Return true if found
            }
        }
        return false; // Return false if not found
    }

    // Method to return an iterator for the linked list
    @Override
    public Iterator<E> iterator() {
        return new ListIterator<>(firstElement); // Return a new ListIterator starting from the first element
    }

    // Inner class implementing the iterator for the linked list
    private static class ListIterator<E> implements Iterator<E> {
        private Node<E> currentElement; // Current node being iterated

        // Constructor to initialize the iterator with the first element
        ListIterator(Node<E> firstElement) {
            this.currentElement = firstElement; // Set the current element to the first
        }

        // Method to check if there are more elements to iterate
        @Override
        public boolean hasNext() {
            return currentElement != null; // Returns true if there is a next element
        }

        // Method to get the next element in the iteration
        @Override
        public E next() {
            if (!hasNext()) { // Check if there are no more elements
                throw new NoSuchElementException("No more elements in the bag."); // Throw exception if no elements left
            }
            E element = currentElement.content; // Get the content of the current element
            currentElement = currentElement.nextElement; // Move to the next element
            return element; // Return the current element
        }
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        Main<String> bag = new Main<>(); // Create a new instance of Main (linked list)
        int n = scanner.nextInt(); // Read the number of elements to add
        scanner.nextLine(); // Consume the newline character

        // Loop to read elements and add them to the linked list
        for (int i = 0; i < n; i++) {
            String element = scanner.nextLine(); // Read each element
            bag.add(element); // Add the element to the linked list
        }

        // Print the contents of the linked list
        System.out.println("Main contents:");
        for (String element : bag) { // Iterate through the linked list
            System.out.println(element); // Print each element
        }

        // Check if a specific element is contained in the linked list
        String checkElement = scanner.nextLine(); // Read the element to check
        System.out.println("Contains " + checkElement + ": " + bag.contains(checkElement)); // Print the result

        // Print the size of the linked list
        System.out.println("Main size: " + bag.size()); // Print the size

        // Check if the linked list is empty
        System.out.println("Is bag empty: " + bag.isEmpty()); // Print whether the bag is empty
    }
}
