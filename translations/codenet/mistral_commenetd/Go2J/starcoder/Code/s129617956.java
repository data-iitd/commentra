
package main;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Read an integer from standard input and initialize n variable
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Initialize minimum factor with a large value
        int minf = 100;

        // Call the checkDivisibility function to find the minimum number of digits in a divisor of n
        checkDivisibility(n, minf);

        // Print the result
        System.out.println(minf);
    }

    // Function to find the minimum number of digits in a divisor of n
    public static void checkDivisibility(int n, int minf) {
        int rt = (int) Math.sqrt(n);
        for (int i = 1; i < rt+1; i++) {
            if (n%i == 0) {
                // Calculate the number of digits in the divisor
                int b = n / i;
                int ndigit = 0;
                while (b > 0) {
                    b /= 10;
                    ndigit++;
                }
                // Update minimum factor if a divisor with fewer digits is found
                minf = Math.min(minf, ndigit);
            }
        }
    }
}

// 