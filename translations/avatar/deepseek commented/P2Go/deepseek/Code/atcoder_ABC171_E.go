package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N int
	fmt.Scan(&N)

	var a []int
	for i := 0; i < N; i++ {
		var num int
		fmt.Scan(&num)
		a = append(a, num)
	}

	var total int
	for _, ai := range a {
		total ^= ai
	}

	var result []string
	for _, ai := range a {
		result = append(result, strconv.Itoa(ai^total))
	}

	fmt.Println(fmt.Sprintf("%s", result))
}

