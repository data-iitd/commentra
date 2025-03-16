package main

import (
	"fmt"
	"strings"
)

const M = 1010

var a, b [M]string
var n, m, ans int

func main() {
	fmt.Scan(&a[1])
	n = len(a[1])
	fmt.Scan(&b[1])
	m = len(b[1])
	for i := 1; i+m-1 <= n; i++ {
		sum := 0
		for j := 1; j <= m; j++ {
			if a[1][i+j-1] != b[1][j-1] {
				sum++
			}
		}
		if sum < ans {
			ans = sum
		}
	}
	fmt.Println(ans)
}

