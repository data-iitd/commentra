package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	var result int
	if a > b {
		result = 2*a - 1
	} else if a == b {
		result = 2 * a
	} else {
		result = 2*b - 1
	}
	fmt.Println(result)
}

