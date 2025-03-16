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

	for i := 1; i <= 100100; i++ {
		if i*i == num {
			fmt.Println("Yes")
			return
		}
	}

	fmt.Println("No")
}

