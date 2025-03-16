package main

import (
	"fmt"
	"math"
)

func nPr(n, r int64) int64 {
	res := int64(1)
	for i := int64(0); i < r; i++ {
		res *= (n - i)
	}
	return res
}

func nCr(n, r int64) int64 {
	res := float64(1)
	for i := int64(0); i < r; i++ {
		res *= float64(n - i)
		res /= float64(i + 1)
	}
	return int64(res)
}

func main() {
	var n, p int
	var b, c int64
	var a [50]int

	fmt.Scan(&n, &p)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		if a[i]%2 == 0 {
			b++
		} else {
			c++
		}
	}

	// Calculate the number of subsets with even and odd numbers
	bsum := int64(math.Pow(2, float64(b)))
	csum := int64(0)

	if p == 0 {
		// Sum combinations where the number of elements is even
		for i := int64(0); i <= c; i++ {
			if i%2 == 0 {
				csum += nCr(c, i)
			}
		}
	} else {
		// Sum combinations where the number of elements is odd
		for i := int64(0); i <= c; i++ {
			if i%2 == 1 {
				csum += nCr(c, i)
			}
		}
	}

	// Calculate the final answer as the product of bsum and csum
	ans := bsum * csum
	fmt.Println(ans)
}

// <END-OF-CODE>
