import java.util.Arrays; // Importing Arrays utility for array operations
import java.util.Scanner; // Importing Scanner for reading input

public final class Main {
    private static final int BASE = 10; // Constant for radix sort base

    // Private constructor to prevent instantiation
    private Main() {
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize scanner for input
        int n = scanner.nextInt(); // Read number of elements
        int[] array = new int[n]; // Initialize array of size n
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt(); // Read elements into array
        }
        sort(array); // Sort the array
        for (int num : array) {
            System.out.print(num + " "); // Print sorted array
        }
        System.out.println();
        scanner.close(); // Close the scanner
    }

    // Method to sort the array using radix sort
    public static int[] sort(int[] array) {
        if (array.length == 0) {
            return array; // Return array if it's empty
        }
        checkForNegativeInput(array); // Check for negative integers
        radixSort(array); // Perform radix sort
        return array; // Return sorted array
    }

    // Private method to check if the array contains negative integers
    private static void checkForNegativeInput(int[] array) {
        for (int number : array) {
            if (number < 0) {
                throw new IllegalArgumentException("Array contains negative integers."); // Throw exception if negative integer found
            }
        }
    }

    // Method to perform radix sort on the array
    private static void radixSort(int[] array) {
        final int max = Arrays.stream(array).max().getAsInt(); // Find maximum value in the array
        for (int exp = 1; max / exp > 0; exp *= BASE) { // Loop through each digit place
            countingSortByDigit(array, exp); // Perform counting sort for the current digit place
        }
    }

    // Private method to perform counting sort based on a specific digit
    private static void countingSortByDigit(int[] array, int exp) {
        int[] count = new int[BASE]; // Array to store count of each digit
        int[] output = new int[array.length]; // Array to store sorted output
        for (int i = 0; i < array.length; i++) {
            count[(array[i] / exp) % BASE]++; // Count occurrences of each digit
        }
        for (int i = 1; i < BASE; i++) {
            count[i] += count[i - 1]; // Calculate cumulative count
        }
        for (int i = array.length - 1; i >= 0; i--) {
            int digit = (array[i] / exp) % BASE;
            output[count[digit] - 1] = array[i]; // Place elements in output array
            count[digit]--; // Decrement count for the digit
        }
        System.arraycopy(output, 0, array, 0, array.length); // Copy output array back to original array
    }
}
