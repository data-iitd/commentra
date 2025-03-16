// Importing required packages
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

// Initializing scanner
var sc = bufio.NewScanner(os.Stdin)

// Function to read a line text from stdin and return its string
func NextLine() string {
	// Scanning next line from stdin
	sc.Scan()
	// Returning the scanned line text
	return sc.Text()
}

// Function to read a line text, that consists of ONLY INTEGERS DELIMITED BY SPACES, from stdin
// And then returns integers slice
func NextIntsLine() []int {
	// Initializing empty integers slice
	ints := []int{}
	// Reading a line text from stdin
	intsStr := NextLine()
	// Splitting the line text by space
	tmp := strings.Split(intsStr, " ")
	// Iterating through the split text and converting each string to integer
	// and appending it to the integers slice
	for _, s := range tmp {
		// Converting string to integer
		integer, _ := strconv.Atoi(s)
		// Appending integer to integers slice
		ints = append(ints, integer)
	}
	// Returning the integers slice
	return ints
}

// Function to read a line text, that consists of ONLY CHARACTERS ARRANGED CONTINUOUSLY, from stdin
// And then returns runes slice
func NextRunesLine() []rune {
	// Returning the next line text as runes slice
	return []rune(NextLine())
}

// Function to find the maximum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
func Max(integers ...int) int {
	// Initializing maximum integer as first integer
	m := integers[0]
	// Iterating through the input integers
	for i, integer := range integers {
		// If current integer is greater than maximum integer, update maximum integer
		if i == 0 {
			continue
		}
		if m < integer {
			m = integer
		}
	}
	// Returning the maximum integer
	return m
}

// Function to find the minimum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
func Min(integers ...int) int {
	// Initializing minimum integer as first integer
	m := integers[0]
	// Iterating through the input integers
	for i, integer := range integers {
		// If current integer is smaller than minimum integer, update minimum integer
		if i == 0 {
			continue
		}
		if m > integer {
			m = integer
		}
	}
	// Returning the minimum integer
	return m
}

// Function to calculate integer power
func PowInt(a, e int) int {
	// Checking for negative integers
	if a < 0 || e < 0 {
		panic(errors.New("[argument error]: PowInt does not accept negative integers"))
	}
	// Converting base and exponent to float64
	fa := float64(a)
	fe := float64(e)
	// Calculating the power using math.Pow
	fanswer := math.Pow(fa, fe)
	// Converting the answer back to integer
	return int(fanswer)
}

// Function to calculate absolute value of an integer
func AbsInt(a int) int {
	// Converting integer to float64
	fa := float64(a)
	// Calculating the absolute value using math.Abs
	fanswer := math.Abs(fa)
	// Converting the answer back to integer
	return int(fanswer)
}

// Function to delete an element from a slice
func DeleteElement(s []int, i int) []int {
	// Checking for negative index or empty slice
	if i < 0 || len(s) <= i {
		panic(errors.New("[index error]"))
	}
	// Creating a new slice with zero capacity
	n := make([]int, 0)
	// Appending elements before the index to the new slice
	n = append(n, s[:i]...)
	// Appending elements after the index to the new slice
	n = append(n, s[i+1:]...)
	// Returning the new slice
	return n
}

// Function to concatenate two slices
func Concat(s, t []rune) []rune {
	// Creating a new slice with zero capacity
	n := make([]rune, 0)
	// Appending elements of the first slice to the new slice
	n = append(n, s...)
	// Appending elements of the second slice to the new slice
	n = append(n, t...)
	// Returning the new slice
	return n
}

// Function to sort a slice using sort package
//sort.Sort(sort.IntSlice(s))
//sort.Sort(sort.Reverse(sort.IntSlice(s)))
//sort.Sort(sort.Float64Slice(s))
//sort.Sort(sort.StringSlice(s))

// Function to copy elements from one slice to another
//a = []int{0, 1, 2}
//b = make([]int, len(a))
//copy(b, a)

// Variable declaration and initialization
var x int

// Main function
func main() {
	// Reading integers from stdin as a line text
	tmp := NextIntsLine()
	// Assigning the first integer to variable x
	x = tmp[0]
	// Initializing sum variable as zero
	sum := 0
	// Initializing index variable as one
	i := 1
	// Looping until the sum is greater than or equal to x
	for {
		// Adding current index to sum
		sum += i
		// Checking if sum is greater than or equal to x
		if sum >= x {
			// Breaking the loop
			break
		}
		// Incrementing index
		i++
	}
	// Printing the index
	fmt.Println(i)
}
