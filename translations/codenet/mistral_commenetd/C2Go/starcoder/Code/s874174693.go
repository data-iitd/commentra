
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
	"sort"
)

// Function to swap two integers
func swap(x, y *int) {
	temp := *x // Variable to store the temporary value
	*x = *y   // Assign the value of y to x
	*y = temp // Assign the value of temp (i.e., the original value of x) to y
	return
}

// Function to find the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	c := a % b // Variable to store the remainder

	// Continue the division process until the remainder becomes zero
	for c > 0 {
		a = b
		b = c
		c = a % b
	}

	return a
}

// Comparator function for qsort() to sort in ascending order
<<<<<<< HEAD
func upll(a, b interface{}) int {
	return int(*(a.(*int64)) < *(b.(*int64)))
}

// Comparator function for qsort() to sort in descending order
func downll(a, b interface{}) int {
	return int(*(a.(*int64)) > *(b.(*int64)))
}

// Function to sort an array in ascending order using qsort()
func sortup(a []int64) {
=======
func upll(a, b *int) int {
	return *a < *b
}

// Comparator function for qsort() to sort in descending order
func downll(a, b *int) int {
	return *a > *b
}

// Function to sort an array in ascending order using qsort()
func sortup(a []int) {
>>>>>>> 98c87cb78a (data updated)
	sort.Slice(a, upll)
}

// Function to sort an array in descending order using qsort()
<<<<<<< HEAD
func sortdown(a []int64) {
=======
func sortdown(a []int) {
>>>>>>> 98c87cb78a (data updated)
	sort.Slice(a, downll)
}

// Function to calculate a^n modulo m
<<<<<<< HEAD
func modpow(a, n, m int64) int64 {
	ans := int64(1) // Initialize the answer as 1
=======
func modpow(a, n, m int) int {
	ans := 1 // Initialize the answer as 1
>>>>>>> 98c87cb78a (data updated)
	for n > 0 {
		if n&1 == 1 { // Check if n is odd
			ans = ans*a % m // Multiply the answer with a and take modulo m
		}
		a = a*a % m // Square a and take modulo m
<<<<<<< HEAD
		n >>= 1      // Divide n by 2
=======
		n /= 2      // Divide n by 2
>>>>>>> 98c87cb78a (data updated)
	}
	return ans
}

// Function to find the modular multiplicative inverse of a modulo m
<<<<<<< HEAD
func modinv(a, m int64) int64 {
=======
func modinv(a, m int) int {
>>>>>>> 98c87cb78a (data updated)
	return modpow(a, m-2, m)
}

// Function to find the maximum of two integers
func max(a, b int) int {
	if a < b { // If a is smaller than b
		return b // Return b as the maximum
	}
	return a // Return a as the maximum
}

// Function to find the minimum of two integers
func min(a, b int) int {
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
	return
}

// Function to update the value of a variable with the minimum of the current value and a new value
func chmin(a *int, b int) {
	if *a > b { // If the current value is greater than the new value
		*a = b // Update the current value with the new value
	}
	return
}

// Main function
func main() {
	var n int // Variable to store the number of digits in the given number
<<<<<<< HEAD
	var sum int // Variable to store the sum of digits
	var m int // Variable to store the given number
=======
	var sum, m int // Variable to store the sum of digits and the given number
>>>>>>> 98c87cb78a (data updated)

	// Read the number of digits from the standard input
	fmt.Scanf("%d", &n)

	// Initialize m with the given number
	m = n

	// Calculate the sum of digits
	for i := 0; i < 9; i++ {
		sum += m % 10 // Add the last digit to the sum
		m /= 10        // Remove the last digit and update m
	}

	// Check if the given number is divisible by the sum of its digits
	if m%sum == 0 {
		fmt.Println("Yes") // If yes, print "Yes"
	} else {
		fmt.Println("No") // If no, print "No"
	}
}

// The above code now includes comments for each logical block. These comments should help in understanding the code better.

Translate the above Go code to Python and end with comment "