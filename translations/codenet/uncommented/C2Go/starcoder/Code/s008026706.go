package main

import "fmt"

func main() {
	var a, b, x, y int
	fmt.Scanf("%d%d", &a, &b)
	x = 2*a + 2*b
	y = a*b
	fmt.Printf("%d %d\n", y, x)
}
