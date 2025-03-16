package main

import (
	"fmt"
	"math"
)

func main() {
	var x, y, a, b, j, i, c, x1, y1 int
	var ans bool
	fmt.Scan(&x, &y, &a, &b)
	c = int(math.Max(float64(x), float64(y)))
	if c > b {
		fmt.Println("0")
		ans = false
	}
	for c%int(math.Min(float64(x), float64(y))) != 0 && ans {
		if x > y {
			c = x * j
		} else {
			c = y * j
		}
		j++
		if c > b {
			fmt.Println("0")
			ans = false
			break
		}
	}
	if ans {
		count := 0
		for i = a; i <= b; i++ {
			if i%c == 0 {
				break
			}
		}
		if i != b+1 {
			fmt.Println(((b-i)/c)+1)
		} else {
			fmt.Println("0")
		}
	}
}

