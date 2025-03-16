

import java.util.Scanner;  // Import the Scanner class from the java.util package.
import java.util.stream.IntStream;  // Import the IntStream class from the java.util.stream package.

public class atcoder_ABC118_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input from the console.
        int N = scanner.nextInt();  // Read an integer input N, representing the number of elements in the list A.
        int[] A = IntStream.range(0, N).map(i -> scanner.nextInt()).toArray();  // Read a space-separated string of integers, convert them into an array of integers, and assign it to the variable A.
        int gcd = A[0];  // Initialize the variable gcd to the first element of the array A.
        for (int i = 1; i < N; i++) {
            gcd = gcd(gcd, A[i]);  // Use the gcd function to compute the greatest common divisor (GCD) of gcd and A[i], and assign the result back to gcd.
        }
        System.out.println(gcd);  // Print the computed GCD.
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
}



Translate the above Java code to C++ and end with comment "