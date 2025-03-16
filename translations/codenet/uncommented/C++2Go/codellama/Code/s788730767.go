package main

import (
	"fmt"
	"math"
)

func nPr(n, r int) int {
	res := 1
	for i := 0; i < r; i++ {
		res *= (n - i)
	}

	return res
}

func nCr(n, r int) int {
	//res := nPr(n, r) / nPr(r, r)
	res := 1
	for i := 0; i < r; i++ {
		res *= (n - i)
		res /= (i + 1)
	}
	return res
}

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

	//fmt.Println("b:", b, "c:", c)
	bsum := 0
	csum := 0
	bsum = int(math.Pow(2, float64(b)))

	if p == 0 {
		for i := 0; i <= c; i++ {
			if i%2 == 0 {
				csum += nCr(c, i)
			}
		}
	} else {
		for i := 0; i <= c; i++ {
			if i%2 == 1 {
				csum += nCr(c, i)
			}
		}
	}

	ans := bsum * csum
	fmt.Println(ans)
}

