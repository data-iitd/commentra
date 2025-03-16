package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var source string
	fmt.Scan(&source)

	if len(source) > 10 || len(source) < 1 {
		return
	}

	maxI := int(math.Pow(2, float64(len(source)-1)))

	var sum float64

	for i := 0; i < maxI; i++ {
		plus := fmt.Sprintf("%0*b", len(source)-1, i)

		number := 0.0

		working := source
		for len(plus) > 0 {
			if plus[0] == '1' {
				index := 0
				for plus[index] != '1' {
					index++
				}
				num, _ := strconv.ParseFloat(working[:index+1], 64)
				sum += num
				plus = plus[index+1:]
				working = working[index+1:]
			} else {
				plus = plus[1:]
				working = working[1:]
			}
		}
		num, _ := strconv.ParseFloat(working, 64)
		sum += num
	}

	fmt.Printf("%.0f\n", sum)
}

