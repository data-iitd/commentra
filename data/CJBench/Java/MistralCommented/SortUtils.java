
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

final class Main {
    private Main() {
    }

    // Initializes a Scanner object to read input from the standard input stream
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reads the number of elements in the array from the standard input
        int n = scanner.nextInt();

        // Creates an Integer array with the given size
        Integer[] array = new Integer[n];

        // Reads the elements of the array from the standard input and stores them in the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        // Reads the indices i and j of the two elements to be swapped from the standard input
        int i = scanner.nextInt();
        int j = scanner.nextInt();

        // Swaps the elements at the given indices in the array
        swap(array, i, j);

        // Prints the swapped array
        print(array);

        // Checks if the array is sorted in ascending order
        boolean sorted = isSorted(array);

        // Prints whether the array is sorted or not
        System.out.println(sorted);

        // Reads the left and right indices of the subarray to be flipped from the standard input
        int left = scanner.nextInt();
        int right = scanner.nextInt();

        // Flips the subarray from left to right in the array
        flip(array, left, right);

        // Prints the flipped array
        print(array);

        // Closes the Scanner object
        scanner.close();
    }

    // Swaps the elements at the given indices in the array
    public static <T> void swap(T[] array, int i, int j) {
        if (i != j) {
            // Temporary variable to store the element at index i
            final T temp = array[i];

            // Assigns the element at index j to index i
            array[i] = array[j];

            // Assigns the element stored in the temporary variable to index j
            array[j] = temp;
        }
    }

    // Helper method to check if the first element is less than the second element
    public static <T extends Comparable<T>> boolean less(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) < 0;
    }

    // Helper method to check if the first element is greater than the second element
    public static <T extends Comparable<T>> boolean greater(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) > 0;
    }

    // Helper method to check if the first element is greater than or equal to the second element
    static <T extends Comparable<T>> boolean greaterOrEqual(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) >= 0;
    }

    // Prints the given list to the standard output, separated by a space
    static void print(List<?> listToPrint) {
        String result = listToPrint.stream().map(Object::toString).collect(Collectors.joining(" "));
        System.out.println(result);
    }

    // Prints the given array to the standard output, enclosed in square brackets and separated by commas
    static <T> void print(T[] array) {
        System.out.println(Arrays.toString(array));
    }

    // Flips the subarray from left to right in the given array
    static <T> void flip(T[] array, int left, int right) {
        while (left <= right) {
            // Swaps the elements at the given indices
            swap(array, left++, right--);
        }
    }

    // Checks if the given array is sorted in ascending order
    public static <T extends Comparable<T>> boolean isSorted(T[] array) {
        for (int i = 1; i < array.length; i++) {
            // Checks if the current element is less than the previous one
            if (less(array[i], array[i - 1])) {
                return false;
            }
        }
        return true;
    }

    // Checks if the given list is sorted in ascending order
    public static <T extends Comparable<T>> boolean isSorted(List<T> list) {
        for (int i = 1; i < list.size(); i++) {
            // Checks if the current element is less than the previous one
            if (less(list.get(i), list.get(i - 1))) {
                return false;
            }
        }
        return true;
    }
}