package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	res := a
	for a >= b {
		res += a / b
		a = (a / b) + (a % b)
	}
	fmt.Println(res)
}

