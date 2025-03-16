import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Method to find the starting and ending positions of a given key in a sorted array
    public static int[] sortedRange(int[] nums, int key) {
        // Initialize the range array to hold the starting and ending indices
        int[] range = new int[] {-1, -1};
        
        // Perform binary search to find the leftmost index of the key
        alteredBinSearchIter(nums, key, 0, nums.length - 1, range, true);
        
        // Perform binary search to find the rightmost index of the key
        alteredBinSearchIter(nums, key, 0, nums.length - 1, range, false);
        
        // Return the range of indices found
        return range;
    }

    // Method to perform an altered binary search iteratively
    public static void alteredBinSearchIter(int[] nums, int key, int left, int right, int[] range, boolean goLeft) {
        // Continue searching while the left index is less than or equal to the right index
        while (left <= right) {
            // Calculate the middle index
            final int mid = (left + right) >>> 1;
            
            // If the middle element is greater than the key, search in the left half
            if (nums[mid] > key) {
                right = mid - 1;
            } 
            // If the middle element is less than the key, search in the right half
            else if (nums[mid] < key) {
                left = mid + 1;
            } 
            // If the middle element is equal to the key
            else {
                // If searching for the leftmost index
                if (goLeft) {
                    // Check if it's the first occurrence of the key
                    if (mid == 0 || nums[mid - 1] != key) {
                        range[0] = mid; // Set the starting index
                        return; // Exit the method
                    } else {
                        right = mid - 1; // Continue searching in the left half
                    }
                } 
                // If searching for the rightmost index
                else {
                    // Check if it's the last occurrence of the key
                    if (mid == nums.length - 1 || nums[mid + 1] != key) {
                        range[1] = mid; // Set the ending index
                        return; // Exit the method
                    } else {
                        left = mid + 1; // Continue searching in the right half
                    }
                }
            }
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements in the array
        int n = scanner.nextInt();
        
        // Initialize the array to hold the numbers
        int[] nums = new int[n];
        
        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        
        // Read the key to search for
        int key = scanner.nextInt();
        
        // Get the range of indices for the key
        int[] range = sortedRange(nums, key);
        
        // Print the starting and ending indices of the key
        System.out.println(range[0] + " " + range[1]);
        
        // Close the scanner to free resources
        scanner.close();
    }
}
