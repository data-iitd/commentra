import java.lang.Math.*; // Importing Math library for mathematical functions
import java.util.Scanner; // Importing Scanner for reading input
import java.util.Arrays; // Importing Arrays for sorting

class Main {
    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in); // Initialize Scanner object to read input
        int n = sc.nextInt(); // Read the number of test cases
        int[] a = new int[3]; // Declare an array of size 3

        // Loop through each test case
        for (int i = 0; i < n; i++) {
            a[0] = sc.nextInt(); // Read the first number
            a[1] = sc.nextInt(); // Read the second number
            a[2] = sc.nextInt(); // Read the third number
            Arrays.sort(a); // Sort the array

            // Check if the square of the largest number is equal to the sum of squares of the other two numbers
            if (Math.pow(a[2], 2) == Math.pow(a[0], 2) + Math.pow(a[1], 2)) {
                System.out.println("YES"); // Print "YES" if the condition is true
            } else {
                System.out.println("NO"); // Print "NO" if the condition is false
            }
        }
    }
}
