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
		var ai int
		fmt.Scan(&ai)
		a = append(a, ai)
	}

	total := 0
	for _, ai := range a {
		total ^= ai
	}

	result := []string{}
	for _, ai := range a {
		result = append(result, strconv.Itoa(ai^total))
	}

	fmt.Println(fmt.Sprintf("%s", result))
}

