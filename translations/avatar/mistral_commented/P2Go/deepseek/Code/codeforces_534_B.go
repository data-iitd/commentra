package main

import (
	"fmt"
	"strconv"
)

func main() {
	var v1, v2, t, d int
	fmt.Scan(&v1, &v2)
	fmt.Scan(&t, &d)

	a := 1
	v := v1
	distance := 0

	for i := 0; i < t; i++ {
		if v-v2 > (t-i)*d {
			a *= -1
			v = (t-i)*d + v2
		}
		distance += v
		v += a * d
	}

	fmt.Println(distance)
}

