
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
	var s string
	fmt.Scan(&s)
	for _, v := range strings.Split(s, " ") {
		i, _ := strconv.Atoi(v)
		lst = append(lst, i)
	}
	for i := 0; i < len(lst); i++ {
		if lst[i]%2 == 0 {
			lst[i] = lst[i] + lst[i]
		}
	}
	for i := 0; i < len(lst); i++ {
		if lst[i]%2 == 1 {
			lst[i] = lst[i] + lst[i]
		}
	}
	fmt.Println(lst)
}

