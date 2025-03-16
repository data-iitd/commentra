package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	var result int64 = 1
	for i := 1; i < len(arr); i++ {
		result *= int64(arr[i]) - int64(arr[i-1])
	}
	fmt.Println(result)
}

