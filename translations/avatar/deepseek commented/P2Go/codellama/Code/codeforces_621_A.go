
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	var lst []int
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		lst = append(lst, num)
	}
	sort.Ints(lst)
	sort.Sort(sort.Reverse(sort.IntSlice(lst)))

	var od int
	for _, v := range lst {
		if v%2 != 0 {
			od++
		}
	}

	var sum int
	var ok bool
	for i, v := range lst {
		if v%2 == 0 {
			sum += v
		} else {
			if ok || od > 1 {
				sum += v
				od--
				ok = !ok
			}
		}
	}
	fmt.Println(sum)
}

// 