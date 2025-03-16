import java.util.*;

// This class provides a method to select the n-th smallest element from a list of comparable elements.
public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class.
    }

    // Method to select the n-th smallest element from a list of comparable elements.
    public static <T extends Comparable<T>> T select(List<T> list, int n) {
        Objects.requireNonNull(list, "The list of elements must not be null."); // Check if the list is null.
        if (list.isEmpty()) { // Check if the list is empty.
            throw new IllegalArgumentException("The list of elements must not be empty.");
        }
        if (n < 0 || n >= list.size()) { // Check if the index is within the bounds of the list.
            throw new IndexOutOfBoundsException("The index must be between 0 and the size of the list - 1.");
        }
        // Find the index of the n-th smallest element using the selectIndex method.
        int index = selectIndex(list, n);
        // Return the n-th smallest element.
        return list.get(index);
    }

    // Recursive helper method to find the index of the n-th smallest element.
    private static <T extends Comparable<T>> int selectIndex(List<T> list, int n) {
        return selectIndex(list, 0, list.size() - 1, n);
    }

    // Recursive helper method to find the index of the n-th smallest element using partitioning.
    private static <T extends Comparable<T>> int selectIndex(List<T> list, int left, int right, int n) {
        while (true) {
            int pivotIndex = pivot(list, left, right); // Find the pivot index.
            int pivotIndexPartitioned = partition(list, left, right, pivotIndex, n); // Partition the list around the pivot.
            if (n == pivotIndexPartitioned) { // If n is the pivot index, return it.
                return n;
            } else if (n < pivotIndexPartitioned) { // If n is to the left of the pivot index, search in the left subarray.
                right = pivotIndexPartitioned - 1;
            } else { // If n is to the right of the pivot index, search in the right subarray.
                left = pivotIndexPartitioned + 1;
            }
        }
    }

    // Helper method to partition the list around a randomly chosen pivot.
    private static <T extends Comparable<T>> int partition(List<T> list, int left, int right, int pivotIndex, int n) {
        T pivotValue = list.get(pivotIndex); // Get the value of the pivot element.
        Collections.swap(list, pivotIndex, right); // Swap the pivot element with the last element.
        int storeIndex = left; // Initialize the index of the first element in the sorted subarray.
        for (int i = left; i < right; i++) { // Iterate through the elements in the subarray.
            if (list.get(i).compareTo(pivotValue) < 0) { // If the element is smaller than the pivot, swap it with the first element in the sorted subarray and increment the index.
                Collections.swap(list, storeIndex, i);
                storeIndex++;
            }
        }
        int storeIndexEq = storeIndex; // Initialize the index of the first equal element in the sorted subarray.
        for (int i = storeIndex; i < right; i++) { // Iterate through the equal elements in the subarray.
            if (list.get(i).compareTo(pivotValue) == 0) { // If the element is equal to the pivot, swap it with the last equal element in the sorted subarray and increment the index.
                Collections.swap(list, storeIndexEq, i);
                storeIndexEq++;
            }
        }
        Collections.swap(list, right, storeIndexEq); // Swap the last equal element with the last element in the subarray.
        return (n < storeIndex) ? storeIndex : Math.min(n, storeIndexEq); // Return the index of n in the sorted subarray.
    }

    // Helper method to find a good pivot index using the median of five elements.
    private static <T extends Comparable<T>> int pivot(List<T> list, int left, int right) {
        if (right - left < 5) { // If the subarray has fewer than five elements, use the simple partitioning method.
            return partition5(list, left, right);
        }
        for (int i = left; i < right; i += 5) { // Iterate through the subarray in steps of five elements.
            int subRight = Math.min(i + 4, right); // Determine the index of the last element in the current subarray of five elements.
            int median5 = partition5(list, i, subRight); // Find the median of the current subarray of five elements.
            Collections.swap(list, median5, left + (i - left) / 5); // Swap the median with the pivot position.
        }
        int mid = left + (right - left) / 10 + 1; // Determine the middle index of the subarray.
        int rightIndex = left + (right - left) / 5; // Determine the index of the fifth element from the left in the subarray.
        return selectIndex(list, left, rightIndex, mid); // Find the index of the pivot using the selectIndex method.
    }

    // Helper method to partition the list around a simple pivot (the middle element).
    private static <T extends Comparable<T>> int partition5(List<T> list, int left, int right) {
        List<T> sublist = list.subList(left, right + 1); // Create a sublist of the current subarray.
        sublist.sort(Comparator.naturalOrder()); // Sort the sublist.
        return left + (right - left) / 2; // Return the index of the middle element in the sorted sublist.
    }

    // Main method to read input and test the select method.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input.
        int n = scanner.nextInt(); // Read the number of elements in the list.
        List<Integer> list = new ArrayList<>(); // Create an empty list to store the elements.
        for (int i = 0; i < n; i++) { // Iterate through the input and add each element to the list.
            list.add(scanner.nextInt());
        }
        int index = scanner.nextInt(); // Read the index of the desired element.
        try { // Begin a try block to handle exceptions.
            int result = select(list, index); // Call the select method to find the desired element.
            System.out.println("The " + index + "-th smallest element is: " + result); // Print the result if successful.
        } catch (Exception e) { // Catch any exceptions thrown by the select method.
            System.out.println(e.getMessage()); // Print the error message if an exception occurs.
        }
        scanner.close(); // Close the Scanner object.
    }
}
