package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	answer := int64(math.Abs(float64(arr[0])))
	for i := 1; i < n; i++ {
		answer += int64(math.Abs(float64(arr[i]) - float64(arr[i-1])))
	}
	fmt.Println(answer)
}

