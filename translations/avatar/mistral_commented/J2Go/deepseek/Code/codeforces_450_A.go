package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	q1 := make([]int, n)
	q2 := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&q1[i])
		q2[i] = i + 1
	}

	ans := 0
	for len(q1) > 0 {
		if q1[0] <= m {
			ans = q2[0]
			q1 = q1[1:]
			q2 = q2[1:]
		} else {
			x := q1[0]
			q1 = q1[1:]
			val := x - m
			q1 = append(q1, val)
			val2 := q2[0]
			q2 = q2[1:]
			q2 = append(q2, val2)
		}
	}

	fmt.Println(ans)
}
