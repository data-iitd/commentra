import java.util.Scanner; // Importing the Scanner class for reading input
import java.lang.String;   // Importing the String class for string manipulation

// Main class where the execution of the program begins
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        String s; // Declare a variable 's' to hold the input string

        // Read a string input from the user and store it in variable 's'
        s = scanner.next(); // Use next() to read a single word input

        // Replace all occurrences of "2017" with "2018" in the input string and print the result
        System.out.println(s.replace("2017", "2018")); // Use replace() method for string replacement

        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
