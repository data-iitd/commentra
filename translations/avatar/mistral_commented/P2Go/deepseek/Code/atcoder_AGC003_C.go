```go
package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		var x int
		fmt.Scan(&x)
		A[i] = x * N + i
	}

	// Sort the list A in ascending order.
	// For simplicity, we will use the built-in sort function in Go.
	// Note: The sort function in Go requires a slice of type `[]int` to sort.
	// We need to convert our array `A` to a slice.
	sort.Ints(A)

	cnt := 0
	for i := 0; i < N; i++ {
		d := (A[i] % N) % 2
		if d%2 != i%2 {
			cnt++
		}
	}

	fmt.Println(cnt / 2)
}
