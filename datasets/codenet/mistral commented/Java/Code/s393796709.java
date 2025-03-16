import java.util.*;
import java.io.*;

// Importing necessary classes for reading input and basic operations

public class Main {
    long MOD = 1000000007; // Constants are usually defined at the top

    void solve(BufferedReader in) throws Exception { // Function to solve the problem
        int[] xx = toInts(in.readLine()); // Read the first line and convert it to an integer array

        // Finding minimum and maximum values in the input array
        int min = Math.min(xx[0], xx[1]);
        int max = Math.max(xx[0], xx[1]);

        long res; // Result variable to store the final answer

        // Checking the conditions and calculating the result accordingly
        if(min == max) {
            long f = f(min); // Finding factorial of min value
            res = (2*f*f)%MOD; // Calculating the result for the case when min and max are equal
        } else if(min + 1 == max){
            long f = f(min); // Finding factorial of min value
            res = (f*((f*max)%MOD))%MOD; // Calculating the result for the case when min and max differ by 1
        } else {
            res = 0; // Setting the result to 0 for other cases
        }

        // Printing the result
        System.out.println(res);
    }

    long f(int n) { // Function to find the factorial of a given number
        long res = 1; // Initializing the result to 1
        for(int i = 2; i<=n; i++) res = (res*i)%MOD; // Multiplying the result with i from 2 to n
        return res; // Returning the final result
    }

    int toInt(String s) {return Integer.parseInt(s);} // Function to convert a string to an integer
    int[] toInts(String s) { // Function to convert a string to an integer array
        String[] a = s.split(" "); // Splitting the string by space to get individual integers
        int[] o = new int[a.length]; // Creating an integer array of the same size as the input string
        for(int i = 0; i<a.length; i++) o[i] = toInt(a[i]); // Assigning the integer value to each element of the array
        return o;
    }

    void e(Object o) { // Function to print error messages
        System.err.println(o);
    }

    public static void main(String[] args) throws Exception{ // Main function to run the program
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in)); // Creating a BufferedReader to read input
        (new Main()).solve(in); // Calling the solve function to start the problem-solving process
    }
}
