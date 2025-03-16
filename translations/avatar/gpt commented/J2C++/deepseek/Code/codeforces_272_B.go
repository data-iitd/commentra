package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize FastReader for input and PrintWriter for output
	sc := NewFastReader()
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read the number of integers to process
	n := sc.nextInt()

	// Array to count occurrences of integers based on their bit count
	a := make([]int, 33)

	// Process each integer and count how many have the same number of set bits
	for i := 0; i < n; i++ {
		a[rec(sc.nextInt())]++
	}

	// Variable to accumulate the final answer
	var answer float64 = 0

	// Calculate the contribution to the answer from each bit count
	for i := 0; i < len(a); i++ {
		summ := float64((1 + a[i] - 1) * (a[i] - 1)) / 2.0
		answer += summ
	}

	// Print the final answer as a long integer
	fmt.Fprintln(out, int64(answer))
}

// Method to count the number of set bits (1s) in the binary representation of x
func rec(x int) int {
	answer := 0
	// Iterate through each bit position from 31 to 0
	for k := 31; k >= 0; k-- {
		// Check if the k-th bit is set
		if x&(1<<k) != 0 {
			answer++
		}
	}
	return answer
}

// FastReader class for efficient input reading
type FastReader struct {
	sc *bufio.Scanner
}

// Constructor to initialize BufferedReader
func NewFastReader() *FastReader {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	return &FastReader{sc: sc}
}

// Method to read the next token as a String
func (r *FastReader) next() string {
	r.sc.Scan()
	return r.sc.Text()
}

// Method to read the next token as an integer
func (r *FastReader) nextInt() int {
	num, _ := strconv.Atoi(r.next())
	return num
}

// Method to read the next token as a long
func (r *FastReader) nextLong() int64 {
	num, _ := strconv.ParseInt(r.next(), 10, 64)
	return num
}

// Method to read the next token as a double
func (r *FastReader) nextDouble() float64 {
	num, _ := strconv.ParseFloat(r.next(), 64)
	return num
}

// Method to read the next line as a String
func (r *FastReader) nextLine() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

