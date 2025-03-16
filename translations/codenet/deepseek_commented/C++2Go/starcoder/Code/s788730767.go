<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

func main() {
	var n, p, b, c int
	var a [50]int
	fmt.Scanf("%d %d", &n, &p)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
		if a[i]%2 == 0 {
			b++
		} else {
			c++
		}
	}
	bsum := int(math.Pow(2, float64(b)))
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

