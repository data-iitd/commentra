package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize a new scanner to read input from standard input
var sc = bufio.NewScanner(os.Stdin)

// next reads the next line of input and returns it as a string
func next() string {
	sc.Scan() // Scan the next token
	return sc.Text() // Return the scanned text
}

// nextInt reads the next line of input, converts it to an integer, and returns it
func nextInt() int {
	sc.Scan() // Scan the next token
	i, _ := strconv.Atoi(sc.Text()) // Convert the scanned text to an integer
	return i // Return the integer value
}

// nextFloat64 reads the next line of input, converts it to a float64, and returns it
func nextFloat64() float64 {
	f, _ := strconv.ParseFloat(next(), 64) // Convert the scanned text to a float64
	return f // Return the float64 value
}

// nextInts reads 'n' integers from input and returns them as a slice
func nextInts(n int) []int {
	slice := make([]int, n) // Create a slice to hold 'n' integers
	for i := 0; i < n; i++ { // Loop 'n' times to read integers
		slice[i] = nextInt() // Read each integer and store it in the slice
	}
	return slice // Return the slice of integers
}

func main() {
	sc.Split(bufio.ScanWords) // Set the scanner to split input by words
	// Read two integers, sum them, and compare the result with a third integer
	if nextInt()+nextInt() >= nextInt() {
		fmt.Println("Yes") // Print "Yes" if the sum is greater than or equal to the third integer
	} else {
		fmt.Println("No") // Print "No" otherwise
	}
}
