// Package main contains the main function for solving the problem.
package main

import (
	// bufio package is used for reading input from the standard input.
	"bufio"
	// fmt package is used for printing output to the standard output.
	"fmt"
	// os package is used for reading input from the standard input.
	"os"
	// strconv package is used for converting strings to integers and integers to strings.
	"strconv"
)

// The main function is the entry point of the program.
func main() {
	// Initialize a new Scanner object named 'sc'.
	sc := NewScanner()

	// Read 'n' and 'k' from the standard input.
	n := sc.ReadInt()
	k := sc.ReadInt()

	// Initialize a variable 'total' to store the sum of combinations.
	total := int64(0)

	// Calculate the sum of combinations of 'n' taken 'i' at a time, where 'i' ranges from 'k' to 'n+1'.
	for i := k; i <= n+1; i++ {
		// Calculate the number of combinations using the combi function.
		comb := combi(n, i)
		// Add the number of combinations to the 'total' variable.
		total += comb
		// Apply modulo operation to reduce the size of the number.
		total = total % (Pow64(10, 9) + 7)
	}

	// Print the result to the standard output.
	fmt.Println(total)
}

// The combi function calculates the number of combinations of 'n' taken 'k' at a time using a simplified formula.
func combi(n int, k int) int64 {
	// Calculate the minimum and maximum number of combinations.
	min := int64(k-1) * int64(k) / 2
	max := int64(2*n-k+1) * int64(k) / 2
	// Return the difference between the maximum and minimum number of combinations.
	return max - min + 1
}

// Util functions for performing basic mathematical operations.

// Abs returns the absolute value of a given integer.
func Abs(x int) int {
	// If the number is positive, return the number itself.
	// Otherwise, return the negative of the number.
	if x >= 0 {
		return x
	}
	return -x
}

// Min returns the minimum value among the given integers.
func Min(values ...int) int {
	// Initialize the minimum value with the first integer.
	min := values[0]
	// Compare each integer with the minimum value and update the minimum value if necessary.
	for _, v := range values {
		if v < min {
			min = v
		}
	}
	// Return the minimum value.
	return min
}

// Max returns the maximum value among the given integers.
func Max(values ...int) int {
	// Initialize the maximum value with the first integer.
	max := values[0]
	// Compare each integer with the maximum value and update the maximum value if necessary.
	for _, v := range values {
		if v > max {
			max = v
		}
	}
	// Return the maximum value.
	return max
}

// Pow returns the result of raising the base to the given exponent.
func Pow(base int, exponent uint) int {
	// Initialize the answer with 1.
	answer := 1
	// Multiply the answer with the base for each bit in the exponent.
	for i := uint(0); i < exponent; i++ {
		answer *= base
	}
	// Return the answer.
	return answer
}

// Abs64 returns the absolute value of a given integer64.
func Abs64(x int64) int64 {
	// If the number is positive, return the number itself.
	// Otherwise, return the negative of the number.
	if x >= 0 {
		return x
	}
	return -x
}

// Min64 returns the minimum value among the given integer64s.
func Min64(values ...int64) int64 {
	// Initialize the minimum value with the first integer.
	min := values[0]
	// Compare each integer with the minimum value and update the minimum value if necessary.
	for _, v := range values {
		if v < min {
			min = v
		}
	}
	// Return the minimum value.
	return min
}

// Max64 returns the maximum value among the given integer64s.
func Max64(values ...int64) int64 {
	// Initialize the maximum value with the first integer.
	max := values[0]
	// Compare each integer with the maximum value and update the maximum value if necessary.
	for _, v := range values {
		if v > max {
			max = v
		}
	}
	// Return the maximum value.
	return max
}

// Pow64 returns the result of raising the base to the given exponent.
func Pow64(base int64, exponent uint) int64 {
	// Initialize the answer with 1.
	answer := int64(1)
	// Multiply the answer with the base for each bit in the exponent.
	for i := uint(0); i < exponent; i++ {
		answer *= base
	}
	// Return the answer.
	return answer
}

// Scanner struct is used to read input from the standard input.
type Scanner struct {
	// bufio.Scanner is used to read input from the standard input.
	bufScanner *bufio.Scanner
}

// NewScanner initializes a new Scanner object.
func NewScanner() *Scanner {
	// Initialize a new bufio.Scanner object named 'bufSc'.
	bufSc := bufio.NewScanner(os.Stdin)
	// Set the splitting function of bufio.Scanner to scan words.
	bufSc.Split(bufio.ScanWords)
	// Initialize a new Scanner object named 'sc' with the bufio.Scanner object.
	sc := &Scanner{bufSc}
	// Return the Scanner object.
	return sc
}

// ReadString reads a string from the standard input.
func (sc *Scanner) ReadString() string {
	// Read a word from the standard input using bufio.Scanner.
	bufSc := sc.bufScanner
	bufSc.Scan()
	// Return the read word as a string.
	return bufSc.Text()
}

// ReadInt reads an integer from the standard input.
func (sc *Scanner) ReadInt() int {
	// Read a word from the standard input using bufio.Scanner.
	bufSc := sc.bufScanner
	bufSc.Scan()
	// Convert the read word to an integer using strconv.Atoi.
	num, err := strconv.Atoi(bufSc.Text())
	// If an error occurs, panic with the error message.
	if err != nil {
		panic(err)
	}
	// Return the read integer.
	return num
}

// ReadInt64 reads an integer64 from the standard input.
func (sc *Scanner) ReadInt64() int64 {
	// Read a word from the standard input using bufio.Scanner.
	bufSc := sc.bufScanner
	bufSc.Scan()
	// Convert the read word to an integer64 using strconv.ParseInt.
	num, err := strconv.ParseInt(bufSc.Text(), 10, 64)
	// If an error occurs, panic with the error message.
	if err != nil {
		panic(err)
	}
	// Return the read integer64.
	return num
}
