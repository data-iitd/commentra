package main;

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
        // Initialize the scanner to read user input
        Scanner scanner = new Scanner(System.in);
        // Declare variables for the upper limit (k) and loop counters (a, b, c)
        int k = scanner.nextInt();
        int ans = 0;
        
        // Iterate through all combinations of a, b, and c from 1 to k
        for (int a = 1; a <= k; a++) {
            for (int b = 1; b <= k; b++) {
                for (int c = 1; c <= k; c++) {
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
