package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int
	fmt.Scan(&x, &y, &a, &b)
	count := 0
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			if i <= j {
				continue
			}
			count++
		}
	}
	fmt.Println(count)
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			if i <= j {
				continue
			}
			fmt.Println(i, j)
		}
	}
}

