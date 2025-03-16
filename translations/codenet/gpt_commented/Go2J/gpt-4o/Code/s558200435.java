import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements from standard input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Initialize an array to hold the input integers
        int[] a = new int[n];
        // Read n integers from standard input into the array a
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize an array to hold the longest increasing subsequence
        int[] b = new int[n];
        int length = 0;

        // Iterate over each value in the input array a
        for (int v : a) {
            // Use binary search to find the index where v can be placed in b
            int x = Arrays.binarySearch(b, 0, length, v);
            if (x < 0) {
                x = -(x + 1); // Convert to the insertion point
            }
            // If v is greater than all elements in b, append it to b
            if (x == length) {
                b[length++] = v;
            } else {
                // Otherwise, replace the existing value at index x with v
                b[x] = v;
            }
        }

        // Output the length of the longest increasing subsequence
        System.out.println(length);
    }
}
// <END-OF-CODE>
