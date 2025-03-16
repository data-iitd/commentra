package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)

	parts := strings.Split(input, " ")
	ABC := make([]int, len(parts))

	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		ABC[i] = num
	}

	// Check if the slice contains exactly two 5s
	countFive := 0
	for _, num := range ABC {
		if num == 5 {
			countFive++
		}
	}

	// Check if the sum of the elements in ABC is 17
	sumABC := 0
	for _, num := range ABC {
		sumABC += num
	}

	if countFive == 2 && sumABC == 17 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
