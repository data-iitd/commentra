package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	lst := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lst[i])
	}

	l := make(map[int]int)
	for i := 0; i < n; i++ {
		l[lst[i]]++
	}

	res := 0
	for i := 0; i < n; i++ {
		if l[lst[i]] > 1 {
			res += n - i - l[lst[i]]
			l[lst[i]]--
		} else {
			res += n - i - 1
		}
	}

	fmt.Println(res)
}

// <END-OF-CODE>
