package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var x int64
	fmt.Scan(&x)

	var list []int64

	for x > 0 {
		r := x % 10

		if 9-r < r {
			if x/10 == 0 && 9-r == 0 {
				list = append(list, r)
			} else {
				list = append(list, 9-r)
			}
		} else {
			list = append(list, r)
		}

		x = x / 10
	}

	var pow int = 0
	var newNumber int64 = 0

	for i := 0; i < len(list); i++ {
		newNumber = newNumber + list[i] * int64(math.Pow(10, float64(pow)))
		pow++
	}

	fmt.Println(newNumber)
}
