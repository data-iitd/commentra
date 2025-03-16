import java.util.Scanner;

public class Main {
    // Function to read an integer from standard input.
    public static int ri(Scanner scanner) {
        return Integer.parseInt(scanner.nextLine().trim());
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the integer value of N from standard input.
        int N = ri(scanner);
        
        // Initialize the variable ans to 0.
        long ans = 0;

        // Start a loop that iterates from 1 to N + 1.
        for (int i = 1; i <= N; i++) {
            // Calculate the sum of multiples of i up to N using the formula for the sum of an arithmetic series.
            ans += (long) i * (N / i) * (N / i + 1) / 2;
        }

        // Print the final value of ans, which represents the sum of multiples of numbers from 1 to N.
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
