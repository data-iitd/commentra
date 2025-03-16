import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements to be sorted
        int n = scanner.nextInt();
        
        // Initialize an array to hold the integers
        Integer[] array = new Integer[n];
        
        // Read the integers from user input and store them in the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        
        // Create an instance of Main to access the sort method
        Main sorter = new Main();
        
        // Sort the array using the sort method
        sorter.sort(array);
        
        // Print the sorted array
        for (int num : array) {
            System.out.print(num + " ");
        }
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    // Generic method to sort an array of comparable items
    public <T extends Comparable<T>> T[] sort(final T[] array) {
        final int length = array.length;
        
        // Iterate through each element in the array
        for (int cycleStart = 0; cycleStart <= length - 2; cycleStart++) {
            // Store the current item to be placed
            T item = array[cycleStart];
            
            // Find the position where the current item should be placed
            int pos = findPosition(array, cycleStart, item);
            
            // If the item is already in the correct position, continue to the next item
            if (pos == cycleStart) {
                continue; 
            }
            
            // Place the item at the found position
            item = placeItem(array, item, pos);
            
            // Continue placing the item until it is in the correct position
            while (pos != cycleStart) {
                pos = findPosition(array, cycleStart, item);
                item = placeItem(array, item, pos);
            }
        }
        return array; // Return the sorted array
    }

    // Method to find the position for the current item in the sorted part of the array
    private <T extends Comparable<T>> int findPosition(final T[] array, final int cycleStart, final T item) {
        int pos = cycleStart;
        
        // Compare the item with the elements in the array to determine its position
        for (int i = cycleStart + 1; i < array.length; i++) {
            if (array[i].compareTo(item) < 0) {
                pos++; // Increment position if the current element is less than the item
            }
        }
        return pos; // Return the calculated position
    }

    // Method to place the item in the array at the specified position
    private <T extends Comparable<T>> T placeItem(final T[] array, final T item, int pos) {
        // Move to the next position if the item is equal to the element at the current position
        while (item.compareTo(array[pos]) == 0) {
            pos++;
        }
        // Replace the element at the position with the item and return the replaced item
        return replace(array, pos, item);
    }

    // Method to replace an item in the array at a specified position
    private <T extends Comparable<T>> T replace(final T[] array, final int pos, final T item) {
        final T replacedItem = array[pos]; // Store the item being replaced
        array[pos] = item; // Replace the item in the array
        return replacedItem; // Return the replaced item
    }
}
