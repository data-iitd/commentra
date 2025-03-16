package main

import (
	"fmt"
	"strconv"
)

func main() {
	var input string
	fmt.Scanln(&input)
	numbers := strings.Split(input, " ")
	a, _ := strconv.Atoi(numbers[0])
	b, _ := strconv.Atoi(numbers[1])

	hole := 1
	i := 0
	check := true

	for check {
		if hole >= b {
			check = false
		} else {
			hole = a*(i+1) - i
			i++
		}
	}

	fmt.Println(i)
}

