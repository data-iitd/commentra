package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	var N, X int
	fmt.Fscan(os.Stdin, &N, &X)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(os.Stdin, &A[i])
	}

	S := make([]int, N)
	S[0] = A[0]
	for i := 1; i < N; i++ {
		S[i] = S[i-1] + A[i]
	}

	ans := math.Inf(1)
	for k := 1; k <= N/2; k++ {
		E := float64(k)*float64(X) + 2*sum(S, N, k)
		if E < ans {
			ans = E
		}
	}

	fmt.Println(ans + float64(N)*float64(X) + 5*float64(S[N-1]))
}

func sum(S []int, N, k int) float64 {
	total := 0
	for j := N - 2*k - 1; j >= 0; j -= k {
		total += S[j]
	}
	return float64(total)
}

// <END-OF-CODE>
