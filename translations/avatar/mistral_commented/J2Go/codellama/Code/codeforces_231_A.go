package main

import (
	"fmt"
	"os"
)

func main() {
	var t int
	fmt.Scan(&t)
	var count int
	for t > 0 {
		var a, b, c int
		fmt.Scan(&a, &b, &c)
		if (a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1) {
			count++
		}
		t--
	}
	fmt.Println(count)
}

