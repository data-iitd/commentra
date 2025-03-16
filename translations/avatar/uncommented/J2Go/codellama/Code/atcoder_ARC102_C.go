
package main

import (
	"fmt"
	"math"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	nchoosek := make([][]int, 4001)
	for i := range nchoosek {
		nchoosek[i] = make([]int, 4001)
		nchoosek[i][0] = nchoosek[i][i] = 1
	}
	for i := 2; i < len(nchoosek); i++ {
		for j := 1; j < i; j++ {
			nchoosek[i][j] = (nchoosek[i-1][j] + nchoosek[i-1][j-1]) % 998244353
		}
	}
	for i := 2; i <= 2*k; i++ {
		pairs := 0
		if i > k {
			pairs = k - i/2
		} else {
			pairs = (i - 1) / 2
		}
		active := k - 2*pairs
		if i%2 == 0 {
			active -= 1
		}
		times2 := 1
		total := 0
		for j := 0; j <= pairs; j++ {
			choice := times2 * nchoosek[pairs][j] % 998244353
			times2 = times2*2 % 998244353
			if active+j-1 < 0 {
				continue
			}
			total += choice * nchoosek[n+active-1][active+j-1]
			if i%2 == 0 {
				total += choice * nchoosek[n+active-2][active+j-1]
			}
			total %= 998244353
		}
		fmt.Println(total)
	}
}

