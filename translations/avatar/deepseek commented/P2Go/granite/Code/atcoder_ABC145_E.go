
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	TIME = 0
	VAL  = 1
)

func main() {
	// Reading Input: The code starts by reading the number of items N and the maximum time T.
	reader := bufio.NewReader(os.Stdin)
	n, t := readTwoNums(reader)

	// Initializing Data Structures: It initializes a list time_value to store the time and value of each item, with a placeholder at index 0.
	time_value := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		time_value[i] = make([]int, 2)
	}
	time_value[0][TIME] = -1
	time_value[0][VAL] = -1

	// Reading Item Details: It reads the time and value for each item and stores them in time_value.
	for i := 1; i <= n; i++ {
		time_value[i][TIME], time_value[i][VAL] = readTwoNums(reader)
	}

	// Sorting Items: The items are sorted based on their value.
	sortItems(time_value)

	// Dynamic Programming Table Initialization: A 2D list dp is initialized to store the maximum value that can be achieved with a given number of items and time.
	dp := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, t+1)
	}

	// Base Cases for DP Table: The base cases are set where no time means no value.
	for i := 0; i <= n; i++ {
		dp[i][0] = 0
	}
	for j := 1; j <= t; j++ {
		dp[0][j] = 0
	}

	for n := 1; n <= N; n++ {
		dp[n][0] = 0
		for t := 1; t <= T; t++ {
			if time_value[n][TIME] > t {
				dp[n][t] = dp[n-1][t]
			} else {
				dp[n][t] = max(dp[n-1][t], time_value[n][VAL]+dp[n-1][t-time_value[n][TIME]])
			}
		}
	}

	// Calculating Maximum Value: The maximum value is calculated by considering the last item and reducing the time accordingly.
	val_acum := time_value[n][VAL]
	t := T - 1
	max_val := val_acum + dp[n-1][t]

	for n := n - 1; n > 0; n-- {
		val_acum += time_value[n][VAL]
		t -= time_value[n+1][TIME]
		if t < 0 {
			break
		} else {
			max_val = max(max_val, val_acum+dp[n-1][t])
		}
	}

	// Printing Result: The final maximum value is printed.
	fmt.Println(max_val)
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readOneNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func sortItems(items [][]int) {
	sort.Slice(items, func(i, j int) bool {
		return items[i][VAL] > items[j][VAL]
	})
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func min(a, b int) int {
	return a + b - max(a, b)
}