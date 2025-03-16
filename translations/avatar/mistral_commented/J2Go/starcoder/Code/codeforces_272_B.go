
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// A custom InputReader class for reading input efficiently
type FastReader struct {
	r *bufio.Reader
	s string
}

// Initialize the FastReader
func (f *FastReader) Init() {
	f.r = bufio.NewReader(os.Stdin)
	f.s = ""
}

// Read a string token
func (f *FastReader) next() string {
	if f.s == "" {
		f.s = f.readLine()
	}
	s := f.s
	f.s = ""
	return s
}

// Read an integer
func (f *FastReader) nextInt() int {
	s := f.next()
	i, _ := strconv.Atoi(s)
	return i
}

// Read a long integer
func (f *FastReader) nextLong() int64 {
	s := f.next()
	i, _ := strconv.ParseInt(s, 10, 64)
	return i
}

// Read a double
func (f *FastReader) nextDouble() float64 {
	s := f.next()
	i, _ := strconv.ParseFloat(s, 64)
	return i
}

// Read a line
func (f *FastReader) readLine() string {
	s, _ := f.r.ReadString('\n')
	return strings.TrimRight(s, "\r\n")
}

// A helper method to get the index of a number in the array 'a'
func rec(x int64) int {
	answer := 0

	// Calculate the index of the number in the array 'a' by counting the number of set bits in the binary representation of the number
	for k := 31; k >= 0; k-- {
		if (x & (1 << uint(k)))!= 0 { // If the k-th bit is set
			answer++ // Increment the answer
		}
	}

	return answer
}

// Initialize FastReader for reading input
func main() {
	f := new(FastReader)
	f.Init()

	// Read the number of test cases
	n := f.nextInt()

	// Initialize an array 'a' to store the frequency of each number
	a := make([]int, 33)

	// Read each test case and update the frequency of the number in the array 'a'
	for i := 0; i < n; i++ {
		num := f.nextLong() // Read a number
		index := rec(num)   // Get the index of the number in the array 'a'
		a[index]++          // Increment the frequency of the number in the array 'a'
	}

	// Calculate the answer and print it
	answer := 0.0
	for i := 0; i < len(a); i++ {
		summ := (1.0 + float64(a[i]) - 1.0) / 2.0 * (float64(a[i]) - 1.0) // Calculate the sum of squares of numbers up to the current number
		answer += summ                                                // Add the sum to the answer
	}
	fmt.Println(int64(answer)) // Print the answer as a long integer
}

