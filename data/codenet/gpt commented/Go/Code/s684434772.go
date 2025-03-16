package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize a new scanner for reading input
	sc := NewScanner()

	// Read two integers n and k from input
	n := sc.ReadInt()
	k := sc.ReadInt()

	// Initialize a variable to hold the total count
	total := int64(0)

	// Calculate the total combinations from k to n+1
	for i := k; i <= n+1; i++ {
		total += combi(n, i) // Add combinations for the current i
		total = total % (Pow64(10, 9) + 7) // Apply modulo to prevent overflow
	}

	// Print the final total
	fmt.Println(total)
}

// combi calculates the number of combinations based on the given n and k
func combi(n int, k int) int64 {
	// Calculate the minimum and maximum possible values for combinations
	min := int64(k-1) * int64(k) / 2
	max := int64(2*n-k+1) * int64(k) / 2
	// Return the count of combinations
	return max - min + 1
}

// util
// *   math/simple

// Abs returns the absolute value of an integer
func Abs(x int) int {
	if x >= 0 {
		return x
	}
	return -x
}

// Min returns the minimum value from a list of integers
func Min(values ...int) int {
	if len(values) == 0 {
		panic("no values")
	}
	min := values[0]
	for _, v := range values {
		if v < min {
			min = v
		}
	}
	return min
}

// Max returns the maximum value from a list of integers
func Max(values ...int) int {
	if len(values) == 0 {
		panic("no values")
	}
	max := values[0]
	for _, v := range values {
		if v > max {
			max = v
		}
	}
	return max
}

// Pow calculates the power of a base raised to an exponent
func Pow(base int, exponent uint) int {
	answer := 1
	for i := uint(0); i < exponent; i++ {
		answer *= base
	}
	return answer
}

// Abs64 returns the absolute value of an int64
func Abs64(x int64) int64 {
	if x >= 0 {
		return x
	}
	return -x
}

// Min64 returns the minimum value from a list of int64 values
func Min64(values ...int64) int64 {
	if len(values) == 0 {
		panic("no values")
	}
	min := values[0]
	for _, v := range values {
		if v < min {
			min = v
		}
	}
	return min
}

// Max64 returns the maximum value from a list of int64 values
func Max64(values ...int64) int64 {
	if len(values) == 0 {
		panic("no values")
	}
	max := values[0]
	for _, v := range values {
		if v > max {
			max = v
		}
	}
	return max
}

// Pow64 calculates the power of a base (int64) raised to an exponent
func Pow64(base int64, exponent uint) int64 {
	answer := int64(1)
	for i := uint(0); i < exponent; i++ {
		answer *= base
	}
	return answer
}

// *   io

// Scanner is a custom input scanner that reads words from standard input
type Scanner struct {
	bufScanner *bufio.Scanner
}

// NewScanner initializes a new Scanner instance
func NewScanner() *Scanner {
	bufSc := bufio.NewScanner(os.Stdin)
	bufSc.Split(bufio.ScanWords) // Split input by words
	return &Scanner{bufSc}
}

// ReadString reads a single string from input
func (sc *Scanner) ReadString() string {
	bufSc := sc.bufScanner
	bufSc.Scan() // Scan the next word
	return bufSc.Text() // Return the scanned text
}

// ReadInt reads a single integer from input
func (sc *Scanner) ReadInt() int {
	bufSc := sc.bufScanner
	bufSc.Scan() // Scan the next word
	text := bufSc.Text()

	// Convert the scanned text to an integer
	num, err := strconv.Atoi(text)
	if err != nil {
		panic(err) // Panic if conversion fails
	}
	return num
}

// ReadInt64 reads a single int64 from input
func (sc *Scanner) ReadInt64() int64 {
	bufSc := sc.bufScanner
	bufSc.Scan() // Scan the next word
	text := bufSc.Text()

	// Convert the scanned text to an int64
	num, err := strconv.ParseInt(text, 10, 64)
	if err != nil {
		panic(err) // Panic if conversion fails
	}
	return num
}
