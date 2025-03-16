package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int, N)
	sum := 0
	wa := 0
	ans := 0
	shou := 0
	min := int(1e9)

	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		sum += A[i]
		wa += i + 1
	}

	if sum%wa != 0 {
		ans = 0
	} else {
		shou = sum / wa
		sa := make([]int, N)
		for i := 0; i < N; i++ {
			sa[i] = A[(i+1)%N] - A[i] - shou
		}

		for i := 0; i < N-1; i++ {
			if sa[i] <= 0 && sa[i]%N == 0 {
				ans = 1
			} else {
				ans = 0
				break
			}
		}
	}

	if ans == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

