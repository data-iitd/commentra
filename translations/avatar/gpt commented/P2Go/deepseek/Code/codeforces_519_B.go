package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	var a, b, c []int
	for i := 0; i < n; i++ {
		var val int
		fmt.Scan(&val)
		a = append(a, val)
	}
	for i := 0; i < n; i++ {
		var val int
		fmt.Scan(&val)
		b = append(b, val)
	}
	for i := 0; i < n; i++ {
		var val int
		fmt.Scan(&val)
		c = append(c, val)
	}

	var x, y, z int
	for _, i := range a {
		x += i
	}
	for _, i := range b {
		y += i
	}
	for _, i := range c {
		z += i
	}

	fmt.Println(math.Abs(float64(x - y)))
	fmt.Println(math.Abs(float64(y - z)))
}

