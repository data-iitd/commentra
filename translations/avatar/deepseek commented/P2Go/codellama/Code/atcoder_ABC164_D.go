
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	s := os.Args[1]
	l := 2019
	m := make([]int, l)
	m[0] = 1
	a := 0
	r := 0
	for i := len(s) - 1; i >= 0; i-- {
		e := s[i]
		a += int(e-'0') * int(math.Pow(10, float64(i))) % l
		r += m[a%l]
		m[a%l]++
	}
	fmt.Println(r)
}

// 