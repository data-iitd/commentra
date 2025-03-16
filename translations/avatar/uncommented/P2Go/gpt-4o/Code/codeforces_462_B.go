package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	var s string
	fmt.Scan(&s)

	count := make([]int, 26)
	for _, c := range s {
		count[c-'A']++
	}

	sort.Sort(sort.Reverse(sort.IntSlice(count)))

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

// <END-OF-CODE>
