package main

import (
	"fmt"
)

// Function to swap two integers
func swap(x *int, y *int) {
	temp := *x // Store the value of x in temp
	*x = *y    // Assign the value of y to x
	*y = temp  // Assign the value of temp (i.e., the original value of x) to y
}

// Function to find the greatest common divisor (GCD) of two numbers
func gcd(a int, b int) int {
	var c int // Variable to store the remainder

	// Continue the division process until the remainder becomes zero
	for b > 0 {
		c = a % b // Calculate the remainder
		a = b     // Update a with the value of b
		b = c     // Update b with the value of the previous remainder
	}

	return a // Return the GCD (i.e., the last non-zero value of a)
}

// Comparator function for sort.Slice() to sort in ascending order
func upll(a, b interface{}) bool {
	return a.(int) < b.(int)
}

// Comparator function for sort.Slice() to sort in descending order
func downll(a, b interface{}) bool {
	return a.(int) > b.(int)
}

// Function to sort an array in ascending order using sort.Slice()
func sortup(a []int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

// Function to sort an array in descending order using sort.Slice()
func sortdown(a []int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
}

// Function to calculate a^n modulo m
func modpow(a int, n int, mod int) int {
	ans := 1 // Initialize the answer as 1
	for n > 0 {
		if n & 1 == 1 { // Check if n is odd
			ans = ans * a % mod // Multiply the answer with a and take modulo m
		}
		a = a * a % mod // Square a and take modulo m
		n /= 2          // Divide n by 2
	}
	return ans // Return the final answer
}

// Function to find the modular multiplicative inverse of a modulo m
func modinv(a int, mod int) int {
	return modpow(a, mod-2, mod)
}

// Function to find the maximum of two integers
func max(a int, b int) int {
	if a < b { // If a is smaller than b
		return b // Return b as the maximum
	}
	return a // Return a as the maximum
}

// Function to find the minimum of two integers
func min(a int, b int) int {
	if a < b { // If a is smaller than b
		return a // Return a as the minimum
	}
	return b // Return b as the minimum
}

// Function to update the value of a variable with the maximum of the current value and a new value
func chmax(a *int, b int) {
	if *a < b { // If the current value is smaller than the new value
		*a = b // Update the current value with the new value
	}
}

// Function to update the value of a variable with the minimum of the current value and a new value
func chmin(a *int, b int) {
	if *a > b { // If the current value is greater than the new value
		*a = b // Update the current value with the new value
	}
}

// Main function
func main() {
	var n int // Variable to store the number of digits in the given number
	var sum int = 0 // Variable to store the sum of digits
	var m int // Variable to store the given number

	// Read the number of digits from the standard input
	fmt.Scan(&n)

	// Initialize m with the given number
	m = n

	// Calculate the sum of digits
	for i := 0; i < 9; i++ {
		sum += m % 10 // Add the last digit to the sum
		m /= 10       // Remove the last digit and update m
	}

	// Check if the given number is divisible by the sum of its digits
	if m % sum == 0 {
		fmt.Println("Yes") // If yes, print "Yes"
	} else {
		fmt.Println("No") // If no, print "No"
	}
}

