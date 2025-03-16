package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	var list []int
	input := ""
	fmt.Scan(&input)
	numbers := strings.Split(input, " ")

	for _, numStr := range numbers {
		num, _ := strconv.Atoi(numStr)
		list = append(list, num%2)
	}

	sum := 0
	for _, num := range list {
		sum += num
	}

	if sum == 1 {
		for i, num := range list {
			if num == 1 {
				fmt.Println("The first number with remainder 1 is:", i+1)
				break
			}
		}
	} else {
		for i, num := range list {
			if num == 0 {
				fmt.Println("The first number with remainder 0 is:", i+1)
				break
			}
		}
	}
}

