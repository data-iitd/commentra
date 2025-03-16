package main

import (
	"fmt"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, k, t int
	data := make([]int, 111112) // size is 111112 to accommodate 0 to 111111
	seq := make([]int, 222223)   // size is 222223 to accommodate 0 to 222222

	for {
		fmt.Scan(&n, &k)
		if n == 0 && k == 0 {
			break
		}

		// Reset data and seq arrays
		for i := range data {
			data[i] = 0
		}
		for i := range seq {
			seq[i] = 0
		}

		for i := 0; i < k; i++ {
			fmt.Scan(&t)
			data[t]++
		}

		p := 0
		for i := 1; i <= n; i++ {
			if data[i] > 0 {
				seq[p]++
			} else {
				p += 2
			}
		}
		p++

		ret := 0
		if data[0] > 0 {
			for i := 0; i < p; i++ {
				ret = max(ret, seq[i]+seq[i+2]+1)
			}
		} else {
			for i := 0; i < p; i++ {
				ret = max(ret, seq[i])
			}
		}

		fmt.Println(ret)
	}
}

// <END-OF-CODE>
