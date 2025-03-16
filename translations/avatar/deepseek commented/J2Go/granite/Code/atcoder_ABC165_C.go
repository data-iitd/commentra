
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	a, b, c, d []int
	n, m, q    int
	ans         int64 = -1000000000
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	buf := make([]byte, 0)
	sc.Buffer(buf, 1010000)
	sc.Split(bufio.ScanWords)

	n, m, q = nextInt(sc), nextInt(sc), nextInt(sc)
	a = make([]int, q)
	b = make([]int, q)
	c = make([]int, q)
	d = make([]int, q)
	for i := 0; i < q; i++ {
		a[i], b[i], c[i], d[i] = nextInt(sc), nextInt(sc), nextInt(sc), nextInt(sc)
	}
	dfs(make([]int, 0))
	fmt.Println(ans)
}

func dfs(list []int) {
	if len(list) == n {
		var score int64
		for i := 0; i < q; i++ {
			if list[b[i]-1]-list[a[i]-1] == c[i] {
				score += int64(d[i])
			}
		}
		if ans < score {
			ans = score
		}
		return
	}
	if len(list)!= 0 {
		for i := list[len(list)-1]; i <= m; i++ {
			list = append(list, i)
			dfs(list)
			list = list[:len(list)-1]
		}
	} else {
		for i := 1; i <= m; i++ {
			list = append(list, i)
			dfs(list)
			list = list[:len(list)-1]
		}
	}
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

