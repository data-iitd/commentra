import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Constants for the program
    private static final int MOD = 1000000000 + 7;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input values for n and x
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int[] A = new int[n];

        // Read the array A
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        // Sort the array A
        Arrays.sort(A);

        // Initialize answer variable
        int ans = 0;

        // Count how many elements can be taken from A without exceeding x
        for (int i = 0; i < n; i++) {
            if (x >= A[i]) {
                ans++;
                x -= A[i];
            } else {
                break;
            }
        }

        // Adjust answer if all elements are taken and there is still remaining x
        if (ans == n && x > 0) {
            ans--;
        }

        // Print the final answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
