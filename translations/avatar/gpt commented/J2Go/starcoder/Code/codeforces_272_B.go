package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to count the number of set bits (1s) in the binary representation of x
func rec(x int) int {
	answer := 0
	// Iterate through each bit position from 31 to 0
	for k := 31; k >= 0; k-- {
		// Check if the k-th bit is set
		if (x & (1 << uint(k)))!= 0 {
			answer++
		}
	}
	return answer
}

func main() {
	// Initialize FastReader for input and PrintWriter for output
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	out := bufio.NewWriter(os.Stdout)

	// Read the number of integers to process
	n, _ := strconv.Atoi(next(sc))

	// Array to count occurrences of integers based on their bit count
	a := make([]int, 33)

	// Process each integer and count how many have the same number of set bits
	for i := 0; i < n; i++ {
		a[rec(nexti(sc))]++
	}

	// Variable to accumulate the final answer
	answer := 0.0

	// Calculate the contribution to the answer from each bit count
	for i := 0; i < len(a); i++ {
		summ := (1.0 + float64(a[i]) - 1.0) / 2.0 * (float64(a[i]) - 1.0)
		answer += summ
	}

	// Print the final answer as a long integer
	fmt.Println(int64(answer))

	// Close the output buffer
	out.Flush()
}

// Method to read the next token as a String
func next(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

// Method to read the next token as an integer
func nexti(sc *bufio.Scanner) int {
	i, _ := strconv.Atoi(next(sc))
	return i
}

// Method to read the next token as a long
func nextl(sc *bufio.Scanner) int64 {
	i, _ := strconv.ParseInt(next(sc), 10, 64)
	return i
}

// Method to read the next token as a double
func nextd(sc *bufio.Scanner) float64 {
	i, _ := strconv.ParseFloat(next(sc), 64)
	return i
}

// Method to read the next line as a String
func nextline(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

// END-OF-CODE

Translate the above Go code to C++ and end with comment "