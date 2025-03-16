import java.util.ArrayList; // Importing necessary libraries for the functionality of the code
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Initialize a scanner to read input from the user
        int n = scanner.nextInt(); // Read the number of elements
        Integer[] array = new Integer[n]; // Create an array to hold the integers
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt(); // Read n integers into the array
        }
        patienceSort(array); // Call the patienceSort method to sort the array
        for (int num : array) {
            System.out.print(num + " "); // Print the sorted array
        }
        scanner.close(); // Close the scanner
    }

    public static <T extends Comparable<T>> T[] patienceSort(T[] array) { // Define the patienceSort method to sort an array
        if (array.length == 0) { // Check if the array is empty
            return array; // Return the array if it is empty
        }
        final List<List<T>> piles = formPiles(array); // Form piles from the array
        final PriorityQueue<PileNode<T>> pq = mergePiles(piles); // Merge the piles into a priority queue
        extractPiles(array, pq); // Extract the elements from the priority queue back into the array
        return array; // Return the sorted array
    }

    private static <T extends Comparable<T>> List<List<T>> formPiles(final T[] array) { // Define the formPiles method to create piles
        final List<List<T>> piles = new ArrayList<>(); // Create a list of lists to store the piles
        final List<T> lastElements = new ArrayList<>(); // Create a list to keep track of the last elements of each pile
        for (T x : array) { // Iterate over each element in the array
            int pos = Collections.binarySearch(lastElements, x); // Find the position of the element in the list of last elements
            if (pos < 0) {
                pos = -pos - 1; // If the element is not found, insert it at the correct position
            }
            if (pos < piles.size()) { // If the element fits into an existing pile
                piles.get(pos).add(x); // Add the element to the appropriate pile
                lastElements.set(pos, x); // Update the last element of the pile
            } else { // If the element starts a new pile
                List<T> newPile = new ArrayList<>(); // Create a new pile
                newPile.add(x); // Add the element to the new pile
                piles.add(newPile); // Add the new pile to the list of piles
                lastElements.add(x); // Add the element to the list of last elements
            }
        }
        return piles; // Return the list of piles
    }

    private static <T extends Comparable<T>> PriorityQueue<PileNode<T>> mergePiles(final Iterable<List<T>> piles) { // Define the mergePiles method to merge piles into a priority queue
        PriorityQueue<PileNode<T>> pq = new PriorityQueue<>(); // Create a priority queue to hold the pile nodes
        for (List<T> pile : piles) { // Iterate over each pile
            pq.add(new PileNode<>(pile.remove(pile.size() - 1), pile)); // Add the last element of the pile to the priority queue and remove it from the pile
        }
        return pq; // Return the priority queue
    }

    private static <T extends Comparable<T>> void extractPiles(final T[] array, final PriorityQueue<PileNode<T>> pq) { // Define the extractPiles method to extract elements from the priority queue
        int index = 0; // Initialize the index to 0
        while (!pq.isEmpty()) { // While there are elements in the priority queue
            PileNode<T> node = pq.poll(); // Remove the smallest element from the priority queue
            array[index++] = node.value; // Add the element to the array
            if (!node.pile.isEmpty()) { // If there are more elements in the pile
                pq.add(new PileNode<>(node.pile.remove(node.pile.size() - 1), node.pile)); // Add the next smallest element from the pile to the priority queue
            }
        }
    }

    private static class PileNode<T extends Comparable<T>> implements Comparable<PileNode<T>> { // Define the PileNode class to represent a node in the priority queue
        final T value; // The value of the node
        final List<T> pile; // The pile the node belongs to

        public PileNode(T value, List<T> pile) { // Constructor for the PileNode class
            this.value = value;
            this.pile = pile;
        }

        @Override
        public int compareTo(PileNode<T> other) { // Implement the compareTo method to compare pile nodes based on their values
            return this.value.compareTo(other.value);
        }
    }
}
