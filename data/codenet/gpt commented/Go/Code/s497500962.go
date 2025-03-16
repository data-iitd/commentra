package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Read the values for R, G, B, and N from standard input
	R := nextInt() // Number of red items
	G := nextInt() // Number of green items
	B := nextInt() // Number of blue items
	N := nextInt() // Total number of items to choose

	var ans int // Variable to store the count of valid combinations

	// Iterate over possible counts of red items (x)
	for x := 0; x <= N; x++ {
		// Iterate over possible counts of green items (y)
		for y := 0; y <= N; y++ {
			// Calculate the remaining items after choosing x red and y green
			tmp := N - R*x - G*y
			// Check if the remaining items can be fully represented by blue items
			if tmp >= 0 && tmp%B == 0 {
				ans++ // Increment the count of valid combinations
			}
		}
	}

	// Output the total count of valid combinations
	fmt.Println(ans)
}

// Input. ----------

// Initialize a scanner for reading input
var sc = bufio.NewScanner(os.Stdin)

func init() {
	// Set the buffer size and split method for the scanner
	sc.Buffer([]byte{}, math.MaxInt64)
	sc.Split(bufio.ScanWords)
}

// Function to read the next integer from input
func nextInt() int {
	sc.Scan() // Read the next token
	i, err := strconv.Atoi(sc.Text()) // Convert the token to an integer
	if err != nil {
		panic(err) // Panic if conversion fails
	}

	return i // Return the integer value
}

// Function to read the next float from input
func nextFloat() float64 {
	sc.Scan() // Read the next token
	f64, err := strconv.ParseFloat(sc.Text(), 64) // Convert the token to a float
	if err != nil {
		panic(err) // Panic if conversion fails
	}

	return f64 // Return the float value
}

// Function to read the next string from input
func nextString() string {
	sc.Scan() // Read the next token
	if err := sc.Err(); err != nil {
		panic(err) // Panic if an error occurs during scanning
	}

	return sc.Text() // Return the string value
}

// ---------- Input.

// Util. ----------

// Function to compute the absolute value of an integer
func abs(x int) int {
	return int(math.Abs(float64(x))) // Return the absolute value
}

// Function to compute the minimum of two integers
func min(x, y int) int {
	return int(math.Min(float64(x), float64(y))) // Return the minimum value
}

// Function to compute the maximum of two integers
func max(x, y int) int {
	return int(math.Max(float64(x), float64(y))) // Return the maximum value
}

// ---------- Util.
