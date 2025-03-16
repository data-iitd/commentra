
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
	for i := 0; i < N; i++ {
		A[i] = A[i] % N
		if A[i]%2 != i%2 {
			cnt++
		}
	}
	fmt.Println(cnt / 2)
}

