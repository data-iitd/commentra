
import java.util.Arrays;
import java.util.Scanner;

public final class Main {
    private static final int BASE = 10; // Base for radix sort
    private Main() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize Scanner for user input
        int n = scanner.nextInt(); // Read the number of elements in the array from user input
        int[] array = new int[n]; // Create an integer array with the given size

        for (int i = 0; i < n; i++) { // Iterate through the array to read user input
            array[i] = scanner.nextInt(); // Read an integer from user input and store it in the array
        }

        sort(array); // Call the sorting method to sort the array

        for (int num : array) { // Iterate through the sorted array and print each element
            System.out.print(num + " ");
        }
        System.out.println(); // Print a newline character after printing all elements
        scanner.close(); // Close the Scanner to release system resources
    }

    public static int[] sort(int[] array) {
        if (array.length == 0) { // Check if the array is empty and return it if true
            return array;
        }
        checkForNegativeInput(array); // Check for negative integers in the array and throw an exception if found
        radixSort(array); // Call the radix sorting method to sort the array
        return array; // Return the sorted array
    }

    private static void checkForNegativeInput(int[] array) {
        for (int number : array) { // Iterate through the array to check for negative integers
            if (number < 0) {
                throw new IllegalArgumentException("Array contains negative integers."); // Throw an exception if a negative integer is found
            }
        }
    }

    private static void radixSort(int[] array) {
        final int max = Arrays.stream(array).max().getAsInt(); // Find the maximum integer in the array
        for (int exp = 1; max / exp > 0; exp *= BASE) { // Iterate through each digit in the integers
            countingSortByDigit(array, exp); // Call the counting sort method to sort the array based on the current digit
        }
    }

    private static void countingSortByDigit(int[] array, int exp) {
        int[] count = new int[BASE]; // Initialize a count array to store the frequency of each digit
        int[] output = new int[array.length]; // Initialize an output array to store the sorted elements

        for (int i = 0; i < array.length; i++) { // Iterate through the array to count the frequency of each digit
            count[(array[i] / exp) % BASE]++; // Increment the count of the digit at the current index
        }

        for (int i = 1; i < BASE; i++) { // Iterate through the count array to calculate the total frequency of each digit
            count[i] += count[i - 1]; // Add the frequency of the current digit to the frequency of the previous digit
        }

        for (int i = array.length - 1; i >= 0; i--) { // Iterate through the array in reverse order to place the elements in their correct positions
            int digit = (array[i] / exp) % BASE; // Extract the digit at the current index
            output[count[digit] - 1] = array[i]; // Place the element at the correct position in the output array
            count[digit]--; // Decrement the count of the current digit to place the next element
        }

        System.arraycopy(output, 0, array, 0, array.length); // Copy the sorted elements from the output array to the original array.