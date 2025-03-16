package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var set sort.IntSlice

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	in.Scan()
	fmt.Sscan(in.Text(), &n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		in.Scan()
		fmt.Sscan(in.Text(), &a[i])
	}

	dp := make([]int64, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = -1
	}
	dp[n-1] = a[n-1]

	for i := n - 1; i >= 0; i-- {
		if dp[i+1] > a[i] {
			dp[i] = dp[i+1]
		} else {
			dp[i] = a[i]
		}
	}

	for i := 0; i < n; i++ {
		if a[i] > dp[i+1] {
			fmt.Fprint(out, 0, " ")
		} else {
			fmt.Fprint(out, dp[i+1]-a[i]+1, " ")
		}
	}
	fmt.Fprintln(out)

	set = make(sort.IntSlice, 0)

	// Debugging the array elements
	for _, v := range a {
		set = append(set, int(v))
	}
	fmt.Println(set)
}

