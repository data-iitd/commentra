
package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		A[i] = A[i] * N + i
	}

	cnt := 0
	for i := 0; i < N; i++ {
		d := (A[i] % N) % 2
		if d%2 != i%2 {
			cnt++
		}
	}

	fmt.Println(cnt / 2)
}

