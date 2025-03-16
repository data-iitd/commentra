import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Main function to execute the logic
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of elements
        int n = getInt(scanner);
        // Read the integer array from input
        int[] ls = getIntArray(scanner, n);
        // Create a reversed copy of the original array
        int[] lsRev = Arrays.copyOf(ls, n);
        // Sort the original array in ascending order
        Arrays.sort(ls);
        // Sort the reversed array in descending order
        Arrays.sort(lsRev);
        reverseArray(lsRev);

        // Initialize the answer variable
        long ans = 0;
        // Iterate through all pairs of elements in the sorted array
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Determine the minimum and maximum of the two selected elements
                int p = Math.min(ls[i], ls[j]);
                int q = Math.max(ls[i], ls[j]);
                // Calculate the differences and sums needed for searching
                int x = q - p;
                int y = q + p;

                // Find the left boundary for elements greater than x
                int l = binarySearch(ls, x);
                // Find the right boundary for elements less than y
                int r = n - binarySearch(lsRev, y, true);

                // Calculate the number of valid elements in the range
                long sum = r - l;
                // Adjust the count if the current indices are within the range
                if (i >= l && i <= r) {
                    sum--;
                }
                if (j >= l && j <= r) {
                    sum--;
                }
                // Ensure the sum is non-negative
                sum = Math.max(0, sum);
                // Accumulate the result
                ans += sum;
            }
        }

        // Divide the final answer by 3 as per the problem requirements
        ans /= 3;
        // Output the result
        System.out.println(ans);
    }

    // Method to read an integer from input
    private static int getInt(Scanner scanner) {
        return scanner.nextInt();
    }

    // Method to read an array of integers from input
    private static int[] getIntArray(Scanner scanner, int n) {
        int[] is = new int[n];
        for (int i = 0; i < n; i++) {
            is[i] = getInt(scanner);
        }
        return is;
    }

    // Method to reverse an array
    private static void reverseArray(int[] array) {
        int left = 0, right = array.length - 1;
        while (left < right) {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }

    // Binary search method to find the left boundary
    private static int binarySearch(int[] array, int key) {
        int low = 0, high = array.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (array[mid] > key) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    // Binary search method to find the right boundary
    private static int binarySearch(int[] array, int key, boolean lessThan) {
        int low = 0, high = array.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (array[mid] < key) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}
// <END-OF-CODE>
