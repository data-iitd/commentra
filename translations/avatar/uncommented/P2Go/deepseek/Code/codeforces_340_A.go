package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	for a%b != 0 {
		a, b = b, a%b
	}
	return b
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	var x, y, a, b int
	fmt.Scan(&x, &y, &a, &b)
	lcmXY := lcm(x, y)
	result := b/lcmXY - (a-1)/lcmXY
	fmt.Println(result)
}
