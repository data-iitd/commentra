import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements in the array
        Integer[] array = new Integer[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt(); // Read the elements of the array
        }
        Main sorter = new Main();
        sorter.sort(array); // Sort the array using the sort method
        for (int num : array) {
            System.out.print(num + " "); // Print the sorted array
        }
        scanner.close(); // Close the Scanner to free up resources
    }

    // Generic sort method using cycle sort algorithm
    public <T extends Comparable<T>> T[] sort(final T[] array) {
        final int length = array.length;
        for (int cycleStart = 0; cycleStart <= length - 2; cycleStart++) {
            T item = array[cycleStart];
            int pos = findPosition(array, cycleStart, item); // Find the correct position for the item
            if (pos == cycleStart) {
                continue; // If the item is already in place, move to the next item
            }
            item = placeItem(array, item, pos); // Place the item at its correct position
            while (pos != cycleStart) {
                pos = findPosition(array, cycleStart, item); // Recalculate the position if necessary
                item = placeItem(array, item, pos); // Place the item at its correct position
            }
        }
        return array;
    }

    // Method to find the correct position for the item in the sorted array
    private <T extends Comparable<T>> int findPosition(final T[] array, final int cycleStart, final T item) {
        int pos = cycleStart;
        for (int i = cycleStart + 1; i < array.length; i++) {
            if (array[i].compareTo(item) < 0) {
                pos++;
            }
        }
        return pos;
    }

    // Method to place the item at its correct position by shifting elements if necessary
    private <T extends Comparable<T>> T placeItem(final T[] array, final T item, int pos) {
        while (item.compareTo(array[pos]) == 0) {
            pos++;
        }
        return replace(array, pos, item); // Replace the item at the correct position
    }

    // Method to replace an item in the array with another item and return the replaced item
    private <T extends Comparable<T>> T replace(final T[] array, final int pos, final T item) {
        final T replacedItem = array[pos];
        array[pos] = item;
        return replacedItem;
    }
}
