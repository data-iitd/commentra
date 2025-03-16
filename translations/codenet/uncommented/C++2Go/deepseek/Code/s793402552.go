package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	bStr := strconv.Itoa(b)
	num := a*int(math.Pow(10, float64(len(bStr)))) + b

	i := 1
	for i*i <= num {
		if i*i == num {
			fmt.Println("Yes")
			return
		}
		i++
	}
	fmt.Println("No")
}
