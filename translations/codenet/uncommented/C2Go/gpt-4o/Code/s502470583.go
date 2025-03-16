package main

import (
	"fmt"
)

func main() {
	var a, b, c, d int
	fmt.Scanf("%d %d", &a, &b)
	c = a * b
	d = 2*a + 2*b
	fmt.Printf("%d %d\n", c, d)
}

// <END-OF-CODE>
