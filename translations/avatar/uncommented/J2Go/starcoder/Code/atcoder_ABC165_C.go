package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	a, b, c, d []int
	n, m, q    int
	ans        int64
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d %d\n", &n, &m, &q)
	a = make([]int, q)
	b = make([]int, q)
	c = make([]int, q)
	d = make([]int, q)
	for i := 0; i < q; i++ {
		fmt.Fscanf(reader, "%d %d %d %d\n", &a[i], &b[i], &c[i], &d[i])
	}
	dfs([]int{})
	fmt.Println(ans)
}

func dfs(list []int) {
	if len(list) == n {
		score := int64(0)
		for i := 0; i < q; i++ {
			if list[b[i]]-list[a[i]] == c[i] {
				score += int64(d[i])
			}
		}
		ans = max(ans, score)
		return
	}
	if len(list) > 0 {
		for num := list[len(list)-1]; num <= m; num++ {
			list = append(list, num)
			dfs(list)
			list = list[:len(list)-1]
		}
	} else {
		for num := 1; num <= m; num++ {
			list = append(list, num)
			dfs(list)
			list = list[:len(list)-1]
		}
	}
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

