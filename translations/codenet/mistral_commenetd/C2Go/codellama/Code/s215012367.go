package main

import "fmt"

func main() {
	var a, b, s int

	fmt.Scanf("%d %d", &a, &b)

	s = (a*b) - (a + b) + 1

	fmt.Printf("%d\n", s)
}

