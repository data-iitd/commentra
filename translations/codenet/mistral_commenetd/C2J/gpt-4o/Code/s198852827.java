import java.util.Scanner;

public class Main {
    // Method to calculate the absolute value of a number
    public static int abs(int x) {
        return (x < 0) ? -x : x;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Variable to store the number of test cases
        int N = scanner.nextInt();
        // Variables to store the current test case data and previous coordinates
        int t, x, y, nx = 0, ny = 0, nt = 0;

        // Loop through each test case
        for (int i = 0; i < N; i++) {
            // Read the current test case data (t, x, y)
            t = scanner.nextInt();
            x = scanner.nextInt();
            y = scanner.nextInt();

            // Calculate the temporary variable 'tmp' to check the distance between the current and previous coordinates
            int tmp = t - nt - (abs(x - nx) + abs(y - ny));

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
// <END-OF-CODE>
