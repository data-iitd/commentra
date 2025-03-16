package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	m := make(map[int]int)
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		if _, ok := m[num]; !ok {
			m[num] = 1
		} else {
			m[num]++
		}
	}
	var ans int
	for _, v := range m {
		ans += v
	}
	fmt.Println(ans)
}

