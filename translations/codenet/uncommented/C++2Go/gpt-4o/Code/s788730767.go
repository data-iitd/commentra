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
	fmt.Scan(&n, &p)

	a := make([]int, n)
	b, c := 0, 0

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		if a[i]%2 == 0 {
			b++
		} else {
			c++
		}
	}

	bsum := int64(math.Pow(2, float64(b)))
	csum := int64(0)

	if p == 0 {
		for i := int64(0); i <= int64(c); i++ {
			if i%2 == 0 {
				csum += nCr(int64(c), i)
			}
		}
	} else {
		for i := int64(0); i <= int64(c); i++ {
			if i%2 == 1 {
				csum += nCr(int64(c), i)
			}
		}
	}

	ans := bsum * csum
	fmt.Println(ans)
}

// <END-OF-CODE>
