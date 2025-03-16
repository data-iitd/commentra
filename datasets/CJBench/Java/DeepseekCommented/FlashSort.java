import java.util.Scanner;
import java.util.Arrays;
public class Main {
    private double classificationRatio = 0.45; // Initialize classification ratio
    public Main() {} // Default constructor
    public Main(double classificationRatio) {
        if (classificationRatio <= 0 || classificationRatio >= 1) {
            throw new IllegalArgumentException("Classification ratio must be between 0 and 1 (exclusive).");
        }
        this.classificationRatio = classificationRatio; // Set the classification ratio
    }
    public void setClassificationRatio(double classificationRatio) {
        if (classificationRatio <= 0 || classificationRatio >= 1) {
            throw new IllegalArgumentException("Classification ratio must be between 0 and 1 (exclusive).");
        }
        this.classificationRatio = classificationRatio; // Set the classification ratio
    }
    public <T extends Comparable<T>> T[] sort(T[] array) {
        flashSort(array); // Call flashSort to sort the array
        return array; // Return the sorted array
    }
    private <T extends Comparable<? super T>> void flashSort(T[] arr) {
        if (arr.length == 0) {
            return; // Return if the array is empty
        }
        T min = findMin(arr); // Find the minimum element in the array
        int maxIndex = findMaxIndex(arr); // Find the index of the maximum element
        if (arr[maxIndex].compareTo(min) == 0) {
            return; // Return if the array is already sorted
        }
        int m = (int) (classificationRatio * arr.length); // Calculate the number of classes
        int[] classificationArray = new int[m]; // Create a classification array
        double c1 = (double) (m - 1) / arr[maxIndex].compareTo(min); // Calculate the classification constant
        classify(arr, classificationArray, c1, min); // Classify the elements
        transform(classificationArray); // Transform the classification array
        permute(arr, classificationArray, c1, min, arr.length, m); // Permute the elements
        insertionSort(arr); // Sort the array using insertion sort
    }
    private <T extends Comparable<? super T>> T findMin(T[] arr) {
        T min = arr[0]; // Initialize min with the first element
        for (T t : arr) { // Iterate through the array
            if (t.compareTo(min) < 0) { // Compare each element with the current min
                min = t; // Update min if a smaller element is found
            }
        }
        return min; // Return the minimum element
    }
    private <T extends Comparable<? super T>> int findMaxIndex(T[] arr) {
        int maxIndex = 0; // Initialize maxIndex with the first index
        for (int i = 1; i < arr.length; i++) { // Iterate through the array
            if (arr[i].compareTo(arr[maxIndex]) > 0) { // Compare each element with the current max
                maxIndex = i; // Update maxIndex if a larger element is found
            }
        }
        return maxIndex; // Return the index of the maximum element
    }
    private <T extends Comparable<? super T>> void classify(T[] arr, int[] classificationArray, double c1, T min) {
        for (T t : arr) { // Iterate through the array
            int k = (int) (c1 * t.compareTo(min)); // Classify the element
            classificationArray[k]++; // Increment the count for the class
        }
    }
    private void transform(int[] classificationArray) {
        for (int i = 1; i < classificationArray.length; i++) { // Iterate through the classification array
            classificationArray[i] += classificationArray[i - 1]; // Update the classification array
        }
    }
    private <T extends Comparable<? super T>> void permute(T[] arr, int[] classificationArray, double c1, T min, int n, int m) {
        int move = 0; // Initialize move counter
        int j = 0; // Initialize j
        int k = m - 1; // Initialize k
        T flash; // Declare a variable for flash
        while (move < n - 1) { // While there are elements to move
            while (j > classificationArray[k] - 1) { // While j is beyond the current class
                j++; // Increment j
                k = (int) (c1 * arr[j].compareTo(min)); // Recalculate k
            }
            flash = arr[j]; // Set flash to the current element
            while (j != classificationArray[k]) { // While j is not in the correct position
                k = (int) (c1 * flash.compareTo(min)); // Recalculate k
                T temp = arr[classificationArray[k] - 1]; // Swap elements
                arr[classificationArray[k] - 1] = flash;
                flash = temp;
                classificationArray[k]--; // Decrement the count for the class
                move++; // Increment the move counter
            }
        }
    }
    private <T extends Comparable<? super T>> void insertionSort(T[] arr) {
        for (int i = 1; i < arr.length; i++) { // Iterate through the array
            T key = arr[i]; // Set key to the current element
            int j = i - 1; // Initialize j
            while (j >= 0 && arr[j].compareTo(key) > 0) { // Compare elements
                arr[j + 1] = arr[j]; // Swap elements
                j--; // Decrement j
            }
            arr[j + 1] = key; // Insert the key in the correct position
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the size of the array
        Integer[] array = new Integer[n];
        for (int i = 0; i < n; i++) { // Read the elements of the array
            array[i] = scanner.nextInt();
        }
        Main flashSort = new Main(); // Create an instance of Main
        flashSort.sort(array); // Sort the array
        for (int num : array) { // Print the sorted array
            System.out.print(num + " ");
        }
        scanner.close(); // Close the scanner
    }
}
