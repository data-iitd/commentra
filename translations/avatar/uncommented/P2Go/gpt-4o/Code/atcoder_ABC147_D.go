package main

import (
	"fmt"
	"math/bits"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	result := int64(0)
	const MOD = 1000000007

	for b := 0; b < 60; b++ {
		bs := int64(0)
		for _, a := range A {
			bs += (a >> b) & 1
		}
		result = (result + bs*(int64(N)-bs)*(1<<b)) % MOD
	}

	fmt.Println(result)
}

// <END-OF-CODE>
