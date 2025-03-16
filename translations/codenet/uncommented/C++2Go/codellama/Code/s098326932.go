
package main

import (
	"fmt"
	"math"
)

func f(n int) int {
	a := make([]int, 20)
	d := 0
	for n > 0 {
		a[d] = n % 10
		n /= 10
		d++
	}
	m := math.MaxFloat64
	res := n
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
	var k int
	fmt.Scan(&k)
	n := f(1)
	for i := 0; i < k; i++ {
		fmt.Println(n)
		n = f(n + 1)
	}
}

