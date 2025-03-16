package main

import (
	"fmt"
	"math"
)

func main() {
	startTime := float64(time.Now().UnixNano()) / 1e6 // Get current time in milliseconds
	var n int
	fmt.Scan(&n)
	div := int64(math.Pow(10, 9)) + 7
	A := make([]int64, n)
	var ans int64 = 0

	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	for i := 0; i < 60; i++ {
		var a int64 = 0
		var count1 int64 = 0
		for j := 0; j < n; j++ {
			if (A[j]>>i)&1 == 1 {
				count1++
			}
		}
		a += count1 * (int64(n) - count1)
		for j := 0; j < i; j++ {
			a = (a << 1) % div
		}
		ans = (ans + a) % div
	}

	fmt.Println(ans)
	endTime := float64(time.Now().UnixNano()) / 1e6 // Get current time in milliseconds
	// You can print the elapsed time if needed
	// fmt.Println("Elapsed time:", endTime-startTime)
}

// <END-OF-CODE>
