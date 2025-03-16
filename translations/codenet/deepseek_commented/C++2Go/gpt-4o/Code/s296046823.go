package main

import (
	"fmt"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K) // 1. Reading the values of N and K from the standard input.

	v := make([]int, N) // 2. Initializing a slice of size N to store N integers.
	for i := 0; i < N; i++ {
		fmt.Scan(&v[i]) // 3. Reading N integers from the standard input and storing them in the slice v.
	}

	// 4. Calculating the number of groups that can be formed using the formula ceil((N-1) / (K-1)).
	count := (N - 1 + (K - 2)) / (K - 1)
	fmt.Println(count) // 5. Outputting the calculated count.
}

// <END-OF-CODE>
