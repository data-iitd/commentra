
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"time"
)

func main() {
	startTime := time.Now()
	sc := make([]int, 1000000)
	var n int
	fmt.Scan(&n)
	div := int(math.Pow(10, 9) + 7)
	A := make([]int, n)
	ans := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	for i := 0; i < 60; i++ {
		a := 0
		count1 := 0
		for j := 0; j < n; j++ {
			if (A[j]>>i)&1 == 1 {
				count1++
			}
		}
		a = a + count1*(n-count1)
		for j := 0; j < i; j++ {
			a = (a << 1) % div
		}
		ans += a
		ans %= div
	}
	fmt.Println(ans)
	endTime := time.Now()
	fmt.Println("Time taken:", endTime.Sub(startTime))
}

