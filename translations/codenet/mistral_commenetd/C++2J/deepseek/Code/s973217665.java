import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Number of test cases

        while (n-- > 0) { // Process each test case
            int p = scanner.nextInt(); // Read p from standard input
            int q = scanner.nextInt(); // Read q from standard input

            int l = (int) Math.sqrt(p * p + q * q); // Calculate the square root of p^2 + q^2

            boolean isprime = true; // Initialize isprime to true

            for (int i = 0; i < l; i++) { // Iterate through all possible integers x from 0 to l^2
                for (int j = 0; j < l; j++) {
                    int x = i * i + j * j; // Calculate x = i^2 + j^2

                    if (x <= 1) continue; // If x is less than or equal to 1, skip to the next iteration
                    if (x > p * p + q * q) continue; // If x is greater than p^2 + q^2, skip to the next iteration

                    if ((i * p + j * q) % x == 0 && (i * q - j * p) % x == 0) { // Check if p*i + q*j and q*i - p*j are both divisible by x
                        isprime = false; // If so, set isprime to false
                        break; // Exit the inner loop
                    }
                }
                if (!isprime) break; // Exit the outer loop if isprime is false
            }

            System.out.println(isprime ? "P" : "C"); // Print "P" if isprime is still true, otherwise print "C"
        }
    }
}

