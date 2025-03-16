import java.util.Scanner;

public class Main {
    // Function to find the greatest common divisor (GCD) of two numbers
    public static int gcd(int a, int b) {
        // Base case: if b is 0, return a as the GCD
        if (b == 0) {
            return a;
        }
        // Recursive case: call gcd function with b and the remainder of a divided by b
        return gcd(b, a % b);
    }

    // Main function
    public static void main(String[] args) {
        // Initialize variables
        int k, a, b, c, ans = 0;
        Scanner scanner = new Scanner(System.in);
        // Read an integer 'k' from the user input
        System.out.print("Enter a positive integer k: ");
        k = scanner.nextInt();
        // Loop through all possible combinations of a, b and c from 1 to k
        for (a = 1; a <= k; a++) {
            for (b = 1; b <= k; b++) {
                for (c = 1; c <= k; c++) {
                    // Add the result of GCD(a, GCD(b, c)) to the answer
                    ans += gcd(a, gcd(b, c));
                }
            }
        }
        // Print the final answer
        System.out.println("The sum of GCD of all combinations of three numbers from 1 to k is: " + ans);
        // End of code
    }
}
