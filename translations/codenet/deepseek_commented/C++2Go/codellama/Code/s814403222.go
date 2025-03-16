package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	for {
		fmt.Scan(&n)
		if n == 0 {
			break
		}
		v := make([]pair, n)
		d := make([][]int, 33)
		for i := 0; i < 33; i++ {
			d[i] = make([]int, 0)
		}
		for i := 0; i < n; i++ {
			v[i].first = 0
			fmt.Scan(&v[i].second, &m)
			for j := 0; j < m; j++ {
				var a int
				fmt.Scan(&a)
				v[i].first += n - len(d[a])
				for k := 0; k < len(d[a]); k++ {
					v[d[a][k]].first--
				}
				d[a] = append(d[a], i)
			}
		}
		sort.Slice(v, func(i, j int) bool {
			return v[i].first < v[j].first
		})
		fmt.Println(v[0].first, v[0].second)
	}
}

type pair struct {
	first  int
	second string
}

