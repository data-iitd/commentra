
// Package declaration
package main;

// Importing required packages
import java.util.Scanner;

// Class declaration
public class s589878052{
    // s589878052 function definition
    public static void main(String[] args) {
        // Variable declaration and initialization
        int a, b, h;

        // Creating a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Reading input values from the standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        h = scanner.nextInt();

        // Calculating the result
        int result = (a + b) * h / 2;

        // Printing the result to the standard output
        System.out.println(result);
    }
}

// End of the code