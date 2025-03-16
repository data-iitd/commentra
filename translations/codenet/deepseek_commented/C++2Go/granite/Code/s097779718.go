
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
func Euclid(x, y int64) int64 {
	var tmp int64

	// Ensure x is greater than y
	if x < y {
		tmp = x
		x = y
		y = tmp
	}

	// Base case: if x is divisible by y, return y
	if x%y == 0 {
		return y
	}

	// Recursive case: apply the Euclidean algorithm
	return Euclid(y, x%y)
}

func main() {
	var A, B int64
	scanner := bufio.NewScanner(os.Stdin)

	// Read two integers from standard input
	if scanner.Scan() {
		A, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}
	if scanner.Scan() {
		B, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}

	// Calculate and output the least common multiple (LCM) of A and B
	fmt.Println((A * B) / Euclid(A, B))
}

