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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	dp := make([]int, 200001)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		dp[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	ans := 0
	for i := 2; i <= n; i++ {
		ans += abs(dp[i] - dp[i-1])
	}
	fmt.Println(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

