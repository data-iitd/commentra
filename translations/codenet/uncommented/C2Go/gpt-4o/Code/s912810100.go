package main

import (
	"fmt"
)

func main() {
	var a, b int

	fmt.Scanf("%d%d", &a, &b)

	x := a * b
	y := (a + b) * 2

	fmt.Printf("%d %d\n", x, y)
}

// <END-OF-CODE>
