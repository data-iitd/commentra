package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	mn, mx := N+1, -1
	for i := 0; i < N; i++ {
		if i+1 != A[i] {
			mn = min(mn, i)
			mx = max(mx, i)
		}
	}
	if mx == -1 {
		fmt.Println("0 0")
	} else {
		A = A[:mn] + A[mn:mx+1][:len(A[mn:mx+1])-1] + A[mx+1:]
		if sorted(A) == A {
			fmt.Println(mn+1, mx+1)
		} else {
			fmt.Println("0 0")
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func sorted(A []int) []int {
	for i := 0; i < len(A)-1; i++ {
		for j := i + 1; j < len(A); j++ {
			if A[i] > A[j] {
				A[i], A[j] = A[j], A[i]
			}
		}
	}
	return A
}

