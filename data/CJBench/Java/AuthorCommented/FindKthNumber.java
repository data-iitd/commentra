
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;

/**
 * This class uses a quicksort-based approach (QuickSelect) to find the k-th largest element in an array.
 * The k-th largest element is the element that would be in the k-th position if the array were sorted in descending order.
 */
public final class FindKthNumber {
    private FindKthNumber() {
    }

    private static final Random RANDOM = new Random();

    /**
     * Finds the k-th largest element in the given array.
     *
     * @param array The input array of integers.
     * @param k     The position (1-based) of the largest element to find.
     * @return The k-th largest element in the array.
     */
    public static int findKthMax(int[] array, int k) {
        if (k <= 0 || k > array.length) {
            throw new IllegalArgumentException("k must be between 1 and the size of the array");
        }

        // Convert k-th largest to index for QuickSelect
        return quickSelect(array, 0, array.length - 1, array.length - k);
    }

    /**
     * Performs the QuickSelect algorithm to find the k-th smallest element in the array.
     *
     * @param array      The input array.
     * @param left       The starting index of the current segment.
     * @param right      The ending index of the current segment.
     * @param kSmallest  The index of the k-th smallest element (0-based).
     * @return The k-th smallest element in the array.
     */
    private static int quickSelect(int[] array, int left, int right, int kSmallest) {
        if (left == right) {
            return array[left];
        }

        // Randomly select a pivot index
        int pivotIndex = left + RANDOM.nextInt(right - left + 1);
        pivotIndex = partition(array, left, right, pivotIndex);

        if (kSmallest == pivotIndex) {
            return array[kSmallest];
        } else if (kSmallest < pivotIndex) {
            return quickSelect(array, left, pivotIndex - 1, kSmallest);
        } else {
            return quickSelect(array, pivotIndex + 1, right, kSmallest);
        }
    }

    /**
     * Partitions the array around a pivot such that all elements smaller than the pivot
     * are moved to the left of the pivot and all elements greater are moved to the right.
     *
     * @param array      The input array.
     * @param left       The starting index of the segment.
     * @param right      The ending index of the segment.
     * @param pivotIndex The index of the pivot element.
     * @return The final position of the pivot element after partitioning.
     */
    private static int partition(int[] array, int left, int right, int pivotIndex) {
        int pivotValue = array[pivotIndex];
        // Move pivot to end
        swap(array, pivotIndex, right);
        int storeIndex = left;

        // Move all smaller elements to the left
        for (int i = left; i < right; i++) {
            if (array[i] < pivotValue) {
                swap(array, storeIndex, i);
                storeIndex++;
            }
        }

        // Move pivot to its final place
        swap(array, storeIndex, right);
        return storeIndex;
    }

    /**
     * Swaps two elements in the array.
     *
     * @param array The input array.
     * @param i     The index of the first element.
     * @param j     The index of the second element.
     */
    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            int n = scanner.nextInt();

            if (n <= 0) {
                System.out.println("Array size must be positive.");
                return;
            }

            int[] array = new int[n];
            for (int i = 0; i < n; i++) {
                array[i] = scanner.nextInt();
            }

            int k = scanner.nextInt();

            if (k <= 0 || k > n) {
                System.out.println("Error: k must be between 1 and the size of the array.");
                return;
            }

            int result = findKthMax(array, k);
            System.out.println("The " + k + "-th largest element is: " + result);
        } catch (Exception e) {
            System.out.println("An error occurred: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
