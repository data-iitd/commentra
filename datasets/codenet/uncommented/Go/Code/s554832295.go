package main

import "fmt"

func main() {
	var x1, y1, x2, y2 int
	fmt.Scan(&x1, &y1, &x2, &y2)

	a := x2 - x1
	b := y2 - y1

	x3 := x2 - b
	y3 := y2 + a
	x4 := x1 - b
	y4 := y1 + a

	fmt.Println(x3, y3, x4, y4)
}
