import java.util.Arrays;
import java.util.Scanner;

public final class Main {
    // Constant for the base used in radix sort
    private static final int BASE = 10;

    // Private constructor to prevent instantiation
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements in the array
        int n = scanner.nextInt();
        
        // Initialize the array with the specified size
        int[] array = new int[n];
        
        // Read the elements of the array from user input
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        
        // Sort the array using the sort method
        sort(array);
        
        // Print the sorted array
        for (int num : array) {
            System.out.print(num + " ");
        }
        System.out.println();
        
        // Close the scanner to free resources
        scanner.close();
    }

    // Method to sort the array using radix sort
    public static int[] sort(int[] array) {
        // Return the array immediately if it is empty
        if (array.length == 0) {
            return array;
        }
        
        // Check for negative integers in the array
        checkForNegativeInput(array);
        
        // Perform radix sort on the array
        radixSort(array);
        
        // Return the sorted array
        return array;
    }

    // Method to check if the array contains negative integers
    private static void checkForNegativeInput(int[] array) {
        for (int number : array) {
            // Throw an exception if a negative integer is found
            if (number < 0) {
                throw new IllegalArgumentException("Array contains negative integers.");
            }
        }
    }

    // Method to perform radix sort on the array
    private static void radixSort(int[] array) {
        // Find the maximum number to determine the number of digits
        final int max = Arrays.stream(array).max().getAsInt();
        
        // Perform counting sort for each digit, starting from the least significant digit
        for (int exp = 1; max / exp > 0; exp *= BASE) {
            countingSortByDigit(array, exp);
        }
    }

    // Method to perform counting sort based on the digit represented by exp
    private static void countingSortByDigit(int[] array, int exp) {
        // Create a count array to store the count of occurrences of each digit
        int[] count = new int[BASE];
        // Create an output array to hold the sorted elements
        int[] output = new int[array.length];
        
        // Count occurrences of each digit in the specified place value
        for (int i = 0; i < array.length; i++) {
            count[(array[i] / exp) % BASE]++;
        }
        
        // Update the count array to contain the actual positions of digits
        for (int i = 1; i < BASE; i++) {
            count[i] += count[i - 1];
        }
        
        // Build the output array by placing elements in the correct order
        for (int i = array.length - 1; i >= 0; i--) {
            int digit = (array[i] / exp) % BASE;
            output[count[digit] - 1] = array[i];
            count[digit]--;
        }
        
        // Copy the sorted output array back to the original array
        System.arraycopy(output, 0, array, 0, array.length);
    }
}
