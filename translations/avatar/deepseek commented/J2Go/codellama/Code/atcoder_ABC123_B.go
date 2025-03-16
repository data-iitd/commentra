package main

import (
	"fmt"
	"sort"
)

func main() {
	var a [5]int
	var r [5]int
	var map = make(map[int]int)

	// Step 2: Reading input and storing remainders
	for i := 0; i < len(a); i++ {
		fmt.Scan(&a[i])
		r[i] = a[i] % 10
		b := 10
		if r[i] != 0 {
			b = 10 - r[i]
			map[b] = a[i]
		}
	}

	// Step 3: Handling edge cases
	if len(map) == 0 {
		var ans int
		for i := 0; i < len(a); i++ {
			ans += a[i]
		}
		fmt.Println(ans)
		return
	}

	// Step 4: Finding the maximum and adjusting values
	var last int
	var idx int
	for i := 0; i < len(a); i++ {
		if a[i] == map[10-r[i]] {
			idx = i
		}
	}
	var ans int
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

