package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)

	v := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&v[i])
	}

	count := int(math.Ceil(float64((N-1)+((K-1)-1)) / float64(K-1)))
	fmt.Println(count)
}

