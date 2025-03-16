
package main

import (
	"fmt"
	"os"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	list := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&list[i])
	}
	sort.Ints(list)
	c := 1
	for i := 0; i < n; i++ {
		if list[i] >= c {
			c++
		}
	}
	fmt.Println(c)
}

