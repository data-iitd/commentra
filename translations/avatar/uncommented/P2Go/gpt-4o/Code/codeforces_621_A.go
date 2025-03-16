package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	lst := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lst[i])
	}

	sort.Sort(sort.Reverse(sort.IntSlice(lst)))

	od := 0
	for _, i := range lst {
		if i%2 != 0 {
			od++
		}
	}

	sum := 0
	ok := false
	for i := 0; i < n; i++ {
		if lst[i]%2 == 0 {
			sum += lst[i]
		} else {
			if ok || od > 1 {
				sum += lst[i]
				od--
				ok = !ok
			}
		}
	}

	fmt.Println(sum)
}

// <END-OF-CODE>
