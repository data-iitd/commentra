package main

import (
	"fmt"
	"sort"
)

func main() {
	var a [5]int
	var r [5]int
	mapValues := make(map[int]int)

	for i := 0; i < len(a); i++ {
		fmt.Scan(&a[i])
		r[i] = a[i] % 10
		b := 10
		if r[i] != 0 {
			b = 10 - r[i]
			mapValues[b] = a[i]
		}
	}

	ans := 0
	if len(mapValues) == 0 {
		for i := 0; i < len(a); i++ {
			ans += a[i]
		}
		fmt.Println(ans)
		return
	}

	// Get the last key (the maximum key)
	keys := make([]int, 0, len(mapValues))
	for k := range mapValues {
		keys = append(keys, k)
	}
	sort.Ints(keys)
	last := mapValues[keys[len(keys)-1]]

	var idx int
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

// <END-OF-CODE>
