

import java.util.Scanner;

public class s513492399{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a positive integer k: ");
        int k = scanner.nextInt();
        int ans = 0;
        for (int a = 1; a <= k; a++) {
            for (int b = 1; b <= k; b++) {
                for (int c = 1; c <= k; c++) {
                    ans += gcd(a, gcd(b, c));
                }
            }
        }
        System.out.println("The sum of GCD of all combinations of three numbers from 1 to k is: " + ans);
    }

    // Function to find the greatest common divisor (GCD) of two numbers
    public static int gcd(int a, int b) {
        // Base case: if b is 0, return a as the GCD
        if (b == 0) {
            return a;
        }
        // Recursive case: call gcd function with b and the remainder of a divided by b
        return gcd(b, a % b);
    }
}

// End of code