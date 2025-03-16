/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/

// Include necessary header files
import java.util.*;
import java.lang.*;
import java.io.*;

// Define constants and type aliases for convenience
class Solution {
    public static void main(String[] args) {
        // Declare variables for input and answer
        int n;
        // Read input value for n
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        // Output the negation of n (0 if n is non-zero, 1 if n is zero)
        System.out.println(!n);
    }
}

// Main function
public class Main {
    public static void main(String[] args) {
        // Declare variables for input and answer
        int n = 1; // Initialize n to 1 (can be modified to read input)
        while (n--) Solution.main(null); // Call the solve function n times
    }
}

