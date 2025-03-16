
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
final class Main {
    private Main() {
    }
    public static void main(String[] args) {
        // Initialize Scanner to read input
        Scanner scanner = new Scanner(System.in);
        // Read the number of elements
        int n = scanner.nextInt();
        // Create an array to hold the integers
        Integer[] array = new Integer[n];
        // Read the integers into the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        // Read the indices for swapping
        int i = scanner.nextInt();
        int j = scanner.nextInt();
        // Swap the elements at indices i and j
        swap(array, i, j);
        // Print the array before and after swapping
        print(array);
        // Check if the array is sorted and print the result
        boolean sorted = isSorted(array);
        System.out.println(sorted);
        // Read the indices for flipping
        int left = scanner.nextInt();
        int right = scanner.nextInt();
        // Flip the subarray between the given indices
        flip(array, left, right);
        // Print the array after flipping
        print(array);
        // Close the Scanner
        scanner.close();
    }
    // Generic method to swap elements in an array
    public static <T> void swap(T[] array, int i, int j) {
        if (i != j) {
            final T temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    // Generic method to check if the first element is less than the second
    public static <T extends Comparable<T>> boolean less(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) < 0;
    }
    // Generic method to check if the first element is greater than the second
    public static <T extends Comparable<T>> boolean greater(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) > 0;
    }
    // Generic method to check if the first element is greater than or equal to the second
    static <T extends Comparable<T>> boolean greaterOrEqual(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) >= 0;
    }
    // Method to print elements of a list
    static void print(List<?> listToPrint) {
        String result = listToPrint.stream().map(Object::toString).collect(Collectors.joining(" "));
        System.out.println(result);
    }
    // Method to print elements of an array
    static <T> void print(T[] array) {
        System.out.println(Arrays.toString(array));
    }
    // Method to flip a subarray in the array
    public static <T extends Comparable<T>> void flip(T[] array, int left, int right) {
        while (left <= right) {
            swap(array, left++, right--);
        }
    }
    // Method to check if an array is sorted
    public static <T extends Comparable<T>> boolean isSorted(T[] array) {
        for (int i = 1; i < array.length; i++) {
            if (less(array[i], array[i - 1])) {
                return false;
            }
        }
        return true;
    }
    // Method to check if a list is sorted
    public static <T extends Comparable<T>> boolean isSorted(List<T> list) {
        for (int i = 1; i < list.size(); i++) {
            if (less(list.get(i), list.get(i - 1))) {
                return false;
            }
        }
        return true;
    }
}

This code provides a comprehensive set of functionalities including reading input, swapping elements, printing arrays, checking sorted status, flipping subarrays, and closing the scanner. Each block of code is well-commented to enhance understanding and maintainability.