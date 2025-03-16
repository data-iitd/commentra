package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	sum := 0

	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
		sum += arr[i]
	}

	c := 0
	var sb strings.Builder

	for i := 0; i < n; i++ {
		if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] {
			c++
			sb.WriteString(fmt.Sprintf("%d ", i+1))
		}
	}

	fmt.Println(c)
	fmt.Println(strings.TrimSpace(sb.String()))
}

// <END-OF-CODE>
