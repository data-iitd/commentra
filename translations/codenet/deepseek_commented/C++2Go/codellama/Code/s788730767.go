package main

import (
	"fmt"
	"math"
)

func main() {
	var n, p, b, c int
	fmt.Scan(&n, &p)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		if a[i]%2 == 0 {
			b++
		} else {
			c++
		}
	}

	// Calculate the number of subsets with even and odd numbers
	bsum := int(math.Pow(2, float64(b)))
	csum := 0

	if p == 0 {
		// Sum combinations where the number of elements is even
		for i := 0; i <= c; i++ {
			if i%2 == 0 {
				csum += nCr(c, i)
			}
		}
	} else {
		// Sum combinations where the number of elements is odd
		for i := 0; i <= c; i++ {
			if i%2 == 1 {
				csum += nCr(c, i)
			}
		}
	}

	// Calculate the final answer as the product of bsum and csum
	ans := bsum * csum
	fmt.Println(ans)
}

func nCr(n, r int) int {
	res := 1
	for i := 0; i < r; i++ {
		res *= (n - i)
	}
	return res
}

// 