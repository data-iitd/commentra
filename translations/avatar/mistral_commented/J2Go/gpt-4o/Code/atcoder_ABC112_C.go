package main

import (
	"fmt"
	"math"
)

const MAX = 100 // Defining a constant MAX with value 100

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements n from the standard input

	x := make([]int, n)
	y := make([]int, n)
	h := make([]int, n)

	for i := 0; i < n; i++ { // Using a loop to read and initialize the arrays
		fmt.Scan(&x[i], &y[i], &h[i])
	}

	for i := 0; i <= MAX; i++ { // Outer loop to iterate through all possible positions (i, j)
		for j := 0; j <= MAX; j++ { // Inner loop to check all possible positions (i, j)
			ch := check(n, x, y, h, i, j) // Calling the check function to calculate the height of the water at position (i, j)
			if ch > 0 { // If the height is greater than 0, print the position and height
				fmt.Printf("%d %d %d\n", i, j, ch)
			}
		}
	}
}

func check(n int, x, y, h []int, cx, cy int) int { // Function to check the height of water at position (cx, cy)
	ch := -1 // Initializing the height to -1

	for i := 0; i < n; i++ { // Loop to iterate through all elements in the arrays x, y, and h
		if h[i] > 0 { // If the height of the current element is greater than 0
			ch = math.Abs(float64(x[i]-cx)) + math.Abs(float64(y[i]-cy)) + float64(h[i]) // Calculate the distance and height of the current element
			break // Exit the loop once the closest element is found
		}
	}

	for i := 0; i < n; i++ { // Loop to check if all elements have the same height as the closest one
		if h[i] != int(math.Max(float64(ch-math.Abs(float64(x[i]-cx))-math.Abs(float64(y[i]-cy))), 0)) { // If the height is different, return -1 to indicate an error
			return -1
		}
	}

	return int(ch) // Return the height of the water at position (cx, cy)
}

// <END-OF-CODE>
