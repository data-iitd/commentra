package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	if possible(N, A) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func possible(N int, A []int) bool {
	var sum int64 = 0
	for i := 0; i < N; i++ {
		sum += int64(A[i])
	}
	var NS int64 = int64(N) * int64(N+1) / 2
	if sum % NS != 0 {
		return false
	}
	var K int64 = sum / NS
	for i := 0; i < N; i++ {
		var j int = i
		if i == 0 {
			j = N - 1
		} else {
			j = i - 1
		}
		var d int64 = K - int64(A[i] - A[j])
		if d < 0 || d % int64(N) != 0 {
			return false
		}
	}
	return true
}

