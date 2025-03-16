// Package main is the entry point of the program

import (
	// Import the "fmt" and "strings" packages
	"fmt"
	"strings"
)

public class Main {
	// The main function is the entry point of the program
	public static void main(String[] args) {
		// Declare two variables, n and s
		int n;
		String s;

		// Read the input from the standard input
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		s = scanner.next();

		// Call the strings.Count function to count the number of occurrences of "ABC" in the string s
		// Print the result using the fmt.Println function
		System.out.println(strings.count(s, "ABC"));
	}
}

// This is the end of the code

