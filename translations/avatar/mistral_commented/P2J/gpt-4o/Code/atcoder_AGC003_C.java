import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();
        // Ask the user for an integer `N` and store it in a variable called `N`

        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt() * N + i;
        }
        // Create an array `A` with `N` elements. Each element is the product of an integer input by the user and `N`,
        // plus an index `i` that goes from `0` to `N-1`.

        Arrays.sort(A);
        // Sort the array `A` in ascending order.

        int cnt = 0;
        // Initialize a counter `cnt` to zero.

        for (int i = 0; i < N; i++) {
            // Iterate through each index `i` in the array `A`.
            int d = (A[i] % N) % 2;
            // Calculate the remainder of `A[i]` divided by `N` and modulo 2.
            // Store this result in a variable called `d`.

            if (d % 2 != i % 2) {
                // Check if the remainder of `d` divided by 2 is different from the remainder of `i` divided by 2.
                // If they are different, increment the counter `cnt` by 1.
                cnt++;
            }
        }

        System.out.println(cnt / 2);
        // After the loop finishes, print the result of the counter `cnt` divided by 2.
    }
}
// <END-OF-CODE>
