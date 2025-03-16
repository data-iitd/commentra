package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var a int
	var ar []int
	var max, min int

	// Reading the size of the array from the user
	fmt.Print("Enter the size of the array: ")
	fmt.Scan(&a)

	// Initializing the array with the size read from the user
	ar = make([]int, a)

	// Filling the array with integers read from the user
	for i := 0; i < len(ar); i++ {
		fmt.Print("Enter the element at index ", i, ": ")
		fmt.Scan(&ar[i])
	}

	// Calculating the minimum and maximum differences between consecutive elements of the array
	for i := 0; i < len(ar); i++ {
		max = int(math.Max(float64(ar[i]-ar[0]), float64(ar[len(ar)-1]-ar[i]))) // Calculating the maximum difference
		if i == 0 {
			min = ar[i+1] - ar[i] // Calculating the minimum difference for the first element
		} else if i == len(ar)-1 {
			min = ar[i] - ar[i-1] // Calculating the minimum difference for the last element
		} else {
			min = int(math.Min(float64(ar[i]-ar[i-1]), float64(ar[i+1]-ar[i]))) // Calculating the minimum difference for other elements
		}
		fmt.Println(min, max) // Displaying the minimum and maximum differences
	}
}

