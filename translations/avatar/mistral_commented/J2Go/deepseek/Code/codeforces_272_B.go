package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := NewFastReader()
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read the number of test cases
	n := sc.nextInt()

	// Initialize an array 'a' to store the frequency of each number
	a := make([]int, 33)

	// Read each test case and update the frequency of the number in the array 'a'
	for i := 0; i < n; i++ {
		num := sc.nextInt() // Read a number
		index := rec(num)   // Get the index of the number in the array 'a'
		a[index]++          // Increment the frequency of the number in the array 'a'
	}

	// Calculate the answer and print it
	var answer float64
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * float64(a[i] - 1) // Calculate the sum of squares of numbers up to the current number
		answer += summ                                         // Add the sum to the answer
	}
	fmt.Fprintln(out, int64(answer)) // Print the answer as a long integer
}

// A helper method to get the index of a number in the array 'a'
func rec(x int) int {
	answer := 0

	// Calculate the index of the number in the array 'a' by counting the number of set bits in the binary representation of the number
	for k := 31; k >= 0; k-- {
		if (x & (1 << k)) != 0 { // If the k-th bit is set
			answer++ // Increment the answer
		}
	}

	return answer
}

// A custom InputReader class for reading input efficiently
type FastReader struct {
	sc *bufio.Scanner
}

// Initialize the FastReader
func NewFastReader() *FastReader {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	return &FastReader{sc: sc}
}

// Read a string token
func (r *FastReader) next() string {
	r.sc.Scan()
	return r.sc.Text()
}

// Read an integer
func (r *FastReader) nextInt() int {
	num, _ := strconv.Atoi(r.next())
	return num
}

// Read a long integer
func (r *FastReader) nextLong() int64 {
	num, _ := strconv.ParseInt(r.next(), 10, 64)
	return num
}

// Read a double
func (r *FastReader) nextDouble() float64 {
	num, _ := strconv.ParseFloat(r.next(), 64)
	return num
}

// Read a line
func (r *FastReader) nextLine() string {
	bytes, _ := r.sc.Bytes()
	return string(bytes)
}
