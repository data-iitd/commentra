
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read the size of the array from the user
        int n = scanner.nextInt();

        // Create an Integer array of the given size
        Integer[] array = new Integer[n];

        // Read the elements of the array from the user
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        // Create an instance of the Main class and call its sort method to sort the array
        Main sorter = new Main();
        array = sorter.sort(array);

        // Print the sorted elements of the array to the console
        for (int num : array) {
            System.out.print(num + " ");
        }

        // Close the Scanner object to free up system resources
        scanner.close();
    }

    // The sort method sorts the given array using the bubble sort algorithm
    public <T extends Comparable<T>> T[] sort(final T[] array) {
        final int length = array.length; // Get the length of the array

        // The outer loop runs through each cycle of the bubble sort algorithm
        for (int cycleStart = 0; cycleStart <= length - 2; cycleStart++) {
            T item = array[cycleStart]; // Get the item to be placed at its correct position
            int pos = findPosition(array, cycleStart, item); // Find the position where the item should be placed

            // If the item is already at its correct position, skip to the next cycle
            if (pos == cycleStart) {
                continue;
            }

            // Swap the item with the element at its correct position
            item = placeItem(array, item, pos);

            // Repeat the process for the next item in the array
            while (pos != cycleStart) {
                pos = findPosition(array, cycleStart, item);
                item = placeItem(array, item, pos);
            }
        }

        // Return the sorted array
        return array;
    }

    // The findPosition method finds the position where the given item should be placed in the array
    private <T extends Comparable<T>> int findPosition(final T[] array, final int cycleStart, final T item) {
        int pos = cycleStart; // Initialize the position variable

        // Iterate through the array starting from the position after the current cycle start
        for (int i = cycleStart + 1; i < array.length; i++) {
            // If the current element is less than the item, increment the position variable
            if (array[i].compareTo(item) < 0) {
                pos++;
            }
        }

        // Return the position where the item should be placed
        return pos;
    }

    // The placeItem method swaps the item with the element at its correct position in the array
    private <T extends Comparable<T>> T placeItem(final T[] array, final T item, int pos) {
        // Swap the item with the element at its correct position
        T temp = array[pos];
        array[pos] = item;
        return temp;
    }

    // The replace method swaps the elements at the given positions in the array
    private <T extends Comparable<T>> T replace(final T[] array, final int pos, final T item) {
        // Swap the elements at the given positions
        T temp = array[pos];
        array[pos] = item;
        return temp;
    }
}