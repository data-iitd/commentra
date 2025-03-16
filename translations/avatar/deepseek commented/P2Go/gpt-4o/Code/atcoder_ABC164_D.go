package main

import (
	"fmt"
	"math"
)

func main() {
	var s string
	l := 2019
	fmt.Scan(&s)

	m := make([]int, l+1)
	m[0] = 1
	a, r := 0, 0

	for i := len(s) - 1; i >= 0; i-- {
		e := s[i] - '0' // Convert byte to int
		a += int(e) * int(math.Pow(10, float64(len(s)-1-i))) % l
		r += m[a%l]
		m[a%l]++
	}

	fmt.Println(r)
}

// <END-OF-CODE>
