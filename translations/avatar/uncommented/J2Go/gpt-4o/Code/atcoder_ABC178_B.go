package main

import (
	"fmt"
)

func main() {
	var a [4]int64
	for i := 0; i < 4; i++ {
		fmt.Scan(&a[i])
	}
	result := max(a[0]*a[2], max(a[1]*a[3], max(a[0]*a[3], a[1]*a[2])))
	fmt.Println(result)
}

func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

// <END-OF-CODE>
