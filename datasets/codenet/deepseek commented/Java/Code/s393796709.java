
import java.util.*;
import java.io.*;
public class Main {
    long MOD = 1000000007; // Define the modulo constant
    
    // Main method to solve the problem
    void solve(BufferedReader in) throws Exception {
        int[] xx = toInts(in.readLine()); // Read input and parse it into an array of integers
        int min = Math.min(xx[0], xx[1]); // Find the minimum of the two numbers
        int max = Math.max(xx[0], xx[1]); // Find the maximum of the two numbers
        long res; // Declare a variable to store the result
        
        // Check if the two numbers are equal
        if(min == max) {
            long f = f(min); // Calculate factorial of the minimum number
            res = (2*f*f)%MOD; // Calculate the result for the equal case
        } else if(min + 1 == max){ // Check if the two numbers are consecutive
            long f = f(min); // Calculate factorial of the minimum number
            res = (f*((f*max)%MOD))%MOD; // Calculate the result for the consecutive case
        } else { // For all other cases
            res = 0; // Set the result to zero
        }
        System.out.println(res); // Print the result
    }
    
    // Helper method to calculate factorial modulo MOD
    long f(int n) {
        long res = 1; // Initialize result to 1
        for(int i = 2; i<=n; i++) res = (res*i)%MOD; // Calculate factorial modulo MOD
        return res;
    }
    
    // Helper method to convert a string to an integer
    int toInt(String s) {
        return Integer.parseInt(s);
    }
    
    // Helper method to convert a string of space-separated integers to an array of integers
    int[] toInts(String s) {
        String[] a = s.split(" "); // Split the string by spaces
        int[] o = new int[a.length]; // Initialize the output array
        for(int i = 0; i<a.length; i++) o[i] = toInt(a[i]); // Convert each part to an integer
        return o;
    }
    
    // Helper method to print error messages
    void e(Object o) {
        System.err.println(o);
    }
    
    // Main method to run the program
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in)); // Create a BufferedReader to read from standard input
        (new Main()).solve(in); // Create an instance of Main and call the solve method
    }
}

