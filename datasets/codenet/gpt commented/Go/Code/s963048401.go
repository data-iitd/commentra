package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Initialize a new scanner to read input from standard input
var sc = bufio.NewScanner(os.Stdin)

// Scanner function reads a line of input and returns it as a string
func Scanner() string {
	sc.Scan()
	return sc.Text()
}

// intScanner function reads an integer from input and returns it
func intScanner() int {
	n, _ := strconv.Atoi(Scanner())
	return n
}

// floatScanner function reads a float64 from input and returns it
func floatScanner() float64 {
	n, _ := strconv.ParseFloat(Scanner(), 64)
	return n
}

// stringToInt converts a string to an integer
func stringToInt(s string) int {
	n, _ := strconv.Atoi(s)
	return n
}

// Declare a variable for the modulus value
var mod int

func main() {
	// Set the modulus value to 1000000007
	mod = 1000000007
	
	// Create a buffer for the scanner with a size limit defined by mod
	buf := make([]byte, 0)
	sc.Buffer(buf, mod)
	
	// Set the scanner to split input by whitespace
	sc.Split(bufio.ScanWords)
	
	// Read the number of elements
	n := intScanner()
	
	// Initialize a slice to hold the integers
	as := make([]int, n)
	
	// Read n integers from input
	for i := 0; i < n; i++ {
		as[i] = intScanner()
	}
	
	// Initialize a slice to hold the unique sorted integers
	xs := []int{as[0]}
	
	// Iterate through the input integers starting from the second element
	for j := 1; j < n; j++ {
		// Use binary search to find the position to insert the current integer
		idx := sort.Search(len(xs), func(i int) bool { return xs[i] < as[j] })
		
		// If the index is equal to the length of xs, append the integer
		if idx == len(xs) {
			xs = append(xs, as[j])
		} else {
			// Otherwise, replace the existing integer at the found index
			xs[idx] = as[j]
		}
	}
	
	// Print the number of unique integers found
	fmt.Println(len(xs))
}
