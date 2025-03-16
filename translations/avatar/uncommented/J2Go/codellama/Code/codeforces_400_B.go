
package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	arrs := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arrs[i])
	}
	length := make([]int, n)
	index := 0
	returnDex := 0
	for _, tmp := range arrs {
		dexG := strings.Index(tmp, "G")
		dexS := strings.Index(tmp, "S")
		if dexG > dexS {
			returnDex = -1
		}
		length[index] = dexS - dexG
		index++
	}
	set := make(map[int]bool)
	for _, len := range length {
		set[len] = true
	}
	if returnDex == -1 {
		fmt.Println(returnDex)
	} else {
		fmt.Println(len(set))
	}
}

