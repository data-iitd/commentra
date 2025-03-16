
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	r := make([]int, n)
	for i := 0; i < n; i++ {
		r[i], _ = strconv.Atoi(strings.Split(fmt.Scanln(), " ")[i])
	}
	ans := abs(r[0])
	for i := 1; i < n; i++ {
		ans += abs(r[i] - r[i-1])
	}
	fmt.Println(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

