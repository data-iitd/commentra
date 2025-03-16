// Package main is the entry point of the program
import java.util.Scanner;

// Class Main is the entry point of the program
public class Main {
    // Method main initializes the program and starts the execution flow
    public static void main(String[] args) {
        // Declare a variable named S of type String
        String S;

        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);
        
        // Read a string input from the standard input
        S = scanner.nextLine();

        // Switch statement to check the value of the string S and print the corresponding weather condition
        switch (S) {
            case "Sunny": // If the input string is "Sunny"
                System.out.println("Cloudy"); // Print "Cloudy" as the output
                break;
            case "Cloudy": // If the input string is "Cloudy"
                System.out.println("Rainy"); // Print "Rainy" as the output
                break;
            case "Rainy": // If the input string is "Rainy"
                System.out.println("Sunny"); // Print "Sunny" as the output
                break;
            default:
                // Optional: Handle unexpected input
                System.out.println("Unknown weather condition");
                break;
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
