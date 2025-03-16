
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := make([]int, 2)
	sc[0], _ = strconv.Atoi(os.Args[1])
	sc[1], _ = strconv.Atoi(os.Args[2])

	var n, b int
	var ans []int
	var q []int

	n = sc[0]
	b = sc[1]
	ans = make([]int, n)
	q = make([]int, 0)

	for i := 0; i < n; i++ {
		sc = make([]int, 2)
		sc[0], _ = strconv.Atoi(os.Args[3+2*i])
		sc[1], _ = strconv.Atoi(os.Args[3+2*i+1])

		t := sc[0]
		d := sc[1]

		for len(q) > 0 && q[0] <= t {
			q = q[1:]
		}

		if len(q) <= b {
			ans[i] = (q[len(q)-1] + d)
			q = append(q, ans[i])
		} else {
			ans[i] = -1
		}
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d ", ans[i])
	}
}

