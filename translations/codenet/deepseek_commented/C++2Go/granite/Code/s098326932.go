

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var k int64
	fmt.Fscanf(reader, "%d\n", &k)
	n := f(1)
	for i := int64(0); i < k; i++ {
		fmt.Println(n)
		n = f(n + 1)
	}
}

func f(n int64) int64 {
	a := make([]int64, 20)
	d := int64(0)
	for n > 0 {
		a[d] = n % 10
		n /= 10
		d++
	}
	m := float64(1e18)
	res := int64(0)
	for i := int64(0); i <= d; i++ {
		bunsi := int64(0)
		bunbo := int64(9 * i)
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

// End of code