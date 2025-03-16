package main

import (
	"fmt"
	"sort"
)

type Pair struct {
	First, Second int
}

func main() {
	var n int
	fmt.Scan(&n)

	m := make([]Pair, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&m[i].First, &m[i].Second)
	}

	sort.Slice(m, func(i, j int) bool {
		return m[i].Second > m[j].Second
	})

	a := m[0]
	for _, i := range m[1:] {
		if i.Second > a.Second {
			fmt.Println("Happy Alex")
			return
		}
		a = i
	}
	fmt.Println("Poor Alex")
}

