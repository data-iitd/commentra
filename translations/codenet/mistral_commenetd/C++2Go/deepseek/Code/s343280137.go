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
		if lefttotal[i]-x[i] > maxlefttotal[i-1] {
			maxlefttotal[i] = lefttotal[i] - x[i]
		} else {
			maxlefttotal[i] = maxlefttotal[i-1]
		}
	}

	righttotal := make([]int, n+1)
	maxrighttotal := make([]int, n+1)
	for i := 1; i <= n; i++ {
		righttotal[i] = righttotal[i-1] + v[n-i+1]
		if righttotal[i]-(c-x[n+1-i]) > maxrighttotal[i-1] {
			maxrighttotal[i] = righttotal[i] - (c - x[n+1-i])
		} else {
			maxrighttotal[i] = maxrighttotal[i-1]
		}
	}

	ans := 0
	for i := 1; i <= n; i++ {
		if lefttotal[i]-x[i] > ans {
			ans = lefttotal[i] - x[i]
		}
		if lefttotal[i]-2*x[i]+maxrighttotal[n-i] > ans {
			ans = lefttotal[i] - 2*x[i] + maxrighttotal[n-i]
		}
		if righttotal[i]-(c-x[n+1-i]) > ans {
			ans = righttotal[i] - (c - x[n+1-i])
		}
		if righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i] > ans {
			ans = righttotal[i] - 2*(c-x[n+1-i]) + maxlefttotal[n-i]
		}
	}

	fmt.Fprintln(writer, ans)
}

