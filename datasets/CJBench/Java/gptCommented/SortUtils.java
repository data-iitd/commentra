import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

final class Main {
    // Private constructor to prevent instantiation of the Main class
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the size of the array
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];
        
        // Populate the array with user input
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        
        // Read the indices to swap in the array
        int i = scanner.nextInt();
        int j = scanner.nextInt();
        
        // Swap the elements at the specified indices
        swap(array, i, j);
        
        // Print the array after the swap operation
        print(array);
        
        // Check if the array is sorted and print the result
        boolean sorted = isSorted(array);
        System.out.println(sorted);
        
        // Read the indices for the flip operation
        int left = scanner.nextInt();
        int right = scanner.nextInt();
        
        // Flip the elements in the array between the specified indices
        flip(array, left, right);
        
        // Print the array after the flip operation
        print(array);
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    // Method to swap two elements in an array
    public static <T> void swap(T[] array, int i, int j) {
        if (i != j) {
            final T temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    // Method to compare if the first element is less than the second
    public static <T extends Comparable<T>> boolean less(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) < 0;
    }

    // Method to compare if the first element is greater than the second
    public static <T extends Comparable<T>> boolean greater(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) > 0;
    }

    // Method to compare if the first element is greater than or equal to the second
    static <T extends Comparable<T>> boolean greaterOrEqual(T firstElement, T secondElement) {
        return firstElement.compareTo(secondElement) >= 0;
    }

    // Method to print a list of elements
    static void print(List<?> listToPrint) {
        String result = listToPrint.stream().map(Object::toString).collect(Collectors.joining(" "));
        System.out.println(result);
    }

    // Method to print an array of elements
    static <T> void print(T[] array) {
        System.out.println(Arrays.toString(array));
    }

    // Method to flip elements in an array between two indices
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

    // Overloaded method to check if a list is sorted
    public static <T extends Comparable<T>> boolean isSorted(List<T> list) {
        for (int i = 1; i < list.size(); i++) {
            if (less(list.get(i), list.get(i - 1))) {
                return false;
            }
        }
        return true;
    }
}
