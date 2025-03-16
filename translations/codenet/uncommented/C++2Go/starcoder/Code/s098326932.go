
package main

import (
	"fmt"
	"math"
)

func f(N int) int {
	a := make([]int, 20)
	d := 0
	for N > 0 {
		a[d] = N % 10
		N /= 10
		d++
	}
	m := 1e18
	res := N
	for i := 0; i <= d; i++ {
		bunsi := 0
		bunbo := 9 * i
		for j := d - 1; j >= 0; j-- {
			bunsi *= 10
			if j < i {
				bunsi += 9
			} else {
				bunsi += a[j]
			}
			if j >= i {
				bunbo += a[j]
			}
		}
		frac := float64(bunsi) / float64(bunbo)
		if frac < m {
			m = frac
			res = bunsi
		}
	}
	return res
}

func main() {
	var K int
	fmt.Scan(&K)
	N := f(1)
	for i := 0; i < K; i++ {
		fmt.Println(N)
		N = f(N + 1)
	}
}

