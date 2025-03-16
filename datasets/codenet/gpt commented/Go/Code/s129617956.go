package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input from the user
	n := nextInt()
	
	// Calculate the integer square root of n
	rt := int(math.Sqrt(float64(n)))
	
	// Initialize a variable to keep track of the minimum number of digits found
	minf := 100
	
	// Loop through all integers from 1 to the square root of n
	for i := 1; i < rt+1; i++ {
		// Check if i is a divisor of n
		if n%i == 0 {
			// Calculate the corresponding divisor b
			b := n / i
			
			// Initialize a counter for the number of digits in b
			ndigit := 0
			
			// Count the number of digits in b
			for b > 0 {
				b /= 10
				ndigit++
			}
			
			// Update minf with the minimum number of digits found
			minf = min(minf, ndigit)
		}
	}
	
	// Print the minimum number of digits found among the divisors
	fmt.Println(minf)
}

// Define a constant for the buffer size
const size = 1000000

// Create a buffered reader with the specified size
var reader = bufio.NewReaderSize(os.Stdin, size)

// Function to read a full line of input
func nextLine() string {
	var line, buffer []byte
	isPrefix := true
	var err error
	
	// Read lines until a complete line is received
	for isPrefix {
		line, isPrefix, err = reader.ReadLine()
		if err != nil {
			panic(err)
		}
		buffer = append(buffer, line...)
	}
	return string(buffer)
}

// Function to read a line of input and split it into a string array
func nextStringArray() []string {
	return strings.Split(nextLine(), " ")
}

// Function to read an integer from input
func nextInt() int {
	n, _ := strconv.Atoi(nextLine())
	return n
}

// Function to read a line of input and convert it into an array of integers
func nextIntArray() []int {
	s := strings.Split(nextLine(), " ")
	n := len(s)
	a := make([]int, n)
	
	// Convert each string in the array to an integer
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(s[i])
	}
	return a
}

// Function to return the minimum of two integers
func min(i, j int) int {
	if i > j {
		return j
	}
	return i
}
