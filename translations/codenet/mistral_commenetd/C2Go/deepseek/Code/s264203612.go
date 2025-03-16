package main

import (
	"fmt"
)

func main() {
	var r float64
	var s, l float64
	const p = 3.141592653589

	fmt.Scan(&r)

	s = r * r * p
	l = 2 * p * r

	fmt.Printf("%f %f\n", s, l)
}

