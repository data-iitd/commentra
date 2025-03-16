
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Read the size of the array from the user input
        int n = scanner.nextInt();

        // Allocate memory for an array of Integer type with the given size
        Integer[] array = new Integer[n];

        // Read the elements of the array from the user input
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        // Read the key to be searched from the user input
        int key = scanner.nextInt();

        // Create an instance of the Main class to call the find() method
        Main searcher = new Main();

        // Call the find() method to search for the key in the array
        int index = searcher.find(array, key);

        // Print the index of the key in the array
        System.out.println(index);

        // Close the Scanner object to release system resources
        scanner.close();
    }

    // Method to search for a given key in a sorted array using binary search algorithm
    public <T extends Comparable<T>> int find(T[] array, T key) {
        // Check if the array is empty
        if (array.length == 0) {
            throw new IllegalArgumentException("Input array must not be empty.");
        }

        // Check if the array is sorted
        if (!isSorted(array)) {
            throw new IllegalArgumentException("Input array must be sorted.");
        }

        // Check if the key is null
        if (key == null) {
            throw new IllegalArgumentException("Key must not be null.");
        }

        // Initialize variables for Fibonacci sequence calculation
        int fibMinus1 = 1;
        int fibMinus2 = 0;
        int fibNumber = fibMinus1 + fibMinus2;

        // Get the length of the array
        int n = array.length;

        // Use Fibonacci sequence to find the optimal search interval
        while (fibNumber < n) {
            fibMinus2 = fibMinus1;
            fibMinus1 = fibNumber;
            fibNumber = fibMinus1 + fibMinus2;
        }

        // Initialize an offset variable to keep track of the current position in the array
        int offset = -1;

        // Use Fibonacci sequence to find the position of the key in the array
        while (fibNumber > 1) {
            int i = Math.min(offset + fibMinus2, n - 1);

            // Compare the current element with the key and adjust the search interval accordingly
            if (array[i].compareTo(key) < 0) {
                fibNumber = fibMinus1;
                fibMinus1 = fibMinus2;
                fibMinus2 = fibNumber - fibMinus1;
                offset = i;
            } else if (array[i].compareTo(key) > 0) {
                fibNumber = fibMinus2;
                fibMinus1 = fibMinus1 - fibMinus2;
                fibMinus2 = fibNumber - fibMinus1;
            }
        }

        // Check if the key is located at the last position of the search interval
        if (fibMinus1 == 1 && offset + 1 < n && array[offset + 1].compareTo(key) == 0) {
            return offset + 1;
        }

        // Return -1 if the key is not found in the array
        return -1;
    }

    // Helper method to check if an array is sorted or not
    private boolean isSorted(Comparable[] array) {
        // Iterate through the array to check if it is sorted
        for (int i = 1; i < array.length; i++) {
            // Compare adjacent elements and return false if they are not in the correct order
            if (array[i - 1].compareTo(array[i]) > 0) {
                return false;
            }
        }

        // Return true if the array is sorted
        return true;
    }
}