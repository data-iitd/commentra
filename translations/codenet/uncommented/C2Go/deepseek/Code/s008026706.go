package main

import "fmt"

func main() {
	var a, b, x, y int
	fmt.Scan(&a, &b)
	x = 2*a + 2*b
	y = a * b
	fmt.Println(y, x)
}

