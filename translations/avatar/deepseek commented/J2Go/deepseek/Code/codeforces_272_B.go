package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := NewFastReader() // Initialize FastReader to read input
	out := bufio.NewWriter(os.Stdout) // Initialize bufio.Writer to provide output
	defer out.Flush() // Ensure all buffered data is written before exiting
	
	n := sc.nextInt() // Read the number of elements
	a := make([]int, 33) // Initialize an array to count occurrences of bits set to 1
	
	// Count the number of bits set to 1 for each input number and store in array a
	for i := 0; i < n; i++ {
		a[rec(sc.nextInt())]++
	}
	
	answer := 0.0 // Initialize the answer variable
	
	// Calculate the answer based on the given formula
	for i := 0; i < len(a); i++ {
		summ := float64((1 + a[i] - 1) / 2 * (a[i] - 1))
		answer += summ
	}
	
	// Print the final answer in the required format
	fmt.Fprintln(out, int64(answer))
}

// Helper function to count the number of bits set to 1 in a given number
func rec(x int) int {
	answer := 0 // Initialize the count of bits set to 1
	for k := 31; k >= 0; k-- { // Iterate through each bit position
		if (x & (1 << k)) != 0 { // Check if the k-th bit is set to 1
			answer++ // Increment the count if the bit is set
		}
	}
	return answer // Return the count of bits set to 1
}

// FastReader struct for fast input operations
type FastReader struct {
	sc *bufio.Scanner
}

func NewFastReader() *FastReader {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	return &FastReader{sc: sc}
}

func (r *FastReader) nextInt() int {
	r.sc.Scan()
	num, _ := strconv.Atoi(r.sc.Text())
	return num
}

func (r *FastReader) nextFloat() float64 {
	r.sc.Scan()
	num, _ := strconv.ParseFloat(r.sc.Text(), 64)
	return num
}

func (r *FastReader) nextLine() string {
	r.sc.Scan()
	return r.sc.Text()
}

func (r *FastReader) next() string {
	r.sc.Scan()
	return r.sc.Text()
}
