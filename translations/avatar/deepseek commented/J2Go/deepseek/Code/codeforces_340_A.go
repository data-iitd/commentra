package main

import (
	"fmt"
	"math"
)

func main() {
	var x, y, a, b int64
	fmt.Scan(&x, &y, &a, &b)
	
	j := int64(2)
	var c int64 = 0
	ans := true
	
	c = int64(math.Max(float64(x), float64(y)))
	
	if c > b {
		fmt.Println("0")
		ans = false
	}
	
	for c % int64(math.Min(float64(x), float64(y))) != 0 && ans {
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
		var count int64 = 0
		i := a
		for i = a; i <= b; i++ {
			if i % c == 0 {
				break
			}
		}
		if i != b + 1 {
			fmt.Println(((b - i) / c) + 1)
		} else {
			fmt.Println("0")
		}
	}
}
