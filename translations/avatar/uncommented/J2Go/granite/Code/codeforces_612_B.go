
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	s := bufio.NewScanner(os.Stdin)
	s.Split(bufio.ScanWords)
	s.Scan()
	n := int(s.Int64())
	dp := make([]int, 200001)
	for i := 0; i < n; i++ {
		s.Scan()
		dp[int(s.Int64())] = i
	}
	ans := int64(0)
	for i := 2; i <= n; i++ {
		ans += int64(abs(dp[i]-dp[i-1]))
	}
	fmt.Println(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

