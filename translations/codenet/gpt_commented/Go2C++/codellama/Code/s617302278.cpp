
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// Go:
package main

import (
	"bufio"
	"errors"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Initialize a new scanner for reading input from standard input
var sc = bufio.NewScanner(os.Stdin)

// NextLine reads a line of text from stdin and returns it as a string.
func NextLine() string {
	sc.Scan()
	return sc.Text()
}

// NextIntsLine reads a line of text consisting of integers separated by spaces from stdin.
// It then converts these strings to integers and returns them as a slice of integers.
func NextIntsLine() []int {
	ints := []int{}
	intsStr := NextLine() // Read the line of integers
	tmp := strings.Split(intsStr, " ") // Split the line into individual string components
	for _, s := range tmp {
		integer, _ := strconv.Atoi(s) // Convert each string to an integer
		ints = append(ints, integer) // Append the integer to the slice
	}
	return ints
}

// NextStringsLine reads a line of text consisting of strings separated by spaces from stdin.
// It returns these strings as a slice.
func NextStringsLine() []string {
	strs := []string{}
	stringsStr := NextLine() // Read the line of strings
	tmp := strings.Split(stringsStr, " ") // Split the line into individual string components
	for _, s := range tmp {
		strs = append(strs, s) // Append each string to the slice
	}
	return strs
}

// NextRunesLine reads a line of text consisting of characters arranged continuously from stdin.
// It returns these characters as a slice of runes.
func NextRunesLine() []rune {
	return []rune(NextLine()) // Convert the line to a slice of runes
}

// Max returns the maximum integer from a variable number of input integers.
// This function requires at least one argument, otherwise it will panic.
func Max(integers ...int) int {
	m := integers[0] // Initialize max with the first integer
	for i, integer := range integers {
		if i == 0 {
			continue // Skip the first iteration
		}
		if m < integer {
			m = integer // Update max if a larger integer is found
		}
	}
	return m // Return the maximum integer
}

// Min returns the minimum integer from a variable number of input integers.
// This function requires at least one argument, otherwise it will panic.
func Min(integers ...int) int {
	m := integers[0] // Initialize min with the first integer
	for i, integer := range integers {
		if i == 0 {
			continue // Skip the first iteration
		}
		if m > integer {
			m = integer // Update min if a smaller integer is found
		}
	}
	return m // Return the minimum integer
}

// PowInt calculates the power of an integer base raised to an integer exponent.
// It panics if either argument is negative.
func PowInt(a, e int) int {
	if a < 0 || e < 0 {
		panic(errors.New("[argument error]: PowInt does not accept negative integers"))
	}
	fa := float64(a) // Convert base to float64
	fe := float64(e) // Convert exponent to float64
	fanswer := math.Pow(fa, fe) // Calculate power
	return int(fanswer) // Return the result as an integer
}

// AbsInt returns the absolute value of an integer.
func AbsInt(a int) int {
	fa := float64(a) // Convert integer to float64
	fanswer := math.Abs(fa) // Calculate absolute value
	return int(fanswer) // Return the result as an integer
}

// DeleteElement removes an element at a specified index from a slice of integers.
// It returns a new slice with the element removed.
func DeleteElement(s []int, i int) []int {
	if i < 0 || len(s) <= i {
		panic(errors.New("[index error]")) // Panic if the index is out of bounds
	}
	// Create a new slice with one less element
	n := make([]int, 0, len(s)-1)
	n = append(n, s[:i]...) // Append elements before the index
	n = append(n, s[i+1:]...) // Append elements after the index
	return n // Return the new slice
}

// Concat concatenates two slices of runes and returns a new slice.
func Concat(s, t []rune) []rune {
	n := make([]rune, 0, len(s)+len(t)) // Create a new slice with combined length
	n = append(n, s...) // Append the first slice
	n = append(n, t...) // Append the second slice
	return n // Return the concatenated slice
}

// Main function where the program execution begins
var x int

func main() {
	tmp := NextIntsLine() // Read a line of integers
	x = tmp[0] // Store the first integer in variable x
	i := 1 // Initialize counter
	sum := 0 // Initialize sum
	for {
		sum += i // Incrementally add to sum
		if sum >= x { // Check if sum has reached or exceeded x
			break // Exit the loop if condition is met
		}
		i++ // Increment counter
	}
	fmt.Println(i) // Print the result
}

