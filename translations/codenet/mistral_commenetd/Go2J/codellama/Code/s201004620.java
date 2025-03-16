
// Package main is the entry point of the program
package main 

import java.util.Scanner;

// Class Main is the entry point of the program
public class Main {

  // Function main initializes the program and starts the execution flow
  public static void main(String[] args) {

    // Declare a variable named S of type String
    String S;

    // Read a string input from the standard input using Scanner
    Scanner scanner = new Scanner(System.in);
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
      default : // If the input string is not "Sunny", "Cloudy" or "Rainy"
        System.out.println("Invalid input"); // Print "Invalid input" as the output
        break;
    }
  }
}

// End of the code 