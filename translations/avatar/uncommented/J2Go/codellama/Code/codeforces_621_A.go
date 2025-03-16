
package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	list := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&list[i])
	}
	odd := make([]int64, 0)
	sum := int64(0)
	for _, i := range list {
		if i%2 == 0 {
			sum += i
		} else {
			odd = append(odd, i)
		}
	}
	sort.Slice(odd, func(i, j int) bool {
		return odd[i] < odd[j]
	})
	for _, i := range odd {
		sum += i
	}
	if len(odd)%2 != 0 {
		sum -= odd[0]
	}
	fmt.Println(sum)
}

