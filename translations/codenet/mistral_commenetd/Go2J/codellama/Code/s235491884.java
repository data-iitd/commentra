
// Package main is the entry point of the program
package main;

// Importing the 'java.util.Scanner' class for reading input from the standard input
import java.util.Scanner;

// Function main is the entry point of the program
public class Main {
    // Function main begins here
    public static void main(String[] args) {
        // Declare a variable 's' of type String
        String s;
        // Use 'Scanner' to read a string input from the standard input
        Scanner scanner = new Scanner(System.in);
        s = scanner.nextLine();

        // Use 'String.length()' to count the number of occurrences of the substring "o" in the string 's'
        int n = s.length() - s.replace("o", "").length();

        // Calculate the result by adding 700 to the product of 100 and the number of occurrences of "o" in the string
        int result = 700 + n*100;
        // Use 'System.out.println' to print the result to the standard output
        System.out.println(result);
    }
    // Function main ends here
}

// The code ends here
