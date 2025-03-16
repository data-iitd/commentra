package main

import (
	"fmt"
)

// Function to calculate (n * 2 + 1) // 3
func calculate(n int) int {
	return (n*2 + 1) / 3
}

// Recursive function to calculate factorial
func factorial(n int) int {
	if n == 0 { // Base case: factorial of 0 is 1
		return 1
	}
	return n * factorial(n-1) // Recursive case
}

// Function to calculate the nth Fibonacci number
func fibonacci(n int) int {
	if n <= 0 { // Return 0 for non-positive input
		return 0
	} else if n == 1 { // Return 1 for input of 1
		return 1
	}
	a, b := 0, 1 // Initialize the first two Fibonacci numbers
	for i := 2; i <= n; i++ { // Loop from 2 to n
		a, b = b, a+b // Update the values of a and b
	}
	return b // Return the nth Fibonacci number
}

func main() {
	var n int
	fmt.Scan(&n) // Take an integer input from the user
	fmt.Println(calculate(n)) // Perform a calculation and print the result

	var number int
	fmt.Scan(&number) // Take an integer input from the user
	result := factorial(number) // Calculate the factorial of the input number
	fmt.Println(result) // Print the result

	var index int
	fmt.Scan(&index) // Take an integer input from the user
	fmt.Println(fibonacci(index)) // Print the nth Fibonacci number
}

// <END-OF-CODE>
