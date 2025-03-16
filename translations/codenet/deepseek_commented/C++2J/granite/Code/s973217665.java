
import java.util.*;
import java.io.*;

public class s973217665{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); // Read the number of test cases
        while (n-- > 0) {
            String[] split = br.readLine().split(" "); // Read the values of p and q for each test case
            int p = Integer.parseInt(split[0]);
            int q = Integer.parseInt(split[1]);
            int l = (int)Math.sqrt(p*p + q*q); // Calculate the length of the hypotenuse
            boolean isprime = true; // Initialize a flag to check if the number is prime
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < l; j++) {
                    int x = i*i + j*j; // Calculate the sum of squares
                    if (x <= 1 || x >= p*p + q*q) continue; // Skip if x is out of range
                    if ((i*p + j*q) % x == 0 && (i*q - j*p) % x == 0) isprime = false; // Check the conditions
                }
            }
            System.out.println(isprime? "P" : "C"); // Print the result
        }
    }
}
