package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	var a [100]int
	var avg, s, ans float64

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		avg += float64(a[i])
	}
	avg /= float64(n)

	s = math.Abs(float64(a[0]) - avg)
	ans = 0
	for i := 1; i < n; i++ {
		if s > math.Abs(float64(a[i])-avg) {
			s = math.Abs(float64(a[i]) - avg)
			ans = float64(i)
		}
	}
	fmt.Println(int(ans))
}

// <END-OF-CODE>
