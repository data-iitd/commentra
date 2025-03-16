package main

import (
	"fmt"
	"math"
	"os"
)

const mod = 1_000_000_007

// Function to read an integer from standard input
func readInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

// Function to read a list of integers from standard input
func readIntSlice() []int {
	var n int
	fmt.Scan(&n)
	slice := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&slice[i])
	}
	return slice
}

// Function to determine the sign of a number
func mySign(x int) int {
	if x > 0 {
		return 1
	} else if x < 0 {
		return -1
	}
	return 0
}

func main() {
	N := readInt()
	a := readIntSlice()
	maxVal := 0
	maxSign := 0
	maxIndex := -1

	// Iterate through the list 'a' to find the maximum absolute value and its sign
	for i, a0 := range a {
		if abs(a0) > maxVal {
			maxVal = abs(a0)
			maxSign = mySign(a0)
			maxIndex = i
		}
	}

	// Determine the output based on the sign of the maximum value
	if maxSign == 0 {
		// If the maximum value is zero, print zero
		fmt.Println(0)
	} else {
		// If the maximum value is positive or negative, print the required output
		fmt.Println(2*N - 1)
		fmt.Println(maxIndex+1, 1)
		if maxSign == 1 {
			// Print the indices of the other elements in pairs
			for i := 1; i < N; i++ {
				fmt.Println(i+1, i+2)
			}
		} else {
			// Print the indices of the other elements in reverse order
			for i := N - 1; i > 0; i-- {
				fmt.Println(i+1, i)
			}
		}
	}
}

// Function to return the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// <END-OF-CODE>
