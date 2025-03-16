// Package declaration, not a logical block, no comments needed.
package main;

// Import statement, not a logical block, no comments needed.
import java.util.Scanner;

// Class declaration
public class Main {
    
    // Method comp checks if x is less than a. If so, it returns 0, otherwise it returns 10.
    public static int comp(int x, int a) {
        // If x is less than a, return 0, otherwise return 10.
        if (x < a) {
            return 0;
        }
        // If x is not less than a, return 10.
        return 10;
    }

    // Main method initializes two integer variables x and a, reads their values from the standard input,
    // and then prints the result of calling the comp method with these values.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int a = scanner.nextInt();
        System.out.println(comp(x, a));
        scanner.close();
    }
}

// <END-OF-CODE>
