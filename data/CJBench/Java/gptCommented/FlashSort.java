import java.util.Scanner;
import java.util.Arrays;

public class Main {
    // Default classification ratio for the sorting algorithm
    private double classificationRatio = 0.45;

    // Default constructor
    public Main() {}

    // Constructor that allows setting a custom classification ratio
    public Main(double classificationRatio) {
        // Validate the classification ratio to ensure it's between 0 and 1
        if (classificationRatio <= 0 || classificationRatio >= 1) {
            throw new IllegalArgumentException("Classification ratio must be between 0 and 1 (exclusive).");
        }
        this.classificationRatio = classificationRatio;
    }

    // Method to set the classification ratio with validation
    public void setClassificationRatio(double classificationRatio) {
        if (classificationRatio <= 0 || classificationRatio >= 1) {
            throw new IllegalArgumentException("Classification ratio must be between 0 and 1 (exclusive).");
        }
        this.classificationRatio = classificationRatio;
    }

    // Public method to sort an array using the flash sort algorithm
    public <T extends Comparable<T>> T[] sort(T[] array) {
        flashSort(array); // Call the flash sort method
        return array; // Return the sorted array
    }

    // Private method implementing the flash sort algorithm
    private <T extends Comparable<? super T>> void flashSort(T[] arr) {
        // Return if the array is empty
        if (arr.length == 0) {
            return;
        }
        
        // Find the minimum value in the array
        T min = findMin(arr);
        // Find the index of the maximum value in the array
        int maxIndex = findMaxIndex(arr);
        
        // If the maximum value is equal to the minimum, no sorting is needed
        if (arr[maxIndex].compareTo(min) == 0) {
            return; 
        }

        // Calculate the size of the classification array based on the classification ratio
        int m = (int) (classificationRatio * arr.length);
        int[] classificationArray = new int[m]; // Create the classification array
        double c1 = (double) (m - 1) / arr[maxIndex].compareTo(min); // Calculate the scaling factor

        // Classify the elements of the array into the classification array
        classify(arr, classificationArray, c1, min);
        // Transform the classification array to cumulative counts
        transform(classificationArray);
        // Permute the original array based on the classification array
        permute(arr, classificationArray, c1, min, arr.length, m);
        // Finally, sort any remaining elements using insertion sort
        insertionSort(arr);
    }

    // Method to find the minimum element in the array
    private <T extends Comparable<? super T>> T findMin(T[] arr) {
        T min = arr[0]; // Assume the first element is the minimum
        for (T t : arr) {
            // Update min if a smaller element is found
            if (t.compareTo(min) < 0) {
                min = t;
            }
        }
        return min; // Return the minimum element
    }

    // Method to find the index of the maximum element in the array
    private <T extends Comparable<? super T>> int findMaxIndex(T[] arr) {
        int maxIndex = 0; // Start with the first index as the maximum
        for (int i = 1; i < arr.length; i++) {
            // Update maxIndex if a larger element is found
            if (arr[i].compareTo(arr[maxIndex]) > 0) {
                maxIndex = i;
            }
        }
        return maxIndex; // Return the index of the maximum element
    }

    // Method to classify elements into the classification array
    private <T extends Comparable<? super T>> void classify(T[] arr, int[] classificationArray, double c1, T min) {
        for (T t : arr) {
            // Calculate the index for classification based on the element's value
            int k = (int) (c1 * t.compareTo(min));
            classificationArray[k]++; // Increment the count in the classification array
        }
    }

    // Method to transform the classification array into cumulative counts
    private void transform(int[] classificationArray) {
        for (int i = 1; i < classificationArray.length; i++) {
            classificationArray[i] += classificationArray[i - 1]; // Cumulative sum
        }
    }

    // Method to permute the original array based on the classification array
    private <T extends Comparable<? super T>> void permute(T[] arr, int[] classificationArray, double c1, T min, int n, int m) {
        int move = 0; // Counter for the number of moves
        int j = 0; // Current index in the original array
        int k = m - 1; // Current index in the classification array
        T flash; // Temporary variable for swapping

        // Loop until all elements have been moved
        while (move < n - 1) {
            // Find the correct position for the current element
            while (j > classificationArray[k] - 1) {
                j++;
                k = (int) (c1 * arr[j].compareTo(min)); // Update k based on the current element
            }
            flash = arr[j]; // Store the current element
            // Swap elements until the current element is in the correct position
            while (j != classificationArray[k]) {
                k = (int) (c1 * flash.compareTo(min)); // Find the new position for flash
                T temp = arr[classificationArray[k] - 1]; // Get the element at the new position
                arr[classificationArray[k] - 1] = flash; // Place flash in the new position
                flash = temp; // Update flash to the element that was swapped out
                classificationArray[k]--; // Decrement the count in the classification array
                move++; // Increment the move counter
            }
        }
    }

    // Method to perform insertion sort on the array
    private <T extends Comparable<? super T>> void insertionSort(T[] arr) {
        for (int i = 1; i < arr.length; i++) {
            T key = arr[i]; // Element to be inserted
            int j = i - 1; // Index of the last sorted element
            // Move elements that are greater than key to one position ahead
            while (j >= 0 && arr[j].compareTo(key) > 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key; // Insert the key in its correct position
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int n = scanner.nextInt(); // Read the number of elements
        Integer[] array = new Integer[n]; // Create an array of integers
        // Read the elements into the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        Main flashSort = new Main(); // Create an instance of Main
        flashSort.sort(array); // Sort the array using flash sort
        // Print the sorted array
        for (int num : array) {
            System.out.print(num + " ");
        }
        scanner.close(); // Close the scanner
    }
}
