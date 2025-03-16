
package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	arr := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	length := make([]int, n)
	index := 0
	returnDex := 0

	for _, tmp := range arr {
		gIndex := strings.Index(tmp, "G")
		sIndex := strings.Index(tmp, "S")
		if gIndex > sIndex {
			returnDex = -1
		}
		length[index] = sIndex - gIndex
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

