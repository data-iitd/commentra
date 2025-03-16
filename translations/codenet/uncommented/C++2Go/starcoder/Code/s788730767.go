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
	res := 1
	for i := 0; i < r; i++ {
		res *= (n - i)
		res /= (i + 1)
	}
	return res
}

func main() {
	var n, p int
	fmt.Scanf("%d %d", &n, &p)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}

	b, c := 0, 0
	for i := 0; i < n; i++ {
		if a[i]%2 == 0 {
			b++
		} else {
			c++
		}
	}

	bsum := 1
	for i := 0; i < b; i++ {
		bsum *= 2
	}

	csum := 0
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

