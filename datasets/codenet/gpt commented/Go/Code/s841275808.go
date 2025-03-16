package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"sort"
)

func main() {
	// Create a new scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	
	// Read the number of elements
	N := ScanInt(scanner)
	// Initialize slices to hold the original values and a sorted copy
	X := make([]int, N)
	Y := make([]int, N)
	
	// Read N integers into slice X and copy them to slice Y
	for i := 0; i < N; i++ {
	    X[i] = ScanInt(scanner)
	    Y[i] = X[i]
	}
	
	// Sort the slice Y to find the median values
	sort.Sort(sort.IntSlice(Y))
	// Calculate the two middle values (medians) for even-sized arrays
	m1 := Y[N / 2 - 1] // First median
	m2 := Y[N / 2]     // Second median
	
	// For each element in X, print the appropriate median based on its value
	for i := 0; i < N; i++ {
	    if X[i] <= m1 {
	        fmt.Println(m2) // If X[i] is less than or equal to m1, print m2
	    } else {
	        fmt.Println(m1) // Otherwise, print m1
	    }
	}
}

// ScanInt reads an integer from the scanner and returns it
func ScanInt(scanner *bufio.Scanner) int {
	scanner.Scan() // Read the next token
	i, e := strconv.Atoi(scanner.Text()) // Convert it to an integer
	if e != nil {
		panic(e) // Panic if there is an error in conversion
	}
	return i // Return the integer
}

// ScanFloat64 reads a float64 from the scanner and returns it
func ScanFloat64(scanner *bufio.Scanner) float64 {
	scanner.Scan() // Read the next token
	f, e := strconv.ParseFloat(scanner.Text(), 64) // Convert it to a float64
	if e != nil {
		panic(e) // Panic if there is an error in conversion
	}
	return f // Return the float64
}

// ScanText reads a string from the scanner and returns it
func ScanText(scanner *bufio.Scanner) string {
	scanner.Scan() // Read the next token
	return scanner.Text() // Return the string
}

// Max returns the maximum of two integers
func Max(a, b int) int {
	if a < b {
		return b // Return b if a is less than b
	}
	return a // Otherwise, return a
}

// Min returns the minimum of two integers
func Min(a, b int) int {
	if a > b {
		return b // Return b if a is greater than b
	}
	return a // Otherwise, return a
}

// Abs returns the absolute value of an integer
func Abs(a int) int {
	if a < 0 {
		a *= -1 // If a is negative, multiply by -1 to make it positive
	}
	return a // Return the absolute value
}
