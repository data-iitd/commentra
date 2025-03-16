import java.util.Scanner; // Importing Scanner class for input

public final class Main {
    private Main() {
    } // Private constructor to prevent instantiation

    // Method to find the range of indices where the key is present in the sorted array
    public static int[] sortedRange(int[] nums, int key) {
        int[] range = new int[] {-1, -1}; // Initialize range with -1 values
        alteredBinSearchIter(nums, key, 0, nums.length - 1, range, true); // Search for the left boundary
        alteredBinSearchIter(nums, key, 0, nums.length - 1, range, false); // Search for the right boundary
        return range; // Return the range of indices
    }

    // Helper method to perform a binary search to find the boundaries of the key
    public static void alteredBinSearchIter(int[] nums, int key, int left, int right, int[] range, boolean goLeft) {
        while (left <= right) { // Continue until the search space is exhausted
            final int mid = (left + right) >>> 1; // Calculate the middle index
            if (nums[mid] > key) {
                right = mid - 1; // Adjust the right boundary
            } else if (nums[mid] < key) {
                left = mid + 1; // Adjust the left boundary
            } else {
                if (goLeft) {
                    if (mid == 0 || nums[mid - 1] != key) { // Check if we've found the left boundary
                        range[0] = mid; // Set the left boundary
                        return; // Exit the method
                    } else {
                        right = mid - 1; // Continue searching to the left
                    }
                } else {
                    if (mid == nums.length - 1 || nums[mid + 1] != key) { // Check if we've found the right boundary
                        range[1] = mid; // Set the right boundary
                        return; // Exit the method
                    } else {
                        left = mid + 1; // Continue searching to the right
                    }
                }
            }
        }
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        int n = scanner.nextInt(); // Read the number of elements
        int[] nums = new int[n]; // Create an array to store the elements
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt(); // Read the elements into the array
        }
        int key = scanner.nextInt(); // Read the key to search for
        int[] range = sortedRange(nums, key); // Find the range of the key
        System.out.println(range[0] + " " + range[1]); // Print the range
        scanner.close(); // Close the Scanner
    }
}
