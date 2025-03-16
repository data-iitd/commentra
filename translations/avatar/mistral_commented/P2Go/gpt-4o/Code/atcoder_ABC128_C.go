package main

import (
	"fmt"
	"math/bits"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	li := make([][]int, m)
	for i := 0; i < m; i++ {
		var size int
		fmt.Scan(&size)
		li[i] = make([]int, size-1)
		for j := 0; j < size-1; j++ {
			fmt.Scan(&li[i][j])
		}
	}

	p := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&p[i])
	}

	q := make(map[int]struct{})
	for _, list := range li {
		for _, num := range list {
			q[num] = struct{}{}
		}
	}

	r := make(map[int]struct{})
	for i := 1; i <= n; i++ {
		r[i] = struct{}{}
	}

	for num := range q {
		delete(r, num)
	}

	v := len(r)

	ans := 0

	// Iterate through all possible subsets of q
	qKeys := make([]int, 0, len(q))
	for k := range q {
		qKeys = append(qKeys, k)
	}

	for i := 0; i < (1 << len(qKeys)); i++ {
		s := make(map[int]struct{})
		for j := 0; j < len(qKeys); j++ {
			if (i & (1 << j)) != 0 {
				s[qKeys[j]] = struct{}{}
			}
		}

		match := true
		for u, w := range p {
			count := 0
			for num := range s {
				if _, exists := q[num]; exists {
					count++
				}
			}
			if count%2 != w {
				match = false
				break
			}
		}

		if match {
			ans += 1 << v // 2^len(v)
		}
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
