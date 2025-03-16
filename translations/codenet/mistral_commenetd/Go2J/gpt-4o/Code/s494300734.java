// Package declaration, this file is the entry point of the program
import java.util.Scanner;

// Entry point of the program
public class Main {
    public static void main(String[] args) {
        // Initialize a variable s of type String and read a string input from the standard input
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();

        // Initialize a variable ans with the string value "No"
        String ans = "No";

        // Check if the index of the substring "C" in the string s is less than the index of the substring "F"
        if (s.indexOf("C") < s.lastIndexOf("F")) {
            // If it is, then change the value of ans to "Yes"
            ans = "Yes";
        }

        // Check if the index of the substring "C" in the string s is less than 0
        if (s.indexOf("C") < 0) {
            // If it is, then do not change the value of ans
        }

        // Print the value of ans to the standard output
        System.out.println(ans);
    }
}

// <END-OF-CODE>
