
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to find the greatest common divisor (GCD) of two numbers using Euclid's algorithm
func Euclid(x, y int64) int64 {
	tmp := int64(0) // Variable to store the temporary value

	// Swap x and y if x is smaller than y
	if x < y {
		tmp = x
		x = y
		y = tmp
	}

	// If x is divisible by y, return y as the GCD
	if!(x%y) {
		return y
	}

	// Recursively call Euclid function with y and the remainder of x divided by y
	return Euclid(y, x%y)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var A, B int64
	scanner.Scan()
	A, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	scanner.Scan()
	B, _ = strconv.ParseInt(scanner.Text(), 10, 64)

	// Calculate the product of A and B and print the result divided by their GCD
	fmt.Println((A * B) / Euclid(A, B))
}
