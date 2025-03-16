
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const maxn = 200000 + 10
const INF = int(1e8)

var (
	n, m int
	maps  [maxn]int
	num   [maxn]int
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &n)
	for i := 1; i <= n; i++ {
		fmt.Fscanf(reader, "%d", &maps[i])
		num[i] = maps[i]
	}
	sort.Ints(maps[1 : n+1])
	m = n / 2
	for i := 1; i <= n; i++ {
		if num[i] <= maps[m] {
			fmt.Println(maps[m+1])
		} else {
			fmt.Println(maps[m])
		}
	}
}

