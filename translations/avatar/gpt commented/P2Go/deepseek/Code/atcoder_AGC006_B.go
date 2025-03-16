package main

import (
	"fmt"
	"sort"
)

func calc(x []int) int {
	sub := func(y []int, debug bool) []int {
		if debug {
			fmt.Println("D", y)
		}
		for len(y) > 1 {
			y = []int{}
			for i := 0; i < len(y)-2; i++ {
				y = append(y, sort.Ints([]int{y[i], y[i+1], y[i+2]})[1])
			}
			if debug {
				fmt.Println("D", y)
			}
		}
		return y
	}

	y := sub(x, false)

	if y[0] == 2 {
		sub(x, true)
		fmt.Println("=", x)
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

		if X == N*2-2 {
			xs := []int{}
			for i := N - 1; i <= X+1; i++ {
				xs = append(xs, i)
			}
			for i := 1; i <= N-2; i++ {
				xs = append(xs, i)
			}
		} else {
			ys := []int{}
			for i := 1; i <= X-1; i++ {
				ys = append(ys, i)
			}
			for i := X + 3; i <= N*2; i++ {
				ys = append(ys, i)
			}
			xs := []int{}
			xs = append(xs, ys[:N-3]...)
			xs = append(xs, X+2, X-1, X, X+1)
			xs = append(xs, ys[N-3:]...)

			for _, x := range xs {
				fmt.Println(x)
			}
		}
	}
}
