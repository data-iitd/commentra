import java.util.Scanner;

/**
 * CocktailShakerSort class implements the Cocktail Shaker Sort algorithm,
 * which is a bidirectional bubble sort. It sorts the array by passing
 * through it back and forth, progressively moving the largest elements
 * to the end and the smallest elements to the beginning.
 *
 * @author Mateus Bizzo (https://github.com/MattBizzo)
 * @author Podshivalov Nikita (https://github.com/nikitap492)
 */
public class CocktailShakerSort {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading the size of the array
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];

        // Reading the array elements
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        // Sorting the array
        CocktailShakerSort sorter = new CocktailShakerSort();
        sorter.sort(array);

        // Printing the sorted array
        for (int num : array) {
            System.out.print(num + " ");
        }

        scanner.close();
    }

    /**
     * Sorts the given array using the Cocktail Shaker Sort algorithm.
     *
     * @param <T> The type of elements in the array, which must be comparable
     * @param array The array to be sorted
     * @return The sorted array
     */
    public <T extends Comparable<T>> void sort(final T[] array) {
        if (array.length == 0) {
            return;
        }

        int left = 0;
        int right = array.length - 1;

        while (left < right) {
            right = performForwardPass(array, left, right);
            left = performBackwardPass(array, left, right);
        }
    }

    /**
     * Performs a forward pass through the array, moving larger elements to the end.
     *
     * @param <T>   The type of elements in the array, which must be comparable
     * @param array The array being sorted
     * @param left  The current left boundary of the sorting area
     * @param right The current right boundary of the sorting area
     * @return The index of the last swapped element during this pass
     */
    private <T extends Comparable<T>> int performForwardPass(final T[] array, final int left, final int right) {
        int lastSwappedIndex = left;

        for (int i = left; i < right; i++) {
            if (array[i].compareTo(array[i + 1]) > 0) {
                swap(array, i, i + 1);
                lastSwappedIndex = i;
            }
        }

        return lastSwappedIndex;
    }

    /**
     * Performs a backward pass through the array, moving smaller elements to the beginning.
     *
     * @param <T>   The type of elements in the array, which must be comparable
     * @param array The array being sorted
     * @param left  The current left boundary of the sorting area
     * @param right The current right boundary of the sorting area
     * @return The index of the last swapped element during this pass
     */
    private <T extends Comparable<T>> int performBackwardPass(final T[] array, final int left, final int right) {
        int lastSwappedIndex = right;

        for (int i = right; i > left; i--) {
            if (array[i].compareTo(array[i - 1]) < 0) {
                swap(array, i - 1, i);
                lastSwappedIndex = i;
            }
        }

        return lastSwappedIndex;
    }

    /**
     * Swaps two elements in the array.
     *
     * @param array The array
     * @param i Index of the first element
     * @param j Index of the second element
     */
    private <T> void swap(final T[] array, final int i, final int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
