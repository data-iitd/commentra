package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Main method is the entry point of the Go application
	// It has a void return type and a String array as its parameter
	// We are using the Scanner class to read input from the standard input
	// and the PrintWriter class to write the output to the standard output
	// We are also handling IOException to catch any I/O related errors

	sc := bufio.NewScanner(os.Stdin)
	// Creating a new Scanner object and initializing it with the standard input stream

	var n int
	fmt.Scan(&n)
	// Reading the number of test cases (n) from the input using the Scan() method of the Scanner class

	var a, b, c int
	// Declaring and initializing three integer variables a, b, and c with zero values

	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		// Using a for loop to read and sum up the first number in each test case using the Scan() method of the Scanner class
		// and adding it to the variable 'a'
		a += x
	}

	for i := 0; i < n-1; i++ {
		var x int
		fmt.Scan(&x)
		// Using a for loop to read and sum up the second number in each test case (except the last one) using the Scan() method of the Scanner class
		// and adding it to the variable 'b'
		b += x
	}

	for i := 0; i < n-2; i++ {
		var x int
		fmt.Scan(&x)
		// Using a for loop to read and sum up the third number in each test case (except the last two) using the Scan() method of the Scanner class
		// and adding it to the variable 'c'
		c += x
	}

	x := a - b
	// Calculating the difference between the sum of the first and second number in each test case and storing it in a variable 'x'

	y := b - c
	// Calculating the difference between the sum of the second and third number in each test case and storing it in a variable 'y'

	fmt.Println(x)
	fmt.Println(y)
	// Printing the values of 'x' and 'y' to the standard output using the Println() method of the PrintWriter class
}

