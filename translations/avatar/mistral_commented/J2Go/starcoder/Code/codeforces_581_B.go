
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscanln(reader, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanln(reader, &a[i])
	}

	dp := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		dp[i] = a[i]
		if i < n-1 && dp[i+1] > a[i] {
			dp[i] = dp[i+1]
		}
	}

	for i := 0; i < n; i++ {
		if a[i] > dp[i+1] {
			fmt.Fprintln(writer, 0)
		} else {
			fmt.Fprintln(writer, dp[i+1]-a[i]+1)
		}
	}
}

