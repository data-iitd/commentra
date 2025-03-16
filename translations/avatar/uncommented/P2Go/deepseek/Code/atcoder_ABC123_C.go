package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var N int
	var A []int
	for i := 0; i < 5; i++ {
		var input int
		fmt.Scan(&input)
		A = append(A, input)
	}
	minA := A[0]
	for _, value := range A {
		if value < minA {
			minA = value
		}
	}
	fmt.Println(int(math.Ceil(float64(N)/float64(minA))) + 4)
}

