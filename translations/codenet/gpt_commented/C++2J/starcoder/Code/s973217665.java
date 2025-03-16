import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of test cases
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        // Process each test case
        while (n--){
            int p, q;
            // Read the values of p and q
            p = in.nextInt();
            q = in.nextInt();

            // Calculate the length l based on the Euclidean distance from the origin
            int l = (int) Math.sqrt(p*p + q*q);

            // Initialize a flag to check if the current case is prime
            boolean isprime = true;

            // Check all combinations of i and j within the range [0, l)
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < l; j++) {
                    // Calculate the sum of squares of i and j
                    int x = i*i + j*j;

                    // Skip values of x that are not in the valid range
                    if (x <= 1 || x >= p*p + q*q) continue;

                    // Check the conditions for primality based on the given formula
                    if ((i*p + j*q) % x == 0 && (i*q - j*p) % x == 0) 
                        isprime = false; // Set isprime to false if conditions are met
                }
            }

            // Output "P" if prime, otherwise output "C"
            System.out.println(isprime? "P" : "C");
        }
    }
}

