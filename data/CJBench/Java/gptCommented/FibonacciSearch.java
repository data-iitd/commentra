import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the size of the array from user input
        int n = scanner.nextInt();
        
        // Initialize an array of Integer with the specified size
        Integer[] array = new Integer[n];
        
        // Populate the array with user input values
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        
        // Read the key value to search for in the array
        int key = scanner.nextInt();
        
        // Create an instance of Main to access the find method
        Main searcher = new Main();
        
        // Call the find method to search for the key in the array and store the result index
        int index = searcher.find(array, key);
        
        // Print the index of the found key or -1 if not found
        System.out.println(index);
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    // Generic method to find the index of a key in a sorted array using Fibonacci search
    public <T extends Comparable<T>> int find(T[] array, T key) {
        // Check if the input array is empty and throw an exception if it is
        if (array.length == 0) {
            throw new IllegalArgumentException("Input array must not be empty.");
        }
        
        // Check if the input array is sorted and throw an exception if it is not
        if (!isSorted(array)) {
            throw new IllegalArgumentException("Input array must be sorted.");
        }
        
        // Check if the key is null and throw an exception if it is
        if (key == null) {
            throw new IllegalArgumentException("Key must not be null.");
        }
        
        // Initialize Fibonacci numbers for the search
        int fibMinus1 = 1; // F(n-1)
        int fibMinus2 = 0; // F(n-2)
        int fibNumber = fibMinus1 + fibMinus2; // F(n)
        
        // Get the length of the array
        int n = array.length;
        
        // Find the largest Fibonacci number less than the length of the array
        while (fibNumber < n) {
            fibMinus2 = fibMinus1;
            fibMinus1 = fibNumber;
            fibNumber = fibMinus2 + fibMinus1;
        }
        
        // Initialize offset for the current position in the array
        int offset = -1;
        
        // Perform Fibonacci search
        while (fibNumber > 1) {
            // Calculate the index to compare with the key
            int i = Math.min(offset + fibMinus2, n - 1);
            
            // If the key is greater than the value at index i, move to the right
            if (array[i].compareTo(key) < 0) {
                fibNumber = fibMinus1;
                fibMinus1 = fibMinus2;
                fibMinus2 = fibNumber - fibMinus1;
                offset = i;
            } 
            // If the key is less than the value at index i, move to the left
            else if (array[i].compareTo(key) > 0) {
                fibNumber = fibMinus2;
                fibMinus1 = fibMinus1 - fibMinus2;
                fibMinus2 = fibNumber - fibMinus1;
            } 
            // If the key is found, return the index
            else {
                return i;
            }
        }
        
        // Check if the last element is the key
        if (fibMinus1 == 1 && offset + 1 < n && array[offset + 1].equals(key)) {
            return offset + 1; // Return the index of the key
        }
        
        // Return -1 if the key is not found in the array
        return -1;
    }

    // Method to check if the array is sorted
    private boolean isSorted(Comparable[] array) {
        // Iterate through the array to check for sorted order
        for (int i = 1; i < array.length; i++) {
            // If any element is greater than the next one, return false
            if (array[i - 1].compareTo(array[i]) > 0) {
                return false;
            }
        }
        // Return true if the array is sorted
        return true;
    }
}
