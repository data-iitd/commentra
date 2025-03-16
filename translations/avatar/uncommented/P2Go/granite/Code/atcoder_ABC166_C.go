
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
	fmt.Fscanf(reader, "%d %d\n", &n, &m)
	p := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &p[i])
	}
	h := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &h[i])
	}
	hp := make(map[int]int)
	for i := 0; i < n; i++ {
		hp[p[i]] = h[i]
	}
	path := make(map[int][]int)
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Fscanf(reader, "%d %d\n", &a, &b)
		path[a] = append(path[a], b)
		path[b] = append(path[b], a)
	}
	c := 0
	for i, v := range path {
		f := 0
		for _, j := range v {
			if hp[i] <= hp[j] {
				f = 1
				break
			}
		}
		if f == 0 {
			c++
		}
	}
	fmt.Println(c)
}
