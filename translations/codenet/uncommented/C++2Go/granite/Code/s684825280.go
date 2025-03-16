
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const SIZE = (1e5 * 2) + 13

var a []int
var cnt [SIZE]int

func main() {
	var n, k int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d\n", &n, &k)
	for i := 0; i < n; i++ {
		var x int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &x)
		cnt[x]++
	}
	for i := 0; i < SIZE; i++ {
		if cnt[i] > 0 {
			a = append(a, cnt[i])
		}
	}
	sort.Ints(a)
	m := len(a) - k
	ans := 0
	for i := 0; i < m; i++ {
		ans += a[i]
	}
	fmt.Println(ans)
}
