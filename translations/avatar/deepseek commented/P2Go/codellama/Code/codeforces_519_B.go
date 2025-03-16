
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	b := make([]int, n)
	c := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&c[i])
	}
	x := 0
	y := 0
	z := 0
	for i := 0; i < n; i++ {
		x += a[i]
	}
	for i := 0; i < n; i++ {
		y += b[i]
	}
	for i := 0; i < n; i++ {
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

