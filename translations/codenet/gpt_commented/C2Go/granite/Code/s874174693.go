
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to swap two integers
func swap(x, y *int) {
	*x, *y = *y, *x
}

// Function to compute the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

// Comparison function for sorting in ascending order
func up(a, b int) bool {
	return a < b
}

// Comparison function for sorting in descending order
func down(a, b int) bool {
	return a > b
}

// Function to sort an array in ascending order
func sortup(a []int) {
	for i := 0; i < len(a); i++ {
		for j := i + 1; j < len(a); j++ {
			if up(a[i], a[j]) {
				swap(&a[i], &a[j])
			}
		}
	}
}

// Function to sort an array in descending order
func sortdown(a []int) {
	for i := 0; i < len(a); i++ {
		for j := i + 1; j < len(a); j++ {
			if down(a[i], a[j]) {
				swap(&a[i], &a[j])
			}
		}
	}
}

// Function to compute modular exponentiation
func modpow(a, n, mod int) int {
	ans := 1
	for n > 0 {
		if n&1 == 1 { // If n is odd
			ans = ans * a % mod // Multiply the base with the result
		}
		a = a * a % mod // Square the base
		n /= 2 // Divide n by 2
	}
	return ans // Return the result
}

// Function to compute modular inverse using Fermat's little theorem
func modinv(a, mod int) int {
	return modpow(a, mod-2, mod) // a^(mod-2) mod mod
}

// Function to return the maximum of two integers
func max(a, b int) int {
	if a < b {
		return b // Return b if a is less than b
	} else {
		return a // Otherwise return a
	}
}

// Function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a // Return a if it is less than b
	} else {
		return b // Otherwise return b
	}
}

// Function to update the value of a if b is greater
func chmax(a, b int) {
	if a < b {
		a = b // Update a to b if b is greater
	}
}

// Function to update the value of a if b is smaller
func chmin(a, b int) {
	if a > b {
		a = b // Update a to b if b is smaller
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	sum := 0 // Initialize sum to 0
	m := n // Store the original value of n
	for i := 0; i < 9; i++ {
		sum += n % 10 // Add the last digit to sum
		n /= 10 // Remove the last digit
	}
	if m%sum == 0 {
		fmt.Println("Yes") // Print "Yes" if divisible
	} else {
		fmt.Println("No") // Print "No" if not divisible
	}
}

