package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	l := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	ans := n - 1
	last := 0

	for _, i := range l {
		ans += int(math.Abs(float64(last-i))) + 1
		last = i
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
