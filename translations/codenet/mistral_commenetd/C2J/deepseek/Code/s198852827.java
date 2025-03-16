import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Variable to store the number of test cases
        int t = 0, x = 0, y = 0; // Variables to store the current test case data
        int nx = 0, ny = 0, nt = 0; // Variables to store the previous coordinates
        int i, j, k, tmp; // Loop variables

        // Loop through each test case
        for (i = 0; i < N; i++) {
            // Read the current test case data (t, x, y)
            t = scanner.nextInt();
            x = scanner.nextInt();
            y = scanner.nextInt();

            // Calculate the temporary variable 'tmp' to check the distance between the current and previous coordinates
            tmp = t - nt - (Math.abs(x - nx) + Math.abs(y - ny));

            // Check if the current test case satisfies the condition
            if (tmp < 0 || tmp % 2 != 0) {
                // If the condition is not satisfied, print 'No' and exit the program
                System.out.println("No");
                return;
            }

            // Update the previous coordinates for the next iteration
            nx = x;
            ny = y;
            nt = t;
        }

        // If all the test cases satisfy the condition, print 'Yes'
        System.out.println("Yes");
    }
}
