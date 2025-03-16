import java.util.Arrays;
import java.util.Scanner;

// Main class of the program
public class Main {
    // Main method, entry point of the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Get the number of elements in the input array
        int n = getInt(scanner);
        // Get the input array
        int[] ls = getIntArray(scanner, n);
        // Create a reversed copy of the input array
        int[] lsRev = Arrays.copyOf(ls, n);
        // Sort the input array in ascending order
        Arrays.sort(ls);
        // Sort the reversed copy of the array in descending order
        Arrays.sort(lsRev);
        reverseArray(lsRev);

        // Initialize the answer variable
        long ans = 0;
        // Iterate through all pairs of elements in the array
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Find the minimum and maximum elements of the current pair
                int p = Math.min(ls[i], ls[j]);
                int q = Math.max(ls[i], ls[j]);
                // Calculate the difference between the maximum and minimum elements
                int x = q - p;
                int y = q + p;
                // Find the indices of the elements greater than x and less than y in the sorted array and reversed array respectively
                int l = binarySearch(ls, x);
                int r = n - binarySearch(lsRev, y);
                // Calculate the sum of the difference between the indices of the greater elements in the sorted array and reversed array
                long sum = r - l;
                // Check if the current pair lies within the range [l, r]
                if (i >= l && i <= r) {
                    sum--;
                }
                if (j >= l && j <= r) {
                    sum--;
                }
                // Ensure that the sum is not negative
                sum = Math.max(0, sum);
                // Add the sum to the answer variable
                ans += sum;
            }
        }
        // Divide the answer by 3 and print it
        ans /= 3;
        System.out.println(ans);
    }

    // Method to read an integer from the scanner
    private static int getInt(Scanner scanner) {
        return scanner.nextInt();
    }

    // Method to read an array of integers from the scanner
    private static int[] getIntArray(Scanner scanner, int n) {
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = getInt(scanner);
        }
        return array;
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

    // Method to perform binary search
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
}
// <END-OF-CODE>
