import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
public class Main {
    private static final int BUCKET_DIVISOR = 10; // Constant divisor for calculating the number of buckets.
    public <T extends Comparable<T>> T[] sort(T[] array) {
        if (array.length == 0) {
            return array; // Return the array as is if it's empty.
        }
        T min = findMin(array); // Find the minimum element in the array.
        T max = findMax(array); // Find the maximum element in the array.
        int numberOfBuckets = calculateNumberOfBuckets(array.length); // Calculate the number of buckets.
        List<List<T>> buckets = initializeBuckets(numberOfBuckets); // Initialize the buckets.
        distributeElementsIntoBuckets(array, buckets, min, max, numberOfBuckets); // Distribute elements into buckets.
        return concatenateBuckets(buckets, array); // Concatenate sorted buckets back into the array.
    }
    private int calculateNumberOfBuckets(final int arrayLength) {
        return Math.max(arrayLength / BUCKET_DIVISOR, 1); // Calculate the number of buckets based on the array length.
    }
    private <T extends Comparable<T>> List<List<T>> initializeBuckets(int numberOfBuckets) {
        List<List<T>> buckets = new ArrayList<>(numberOfBuckets); // Create a list of empty lists for buckets.
        for (int i = 0; i < numberOfBuckets; i++) {
            buckets.add(new ArrayList<>()); // Initialize each bucket as an empty list.
        }
        return buckets;
    }
    private <T extends Comparable<T>> void distributeElementsIntoBuckets(T[] array, List<List<T>> buckets, final T min, final T max, final int numberOfBuckets) {
        for (final T element : array) {
            int bucketIndex = hash(element, min, max, numberOfBuckets); // Determine the bucket index for the element.
            buckets.get(bucketIndex).add(element); // Add the element to the appropriate bucket.
        }
    }
    private <T extends Comparable<T>> T[] concatenateBuckets(Iterable<List<T>> buckets, T[] array) {
        int index = 0;
        for (List<T> bucket : buckets) {
            Collections.sort(bucket); // Sort each bucket.
            for (T element : bucket) {
                array[index++] = element; // Add sorted elements back into the original array.
            }
        }
        return array;
    }
    private <T extends Comparable<T>> int hash(final T element, final T min, final T max, final int numberOfBuckets) {
        double range = max.compareTo(min); // Calculate the range between max and min.
        double normalizedValue = element.compareTo(min) / range; // Normalize the element's value.
        return (int) (normalizedValue * (numberOfBuckets - 1)); // Calculate the bucket index.
    }
    private <T extends Comparable<T>> T findMin(T[] array) {
        T min = array[0]; // Initialize min with the first element.
        for (T element : array) {
            if (element.compareTo(min) < 0) { // Update min if a smaller element is found.
                min = element;
            }
        }
        return min;
    }
    private <T extends Comparable<T>> T findMax(T[] array) {
        T max = array[0]; // Initialize max with the first element.
        for (T element : array) {
            if (element.compareTo(max) > 0) { // Update max if a larger element is found.
                max = element;
            }
        }
        return max;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements.
        Double[] array = new Double[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextDouble(); // Read the elements of the array.
        }
        Main sorter = new Main();
        Double[] sortedArray = sorter.sort(array); // Sort the array.
        for (double num : sortedArray) {
            System.out.print(num + " "); // Print the sorted array.
        }
        scanner.close(); // Close the scanner.
    }
}
