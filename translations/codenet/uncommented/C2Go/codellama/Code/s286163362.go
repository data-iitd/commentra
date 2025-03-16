
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, k, t, i, p, ret int
	var data [111111]int
	var seq [222222]int

	for {
		fmt.Scan(&n, &k)
		if n == 0 && k == 0 {
			break
		}

		for i = 0; i < 111111; i++ {
			data[i] = 0
		}
		for i = 0; i < 222222; i++ {
			seq[i] = 0
		}

		for i = 0; i < k; i++ {
			fmt.Scan(&t)
			data[t]++
		}

		p = 0
		for i = 1; i <= n; i++ {
			if data[i] != 0 {
				seq[p]++
			} else {
				p += 2
			}
		}
		p++

		if data[0] != 0 {
			for i = 0; i < p; i++ {
				ret = max(ret, seq[i]+seq[i+2]+1)
			}
		} else {
			for i = 0; i < p; i++ {
				ret = max(ret, seq[i])
			}
		}

		fmt.Println(ret)
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

