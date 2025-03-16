package main

import (
	"fmt"
	"math"
)

func power(a int) int {
	res := 0
	for a > 0 {
		res++
		a /= 10
	}
	return res
}

func mult(a int) int {
	pow := power(a)
	max := 0
	for j := 0; j < pow; j++ {
		max = max*10 + 9
	}
	return a * (max - a)
}

func main() {
	var l, r int
	fmt.Scan(&l, &r)
	res := 0
	maxxes := make([]int, 10)
	temp := 0
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9
		maxxes[i] = temp/2 * (temp - temp/2)
	}
	res = int(math.Max(float64(mult(l)), float64(res)))
	res = int(math.Max(float64(mult(r)), float64(res)))
	temp = 0
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9
		if l <= temp/2 && temp/2 <= r {
			res = int(math.Max(float64(maxxes[i]), float64(res)))
		}
	}
	fmt.Println(res)
}

