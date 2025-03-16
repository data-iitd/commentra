package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := []int{}
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		if x == 1 {
			arr = append(arr, i)
		}
	}
	if len(arr) == 0 {
		fmt.Println(0)
	} else {
		result := 1
		for i := 1; i < len(arr); i++ {
			result *= arr[i] - arr[i-1]
		}
		fmt.Println(result)
	}
}

