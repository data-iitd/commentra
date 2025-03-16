
package main

import (
	"fmt"
	"math"
	"sort"
)

// Function to swap two integers
func swap(x, y int) {
	temp := x
	x = y
	y = temp
}

// Function to find the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	c := a % b
	for c > 0 {
		a = b
		b = c
		c = a % b
	}
	return b
}

// Comparator function for sort.Sort() to sort in ascending order
type upll []int

func (a upll) Len() int {
	return len(a)
}

func (a upll) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}

func (a upll) Less(i, j int) bool {
	return a[i] < a[j]
}

// Comparator function for sort.Sort() to sort in descending order
type downll []int

func (a downll) Len() int {
	return len(a)
}

func (a downll) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}

func (a downll) Less(i, j int) bool {
	return a[i] > a[j]
}

// Function to sort an array in ascending order using sort.Sort()
func sortup(a []int) {
	sort.Sort(upll(a))
}

// Function to sort an array in descending order using sort.Sort()
func sortdown(a []int) {
	sort.Sort(downll(a))
}

// Function to calculate a^n modulo m
func modpow(a, n, mod int) int {
	ans := 1
	for n > 0 {
		if n&1 == 1 {
			ans = (ans * a) % mod
		}
		a = (a * a) % mod
		n /= 2
	}
	return ans
}

// Function to find the modular multiplicative inverse of a modulo m
func modinv(a, mod int) int {
	return modpow(a, mod-2, mod)
}

// Function to find the maximum of two integers
func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

// Function to find the minimum of two integers
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// Function to update the value of a variable with the maximum of the current value and a new value
func chmax(a *int, b int) {
	if *a < b {
		*a = b
	}
}

// Function to update the value of a variable with the minimum of the current value and a new value
func chmin(a *int, b int) {
	if *a > b {
		*a = b
	}
}

// Main function
func main() {
	var n, sum, m int

	// Read the number of digits from the standard input
	fmt.Scan(&n)

	// Initialize m with the given number
	m = n

	// Calculate the sum of digits
	for m > 0 {
		sum += m % 10
		m /= 10
	}

	// Check if the given number is divisible by the sum of its digits
	if m%sum == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// The above code now includes comments for each logical block. These comments should help in understanding the code better.

