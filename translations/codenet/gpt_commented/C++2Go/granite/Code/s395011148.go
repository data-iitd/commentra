
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	N int64
	A [1 << 18]int64
	dp [1 << 18][2][20]int64
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initial int64 = 1 << 60
	const offset int64 = 10

	if scanner.Scan() {
		N, _ = readInt64(scanner.Bytes())
	}

	for i := int64(1); i <= N; i++ {
		if scanner.Scan() {
			A[i], _ = readInt64(scanner.Bytes())
		}
	}

	for i := int64(0); i <= N; i++ {
		for j := int64(0); j < 20; j++ {
			dp[i][0][j] = -initial
			dp[i][1][j] = -initial
		}
	}

	dp[0][0][offset] = 0

	for i := int64(1); i <= N; i++ {
		for j := int64(6); j <= 14; j++ {
			if dp[i-1][0][j]!= -initial {
				dp[i][1][j+1] = max(dp[i][1][j+1], dp[i-1][0][j]+A[i])
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][0][j])
			}
			if dp[i-1][1][j]!= -initial {
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][1][j])
			}
		}
	}

	V := offset + (N/2) - (N-(N/2))

	T1 := dp[N][0][V]
	T2 := dp[N][1][V]

	fmt.Println(max(T1, T2))
}

func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func readInt64(bytes []byte) (int64, error) {
	result := int64(0)
	sign := 1
	i := 0
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		result = result*10 + int64(bytes[i]-'0')
		i++
	}
	return result * int64(sign), nil
}

