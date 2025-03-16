import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        // Create a scanner to read input from the console
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        // Read the number of elements in the array
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];
        
        // Read the elements of the array from the input
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        
        // Perform patience sort on the array
        patienceSort(array);
        
        // Print the sorted array
        for (int num : array) {
            System.out.print(num + " ");
        }
        
        // Close the scanner to free resources
        scanner.close();
    }

    // Method to perform patience sort on an array
    public static <T extends Comparable<T>> T[] patienceSort(T[] array) {
        // Return the array as is if it is empty
        if (array.length == 0) {
            return array;
        }
        
        // Form piles from the array elements
        final List<List<T>> piles = formPiles(array);
        
        // Merge the piles into a priority queue
        final PriorityQueue<PileNode<T>> pq = mergePiles(piles);
        
        // Extract the sorted elements from the priority queue back into the array
        extractPiles(array, pq);
        
        return array;
    }

    // Method to form piles based on the patience sorting algorithm
    private static <T extends Comparable<T>> List<List<T>> formPiles(final T[] array) {
        final List<List<T>> piles = new ArrayList<>();
        final List<T> lastElements = new ArrayList<>();
        
        // Iterate through each element in the array
        for (T x : array) {
            // Find the position to place the current element in the lastElements list
            int pos = Collections.binarySearch(lastElements, x);
            if (pos < 0) {
                pos = -pos - 1; // Get the insertion point
            }
            
            // If the position is within the current number of piles
            if (pos < piles.size()) {
                // Add the element to the corresponding pile
                piles.get(pos).add(x);
                lastElements.set(pos, x); // Update the last element of the pile
            } else {
                // Create a new pile for the current element
                List<T> newPile = new ArrayList<>();
                newPile.add(x);
                piles.add(newPile);
                lastElements.add(x); // Add the new last element
            }
        }
        return piles; // Return the formed piles
    }

    // Method to merge the piles into a priority queue
    private static <T extends Comparable<T>> PriorityQueue<PileNode<T>> mergePiles(final Iterable<List<T>> piles) {
        PriorityQueue<PileNode<T>> pq = new PriorityQueue<>();
        
        // Add the top element of each pile to the priority queue
        for (List<T> pile : piles) {
            pq.add(new PileNode<>(pile.remove(pile.size() - 1), pile));
        }
        return pq; // Return the priority queue containing the top elements of each pile
    }

    // Method to extract sorted elements from the priority queue back into the array
    private static <T extends Comparable<T>> void extractPiles(final T[] array, final PriorityQueue<PileNode<T>> pq) {
        int index = 0; // Index to track position in the output array
        
        // While there are elements in the priority queue
        while (!pq.isEmpty()) {
            PileNode<T> node = pq.poll(); // Get the smallest element
            array[index++] = node.value; // Place it in the sorted array
            
            // If the current pile still has elements, add the next top element to the queue
            if (!node.pile.isEmpty()) {
                pq.add(new PileNode<>(node.pile.remove(node.pile.size() - 1), node.pile));
            }
        }
    }

    // Class to represent a node in the priority queue, holding a value and a reference to its pile
    private static class PileNode<T extends Comparable<T>> implements Comparable<PileNode<T>> {
        final T value; // The value of the node
        final List<T> pile; // The remaining pile associated with this node
        
        // Constructor to initialize the PileNode
        public PileNode(T value, List<T> pile) {
            this.value = value;
            this.pile = pile;
        }
        
        // Compare this node with another based on the value
        @Override
        public int compareTo(PileNode<T> other) {
            return this.value.compareTo(other.value);
        }
    }
}
