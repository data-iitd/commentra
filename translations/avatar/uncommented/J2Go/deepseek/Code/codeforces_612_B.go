package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	
	var n int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)
	
	dp := make([]int, 200001)
	for i := 0; i < n; i++ {
		scanner.Scan()
		val := 0
		fmt.Sscan(scanner.Text(), &val)
		dp[val] = i
	}
	
	var ans int64 = 0
	for i := 2; i <= n; i++ {
		ans += int64(math.Abs(float64(dp[i] - dp[i-1])))
	}
	fmt.Println(ans)
}
