
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read two integers n and m from input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	// Reverse the integer m and store the result in t
	t := reverse(m)

	// Print the sum of t and n
	fmt.Println(t + n)
}

func reverse(n int) int {
	// If n is a single digit, return n multiplied by 10
	if n < 10 {
		return n * 10
	}

	t := n
	r := 0

	// Loop to reverse the digits of n
	for t > 0 {
		r = (r * 10) + t%10 // Add the last digit of t to r
		t = t / 10          // Remove the last digit from t
	}

	// Return the reversed integer
	return r
}

// END-OF-CODE