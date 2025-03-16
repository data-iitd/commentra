package main

import (
	"fmt"
	"strconv"
)

func main() {
	var inputNumbers string
	var temp string
	var a, b, c, d int
	var sum int
	var symbols string

	fmt.Scan(&inputNumbers)

	temp = string(inputNumbers[0])
	a, _ = strconv.Atoi(temp)
	temp = string(inputNumbers[1])
	b, _ = strconv.Atoi(temp)
	temp = string(inputNumbers[2])
	c, _ = strconv.Atoi(temp)
	temp = string(inputNumbers[3])
	d, _ = strconv.Atoi(temp)

	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				if i == 0 {
					sum = a + b
					symbols = "+"
				} else {
					sum = a - b
					symbols = "-"
				}

				if j == 0 {
					sum = sum + c
					symbols += "+"
				} else {
					sum = sum - c
					symbols += "-"
				}

				if k == 0 {
					sum = sum + d
					symbols += "+"
				} else {
					sum = sum - d
					symbols += "-"
				}

				if sum == 7 {
					fmt.Printf("%d%s%d%s%d%s%d=7\n", a, symbols[0], b, symbols[1], c, symbols[2], d)

					return
				}
			}
		}
	}
}

