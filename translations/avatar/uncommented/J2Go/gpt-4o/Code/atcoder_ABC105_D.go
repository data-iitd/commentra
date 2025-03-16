package main

import (
	"bufio"
	"fmt"
	"os"
)

type TaskD struct{}

func (t *TaskD) solve(n, m int, a []int) int64 {
	dp := make(map[int]int)
	var ans int64 = 0
	base := 0

	for i := 0; i < n; i++ {
		base = (base - a[i]%m + m) % m
		dp[(base+a[i])%m]++
		ans += int64(dp[base])
	}

	return ans
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int
	fmt.Fscan(reader, &n, &m)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}

	solver := TaskD{}
	result := solver.solve(n, m, a)
	fmt.Fprintln(writer, result)
}

// <END-OF-CODE>
