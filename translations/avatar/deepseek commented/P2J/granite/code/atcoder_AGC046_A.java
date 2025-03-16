

import java.util.Scanner;  // Importing the Scanner class from the java.util package

public class atcoder_AGC046_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Creating a Scanner object to read input from the user

        // Take an integer input x
        int x = scanner.nextInt();

        // Calculate the number of distinct cyclic permutations of a string of length x
        System.out.println(360 / gcd(360, x));  // Printing the result

        scanner.close();  // Closing the Scanner object to release system resources
    }

    // Function to calculate the greatest common divisor (gcd) of two integers
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
}



Translate the above Python code to C++ and end with comment "