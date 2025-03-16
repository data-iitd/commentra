package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	b := make([]int, n)
	c := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.Split(fmt.Sscanln(), " ")[i])
		b[i], _ = strconv.Atoi(strings.Split(fmt.Sscanln(), " ")[i])
		c[i], _ = strconv.Atoi(strings.Split(fmt.Sscanln(), " ")[i])
	}
	x := 0
	y := 0
	z := 0
	for i := 0; i < n; i++ {
		x += a[i]
		y += b[i]
		z += c[i]
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

