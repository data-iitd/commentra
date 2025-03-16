package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K) // 1. Reading the values of N and K from the standard input.

	var v []int
	for i := 0; i < N; i++ {
		var value int
		fmt.Scan(&value) // 3. Reading N integers from the standard input and storing them in the slice v.
		v = append(v, value)
	}

	// 4. Calculating the number of groups that can be formed using the formula ceil((N-1) / (K-1)).
	count := int(math.Ceil(float64(N-1)/(K-1)))
	fmt.Println(count) // 5. Outputting the calculated count.
}

