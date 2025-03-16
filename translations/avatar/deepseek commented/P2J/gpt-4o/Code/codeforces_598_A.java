import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();  // Read the number of test cases

        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();  // Read each n for the test case
            System.out.println(solve(n));  // Print the result of the solve function for the current n
        }
        
        scanner.close();
    }

    public static int solve(int n) {
        // Calculate the sum of the first n natural numbers
        int s = (1 + n) * n / 2;
        // Initialize t to 1
        int t = 1;
        // Subtract twice the sum of powers of 2 up to n from s
        while (t <= n) {
            s -= 2 * t;
            t *= 2;
        }
        return s;
    }
}

// <END-OF-CODE>
