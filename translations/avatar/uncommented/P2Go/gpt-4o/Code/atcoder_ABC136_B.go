package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	i := 1
	ans := 0

	for int(math.Pow(10, float64(i))) <= N {
		ans += (int(math.Pow(10, float64(i))) - int(math.Pow(10, float64(i-1))))
		i += 2
	}
	ans += max(0, N-int(math.Pow(10, float64(i-1)))+1)
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
