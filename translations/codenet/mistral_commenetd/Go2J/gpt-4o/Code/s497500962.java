import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initialize variables R, G, B, and N with next integers
        int R = scanner.nextInt();
        int G = scanner.nextInt();
        int B = scanner.nextInt();
        int N = scanner.nextInt();

        // Initialize variable ans with zero
        int ans = 0;

        // Nested for loops to iterate through all possible combinations of x and y within the range of N
        for (int x = 0; x <= N; x++) {
            for (int y = 0; y <= N; y++) {
                // Calculate temporary variable tmp
                int tmp = N - R * x - G * y;

                // Check if tmp is non-negative and the remainder of tmp when divided by B is zero
                if (tmp >= 0 && tmp % B == 0) {
                    // Increment the value of ans if the condition is true
                    ans++;
                }
            }
        }

        // Print the value of ans
        System.out.println(ans);
    }
}

// Utility functions can be added here if needed

// <END-OF-CODE>
