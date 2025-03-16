
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Fscanln(reader, &n, &m)
	fa := make([]int, n+1)
	v := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fa[i] = i
	}
	for i := 0; i < m; i++ {
		var l, r, vi int
		fmt.Fscanln(reader, &l, &r, &vi)
		li := get(l, fa)
		ri := get(r, fa)
		if li!= ri {
			v[ri] = vi - v[r] + v[l]
			fa[ri] = li
		} else {
			if v[r]-v[l]!= vi {
				fmt.Println("No")
				return
			}
		}
	}
	fmt.Println("Yes")
}

func get(x int, fa []int) int {
	if x == fa[x] {
		return x
	}
	f := get(fa[x], fa)
	v[x] += v[fa[x]]
	return fa[x] = f
}

