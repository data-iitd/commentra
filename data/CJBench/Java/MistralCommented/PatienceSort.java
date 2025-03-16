
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    // Initialize a Scanner to read input from the standard input
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read the number of elements in the array from the standard input
        int n = scanner.nextInt();

        // Allocate an array of Integer type with the given size
        Integer[] array = new Integer[n];

        // Read each element of the array from the standard input and store it in the corresponding index
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        // Call the patienceSort method to sort the array using the Merge-Sort algorithm with patience
        patienceSort(array);

        // Print each element of the sorted array to the standard output
        for (int num : array) {
            System.out.print(num + " ");
        }

        // Close the Scanner to release the system resources
        scanner.close();
    }

    // The patienceSort method sorts an array using the Merge-Sort algorithm with patience
    // It returns the sorted array as a result
    public static <T extends Comparable<T>> T[] patienceSort(T[] array) {
        // Base case: if the array is empty, return it as is
        if (array.length == 0) {
            return array;
        }

        // Form piles of elements using the Merge-Sort algorithm with patience
        final List<List<T>> piles = formPiles(array);

        // Merge the piles using a PriorityQueue
        final PriorityQueue<PileNode<T>> pq = mergePiles(piles);

        // Extract the sorted elements from the PriorityQueue and store them back in the array
        extractPiles(array, pq);

        // Return the sorted array as a result
        return array;
    }

    // Form piles of elements using the Merge-Sort algorithm with patience
    // The method returns a List of Lists, where each List represents a pile
    private static <T extends Comparable<T>> List<List<T>> formPiles(final T[] array) {
        final List<List<T>> piles = new ArrayList<>();
        final List<T> lastElements = new ArrayList<>();

        // Iterate through each element in the array
        for (T x : array) {
            // Determine the position where the current element should be placed in the lastElements List
            int pos = Collections.binarySearch(lastElements, x);

            // If the current element is smaller than the last element in the lastElements List,
            // it should be placed before that element in the corresponding pile
            if (pos < 0) {
                pos = -pos - 1;
            }

            // If the current position is within the bounds of the piles List,
            // add the current element to the corresponding pile and update the lastElements List
            if (pos < piles.size()) {
                piles.get(pos).add(x);
                lastElements.set(pos, x);
            } else {
                // Otherwise, create a new pile and add the current element to it
                List<T> newPile = new ArrayList<>();
                newPile.add(x);
                piles.add(newPile);
                lastElements.add(x);
            }
        }

        // Return the piles List as a result
        return piles;
    }

    // Merge the piles using a PriorityQueue
    // The method returns a PriorityQueue of PileNodes, where each PileNode represents a pile
    private static <T extends Comparable<T>> PriorityQueue<PileNode<T>> mergePiles(final Iterable<List<T>> piles) {
        PriorityQueue<PileNode<T>> pq = new PriorityQueue<>();

        // Iterate through each pile in the piles Iterable
        for (List<T> pile : piles) {
            // Create a new PileNode with the last element of the current pile and the pile itself
            // Add the new PileNode to the PriorityQueue
            pq.add(new PileNode<>(pile.remove(pile.size() - 1), pile));
        }

        // Return the PriorityQueue of PileNodes as a result
        return pq;
    }

    // Extract the sorted elements from the PriorityQueue and store them back in the array
    private static <T extends Comparable<T>> void extractPiles(final T[] array, final PriorityQueue<PileNode<T>> pq) {
        int index = 0;

        // Iterate through each PileNode in the PriorityQueue until it is empty
        while (!pq.isEmpty()) {
            // Dequeue the current PileNode from the PriorityQueue
            PileNode<T> node = pq.poll();

            // Store the value of the current PileNode (the last element of the corresponding pile)
            // in the corresponding index of the array
            array[index++] = node.value;

            // If the pile of the current PileNode is not empty, add its last element to the PriorityQueue
            if (!node.pile.isEmpty()) {
                // Create a new PileNode with the last element of the updated pile and the pile itself
                // Add the new PileNode to the PriorityQueue
                pq.add(new PileNode<>(node.pile.remove(node.pile.size() - 1), node.pile));
            }
        }
    }

    // A custom class representing a pile of elements and a PileNode in the PriorityQueue
    private static class PileNode<T extends Comparable<T>> implements Comparable<PileNode<T>> {
        // The value of the current pile (the last element)
        final T value;

        // The pile itself (the rest of the elements)
        final List<T> pile;

        // Initialize a new PileNode with the given value and pile
        public PileNode(T value, List<T> pile) {
            this.value = value;
            this.pile = pile;
        }

        // Implement the Comparable interface to compare two PileNodes based on their values
        @Override
        public int compareTo(PileNode<T> other) {
            return this.value.compareTo(other.value);
        }
    }
}