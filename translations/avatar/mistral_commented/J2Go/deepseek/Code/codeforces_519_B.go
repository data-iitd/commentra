package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Main function is the entry point of the Go application
	// It has no return type and takes no parameters
	// We are using the bufio package to read input from the standard input
	// and the fmt package to write the output to the standard output

	scanner := bufio.NewScanner(os.Stdin)
	// Creating a new Scanner object and initializing it with the standard input stream

	scanner.Scan()
	// Reading the number of test cases (n) from the input using the Scan() method of the Scanner class
	n := 0
	fmt.Sscanf(scanner.Text(), "%d", &n)
	// Scanning the input text to extract the integer value of n

	a, b, c := 0, 0, 0
	// Declaring and initializing three integer variables a, b, and c with zero values

	for i := 0; i < n; i++ {
		scanner.Scan()
		// Reading the next line of input
		val := 0
		fmt.Sscanf(scanner.Text(), "%d", &val)
		// Scanning the input text to extract the integer value of val
		a += val
		// Adding the value of val to the variable 'a'
	}

	for i := 0; i < n-1; i++ {
		scanner.Scan()
		// Reading the next line of input
		val := 0
		fmt.Sscanf(scanner.Text(), "%d", &val)
		// Scanning the input text to extract the integer value of val
		b += val
		// Adding the value of val to the variable 'b'
	}

	for i := 0; i < n-2; i++ {
		scanner.Scan()
		// Reading the next line of input
		val := 0
		fmt.Sscanf(scanner.Text(), "%d", &val)
		// Scanning the input text to extract the integer value of val
		c += val
		// Adding the value of val to the variable 'c'
	}

	x := a - b
	// Calculating the difference between the sum of the first and second number in each test case and storing it in a variable 'x'

	y := b - c
	// Calculating the difference between the sum of the second and third number in each test case and storing it in a variable 'y'

	fmt.Println(x)
	fmt.Println(y)
	// Printing the values of 'x' and 'y' to the standard output using the Println() method of the fmt package
}
