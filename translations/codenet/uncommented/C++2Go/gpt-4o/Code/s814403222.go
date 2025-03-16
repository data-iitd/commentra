package main

import (
	"fmt"
	"sort"
)

type Pair struct {
	first  int
	second string
}

func main() {
	var n int
	for {
		if _, err := fmt.Scan(&n); err != nil || n == 0 {
			break
		}
		m := 0
		v := make([]Pair, n)
		d := make([][]int, 33)
		for i := 0; i < 33; i++ {
			d[i] = []int{}
		}
		for i := 0; i < n; i++ {
			v[i].first = 0
			fmt.Scan(&v[i].second, &m)
			for j := 0; j < m; j++ {
				var a int
				fmt.Scan(&a)
				v[i].first += n - len(d[a])
				for _, k := range d[a] {
					v[k].first--
				}
				d[a] = append(d[a], i)
			}
		}
		sort.Slice(v, func(i, j int) bool {
			if v[i].first == v[j].first {
				return v[i].second < v[j].second
			}
			return v[i].first < v[j].first
		})
		fmt.Printf("%d %s\n", v[0].first, v[0].second)
	}
}

// <END-OF-CODE>
