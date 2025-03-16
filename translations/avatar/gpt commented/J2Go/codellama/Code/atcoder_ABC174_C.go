
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// BufferedReader for efficient input reading
	br := bufio.NewReader(os.Stdin)
	// PrintWriter for efficient output writing
	pw := bufio.NewWriter(os.Stdout)
	// StringTokenizer for efficient string tokenization
	st := strings.Split(br.ReadString('\n'), " ")

	// Method to read an integer from input
	readInt := func() int {
		// Ensure that the tokenizer has tokens to read
		for len(st) == 0 {
			st = strings.Split(br.ReadString('\n'), " ")
		}
		// Parse and return the next integer token
		i, _ := strconv.Atoi(st[0])
		st = st[1:]
		return i
	}

	// Method to solve the main logic of the problem
	solve := func() int {
		// Read the integer K from input
		K := readInt()

		// Check if K is even or divisible by 5, return -1 if true
		if K%2 == 0 || K%5 == 0 {
			return -1
		}

		// If K is divisible by 7, divide it by 7
		if K%7 == 0 {
			K /= 7
		}

		// Multiply K by 9 as part of the calculation
		K *= 9

		// Initialize the answer counter
		ans := 1

		// Calculate the remainder of 10 divided by K
		remainder := 10 % K

		// Loop until the remainder is 1
		for remainder != 1 {
			// Increment the answer counter
			ans++
			// Update the remainder for the next iteration
			remainder = remainder*10 % K
		}

		// Return the final answer
		return ans
	}

	// Solve the problem and print the result
	fmt.Fprintln(pw, solve())
	// Close the PrintWriter to flush the output
	pw.Flush()
}

