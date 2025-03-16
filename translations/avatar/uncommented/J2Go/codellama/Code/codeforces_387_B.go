
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, m int
	var req, pre []int
	var ans int
	var i, j int

	fmt.Scan(&n, &m)
	req = make([]int, n)
	pre = make([]int, m)
	for i = 0; i < n; i++ {
		req[i], _ = strconv.Atoi(os.Args[i+1])
	}
	for j = 0; j < m; j++ {
		pre[j], _ = strconv.Atoi(os.Args[j+1])
	}
	i = n - 1
	j = m - 1
	for i >= 0 && j >= 0 {
		if req[i] > pre[j] {
			ans++
		} else {
			j--
		}
		i--
	}
	fmt.Println(ans + i + 1)
}

