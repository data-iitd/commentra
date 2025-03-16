import java.util.Scanner;

public class Main {
    
    // gcd function calculates the greatest common divisor of two integers a and b using the Euclidean algorithm.
    public static int gcd(int a, int b) {
        // Base case: if b is 0, return a as the GCD
        if (b == 0) {
            return a;
        }
        // Recursive case: call gcd with b and the remainder of a divided by b
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        // Declare variables for the upper limit (k) and loop counters (a, b, c)
        int k, a, b, c;
        // Initialize the answer variable to accumulate the results
        int ans = 0;

        // Read the upper limit k from user input
        Scanner scanner = new Scanner(System.in);
        k = scanner.nextInt();

        // Iterate through all combinations of a, b, and c from 1 to k
        for (a = 1; a <= k; a++) {
            for (b = 1; b <= k; b++) {
                for (c = 1; c <= k; c++) {
                    // Calculate the GCD of a, b, and c and add it to the answer
                    ans += gcd(a, gcd(b, c));
                }
            }
        }

        // Print the final accumulated answer
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
