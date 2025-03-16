package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	min := 0
	var inputs []int
	for i := 0; i < 5; i++ {
		var input int
		fmt.Scan(&input)
		inputs = append(inputs, input)
	}

	sort.Ints(inputs)
	min = inputs[0]

	fmt.Println(int(math.Ceil(float64(N)/float64(min))) + 4)
}

