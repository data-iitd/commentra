package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int64
	fmt.Scan(&x, &y, &a, &b)

	var j int64 = 2
	var c int64 = 0
	ans := true
	c = max(x, y)

	if c > b {
		fmt.Println("0")
		ans = false
	}

	for c%min(x, y) != 0 && ans {
		if x > y {
			c = x * j
			j++
		} else {
			c = y * j
			j++
		}
		if c > b {
			fmt.Println("0")
			ans = false
			break
		}
	}

	if ans {
		var count int64 = 0
		i := a
		for i <= b {
			if i%c == 0 {
				break
			}
			i++
		}
		if i != b+1 {
			fmt.Println((b - i) / c + 1)
		} else {
			fmt.Println("0")
		}
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
