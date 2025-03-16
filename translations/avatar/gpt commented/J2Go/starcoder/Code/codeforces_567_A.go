package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Reading the number of elements to be inputted
	var a int
	fmt.Scanf("%d\n", &a)

	// Initializing an array to hold the input integers
	ar := make([]int, a)

	// Variables to hold the maximum and minimum differences
	var max, min int

	// Loop to read integers into the array
	for i := 0; i < a; i++ {
		fmt.Scanf("%d\n", &ar[i])
	}

	// Loop to calculate and print the min and max differences for each element
	for i := 0; i < a; i++ {
		// Calculating the maximum difference from the first and last elements
		max = int(math.Max(float64(ar[i] - ar[0]), float64(ar[len(ar)-1] - ar[i])))

		// Calculating the minimum difference based on the position of the current element
		if i == 0 {
			// If it's the first element, compare with the second element
			min = ar[i+1] - ar[i]
		} else if i == len(ar)-1 {
			// If it's the last element, compare with the second last element
			min = ar[i] - ar[i-1]
		} else {
			// For middle elements, compare with both neighbors
			min = int(math.Min(float64(ar[i] - ar[i-1]), float64(ar[i+1] - ar[i])))
		}

		// Printing the minimum and maximum differences for the current element
		fmt.Printf("%d %d\n", min, max)
	}
}

