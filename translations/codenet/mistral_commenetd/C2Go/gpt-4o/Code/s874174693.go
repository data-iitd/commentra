package main

import (
	"fmt"
)

// Function to swap two integers
func swap(x, y *int) {
	temp := *x // Store the value of x in temp
	*x = *y    // Assign the value of y to x
	*y = temp  // Assign the value of temp (i.e., the original value of x) to y
}

// Function to find the greatest common divisor (GCD) of two numbers
func gcd(a, b int64) int64 {
	var c int64 // Variable to store the remainder

	// Continue the division process until the remainder becomes zero
	for b > 0 {
		c = a % b // Calculate the remainder
		a = b     // Update a with the value of b
		b = c     // Update b with the value of the previous remainder
	}

	return a // Return the GCD (i.e., the last non-zero value of a)
}

// Comparator function for sorting in ascending order
func upll(a, b *int64) int {
	if *a < *b {
		return -1
	} else if *a > *b {
		return 1
	}
	return 0
}

// Comparator function for sorting in descending order
func downll(a, b *int64) int {
	if *a < *b {
		return 1
	} else if *a > *b {
		return -1
	}
	return 0
}

// Function to sort an array in ascending order
func sortup(arr []int64) {
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})
}

// Function to sort an array in descending order
func sortdown(arr []int64) {
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] > arr[j]
	})
}

// Function to calculate a^n modulo m
func modpow(a, n, mod int64) int64 {
	ans := int64(1) // Initialize the answer as 1
	for n > 0 {
		if n&1 == 1 { // Check if n is odd
			ans = ans * a % mod // Multiply the answer with a and take modulo m
		}
		a = a * a % mod // Square a and take modulo m
		n /= 2         // Divide n by 2
	}
	return ans // Return the final answer
}

// Function to find the modular multiplicative inverse of a modulo m
func modinv(a, mod int64) int64 {
	return modpow(a, mod-2, mod)
}

// Function to find the maximum of two integers
func max(a, b int) int {
	if a < b {
		return b // Return b as the maximum
	}
	return a // Return a as the maximum
}

// Function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
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
	var sum int // Variable to store the sum of digits
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
	if n%sum == 0 {
		fmt.Println("Yes") // If yes, print "Yes"
	} else {
		fmt.Println("No") // If no, print "No"
	}
}

// <END-OF-CODE>
