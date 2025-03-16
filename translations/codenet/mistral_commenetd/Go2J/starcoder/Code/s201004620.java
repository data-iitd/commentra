// Package main is the entry point of the program

import java.util.Scanner;

// Function main initializes the program and starts the execution flow
public class Main {
  // Function main is the entry point of the program
  public static void main(String[] args) {
    // Declare a variable named S of type string
    String S;

    // Read a string input from the standard input using Scanner
    Scanner scanner = new Scanner(System.in);
    S = scanner.next();

    // Switch statement to check the value of the string S and print the corresponding weather condition
    switch (S) {
      case "Sunny" : // If the input string is "Sunny"
        System.out.println("Cloudy"); // Print "Cloudy" as the output
      case "Cloudy" : // If the input string is "Cloudy"
        System.out.println("Rainy"); // Print "Rainy" as the output
        case "Rainy" : // If the input string is "Rainy"
          System.out.println("Sunny"); // Print "Sunny" as the output
    }
  }
}

// End of the code

