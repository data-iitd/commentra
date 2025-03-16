package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N int
	fmt.Scan(&N)

	var x []float64
	for i := 0; i < N; i++ {
		var input string
		fmt.Scan(&input)
		parts := input.Split(" ")
		for j := 0; j < len(parts); j++ {
			if parts[j] == "JPY" {
				parts[j] = "1.0"
			} else if parts[j] == "BTC" {
				parts[j] = "380000.0"
			}
		}
		expression := strings.Join(parts, " ")
		value, _ := strconv.ParseFloat(expression, 64)
		x = append(x, value)
	}

	sum := 0.0
	for _, v := range x {
		sum += v
	}
	fmt.Println(sum)
}

