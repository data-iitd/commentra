
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, b int
	fmt.Fscanf(reader, "%d %d\n", &n, &b)
	ans := make([]int64, n)
	q := make([]int64, 0)
	for i := 0; i < n; i++ {
		var t, d int
		fmt.Fscanf(reader, "%d %d\n", &t, &d)
		for len(q) > 0 && q[0] <= int64(t) {
			q = q[1:]
		}
		if len(q) <= b {
			ans[i] = (int64(t) + int64(d))
			if len(q) > 0 {
				ans[i] = int64(max(int(q[len(q)-1]), int(t+d)))
			}
			q = append(q, ans[i])
		} else {
			ans[i] = -1
		}
	}
	for i := 0; i < n; i++ {
		fmt.Printf("%d ", ans[i])
	}
	fmt.Println()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

