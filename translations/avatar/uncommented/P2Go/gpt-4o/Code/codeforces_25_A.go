package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	var input string
	fmt.Scan(&input)

	nums := strings.Split(input, " ")
	list := make([]int, n)

	for i, num := range nums {
		x, _ := strconv.Atoi(num)
		list[i] = x % 2
	}

	sum := 0
	for _, value := range list {
		sum += value
	}

	if sum == 1 {
		for i, value := range list {
			if value == 1 {
				fmt.Println(i + 1)
				break
			}
		}
	} else {
		for i, value := range list {
			if value == 0 {
				fmt.Println(i + 1)
				break
			}
		}
	}
}

// <END-OF-CODE>
