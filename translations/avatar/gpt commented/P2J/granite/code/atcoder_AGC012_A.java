
import java.util.*;  // Importing required classes and modules
import java.io.*;
import java.math.*;

public class atcoder_AGC012_A{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());  // Reading an integer input for 'n'
        String[] input = br.readLine().split(" ");  // Reading a list of integers as input
        int[] A = new int[n];  // Creating an array of size 'n' to store the input integers
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(input[i]);  // Storing the input integers in the array
        }
        Arrays.sort(A);  // Sorting the array of integers in ascending order
        long ans = 0;  // Initializing the answer variable to accumulate the result
        
        // Looping through the last 2*n elements of the sorted array in reverse order
        for (int i = n - 1; i >= n - 2 * n; i -= 2) {
            ans += A[i];  // Adding the current element to the answer
        }
        
        System.out.println(ans);  // Printing the final accumulated answer
    }
}

Translate the above Java code to C++ and end with comment "