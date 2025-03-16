package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var N int
	var i int
	var sum int64 = 0
	var wa int64 = 0
	var A []int
	var sa []int
	var ans bool
	var shou int64

	// Read input
	fmt.Scan(&N)
	// Read N integers into the array A
	A = make([]int, N)
	for i = 0; i < N; i++ {
		fmt.Scan(&A[i])
		// Add current element to sum
		sum += int64(A[i])
		// Add current index to wa
		wa += int64(i+1)
	}

	// Check if sum is divisible by wa
	if sum%wa != 0 {
		ans = false
	} else {
		// Calculate quotient of sum and wa
		shou = sum / wa
		// Calculate differences between adjacent elements and store in array sa
		sa = make([]int, N)
		for i = 0; i < N; i++ {
			sa[i] = A[(i+1)%N] - A[i] - int(shou)
		}

		// Check if any difference is less than or equal to 0 and divisible by N
		ans = true
		for i = 0; i < N-1; i++ {
			if sa[i] <= 0 && sa[i]%int64(N) == 0 {
				ans = true
			} else {
				ans = false
				break
			}
		}
	}

	// Print answer
	if ans {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

