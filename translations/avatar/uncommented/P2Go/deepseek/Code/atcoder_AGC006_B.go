package main

import (
	"fmt"
	"sort"
)

func calc(x []int) int {
	sub := func(y []int, debug int) []int {
		if debug > 0 {
			fmt.Println("D", y)
		}
		for len(y) > 1 {
			newY := []int{}
			for i := 0; i < len(y)-2; i++ {
				subSlice := y[i : i+3]
				sort.Ints(subSlice)
				newY = append(newY, subSlice[1])
			}
			y = newY
			if debug > 0 {
				fmt.Println("D", y)
			}
		}
		return y
	}
	y := sub(x, 0)
	if y[0] == 2 {
		sub(x, 1)
		fmt.Println("=", x)
	}
	return y[0]
}

func main() {
	var N, X int
	fmt.Scan(&N, &X)

	if X == 1 || X == N*2-1 {
		fmt.Println("No")
		return
	}

	fmt.Println("Yes")
	xs := []int{}
	if X == N*2-2 {
		xs = append(xs, N-1, N-2, N-3, N-4, 1, 2, 3, 4)
	} else {
		ys := []int{}
		for i := 1; i < X-1; i++ {
			ys = append(ys, i)
		}
		for i := X + 3; i < N*2; i++ {
			ys = append(ys, i)
		}
		xs = append(ys[:N-3], []int{X + 2, X - 1, X, X + 1}...)
		xs = append(xs, ys[N-3:]...)
	}

	for _, x := range xs {
		fmt.Println(x)
	}
}
