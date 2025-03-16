package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}

	c := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&c[i])
	}

	x, y, z := 0, 0, 0
	for _, value := range a {
		x += value
	}
	for _, value := range b {
		y += value
	}
	for _, value := range c {
		z += value
	}

	fmt.Println(int(math.Abs(float64(x - y))))
	fmt.Println(int(math.Abs(float64(y - z))))
}

// <END-OF-CODE>
