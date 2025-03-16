package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, c int
	fmt.Fscan(reader, &n, &c)

	x := make([]int, n+1)
	v := make([]int, n+1)

	for i := 1; i <= n; i++ {
		fmt.Fscan(reader, &x[i], &v[i])
	}

	lefttotal := make([]int, n+1)
	maxlefttotal := make([]int, n+1)
	for i := 1; i <= n; i++ {
		lefttotal[i] = lefttotal[i-1] + v[i]
	}

	for i := 1; i <= n; i++ {
		maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i]-x[i])
	}

	righttotal := make([]int, n+1)
	maxrighttotal := make([]int, n+1)
	for i := 1; i <= n; i++ {
		righttotal[i] = righttotal[i-1] + v[n-i+1]
	}

	for i := 1; i <= n; i++ {
		maxrighttotal[i] = max(maxrighttotal[i-1], righttotal[i]-(c-x[n+1-i]))
	}

	ans := 0

	for i := 1; i <= n; i++ {
		ans = max(ans, lefttotal[i]-x[i])
		ans = max(ans, lefttotal[i]-2*x[i]+maxrighttotal[n-i])
		ans = max(ans, righttotal[i]-(c-x[n+1-i]))
		ans = max(ans, righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i])
	}

	fmt.Fprintln(writer, ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

