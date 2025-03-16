// +build ignore
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

// I/O
type Scanner struct {
	sc *bufio.Scanner
}

func NewScanner() *Scanner {
	sc := bufio.NewScanner(os.Stdin) // Create a new scanner from standard input
	sc.Split(bufio.ScanWords)         // Set the scanner to split input by words
	sc.Buffer(make([]byte, 10240), int(1e+9)) // Set the buffer size for the scanner
	return &Scanner{sc}               // Return a new Scanner instance
}

// ... (rest of the Scanner methods)

func run(input io.Reader, output io.Writer) int {
	sc := NewScanner() // Initialize a new Scanner

	N := sc.nextInt() // Read the first integer from input

	// ... (empty block for N == 0 case)

	if N < 4 { // Check if N is less than 4
		fmt.Println(0) // Print 0 if N is less than 4
		return 0 // Return 0
	}

	// ... (variable initialization block)

	var nr, nb, ng int // Declare and initialize variables for red, blue, and green balls

	for _, c := range S { // Iterate through each character in the string S
		if c == 'R' { // If the character is 'R'
			nr++ // Increment the nr counter
		}

		if c == 'B' { // If the character is 'B'
			nb++ // Increment the nb counter
		}

		if c == 'G' { // If the character is 'G'
			ng++ // Increment the ng counter
		}
	}

	same := 0 // Initialize a counter for the number of same-colored groups of three balls

	// ... (outer loop block)

	for a := 1; a < N; a++ { // Iterate through each index a from 1 to N-1
		i := 0 // Initialize index i to 0
		j := 1 * a // Initialize index j to a multiplied by 1
		k := 2 * a // Initialize index k to a multiplied by 2

		// ... (inner loop block)

		for k < N { // Iterate through each index k from a*2 to N-1
			// ... (check condition block)

			if S[i] != S[j] && S[i] != S[k] && S[j] != S[k] { // Check if the balls at indices i, j, and k have different colors
				same++ // If so, increment the same counter
			}

			// ... (update indices block)

			i += 1 // Increment index i
			j += 1 // Increment index j
			k += 1 // Increment index k
		}
	}

	tot := nr * nb * ng // Calculate the total number of balls

	// ... (comment out or remove the following lines as they are not used in the final solution)

	// tot := 0 // Initialize a variable for the total number of balls
	// sum := 0 // Initialize a variable for the number of distinct triples
	// sum2 := 0 // Initialize a variable for the number of distinct triples with the same middle index

	// ... (calculate the final result)

	fmt.Println(tot - same) // Print the result, which is the total number of balls minus the number of same-colored groups of three balls

	return 0 // Return 0 to indicate successful execution
}

func main() {
	os.Exit(run(os.Stdin, os.Stdout)) // Run the main function with standard input and output
}

