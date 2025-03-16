import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the list 'A'
        int N = scanner.nextInt();

        // Initialize an array 'A' with the given size 'N'
        // and read the elements from the standard input
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Initialize minimum and maximum indices 'mn' and 'mx'
        int mn = N + 1, mx = -1;

        // Iterate through the array 'A' from index 0 to 'N-1'
        for (int i = 0; i < N; i++) {
            // Check if the current index 'i' is not equal to the next element
            if (i + 1 != A[i]) {
                // Update the minimum and maximum indices 'mn' and 'mx'
                mn = Math.min(mn, i);
                mx = Math.max(mx, i);
            }
        }

        // Check if the maximum index 'mx' is still equal to -1
        if (mx == -1) {
            // If yes, print '0 0' as the output
            System.out.println("0 0");
        } else {
            // Reverse the subarray from index 'mn' to 'mx'
            reverse(A, mn, mx);

            // Check if the reversed array 'A' is sorted in ascending order
            if (isSorted(A)) {
                // If yes, print the minimum and maximum indices 'mn+1' and 'mx+1' as the output
                System.out.println((mn + 1) + " " + (mx + 1));
            } else {
                // If no, print '0 0' as the output
                System.out.println("0 0");
            }
        }
    }

    // Helper method to reverse a subarray in the array
    private static void reverse(int[] A, int start, int end) {
        while (start < end) {
            int temp = A[start];
            A[start] = A[end];
            A[end] = temp;
            start++;
            end--;
        }
    }

    // Helper method to check if the array is sorted in ascending order
    private static boolean isSorted(int[] A) {
        for (int i = 1; i < A.length; i++) {
            if (A[i] < A[i - 1]) {
                return false;
            }
        }
        return true;
    }
}
