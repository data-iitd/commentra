package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	var a, b, c []int
	input := ""
	for i := 0; i < n; i++ {
		fmt.Scan(&input)
		val, _ := strconv.Atoi(input)
		a = append(a, val)
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&input)
		val, _ := strconv.Atoi(input)
		b = append(b, val)
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&input)
		val, _ := strconv.Atoi(input)
		c = append(c, val)
	}

	x, y, z := 0, 0, 0
	for _, i := range a {
		x += i
	}
	for _, i := range b {
		y += i
	}
	for _, i := range c {
		z += i
	}

	fmt.Println(abs(x - y))
	fmt.Println(abs(y - z))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

