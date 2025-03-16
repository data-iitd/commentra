package main

import "fmt"

func main() {
	var n int64
	fmt.Scanf("%d", &n)
	a := make([]int64, n)
	count := make([]int64, n)

	for i := int64(1); i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}

	for i := int64(0); i < n; i++ {
		count[i] = 0
	}

	for i := int64(1); i < n; i++ {
		count[a[i]-1]++
	}

	for i := int64(0); i < n; i++ {
		fmt.Println(count[i])
	}
}

