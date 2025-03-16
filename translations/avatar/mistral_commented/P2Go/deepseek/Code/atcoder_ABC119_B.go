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
		if input == "JPY" {
			x = append(x, 1.0)
		} else if input == "BTC" {
			x = append(x, 380000.0)
		} else {
			value, _ := strconv.ParseFloat(input[:len(input)-3], 64)
			x = append(x, value)
		}
	}

	var sum float64
	for _, v := range x {
		sum += v
	}

	fmt.Println(sum)
}

