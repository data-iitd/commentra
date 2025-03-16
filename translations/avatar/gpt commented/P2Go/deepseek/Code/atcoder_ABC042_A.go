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
	var numbers []int

	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		numbers = append(numbers, num)
	}

	if count(numbers, 5) == 2 {
		if sum(numbers) == 17 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	} else {
		fmt.Println("NO")
	}
}

func count(slice []int, val int) int {
	count := 0
	for _, v := range slice {
		if v == val {
			count++
		}
	}
	return count
}

func sum(slice []int) int {
	total := 0
	for _, v := range slice {
		total += v
	}
	return total
}

