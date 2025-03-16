
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Constants
    private static final int BUCKET_DIVISOR = 10;

    // Method to sort an array of comparable elements
    public <T extends Comparable<T>> T[] sort(T[] array) {
        if (array.length == 0) { // Base case: empty array is already sorted
            return array;
        }

        T min = findMin(array); // Find the minimum element in the array
        T max = findMax(array); // Find the maximum element in the array
        int numberOfBuckets = calculateNumberOfBuckets(array.length); // Calculate the number of buckets needed

        // Initialize the buckets list with the specified number of empty lists
        List<List<T>> buckets = initializeBuckets(numberOfBuckets);

        // Distribute the elements into the buckets based on their hash values
        distributeElementsIntoBuckets(array, buckets, min, max, numberOfBuckets);

        // Concatenate the sorted buckets back into a single sorted array
        return concatenateBuckets(buckets, array);
    }

    // Helper method to calculate the number of buckets needed based on the array length
    private int calculateNumberOfBuckets(final int arrayLength) {
        return Math.max(arrayLength / BUCKET_DIVISOR, 1);
    }

    // Helper method to initialize the buckets list with the specified number of empty lists
    private <T extends Comparable<T>> List<List<T>> initializeBuckets(int numberOfBuckets) {
        List<List<T>> buckets = new ArrayList<>(numberOfBuckets); // Create an ArrayList of the specified size

        // Initialize each empty list in the ArrayList
        for (int i = 0; i < numberOfBuckets; i++) {
            buckets.add(new ArrayList<>());
        }

        return buckets;
    }

    // Helper method to distribute the elements into the buckets based on their hash values
    private <T extends Comparable<T>> void distributeElementsIntoBuckets(T[] array, List<List<T>> buckets, final T min, final T max, final int numberOfBuckets) {
        for (final T element : array) { // Iterate through each element in the array
            int bucketIndex = hash(element, min, max, numberOfBuckets); // Calculate the hash value for the element
            buckets.get(bucketIndex).add(element); // Add the element to the corresponding bucket
        }
    }

    // Helper method to concatenate the sorted buckets back into a single sorted array
    private <T extends Comparable<T>> T[] concatenateBuckets(Iterable<List<T>> buckets, T[] array) {
        int index = 0; // Initialize an index to keep track of the array position

        // Iterate through each sorted bucket and add its elements to the array
        for (List<T> bucket : buckets) {
            Collections.sort(bucket); // Sort the elements in the bucket
            for (T element : bucket) {
                array[index++] = element; // Add the element to the array
            }
        }

        return array;
    }

    // Helper method to calculate the hash value for an element based on the minimum, maximum, and number of buckets
    private <T extends Comparable<T>> int hash(final T element, final T min, final T max, final int numberOfBuckets) {
        double range = max.compareTo(min); // Calculate the range between the minimum and maximum elements
        double normalizedValue = element.compareTo(min) / range; // Calculate the normalized value of the element
        return (int) (normalizedValue * (numberOfBuckets - 1)); // Calculate the hash value as an index
    }

    // Helper methods to find the minimum and maximum elements in the array
    private <T extends Comparable<T>> T findMin(T[] array) {
        T min = array[0]; // Initialize the minimum element as the first element in the array
        for (T element : array) { // Iterate through the remaining elements in the array
            if (element.compareTo(min) < 0) { // If the current element is less than the minimum, update the minimum
                min = element;
            }
        }
        return min;
    }

    private <T extends Comparable<T>> T findMax(T[] array) {
        T max = array[0]; // Initialize the maximum element as the first element in the array
        for (T element : array) { // Iterate through the remaining elements in the array
            if (element.compareTo(max) > 0) { // If the current element is greater than the maximum, update the maximum
                max = element;
            }
        }
        return max;
    }

    // Main method to read input and call the sorting method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the console
        int n = scanner.nextInt(); // Read the number of elements in the array from the console
        Double[] array = new Double[n]; // Create a Double array of the specified size

        // Read the elements of the array from the console and store them in the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextDouble();
        }

        Main sorter = new Main(); // Create an instance of the Main class
        Double[] sortedArray = sorter.sort(array); // Call the sorting method to sort the array

        // Print the sorted elements to the console
        for (double num : sortedArray) {
            System.out.print(num + " ");
        }

        scanner.close(); // Close the Scanner object
    }
}

