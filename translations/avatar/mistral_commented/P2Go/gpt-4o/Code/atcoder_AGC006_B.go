package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, X int
	fmt.Scan(&N, &X)
	// Read input values N and X from the standard input

	if X == 1 || X == N*2-1 {
		fmt.Println("No")
		// If X is equal to 1 or N*2-1, print "No"
	} else {
		fmt.Println("Yes")
		// Else, X is neither 1 nor N*2-1

		var xs []int
		if X == N*2-2 {
			for i := N - 1; i <= X+1; i++ {
				xs = append(xs, i)
			}
			for i := 1; i < N-1; i++ {
				xs = append(xs, i)
			}
		} else {
			for i := 1; i < X-1; i++ {
				xs = append(xs, i)
			}
			for i := X + 3; i < N*2; i++ {
				xs = append(xs, i)
			}
			ys := xs[:N-3]
			xs = append(ys, X+2, X-1, X, X+1)
			xs = append(xs, ys[N-3:]...)
		}
		// Calculate the list xs based on the value of X

		for _, x := range xs {
			fmt.Println(x)
		}
		// Print each element of the list xs
	}
}

// Define a function calc that takes an integer x as an argument
func calc(x int) int {
	y := sub(x)
	if y[0] == 2 {
		sub(x)
		fmt.Println("=", x)
	}
	return y[0]
}

// Define a nested function sub that takes an integer y and an optional debug argument
func sub(y []int) []int {
	for len(y) > 1 {
		newY := make([]int, 0)
		for i := 0; i < len(y)-2; i++ {
			triplet := []int{y[i], y[i+1], y[i+2]}
			sort.Ints(triplet)
			newY = append(newY, triplet[1])
		}
		y = newY
	}
	return y
}

// Note: The calc and sub functions are not called in the main function.
// They are included here for completeness based on the original Python code.

