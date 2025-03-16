
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

	var n, k int
	fmt.Fscanf(reader, "%d %d\n", &n, &k)

	l := make([]int, n+1)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &l[i])
	}

	path := []int{1}
	ind := 0
	count := 0
	x := 1
	t := -1
	flag := false
	hash := make(map[int]int)
	for i := 0; i <= n; i++ {
		ne := l[x-1]
		if hash[ne] > 0 {
			flag = true
			t = hash[ne]
			break
		}
		path = append(path, ne)
		ind++
		hash[ne] = ind
		x = ne
	}
	if flag {
		loop := path[t-1:]
		if k < len(path) {
			fmt.Println(path[k-1])
		} else {
			k = k - len(path)
			k = k % len(loop)
			fmt.Println(loop[k-1])
		}
	} else {
		fmt.Println(path[k-1])
	}
}
