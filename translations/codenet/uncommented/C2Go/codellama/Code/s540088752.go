
package main

import "fmt"

func main() {

	var N int
	fmt.Scan(&N)

	A := make([]int, N+1)
	B := make([]int, N)
	var i int

	for i = 0; i < N+1; i++ {
		fmt.Scan(&A[i])
	}

	for i = 0; i < N; i++ {
		fmt.Scan(&B[i])
	}

	var ans int64 = 0

	for i = 0; i < N; i++ {

		//site i
		if A[i] >= B[i] {
			ans = ans + B[i]
			A[i] = A[i] - B[i]
			B[i] = 0
		} else {
			ans = ans + A[i]
			B[i] = B[i] - A[i]
			A[i] = 0
		}

		//site i + 1
		if A[i+1] >= B[i] {
			ans = ans + B[i]
			A[i+1] = A[i+1] - B[i]
			B[i] = 0
		} else {
			ans = ans + A[i+1]
			B[i] = B[i] - A[i+1]
			A[i+1] = 0
		}
	}

	fmt.Println(ans)

}

