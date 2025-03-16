// Package main is the entry point of the program
package main

import (
	// Importing necessary packages
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func solve() {
	// Function to solve the problem
	n := getInt() // Read the number of elements in the array
	as := getIntSlice(n) // Read the array elements

	// Initialize an array xs of size n
	xs := make([]int, n)
	// Iterate through the array as and assign the value xs[i]
	for i, a := range as {
		xs[i] = a - i + 1 // Assign the value xs[i] = a - i + 1
	}
	// Sort the array xs in ascending order
	sort.Ints(xs)

	// Assign the middle element of the sorted array xs to variable b
	b := xs[n/2]
	// Initialize variable ans with 0
	ans := 0
	// Iterate through the array xs and calculate the absolute difference between each element and b
	for _, x := range xs {
		ans += abs(x - b) // Calculate the absolute difference and add it to ans
	}
	// Print the answer
	fmt.Fprintln(wr, ans)
}

func abs(n int) int {
	// Function to calculate the absolute difference of a number
	if n < 0 {
		// If the number is negative, return the negative number with the minus sign removed
		return -n
	}
	// If the number is non-negative, return the number itself
	return n
}

// -----------------------------------------

const (
	inf = 1 << 60 // Constant inf is set to 2^60
	// mod = 1000000007 // Constant mod is set to 1000000007
)

var (
	sc = bufio.NewScanner(os.Stdin) // Variable sc is initialized as a new bufio.Scanner with standard input as the source
	wr = bufio.NewWriter(os.Stdout) // Variable wr is initialized as a new bufio.Writer with standard output as the destination
)

func main() {
	// Main function
	maxBufSize := int(1e8) // Set the maximum buffer size to 100,000,000
	sc.Buffer(make([]byte, 4096), maxBufSize) // Set the buffer size for scanner
	sc.Split(bufio.ScanWords)                 // Set the splitting function for scanner
	solve()                                   // Call the solve function
	wr.Flush()                               // Flush the writer buffer
}

func getInt() (ret int) {
	// Function to read an integer from standard input
	sc.Scan() // Read the next token
	ret, err := strconv.Atoi(sc.Text()) // Convert the token to an integer
	if err != nil {
		panic(err) // If there is an error, panic
	}
	return
}

func getIntSlice(n int) (ret []int) {
	// Function to read an array of n integers from standard input
	ret = make([]int, n) // Initialize the array with size n
	for i := range ret {
		ret[i] = getInt() // Read each integer and assign it to the corresponding index in the array
	}
	return
}

func getString() (ret string) {
	// Function to read a string from standard input
	sc.Scan() // Read the next token
	ret = sc.Text() // Assign the token as the string
	return
}

func getRunes() (ret []rune) {
	// Function to read a rune string from standard input
	ret = []rune(getString()) // Convert the string to a rune slice
	return
}
