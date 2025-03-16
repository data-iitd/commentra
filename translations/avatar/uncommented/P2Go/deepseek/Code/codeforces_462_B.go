package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	var s string
	fmt.Scan(&n, &k, &s)

	count := make([]int, 26)
	for _, c := range s {
		count[int(c)-int('A')]++
	}

	sort.Slice(count, func(i, j int) bool {
		return count[i] > count[j]
	})

	res := 0
	for i := 0; i < 26; i++ {
		if count[i] >= k {
			res += k * k
			fmt.Println(res)
			return
		}
		k -= count[i]
		res += count[i] * count[i]
	}
	fmt.Println(res)
}

