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

	var a, r int

	for i := len(s) - 1; i >= 0; i-- {
		e := s[i]
		a += int(e-'0') * int(math.Pow(10, float64(len(s)-1-i))) % l
		m[a%l]++
		r += m[a%l]
	}

	fmt.Println(r)
}

