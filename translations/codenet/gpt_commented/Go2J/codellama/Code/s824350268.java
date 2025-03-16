
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read an integer N from input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        // Calculate the integer square root of N
        int sqrtN = (int) Math.sqrt(N);

        // Initialize min to N, which will hold the minimum value found
        int min = N;
        // Iterate through all possible divisors of N
        for (int i = 1; i <= sqrtN; i++) {
            // If i is not a divisor of N, skip to the next iteration
            if (N % i != 0) {
                continue;
            }

            // Calculate the value based on the divisor and its complement
            int num = i + (N / i) - 2;
            // Update min if the new value is smaller
            if (num < min) {
                min = num;
            }
        }

        // Print the minimum value found
        System.out.println(min);
    }
}

