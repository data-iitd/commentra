package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	ans := arr[0] + 1
	for i := 1; i < n; i++ {
		ans += int(math.Abs(float64(arr[i] - arr[i-1]))) + 2
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
