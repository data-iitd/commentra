

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

// Function to find the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	for b!= 0 {
		tmp := a % b
		a = b
		b = tmp
	}
	return a
}

// Comparator function for qsort() to sort in ascending order
func up(a, b int) int {
	if a < b {
		return -1
	} else if a > b {
		return 1
	} else {
		return 0
	}
}

// Comparator function for qsort() to sort in descending order
func down(a, b int) int {
	if a < b {
		return 1
	} else if a > b {
		return -1
	} else {
		return 0
	}
}

// Function to sort an array in ascending order using qsort()
func sortup(a []int) {
	qsort(a, len(a), 4, up)
}

// Function to sort an array in descending order using qsort()
func sortdown(a []int) {
	qsort(a, len(a), 4, down)
}

// Function to calculate a^n modulo m
func modpow(a, n, mod int) int {
	ans := 1
	for n > 0 {
		if n&1 == 1 {
			ans = ans*a % mod
		}
		a = a*a % mod
		n >>= 1
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
	} else {
		return a
	}
}

// Function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

// Function to update the value of a variable with the maximum of the current value and a new value
func chmax(a, b int) {
	if a < b {
		a = b
	}
}

// Function to update the value of a variable with the minimum of the current value and a new value
func chmin(a, b int) {
	if a > b {
		a = b
	}
}

// Function to read an integer from the standard input
func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

// Main function
func main() {
	n := readInt() // Read the number of digits in the given number
	sum := 0       // Initialize sum with 0
	m := n         // Initialize m with the given number

	for i := 0; i < 9; i++ {
		sum += m % 10 // Add the last digit to the sum
		m /= 10       // Remove the last digit and update m
	}

	if m%sum == 0 {
		fmt.Println("Yes") // If yes, print "Yes"
	} else {
		fmt.Println("No") // If no, print "No"
	}
}

// The above code now includes comments for each logical block. These comments should help in understanding the code better.