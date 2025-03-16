import java.util.Scanner;

public class Main {
    // Main function
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a new scanner for input

        // Read four integers from input
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();

        // Determine the maximum value among A, B, and C
        int ma = max(A, B, C);
        int rest = 0; // Initialize the rest variable to hold the sum of the other two values

        // Calculate the sum of the two smaller values
        if (ma == A) {
            rest += B + C;
        } else if (ma == B) {
            rest += A + C;
        } else {
            rest += A + B;
        }

        // Double the maximum value K times
        for (int i = 1; i <= K; i++) {
            ma *= 2;
        }

        // Output the final result: doubled max value plus the sum of the other two
        System.out.println(ma + rest);
    }

    // Utility functions

    // max returns the maximum value from a list of integers
    public static int max(int... nums) {
        int m = nums[0]; // Initialize max with the first element
        for (int i : nums) {
            if (m < i) {
                m = i; // Update max if a larger value is found
            }
        }
        return m;
    }
}
// <END-OF-CODE>
