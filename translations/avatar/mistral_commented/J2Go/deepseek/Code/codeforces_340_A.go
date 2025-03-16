package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int64
	fmt.Scan(&x, &y, &a, &b)

	c := max(x, y)

	if c > b {
		fmt.Println("0")
		return
	}

	j := int64(2)
	for c%min(x, y) != 0 {
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

	if c <= b {
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
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

