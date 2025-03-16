package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
	}

	x := 0
	for _, value := range w {
		x += value
	}

	d := []int{}
	for i := 0; i < n; i++ {
		if (x-w[i])/(n-1) == w[i] {
			d = append(d, i+1)
		}
	}

	fmt.Println(len(d))
	for i, index := range d {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(index)
	}
	fmt.Println()
}

// <END-OF-CODE>
