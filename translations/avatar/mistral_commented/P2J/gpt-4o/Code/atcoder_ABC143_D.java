import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements 'n' and a list 'l' of 'n' integers from standard input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        scanner.close();

        // Sort the list 'l' in ascending order
        Arrays.sort(l);

        // Initialize an answer variable 'ans' to zero
        long ans = 0;

        // Iterate through each pair of indices 'i' and 'j' in the list 'l'
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Assign the elements at indices 'i' and 'j' to variables 'a' and 'b' respectively
                int a = l[i];
                int b = l[j];

                // Use binary search to find the index 'right' where an element greater than 'a+b' is present
                int right = bisectLeft(l, a + b);
                // Use binary search to find the index 'left' where the smallest element greater than 'max(a-b, b-a)' is present
                int left = bisectRight(l, Math.max(a - b, b - a));

                // Calculate the temporary answer 'tmp' based on the indices 'left' and 'right'
                long tmp = Math.max(0, right - left);

                // Subtract one from the temporary answer 'tmp' if both 'i' and 'j' lie between 'left' and 'right'
                if (left <= i && i < right) {
                    tmp--;
                }
                if (left <= j && j < right) {
                    tmp--;
                }

                // Add the temporary answer 'tmp' to the final answer 'ans'
                ans += tmp;
            }
        }

        // Print the final answer 'ans' divided by three
        System.out.println(ans / 3);
    }

    // Method to find the leftmost index where the value is greater than or equal to target
    private static int bisectLeft(int[] arr, int target) {
        int low = 0, high = arr.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    // Method to find the rightmost index where the value is less than or equal to target
    private static int bisectRight(int[] arr, int target) {
        int low = 0, high = arr.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}
// <END-OF-CODE>
