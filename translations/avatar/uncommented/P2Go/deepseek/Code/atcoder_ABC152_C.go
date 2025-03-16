package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N int
	fmt.Scan(&N)

	var n []int
	var input string
	fmt.Scan(&input)

	for _, s := range input.Split(" ") {
		num, _ := strconv.Atoi(s)
		n = append(n, num)
	}

	a := 1
	pos := 0
	for i := 1; i < N; i++ {
		if n[pos] > n[i] {
			a += 1
			pos = i
		}
	}
	fmt.Println(a)
}
