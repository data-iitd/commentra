
package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	list := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&list[i])
	}

	odd := make([]int, 0)
	sum := 0

	for _, v := range list {
		if v%2 == 0 {
			sum += v
		} else {
			odd = append(odd, v)
		}
	}

	sort.Ints(odd)

	for _, v := range odd {
		sum += v
	}

	if len(odd)%2 != 0 {
		sum -= odd[0]
	}

	fmt.Println(sum)
}

