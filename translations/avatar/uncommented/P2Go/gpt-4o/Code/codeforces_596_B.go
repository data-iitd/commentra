package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	r := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&r[i])
	}

	ans := int(math.Abs(float64(r[0])))
	for i := 1; i < n; i++ {
		ans += int(math.Abs(float64(r[i] - r[i-1])))
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
