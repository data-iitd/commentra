package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize a new scanner to read input from standard input
var sc = bufio.NewScanner(os.Stdin)

// Function to read an integer from input
func readInt() int {
	sc.Scan() // Read the next token from input
	i, err := strconv.Atoi(sc.Text()) // Convert the token to an integer
	if err != nil {
		panic(err) // Panic if there is an error in conversion
	}
	return i // Return the integer value
}

// Function to read a float64 from input
func readFloat64() float64 {
	sc.Scan() // Read the next token from input
	f, err := strconv.ParseFloat(sc.Text(), 64) // Convert the token to a float64
	if err != nil {
		panic(err) // Panic if there is an error in conversion
	}
	return f // Return the float64 value
}

// Function to read a string from input
func readString() string {
	sc.Scan() // Read the next token from input
	return sc.Text() // Return the string value
}

func main() {
	// Set the scanner to split input by whitespace
	sc.Split(bufio.ScanWords)

	// Read two integers n and m from input
	n, m := readInt(), readInt()

	// Initialize a slice to hold m integers
	a := make([]int, n)

	// Initialize a variable to hold the sum of the integers read
	sum := 0

	// Read m integers from input and calculate their sum
	for i := 0; i < m; i++ {
		a[i] = readInt() // Read an integer and store it in the slice
		sum += a[i] // Add the integer to the sum
	}

	// Check if the sum of the integers exceeds n
	if sum > n {
		fmt.Println("-1") // Print -1 if the sum is greater than n
		return // Exit the function
	}

	// Print the difference between n and the sum of the integers
	fmt.Println(n - sum)
}
