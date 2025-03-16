package main

import (
	"fmt"
	"math"
	"time"
)

func main() {
	startTime := time.Now().UnixMilli()
	var n int
	fmt.Scan(&n)
	div := int(math.Pow(10, 9)) + 7
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
		a = a + count1*(int64(n)-count1)
		for j := 0; j < i; j++ {
			a = (a << 1) % int64(div)
		}
		ans += a
		ans %= int64(div)
	}
	fmt.Println(ans)
	endTime := time.Now().UnixMilli()
	fmt.Println("Time taken:", endTime-startTime, "ms")
}

