package main

import (
	"fmt"
)

func main() {
	var x1, x2, y1, y2 int64
	fmt.Scan(&x1, &y1, &x2, &y2)

	dx := x2 - x1
	dy := y2 - y1

	x3 := x2 - dy
	y3 := y2 + dx
	x4 := x1 - dy
	y4 := y1 + dx

	fmt.Println(x3, y3, x4, y4)
}

