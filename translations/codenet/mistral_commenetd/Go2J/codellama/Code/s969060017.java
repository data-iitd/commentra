
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables 'a' and 'b'
        int a, b;

        // Read two integer values from the user input using Scanner
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Check if 'b' is divisible by 'a' using if statement
        if (b % a == 0) {
            // If 'b' is divisible by 'a', print the sum of 'a' and 'b'
            System.out.println(a + b);
        } else {
            // If 'b' is not divisible by 'a', print the difference between 'b' and 'a'
            System.out.println(b - a);
        }
    }
}

