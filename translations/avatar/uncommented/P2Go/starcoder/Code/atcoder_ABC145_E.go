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
	fmt.Println("Enter the number of elements in the array:")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the number of elements in the array:")
	t, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	time_value := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		time_value[i] = make([]int, 2)
	}
	fmt.Println("Enter the elements of the array:")
	for i := 1; i < n+1; i++ {
		time_value[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	sort.Slice(time_value[1:], func(i, j int) bool {
		return time_value[i+1][1] < time_value[j+1][1]
	})
	dp := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]int, t+1)
	}
	for i := 0; i < n+1; i++ {
		dp[i][0] = 0
	}
	for i := 1; i < n+1; i++ {
		dp[i][0] = 0
		for j := 1; j < t+1; j++ {
			if time_value[i][0] > j {
				dp[i][j] = dp[i-1][j]
			} else {
				dp[i][j] = max(dp[i-1][j], time_value[i][1]+dp[i-1][j-time_value[i][0]])
			}
		}
	}
	val_acum := time_value[n][1]
	t := t - 1
	max_val := val_acum + dp[n-1][t]
	for i := n - 1; i > 0; i-- {
		val_acum += time_value[i][1]
		t -= time_value[i+1][0]
		if t < 0 {
			break
		} else {
			max_val = max(max_val, val_acum+dp[i-1][t])
		}
	}
	fmt.Println(max_val)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

