package main

import (
	"fmt"
	"sort"
)

// Read N and X from input
func main() {
	var N, X int
	fmt.Scan(&N, &X)

	// Check if X is 1 or N * 2 - 1, print "No" if true
	if X == 1 || X == 2*N-1 {
		fmt.Println("No")
		return
	}

	// Print "Yes" if X is not 1 or N * 2 - 1
	fmt.Println("Yes")

	// Construct the list xs based on the value of X
	var xs []int
	if X == 2*N-2 {
		xs = append(xs, []int{N-1, N, N+1, N+2}...)
		for i := 1; i < N-2; i++ {
			xs = append(xs, i)
		}
	} else {
		for i := 1; i < X-1; i++ {
			xs = append(xs, i)
		}
		xs = append(xs, X+2, X-1, X, X+1)
		for i := X + 3; i < 2*N; i++ {
			xs = append(xs, i)
		}
	}

	// Print each element of xs
	for _, x := range xs {
		fmt.Println(x)
	}
}
