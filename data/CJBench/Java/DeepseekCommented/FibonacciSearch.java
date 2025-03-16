import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input stream
        Scanner scanner = new Scanner(System.in);
        // Read the size of the array
        int n = scanner.nextInt();
        // Create an array of size n to store the integers
        Integer[] array = new Integer[n];
        // Read n integers into the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        // Read the key to be searched for in the array
        int key = scanner.nextInt();
        // Create an instance of the Main class to call the find method
        Main searcher = new Main();
        // Call the find method to find the index of the key in the array
        int index = searcher.find(array, key);
        // Print the index of the key in the array
        System.out.println(index);
        // Close the scanner to free up resources
        scanner.close();
    }
    // The find method uses a modified binary search (Fibonacci search) to find the index of the key in the array
    public <T extends Comparable<T>> int find(T[] array, T key) {
        // Check if the array is empty and throw an exception if it is
        if (array.length == 0) {
            throw new IllegalArgumentException("Input array must not be empty.");
        }
        // Check if the array is sorted and throw an exception if it is not
        if (!isSorted(array)) {
            throw new IllegalArgumentException("Input array must be sorted.");
        }
        // Check if the key is null and throw an exception if it is
        if (key == null) {
            throw new IllegalArgumentException("Key must not be null.");
        }
        // Calculate Fibonacci numbers to determine the range to search within the array
        int fibMinus1 = 1;
        int fibMinus2 = 0;
        int fibNumber = fibMinus1 + fibMinus2;
        int n = array.length;
        while (fibNumber < n) {
            fibMinus2 = fibMinus1;
            fibMinus1 = fibNumber;
            fibNumber = fibMinus2 + fibMinus1;
        }
        // Perform a search similar to binary search but using Fibonacci numbers to reduce the number of comparisons
        int offset = -1;
        while (fibNumber > 1) {
            int i = Math.min(offset + fibMinus2, n - 1);
            if (array[i].compareTo(key) < 0) {
                fibNumber = fibMinus1;
                fibMinus1 = fibMinus2;
                fibMinus2 = fibNumber - fibMinus1;
                offset = i;
            } else if (array[i].compareTo(key) > 0) {
                fibNumber = fibMinus2;
                fibMinus1 = fibMinus1 - fibMinus2;
                fibMinus2 = fibNumber - fibMinus1;
            } else {
                return i;
            }
        }
        // Check if the key is found at the next position after the offset
        if (fibMinus1 == 1 && offset + 1 < n && array[offset + 1].equals(key)) {
            return offset + 1;
        }
        // Return -1 if the key is not found in the array
        return -1;
    }
    // The isSorted method checks if the array is sorted in ascending order
    private boolean isSorted(Comparable[] array) {
        for (int i = 1; i < array.length; i++) {
            if (array[i - 1].compareTo(array[i]) > 0) {
                return false;
            }
        }
        return true;
    }
}
