package main

import (
	"fmt"
)

func main() {
	var t int
	fmt.Scan(&t)
	count := 0
	for i := 0; i < t; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c)
		if a == 1 && b == 1 || a == 1 && c == 1 || b == 1 && c == 1 || a == 1 && b == 1 && c == 1 {
			count++
		}
	}
	fmt.Println(count)
}

