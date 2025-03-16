
// Package main is the entry point of the program
package main 

import java.util.Scanner;

// Function main initializes the program and starts the execution flow
public class s201004620{
  public static void main(String[] args) {
    // Declare a variable named S of type String
    String S;

    // Create a Scanner object to read input from the standard input
    Scanner scanner = new Scanner(System.in);

    // Read a string input from the standard input using scanner.nextLine()
    S = scanner.nextLine();

    // Switch statement to check the value of the string S and print the corresponding weather condition
    switch (S) {
      case "Sunny" : // If the input string is "Sunny"
        System.out.println("Cloudy"); // Print "Cloudy" as the output
        break;
      case "Cloudy" : // If the input string is "Cloudy"
        System.out.println("Rainy"); // Print "Rainy" as the output
        break;
      case "Rainy" : // If the input string is "Rainy"
        System.out.println("Sunny"); // Print "Sunny" as the output
        break;
    }

    // Close the Scanner object to release system resources
    scanner.close();
  }
}

// End of the code