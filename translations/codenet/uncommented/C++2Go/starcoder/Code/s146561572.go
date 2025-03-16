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
	var t int
	fmt.Fscan(reader, &t)
	for i := 0; i < t; i++ {
		solve()
	}
}

func solve() {
	var n int
	fmt.Fscan(reader, &n)
	ans := 0
	for i := 1; i <= n; i++ {
		ans += i * (n - i + 1)
	}
	for i := 1; i < n; i++ {
		var u, v int
		fmt.Fscan(reader, &u, &v)
		a := max(u, v)
		b := min(u, v)
		ans -= b * (n - a + 1)
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

