
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Scanner;
public class Bag<E> implements Iterable<E> {
    private Node<E> firstElement; 
    private int size; 
    private static final class Node<E> {
        private E content;
        private Node<E> nextElement;
    }
    public Bag() {
        firstElement = null;
        size = 0;
    }
    public boolean isEmpty() {
        return size == 0;
    }
    public int size() {
        return size;
    }
    public void add(E element) {
        Node<E> newNode = new Node<>();
        newNode.content = element;
        newNode.nextElement = firstElement;
        firstElement = newNode;
        size++;
    }
    public boolean contains(E element) {
        for (E value : this) {
            if (value.equals(element)) {
                return true;
            }
        }
        return false;
    }
    @Override
    public Iterator<E> iterator() {
        return new ListIterator<>(firstElement);
    }
    private static class ListIterator<E> implements Iterator<E> {
        private Node<E> currentElement;
        ListIterator(Node<E> firstElement) {
            this.currentElement = firstElement;
        }
        @Override
        public boolean hasNext() {
            return currentElement != null;
        }
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
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Bag<String> bag = new Bag<>();
        int n = scanner.nextInt();
        scanner.nextLine(); 
        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            String element = scanner.nextLine();
            bag.add(element);
        }
        System.out.println("Bag contents:");
        for (String element : bag) {
            System.out.println(element);
        }
        System.out.println("Enter an element to check for membership:");
        String checkElement = scanner.nextLine();
        System.out.println("Contains " + checkElement + ": " + bag.contains(checkElement));
        System.out.println("Bag size: " + bag.size());
        System.out.println("Is bag empty: " + bag.isEmpty());
    }
}
