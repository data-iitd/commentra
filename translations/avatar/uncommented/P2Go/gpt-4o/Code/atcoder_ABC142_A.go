package main

import (
	"fmt"
)

func nextInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func nextInts() []int {
	var n int
	fmt.Scan(&n)
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&ints[i])
	}
	return ints
}

func main() {
	n := nextInt()
	t := 0
	for i := 0; i < n; i++ {
		if (i+1)&1 == 1 {
			t++
		}
	}
	fmt.Println(float64(t) / float64(n))
}

// <END-OF-CODE>
