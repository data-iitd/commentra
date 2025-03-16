package main

import (
	"fmt"
	"os"
)

func main() {
	var n int
	fmt.Scan(&n)

	w := make([]int, n)
	var x int
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
		x += w[i]
	}

	var d []int
	for i := 0; i < n; i++ {
		if (x-w[i])/(n-1) == w[i] {
			d = append(d, i+1)
		}
	}

	fmt.Println(len(d))
	for i, v := range d {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(v)
	}
	fmt.Println()
}

// <END-OF-CODE>
