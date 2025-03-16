package main

import (
	"fmt"
	"sort"
)

func calc(x []int) int {
	sub := func(y []int, debug int) []int {
		if debug == 1 {
			fmt.Println("D", y)
		}
		for len(y) > 1 {
			newY := make([]int, 0)
			for i := 0; i < len(y)-2; i++ {
				// Get the second largest of every three consecutive elements
				triplet := []int{y[i], y[i+1], y[i+2]}
				sort.Ints(triplet)
				newY = append(newY, triplet[1])
			}
			y = newY
			if debug == 1 {
				fmt.Println("D", y)
			}
		}
		return y
	}

	y := sub(x, 0)

	if y[0] == 2 {
		// Placeholder for potential future logic
		sub(x, 1) // Call sub with debug mode on
		fmt.Println("=", x) // Print the original list x
	}

	return y[0]
}

func main() {
	var N, X int
	fmt.Scan(&N, &X)

	if X == 1 || X == N*2-1 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")

		var xs []int
		if X == N*2-2 {
			for i := N - 1; i <= X+1; i++ {
				xs = append(xs, i)
			}
			for i := 1; i < N-1; i++ {
				xs = append(xs, i)
			}
		} else {
			var ys []int
			for i := 1; i < X-1; i++ {
				ys = append(ys, i)
			}
			for i := X + 3; i < N*2; i++ {
				ys = append(ys, i)
			}
			xs = append(xs, ys[:N-3]...)
			xs = append(xs, X+2, X-1, X, X+1)
			xs = append(xs, ys[N-3:]...)
		}

		for _, x := range xs {
			fmt.Println(x)
		}
	}
}

// <END-OF-CODE>
