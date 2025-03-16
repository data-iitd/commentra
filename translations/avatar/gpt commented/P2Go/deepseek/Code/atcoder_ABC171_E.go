package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N int
	fmt.Scan(&N)

	var a []int
	fmt.Scan(&a)

	var total int
	for _, ai := range a {
		total ^= ai
	}

	var result []string
	for _, ai := range a {
		result = append(result, strconv.Itoa(ai^total))
	}

	fmt.Println(strings.Join(result, " "))
}

