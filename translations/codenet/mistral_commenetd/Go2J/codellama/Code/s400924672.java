// Package declaration
package main;

// Importing the required package
import java.util.Scanner;

// Function definition for the main function
public class Main {
    public static void main(String[] args) {
        // Declaring variables r, D, and x of type int
        int r, D, x;

        // Reading input values for r, D, and x from the standard input
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        D = sc.nextInt();
        x = sc.nextInt();

        // Comment for the for loop
        // Loop runs 10 times
        for (int i = 1; i <= 10; i++) {
            // Print the result of the current iteration
            System.out.println(r * x - D);

            // Update the value of x for the next iteration
            x = r * x - D;
        }
    }
}

// End of the code
