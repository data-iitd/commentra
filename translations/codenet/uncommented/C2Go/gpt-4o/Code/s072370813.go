package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	var sum, wa int64
	A := make([]int, N)
	sa := make([]int, N)
	var ans int
	var shou int64
	min := int64(1123456789)

	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		sum += int64(A[i])
		wa += int64(i + 1)
	}

	if sum%wa != 0 {
		ans = 0
	} else {
		shou = sum / wa
		for i := 0; i < N; i++ {
			sa[i] = A[(i+1)%N] - A[i] - int(shou)
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

// <END-OF-CODE>
