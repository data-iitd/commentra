import java.util.Scanner;
import java.util.Arrays;

// Class definition for the Main class
public class Main {

    // Class variable for the classification ratio
    private double classificationRatio = 0.45;

    // Constructor with no arguments
    public Main() {}

    // Constructor with a classification ratio argument
    public Main(double classificationRatio) {
        // Initialize the classification ratio with the given value
        // If the classification ratio is not between 0 and 1, throw an exception
        if (classificationRatio <= 0 || classificationRatio >= 1) {
            throw new IllegalArgumentException("Classification ratio must be between 0 and 1 (exclusive).");
        }
        this.classificationRatio = classificationRatio;
    }

    // Setter method for the classification ratio
    public void setClassificationRatio(double classificationRatio) {
        // Initialize the classification ratio with the given value
        // If the classification ratio is not between 0 and 1, throw an exception
        if (classificationRatio <= 0 || classificationRatio >= 1) {
            throw new IllegalArgumentException("Classification ratio must be between 0 and 1 (exclusive).");
        }
        this.classificationRatio = classificationRatio;
    }

    // Method to sort an array using the flash sort algorithm
    public <T extends Comparable<T>> T[] sort(T[] array) {
        flashSort(array);
        return array;
    }

    // Private method to perform the flash sort algorithm on an array
    private <T extends Comparable<? super T>> void flashSort(T[] arr) {
        // Base case: if the array is empty, return
        if (arr.length == 0) {
            return;
        }

        // Find the minimum and maximum elements in the array
        T min = findMin(arr);
        int maxIndex = findMaxIndex(arr);

        // If the minimum and maximum elements are the same, return
        if (arr[maxIndex].compareTo(min) == 0) {
            return;
        }

        // Calculate the number of elements to classify based on the classification ratio
        int m = (int) (classificationRatio * arr.length);

        // Create an array to store the classification results
        int[] classificationArray = new int[m];

        // Calculate the constant c1 for the flash sort algorithm
        double c1 = (double) (m - 1) / arr[maxIndex].compareTo(min);

        // Perform the classify step of the flash sort algorithm
        classify(arr, classificationArray, c1, min);

        // Perform the transform step of the flash sort algorithm
        transform(classificationArray);

        // Perform the permute step of the flash sort algorithm
        permute(arr, classificationArray, c1, min, arr.length, m);

        // Perform the insertion sort step of the flash sort algorithm
        insertionSort(arr);
    }

    // Method to find the minimum element in an array
    private <T extends Comparable<? super T>> T findMin(T[] arr) {
        // Initialize the minimum element to the first element in the array
        T min = arr[0];

        // Iterate through the array to find the minimum element
        for (T t : arr) {
            // If the current element is smaller than the minimum element, update the minimum element
            if (t.compareTo(min) < 0) {
                min = t;
            }
        }

        // Return the minimum element
        return min;
    }

    // Method to find the index of the maximum element in an array
    private <T extends Comparable<? super T>> int findMaxIndex(T[] arr) {
        // Initialize the maximum index to the first index in the array
        int maxIndex = 0;

        // Iterate through the array to find the index of the maximum element
        for (int i = 1; i < arr.length; i++) {
            // If the current element is greater than the maximum element, update the maximum index
            if (arr[i].compareTo(arr[maxIndex]) > 0) {
                maxIndex = i;
            }
        }

        // Return the index of the maximum element
        return maxIndex;
    }

    // Method to perform the classify step of the flash sort algorithm
    private <T extends Comparable<? super T>> void classify(T[] arr, int[] classificationArray, double c1, T min) {
        // Iterate through the array to classify each element
        for (T t : arr) {
            // Calculate the index in the classification array based on the comparison of the element and the minimum element
            int k = (int) (c1 * t.compareTo(min));

            // Increment the corresponding index in the classification array
            classificationArray[k]++;
        }
    }

    // Method to perform the transform step of the flash sort algorithm
    private void transform(int[] classificationArray) {
        // Iterate through the classification array to calculate the cumulative sum of each index
        for (int i = 1; i < classificationArray.length; i++) {
            classificationArray[i] += classificationArray[i - 1];
        }
    }

    // Method to perform the permute step of the flash sort algorithm
    private <T extends Comparable<? super T>> void permute(T[] arr, int[] classificationArray, double c1, T min, int n, int m) {
        // Initialize variables for the move index, the index j, and the index k
        int move = 0;
        int j = 0;
        int k = m - 1;

        // Initialize a variable to store the flashed element
        T flash;

        // Iterate through the array to perform the permute step
        while (move < n - 1) {
            // Iterate through the classification array to find the next element to swap
            while (j > classificationArray[k] - 1) {
                j++;
                k = (int) (c1 * arr[j].compareTo(min));
            }

            // Swap the current element with the element found in the classification array
            flash = arr[j];
            while (j != classificationArray[k]) {
                k = (int) (c1 * flash.compareTo(min));
                // Swap the elements at the indices found in the classification array
                T temp = arr[classificationArray[k] - 1];
                arr[classificationArray[k] - 1] = flash;
                flash = temp;
                // Decrement the index k in the classification array
                classificationArray[k]--;
                // Increment the move index
                move++;
            }
        }
    }

    // Method to perform the insertion sort step of the flash sort algorithm
    private <T extends Comparable<? super T>> void insertionSort(T[] arr) {
        // Iterate through the array to perform the insertion sort
        for (int i = 1; i < arr.length; i++) {
            T key = arr[i];
            int j = i - 1;

            // Iterate through the array to find the position of the key element
            while (j >= 0 && arr[j].compareTo(key) > 0) {
                arr[j + 1] = arr[j];
                j--;
            }

            // Insert the key element at its correct position
            arr[j + 1] = key;
        }
    }

    // Main method to read input and call the sort method
    public static void main(String[] args) {
        // Initialize a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array from the standard input
        int n = scanner.nextInt();

        // Create an array of integers with the given size
        Integer[] array = new Integer[n];

        // Read each element of the array from the standard input
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        // Create a Main object and call the sort method to sort the array
        Main flashSort = new Main();
        flashSort.sort(array);

        // Print the sorted array to the standard output
        for (int num : array) {
            System.out.print(num + " ");
        }

        // Close the Scanner object
        scanner.close();
    }
}
