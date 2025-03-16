package main

import (
	"fmt"
	"math"
)

func main() {
	var x, y, a, b int64
	fmt.Scan(&x, &y, &a, &b)

	c := int64(math.Max(float64(x), float64(y)))
	if c > b {
		fmt.Println("0")
		return
	}

	j := int64(2)
	for c%int64(math.Min(float64(x), float64(y))) != 0 {
		if x > y {
			c = x * j
		} else {
			c = y * j
		}
		j++
		if c > b {
			fmt.Println("0")
			return
		}
	}

	count := int64(0)
	for i := a; i <= b; i++ {
		if i%c == 0 {
			break
		}
	}
	if i != b+1 {
		fmt.Println((b-i)/c + 1)
	} else {
		fmt.Println("0")
	}
}

