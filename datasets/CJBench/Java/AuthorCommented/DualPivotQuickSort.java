import java.util.Scanner;

/**
 * Dual Pivot Quick Sort Algorithm
 *
 * @author Debasish Biswas (https://github.com/debasishbsws) *
 * @see SortAlgorithm
 */
public class DualPivotQuickSort {

    /**
     * Sorts an array using the Dual Pivot QuickSort algorithm.
     *
     * @param array The array to be sorted
     * @param <T>   The type of elements in the array, which must be comparable
     * @return The sorted array
     */
    public static <T extends Comparable<T>> void sort(T[] array) {
        if (array.length > 1) {
            dualPivotQuicksort(array, 0, array.length - 1);
        }
    }

    /**
     * Recursively applies the Dual Pivot QuickSort algorithm to subarrays.
     *
     * @param array The array to be sorted
     * @param left  The starting index of the subarray
     * @param right The ending index of the subarray
     * @param <T>   The type of elements in the array, which must be comparable
     */
    private static <T extends Comparable<T>> void dualPivotQuicksort(final T[] array, final int left, final int right) {
        if (left < right) {
            final int[] pivots = partition(array, left, right);

            dualPivotQuicksort(array, left, pivots[0] - 1);
            dualPivotQuicksort(array, pivots[0] + 1, pivots[1] - 1);
            dualPivotQuicksort(array, pivots[1] + 1, right);
        }
    }

    /**
     * Partitions the array into three parts using two pivots.
     *
     * @param array The array to be partitioned
     * @param left  The starting index for partitioning
     * @param right The ending index for partitioning
     * @param <T>   The type of elements in the array, which must be comparable
     * @return An array containing the indices of the two pivots
     */
    private static <T extends Comparable<T>> int[] partition(final T[] array, int left, final int right) {
        if (array[left].compareTo(array[right]) > 0) {
            swap(array, left, right);
        }

        final T pivot1 = array[left];
        final T pivot2 = array[right];

        int pivot1End = left + 1;
        int low = left + 1;
        int high = right - 1;

        while (low <= high) {
            if (array[low].compareTo(pivot1) < 0) {
                swap(array, low, pivot1End);
                pivot1End++;
            } else if (array[low].compareTo(pivot2) >= 0) {
                while (low < high && array[high].compareTo(pivot2) > 0) {
                    high--;
                }
                swap(array, low, high);
                high--;

                if (array[low].compareTo(pivot1) < 0) {
                    swap(array, low, pivot1End);
                    pivot1End++;
                }
            }
            low++;
        }

        // Place the pivots in their correct positions
        pivot1End--;
        high++;

        swap(array, left, pivot1End);
        swap(array, right, high);

        // Return the indices of the pivots
        return new int[]{pivot1End, high};
    }

    private static <T> void swap(T[] array, int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input array size
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];

        // Input array elements
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        // Sort the array
        sort(array);

        // Print the sorted array
        for (int num : array) {
            System.out.print(num + " ");
        }
        scanner.close();
    }
}
