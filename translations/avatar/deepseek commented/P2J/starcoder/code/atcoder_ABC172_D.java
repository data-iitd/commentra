
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Read the integer value of N from standard input.
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        // Initialize the variable ans to 0.
        int ans = 0;

        // Start a loop that iterates from 1 to N + 1.
        for (int i = 1; i <= N; i++) {
            // Calculate the sum of multiples of i up to N using the formula for the sum of an arithmetic series.
            ans += i * (N / i) * (N / i + 1) / 2;
        }

        // Print the final value of ans, which represents the sum of multiples of numbers from 1 to N.
        System.out.println(ans);
    }
}

