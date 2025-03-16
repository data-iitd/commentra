
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int K = in.nextInt();
        int N = f(1);
        for (int i = 0; i < K; i++) {
            System.out.println(N);
            N = f(N+1);
        }
    }
    
    // Function to calculate the minimum n/S(n)
    public static int f(int N) {
        int[] a = new int[20]; // Vector to store digits of N
        int d = 0; // Digit counter
        while (N > 0) {
            a[d] = N % 10; // Store the last digit of N
            N /= 10; // Remove the last digit from N
            d++; // Increment the digit counter
        }
        double m = 1e18; // Initialize the minimum fraction to a large number
        int res = N; // Initialize the result to 0
        for (int i = 0; i <= d; i++) {
            int bunsi = 0; // Numerator
            int bunbo = 9 * i; // Denominator
            for (int j = d-1; j >= 0; j--) {
                bunsi *= 10;
                if (j < i) bunsi += 9; // Add 9 to the current digit if necessary
                else bunsi += a[j]; // Add the actual digit
                
                if (j >= i) bunbo += a[j]; // Add the actual digit to the denominator if necessary
                
            }
            //System.out.println("bb" + bunsi +  " " + bunbo);
            double frac = (double) bunsi / (double) bunbo; // Calculate the fraction
            if (frac < m) {
                m = frac; // Update the minimum fraction
                res = bunsi; // Update the result
            }
        }
        return res; // Return the result
    }
}

// End of code

