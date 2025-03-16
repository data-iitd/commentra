import java.util.Scanner;

public class Main {
    // Method to calculate the absolute value of a number
    public static int abs(int x) {
        return (x < 0) ? -x : x;
    }

    public static void main(String[] args) {
        // Declare variables
        Scanner scanner = new Scanner(System.in);
        int N, t, x, y, nx = 0, ny = 0, nt = 0;

        // Read the number of test cases
        N = scanner.nextInt();
        
        // Loop through each test case
        for (int i = 0; i < N; i++) {
            // Read the time and coordinates for each test case
            t = scanner.nextInt();
            x = scanner.nextInt();
            y = scanner.nextInt();
            
            // Calculate the time left after accounting for the previous time and the distance traveled
            int tmp = t - nt - (abs(x - nx) + abs(y - ny));
            
            // Check if the remaining time is negative or odd
            if (tmp < 0 || tmp % 2 != 0) {
                // If so, print "No" and exit the program
                System.out.println("No");
                return;
            }
            
            // Update the current position and time for the next iteration
            nt = t; // Update the previous time
            nx = x; // Update the previous x coordinate
            ny = y; // Update the previous y coordinate
        }
        
        // If all test cases are valid, print "Yes"
        System.out.println("Yes");
    }
}
// <END-OF-CODE>
