package main

import (
	"fmt"
	"math"
)

func main() {
	var s string
	var l int = 2019
	fmt.Scan(&s)

	m := make([]int, l)
	m[0] = 1
	a, r := 0, 0

	for i, e := range s {
		digit := int(e - '0')
		a += digit * int(math.Pow(10, float64(i)))
		r += m[a%l]
		m[a%l]++
	}

	fmt.Println(r)
}

// <END-OF-CODE>
