package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize a new scanner to read input from standard input
var sc = bufio.NewScanner(os.Stdin)

// Function to read the next line of input as a string
func next() string {
	sc.Scan() // Scan the next token
	return sc.Text() // Return the scanned text
}

// Function to read the next line of input as an integer
func nextInt() int {
	sc.Scan() // Scan the next token
	i, _ := strconv.Atoi(sc.Text()) // Convert the scanned text to an integer
	return i // Return the integer value
}

// Function to read the next line of input as a float64
func nextFloat64() float64 {
	f, _ := strconv.ParseFloat(next(), 64) // Parse the next input as a float64
	return f // Return the float64 value
}

// Function to read 'n' integers from input and return them as a slice
func nextInts(n int) []int {
	slice := make([]int, n) // Create a slice to hold 'n' integers
	for i := 0; i < n; i++ {
		slice[i] = nextInt() // Fill the slice with integers from input
	}
	return slice // Return the slice of integers
}

func main() {
	// Set the scanner to split input by whitespace
	sc.Split(bufio.ScanWords)
	
	// Read two integers from input: n (number of elements) and k (some parameter)
	n, k := nextInt(), nextInt()
	
	// Read 'n' integers into slice 'a'
	a := nextInts(n)
	
	// Avoid unused variable error by assigning a value to the first element of 'a'
	a[0] = 0

	// Initialize sum with the value of k and set ans to 1
	sum := k
	ans := 1
	
	// Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
	for sum < n {
		sum = sum - 1 + k // Update sum by subtracting 1 and adding k
		ans++ // Increment the answer counter
	}
	
	// Print the final answer
	fmt.Println(ans)
}
