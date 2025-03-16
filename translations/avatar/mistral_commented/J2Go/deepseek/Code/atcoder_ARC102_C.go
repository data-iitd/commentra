package main

import (
	"fmt"
)

const mod = 998244353

var nchoosek [][]int64

func main() {
	nchoosek = make([][]int64, 4001)
	for i := range nchoosek {
		nchoosek[i] = make([]int64, 4001)
		nchoosek[i][0], nchoosek[i][i] = 1, 1
	}

	for i := 2; i < len(nchoosek); i++ {
		for j := 1; j < i; j++ {
			nchoosek[i][j] = (nchoosek[i-1][j] + nchoosek[i-1][j-1]) % mod
		}
	}

	var k, n int
	fmt.Scan(&k, &n)

	for i := 2; i <= 2*k; i++ {
		var pairs int
		if i > k {
			pairs = k - i/2
		} else {
			pairs = (i - 1) / 2
		}

		active := k - 2*pairs
		if i%2 == 0 {
			active -= 1
		}

		var times2 int64 = 1
		var total int64 = 0

		for j := 0; j <= pairs; j++ {
			var choice int64 = times2 * int64(nchoosek[pairs][j]) % mod
			times2 = times2 * 2 % mod

			if active+j-1 < 0 {
				continue
			}

			total += choice * int64(nchoosek[n+active-1][active+j-1])
			if i%2 == 0 {
				total += choice * int64(nchoosek[n+active-2][active+j-1])
			}

			total %= mod
		}

		fmt.Println(total)
	}
}
