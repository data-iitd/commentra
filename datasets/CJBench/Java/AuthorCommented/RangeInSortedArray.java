
import java.util.Scanner;

public final class RangeInSortedArray {
    private RangeInSortedArray() {
    }

    /**
     * Get the 1st and last occurrence index of a number 'key' in a non-decreasing array 'nums'.
     * Gives [-1, -1] in case element doesn't exist in the array.
     */
    public static int[] sortedRange(int[] nums, int key) {
        int[] range = new int[] {-1, -1};
        alteredBinSearchIter(nums, key, 0, nums.length - 1, range, true);
        alteredBinSearchIter(nums, key, 0, nums.length - 1, range, false);
        return range;
    }

    /**
     * Iterative altered binary search which searches for leftmost as well as rightmost occurrence of 'key'.
     */
    public static void alteredBinSearchIter(int[] nums, int key, int left, int right, int[] range, boolean goLeft) {
        while (left <= right) {
            final int mid = (left + right) >>> 1;
            if (nums[mid] > key) {
                right = mid - 1;
            } else if (nums[mid] < key) {
                left = mid + 1;
            } else {
                if (goLeft) {
                    if (mid == 0 || nums[mid - 1] != key) {
                        range[0] = mid;
                        return;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    if (mid == nums.length - 1 || nums[mid + 1] != key) {
                        range[1] = mid;
                        return;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }
    }

    /**
     * Main method to take input and output the result.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the size of the array
        int n = scanner.nextInt();
        int[] nums = new int[n];

        // Input the elements of the array
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        // Input the key to search
        int key = scanner.nextInt();

        // Get the range and print the result
        int[] range = sortedRange(nums, key);
        System.out.println(range[0] + " " + range[1]);

        scanner.close();
    }
}
