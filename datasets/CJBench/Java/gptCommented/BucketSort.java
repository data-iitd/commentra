import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Constant to determine the divisor for bucket calculation
    private static final int BUCKET_DIVISOR = 10;

    // Main sorting method that sorts an array using bucket sort
    public <T extends Comparable<T>> T[] sort(T[] array) {
        // Return the original array if it is empty
        if (array.length == 0) {
            return array;
        }
        
        // Find the minimum and maximum elements in the array
        T min = findMin(array);
        T max = findMax(array);
        
        // Calculate the number of buckets needed for sorting
        int numberOfBuckets = calculateNumberOfBuckets(array.length);
        
        // Initialize the buckets as a list of lists
        List<List<T>> buckets = initializeBuckets(numberOfBuckets);
        
        // Distribute the elements of the array into the appropriate buckets
        distributeElementsIntoBuckets(array, buckets, min, max, numberOfBuckets);
        
        // Concatenate the sorted elements from the buckets back into the original array
        return concatenateBuckets(buckets, array);
    }

    // Calculate the number of buckets based on the length of the array
    private int calculateNumberOfBuckets(final int arrayLength) {
        return Math.max(arrayLength / BUCKET_DIVISOR, 1);
    }

    // Initialize the buckets as empty lists
    private <T extends Comparable<T>> List<List<T>> initializeBuckets(int numberOfBuckets) {
        List<List<T>> buckets = new ArrayList<>(numberOfBuckets);
        for (int i = 0; i < numberOfBuckets; i++) {
            buckets.add(new ArrayList<>());
        }
        return buckets;
    }

    // Distribute each element of the array into the corresponding bucket
    private <T extends Comparable<T>> void distributeElementsIntoBuckets(T[] array, List<List<T>> buckets, final T min, final T max, final int numberOfBuckets) {
        for (final T element : array) {
            // Determine the bucket index for the current element
            int bucketIndex = hash(element, min, max, numberOfBuckets);
            // Add the element to the appropriate bucket
            buckets.get(bucketIndex).add(element);
        }
    }

    // Concatenate the sorted elements from all buckets back into the original array
    private <T extends Comparable<T>> T[] concatenateBuckets(Iterable<List<T>> buckets, T[] array) {
        int index = 0;
        for (List<T> bucket : buckets) {
            // Sort each bucket before concatenation
            Collections.sort(bucket);
            for (T element : bucket) {
                array[index++] = element; // Place the sorted elements back into the array
            }
        }
        return array;
    }

    // Calculate the bucket index for a given element
    private <T extends Comparable<T>> int hash(final T element, final T min, final T max, final int numberOfBuckets) {
        double range = max.compareTo(min); // Calculate the range of values
        double normalizedValue = element.compareTo(min) / range; // Normalize the value to a range of 0 to 1
        return (int) (normalizedValue * (numberOfBuckets - 1)); // Scale to the number of buckets
    }

    // Find the minimum element in the array
    private <T extends Comparable<T>> T findMin(T[] array) {
        T min = array[0]; // Assume the first element is the minimum
        for (T element : array) {
            if (element.compareTo(min) < 0) {
                min = element; // Update min if a smaller element is found
            }
        }
        return min;
    }

    // Find the maximum element in the array
    private <T extends Comparable<T>> T findMax(T[] array) {
        T max = array[0]; // Assume the first element is the maximum
        for (T element : array) {
            if (element.compareTo(max) > 0) {
                max = element; // Update max if a larger element is found
            }
        }
        return max;
    }

    // Main method to execute the sorting process
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        Double[] array = new Double[n]; // Create an array to hold the elements
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextDouble(); // Read each element into the array
        }
        Main sorter = new Main(); // Create an instance of the Main class
        Double[] sortedArray = sorter.sort(array); // Sort the array
        for (double num : sortedArray) {
            System.out.print(num + " "); // Print the sorted array
        }
        scanner.close(); // Close the scanner to prevent resource leaks
    }
}
