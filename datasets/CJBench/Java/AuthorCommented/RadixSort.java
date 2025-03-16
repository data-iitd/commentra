import java.util.Arrays;
import java.util.Scanner;

/**
 * This class provides an implementation of the radix sort algorithm.
 * It sorts an array of nonnegative integers in increasing order.
 */
public final class RadixSort {

    private static final int BASE = 10;

    private RadixSort() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input: Size of the array
        int n = scanner.nextInt();
        int[] array = new int[n];

        // Input: Array elements
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        // Perform Radix Sort
        sort(array);

        // Output: Sorted array
        for (int num : array) {
            System.out.print(num + " ");
        }
        System.out.println();

        scanner.close();
    }

    /**
     * Sorts an array of nonnegative integers using the radix sort algorithm.
     *
     * @param array the array to be sorted
     * @return the sorted array
     * @throws IllegalArgumentException if any negative integers are found
     */
    public static int[] sort(int[] array) {
        if (array.length == 0) {
            return array;
        }

        checkForNegativeInput(array);
        radixSort(array);
        return array;
    }

    /**
     * Checks if the array contains any negative integers.
     *
     * @param array the array to be checked
     * @throws IllegalArgumentException if any negative integers are found
     */
    private static void checkForNegativeInput(int[] array) {
        for (int number : array) {
            if (number < 0) {
                throw new IllegalArgumentException("Array contains negative integers.");
            }
        }
    }

    private static void radixSort(int[] array) {
        final int max = Arrays.stream(array).max().getAsInt();
        for (int exp = 1; max / exp > 0; exp *= BASE) {
            countingSortByDigit(array, exp);
        }
    }

    /**
     * A utility method to perform counting sort of array[] according to the digit represented by exp.
     *
     * @param array the array to be sorted
     * @param exp   the exponent representing the current digit position
     */
    private static void countingSortByDigit(int[] array, int exp) {
        int[] count = new int[BASE];
        int[] output = new int[array.length];

        for (int i = 0; i < array.length; i++) {
            count[(array[i] / exp) % BASE]++;
        }

        for (int i = 1; i < BASE; i++) {
            count[i] += count[i - 1];
        }

        for (int i = array.length - 1; i >= 0; i--) {
            int digit = (array[i] / exp) % BASE;
            output[count[digit] - 1] = array[i];
            count[digit]--;
        }

        System.arraycopy(output, 0, array, 0, array.length);
    }
}
