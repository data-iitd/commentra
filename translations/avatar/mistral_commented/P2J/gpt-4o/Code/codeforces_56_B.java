import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements in the list 'A'
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Initialize an array 'A' with the given size 'N'
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
            // Create a new list to hold the modified array
            List<Integer> result = new ArrayList<>();
            // Add elements before 'mn'
            for (int i = 0; i < mn; i++) {
                result.add(A[i]);
            }
            // Add elements from 'mx' to 'mn' in reverse order
            for (int i = mx; i >= mn; i--) {
                result.add(A[i]);
            }
            // Add elements after 'mx'
            for (int i = mx + 1; i < N; i++) {
                result.add(A[i]);
            }

            // Check if the modified list is sorted in ascending order
            boolean isSorted = true;
            for (int i = 1; i < result.size(); i++) {
                if (result.get(i) < result.get(i - 1)) {
                    isSorted = false;
                    break;
                }
            }

            // Print the result based on whether the list is sorted
            if (isSorted) {
                System.out.println((mn + 1) + " " + (mx + 1));
            } else {
                System.out.println("0 0");
            }
        }

        scanner.close();
    }
}
// <END-OF-CODE>
