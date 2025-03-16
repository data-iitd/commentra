package main

import (
	"fmt"
	"sort"
)

func main() {
	var a [5]int
	var r [5]int
	mapa := make(map[int]int)

	for i := 0; i < len(a); i++ {
		fmt.Scan(&a[i])
		r[i] = a[i] % 10
		b := 10
		if r[i] != 0 {
			b = 10 - r[i]
			mapa[b] = a[i]
		}
	}

	ans := 0
	if len(mapa) == 0 {
		for i := 0; i < len(a); i++ {
			ans += a[i]
		}
		fmt.Println(ans)
		return
	}

	keys := make([]int, 0, len(mapa))
	for k := range mapa {
		keys = append(keys, k)
	}
	sort.Ints(keys)

	last := mapa[keys[len(keys)-1]]
	idx := 0
	for i := 0; i < len(a); i++ {
		if a[i] == last {
			idx = i
		}
	}

	for i := 0; i < len(a); i++ {
		if i != idx {
			if a[i]%10 == 0 {
				ans += a[i]
			} else {
				ans += a[i] + (10 - r[i])
			}
		}
	}
	ans += last
	fmt.Println(ans)
}

