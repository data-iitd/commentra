
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
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the three integers representing the array elements")
	a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	b, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	c, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	arr := []int{a, b, c}
	maxn := 4010
	dp := make([]int, maxn)
	for i := 0; i < n; i++ {
		dp[i] = -1
	}
	dp[0] = 0
	for i := 0; i < 3; i++ {
		for j := arr[i]; j < maxn; j++ {
			if dp[j] < dp[j-arr[i]]+1 {
				dp[j] = dp[j-arr[i]] + 1
			}
		}
	}
	fmt.Println(dp[n])
}

