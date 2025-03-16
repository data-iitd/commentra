package main

import (
	"fmt"
)

const mod = 1000000007

func main() {
	var n, q int
	fmt.Scan(&n, &q)
	c := make([]rune, n)
	for i := 0; i < n; i++ {
		var ch rune
		fmt.Scanf("%c", &ch)
		c[i] = ch
	}

	rangeQueries := make([][2]int, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&rangeQueries[i][0], &rangeQueries[i][1])
	}

	frag := make([]int, n+1)
	rui := make([]int, n+1)

	for i := 2; i <= n; i++ {
		if c[i-2] == 'A' && c[i-1] == 'C' {
			frag[i]++
		}
		rui[i] = rui[i-1] + frag[i]
	}

	for i := 0; i < q; i++ {
		left := rangeQueries[i][0]
		right := rangeQueries[i][1]
		fmt.Println(rui[right] - rui[left])
	}
}

// <END-OF-CODE>
