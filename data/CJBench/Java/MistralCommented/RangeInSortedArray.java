
import java.util.Scanner;

// Class definition for Main
public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    // Method to find the indices of the first and last occurrences of a given key in a sorted array
    public static int[] sortedRange(int[] nums, int key) {
        int[] range = new int[] {-1, -1}; // Initialize an array to store the indices of the first and last occurrences of the key

        // Binary search algorithm to find the indices
        alteredBinSearchIter(nums, key, 0, nums.length - 1, range, true);
        alteredBinSearchIter(nums, key, 0, nums.length - 1, range, false);

        // Return the indices array
        return range;
    }

    // Iterative implementation of binary search algorithm
    public static void alteredBinSearchIter(int[] nums, int key, int left, int right, int[] range, boolean goLeft) {
        // Continue searching while the left index is less than or equal to the right index
        while (left <= right) {
            final int mid = (left + right) >>> 1; // Calculate the middle index

            // Check if the middle element is greater than the key
            if (nums[mid] > key) {
                // If so, update the right index to search in the left half of the array
                right = mid - 1;
            }
            // Check if the middle element is less than the key
            else if (nums[mid] < key) {
                // If so, update the left index to search in the right half of the array
                left = mid + 1;
            }
            // If the middle element is equal to the key
            else {
                // If we're searching for the leftmost occurrence, update the range indices and return
                if (goLeft) {
                    if (mid == 0 || nums[mid - 1] != key) {
                        range[0] = mid;
                        return;
                    } else {
                        // If the previous element is also the key, update the right index to search in the left half
                        right = mid - 1;
                    }
                }
                // If we're searching for the rightmost occurrence, update the range indices and return
                else {
                    if (mid == nums.length - 1 || nums[mid + 1] != key) {
                        range[1] = mid;
                        return;
                    } else {
                        // If the next element is also the key, update the left index to search in the right half
                        left = mid + 1;
                    }
                }
            }
        }
    }

    // Main method to read input and call the sortedRange method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the console

        // Read the number of elements in the array and initialize the array
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt(); // Read each element of the array
        }

        // Read the key and call the sortedRange method to find the indices of the first and last occurrences
        int key = scanner.nextInt();
        int[] range = sortedRange(nums, key);

        // Print the indices of the first and last occurrences
        System.out.println(range[0] + " " + range[1]);

        // Close the Scanner object
        scanner.close();
    }
}