import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Main function to initialize the program.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = getInt(scanner);
        int[] ls = getIntArray(scanner, n);
        int[] lsRev = Arrays.copyOf(ls, n);
        
        // Sort the original array in ascending order.
        Arrays.sort(ls);
        // Sort the reversed array in descending order.
        Arrays.sort(lsRev);
        reverseArray(lsRev);

        // Initialize the answer variable.
        long ans = 0;
        // Loop through the array to calculate the answer.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Calculate p and q based on the current elements.
                int p = Math.min(ls[i], ls[j]);
                int q = Math.max(ls[i], ls[j]);
                // Calculate x and y based on p and q.
                int x = q - p;
                int y = q + p;

                // Find the left boundary using binary search.
                int l = binarySearchLeft(ls, x);
                // Find the right boundary using binary search.
                int r = n - binarySearchRight(lsRev, y);

                // Calculate the sum of valid pairs.
                long sum = r - l;
                // Adjust the sum if the current indices are within the range.
                if (i >= l && i <= r) {
                    sum--;
                }
                if (j >= l && j <= r) {
                    sum--;
                }
                // Ensure the sum is not negative.
                sum = Math.max(0, sum);
                // Add the sum to the answer.
                ans += sum;
            }
        }

        // Divide the answer by 3 to get the final result.
        ans /= 3;
        // Print the final answer.
        System.out.println(ans);
    }

    // Helper function to read an integer from the scanner.
    private static int getInt(Scanner scanner) {
        return scanner.nextInt();
    }

    // Helper function to read an array of integers from the scanner.
    private static int[] getIntArray(Scanner scanner, int n) {
        int[] is = new int[n];
        for (int i = 0; i < n; i++) {
            is[i] = getInt(scanner);
        }
        return is;
    }

    // Helper function to reverse an array.
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

    // Binary search to find the left boundary.
    private static int binarySearchLeft(int[] array, int x) {
        int low = 0, high = array.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (array[mid] > x) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    // Binary search to find the right boundary.
    private static int binarySearchRight(int[] array, int y) {
        int low = 0, high = array.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (array[mid] < y) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}
// <END-OF-CODE>
