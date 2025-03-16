package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	sc := bufio.NewScanner(os.Stdin) // Initialize scanner for input
	sc.Split(bufio.ScanWords)          // Split input by whitespace

	n := nextInt(sc) // Read the number of elements
	a := make([]int, 33) // Initialize an array to count occurrences of bits set to 1

	// Count the number of bits set to 1 for each input number and store in array a
	for i := 0; i < n; i++ {
		a[rec(nextInt(sc))]++
	}

	answer := 0.0 // Initialize the answer variable

	// Calculate the answer based on the given formula
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]-1)) / 2.0 * float64(a[i]-1)
		answer += summ
	}

	// Print the final answer in the required format
	fmt.Println(int64(answer))
}

// Helper method to count the number of bits set to 1 in a given number
func rec(x int) int {
	answer := 0 // Initialize the count of bits set to 1
	for k := 31; k >= 0; k-- { // Iterate through each bit position
		if (x & (1 << k)) != 0 { // Check if the k-th bit is set to 1
			answer++ // Increment the count if the bit is set
		}
	}
	return answer // Return the count of bits set to 1
}

// Function to read the next integer from the scanner
func nextInt(sc *bufio.Scanner) int {
	sc.Scan() // Read the next token
	var x int
	fmt.Sscan(sc.Text(), &x) // Convert the token to an integer
	return x
}

// <END-OF-CODE>
