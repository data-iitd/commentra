import java.util.*;
import java.io.*;

public class Main {
    // Define a constant for the modulo operation
    long MOD = 1000000007;

    // Method to solve the problem using input from BufferedReader
    void solve(BufferedReader in) throws Exception {
        // Read a line of input and convert it to an array of integers
        int[] xx = toInts(in.readLine());
        
        // Determine the minimum and maximum values from the input
        int min = Math.min(xx[0], xx[1]);
        int max = Math.max(xx[0], xx[1]);
        
        long res; // Variable to store the result
        
        // Case 1: If both numbers are equal
        if(min == max) {
            // Calculate factorial of min and compute the result
            long f = f(min);
            res = (2 * f * f) % MOD; // Result is 2 times the factorial squared
        } 
        // Case 2: If the numbers are consecutive
        else if(min + 1 == max) {
            // Calculate factorial of min and compute the result based on max
            long f = f(min);
            res = (f * ((f * max) % MOD)) % MOD; // Result is factorial of min times factorial of min times max
        } 
        // Case 3: If the numbers are not equal and not consecutive
        else {
            res = 0; // Result is 0 for non-consecutive numbers
        }
        
        // Output the final result
        System.out.println(res);
    }

    // Method to calculate factorial of a number n modulo MOD
    long f(int n) {
        long res = 1; // Initialize result to 1
        // Calculate factorial iteratively
        for(int i = 2; i <= n; i++) 
            res = (res * i) % MOD; // Update result with modulo
        return res; // Return the computed factorial
    }

    // Helper method to convert a string to an integer
    int toInt(String s) {
        return Integer.parseInt(s);
    }

    // Helper method to convert a space-separated string to an array of integers
    int[] toInts(String s) {
        String[] a = s.split(" "); // Split the string by spaces
        int[] o = new int[a.length]; // Create an array to hold the integers
        // Convert each string to an integer
        for(int i = 0; i < a.length; i++) 
            o[i] = toInt(a[i]);
        return o; // Return the array of integers
    }

    // Method to print error messages to standard error
    void e(Object o) {
        System.err.println(o);
    }

    // Main method to run the program
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in)); // Create BufferedReader for input
        (new Main()).solve(in); // Create an instance of Main and call the solve method
    }
}
