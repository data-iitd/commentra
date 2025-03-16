import java.util.*;

public final class Main {
    // Private constructor to prevent instantiation of the utility class
    private Main() {
    }

    // Method to select the n-th smallest element from the list
    public static <T extends Comparable<T>> T select(List<T> list, int n) {
        // Ensure the list is not null
        Objects.requireNonNull(list, "The list of elements must not be null.");
        
        // Check if the list is empty
        if (list.isEmpty()) {
            throw new IllegalArgumentException("The list of elements must not be empty.");
        }
        
        // Validate the index n
        if (n < 0 || n >= list.size()) {
            throw new IndexOutOfBoundsException("The index must be between 0 and the size of the list - 1.");
        }
        
        // Get the index of the n-th smallest element
        int index = selectIndex(list, n);
        return list.get(index); // Return the n-th smallest element
    }

    // Helper method to initiate the selection process
    private static <T extends Comparable<T>> int selectIndex(List<T> list, int n) {
        return selectIndex(list, 0, list.size() - 1, n);
    }

    // Recursive method to find the index of the n-th smallest element
    private static <T extends Comparable<T>> int selectIndex(List<T> list, int left, int right, int n) {
        while (true) {
            // If the left and right pointers converge, return the left index
            if (left == right) {
                return left;
            }
            
            // Choose a pivot index for partitioning
            int pivotIndex = pivot(list, left, right);
            // Partition the list around the pivot and get the new pivot index
            pivotIndex = partition(list, left, right, pivotIndex, n);
            
            // Check if the pivot index is the desired index
            if (n == pivotIndex) {
                return n; // Found the n-th smallest element
            } else if (n < pivotIndex) {
                right = pivotIndex - 1; // Search in the left part
            } else {
                left = pivotIndex + 1; // Search in the right part
            }
        }
    }

    // Method to partition the list around a pivot
    private static <T extends Comparable<T>> int partition(List<T> list, int left, int right, int pivotIndex, int n) {
        T pivotValue = list.get(pivotIndex); // Get the pivot value
        Collections.swap(list, pivotIndex, right); // Move pivot to the end
        int storeIndex = left; // Pointer for the next position to swap
        
        // Partition the list into elements less than the pivot
        for (int i = left; i < right; i++) {
            if (list.get(i).compareTo(pivotValue) < 0) {
                Collections.swap(list, storeIndex, i);
                storeIndex++;
            }
        }
        
        // Handle elements equal to the pivot
        int storeIndexEq = storeIndex;
        for (int i = storeIndex; i < right; i++) {
            if (list.get(i).compareTo(pivotValue) == 0) {
                Collections.swap(list, storeIndexEq, i);
                storeIndexEq++;
            }
        }
        
        // Move the pivot to its final place
        Collections.swap(list, right, storeIndexEq);
        // Return the appropriate index based on the n value
        return (n < storeIndex) ? storeIndex : Math.min(n, storeIndexEq);
    }

    // Method to select a pivot for partitioning
    private static <T extends Comparable<T>> int pivot(List<T> list, int left, int right) {
        // If the range is small, use a simple partitioning method
        if (right - left < 5) {
            return partition5(list, left, right);
        }
        
        // Group elements into sublists of 5 and find their medians
        for (int i = left; i < right; i += 5) {
            int subRight = Math.min(i + 4, right);
            int median5 = partition5(list, i, subRight);
            Collections.swap(list, median5, left + (i - left) / 5); // Move median to the front
        }
        
        // Recursively select the median of the medians
        int mid = left + (right - left) / 10 + 1;
        int rightIndex = left + (right - left) / 5;
        return selectIndex(list, left, rightIndex, mid);
    }

    // Method to partition a small sublist of 5 elements and return the median
    private static <T extends Comparable<T>> int partition5(List<T> list, int left, int right) {
        List<T> sublist = list.subList(left, right + 1); // Create a sublist
        sublist.sort(Comparator.naturalOrder()); // Sort the sublist
        return left + (right - left) / 2; // Return the median index
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        List<Integer> list = new ArrayList<>();
        
        // Read the elements into the list
        for (int i = 0; i < n; i++) {
            list.add(scanner.nextInt());
        }
        
        int index = scanner.nextInt(); // Read the index of the desired smallest element
        try {
            // Attempt to select the n-th smallest element
            int result = select(list, index);
            System.out.println("The " + index + "-th smallest element is: " + result);
        } catch (Exception e) {
            // Print any exceptions that occur
            System.out.println(e.getMessage());
        }
        
        scanner.close(); // Close the scanner resource
    }
}
