package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod = 1000000007

var (
	dp    [][]int
	S     string
	n     int
)

func init() {
	reader := bufio.NewReader(os.Stdin)
	S, _ = reader.ReadString('\n')
	S = S[:len(S)-1]
	n = len(S)
	if n == 1 {
		if S == "5" || S == "?" {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
		os.Exit(0)
	}
	dp = make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 13)
	}
}

func main() {
	if S[0] != '?' {
		dp[0][int(S[0]-'0')]++
	} else {
		for j := 0; j < 10; j++ {
			dp[0][j]++
		}
	}
	for i := 1; i < n; i++ {
		if S[i] != '?' {
			for k := 0; k < 13; k++ {
				dp[i][(k*10+int(S[i]-'0'))%13] = (dp[i][(k*10+int(S[i]-'0'))%13] + dp[i-1][k]) % mod
			}
		} else {
			for j := 0; j < 10; j++ {
				for k := 0; k < 13; k++ {
					dp[i][(k*10+j)%13] = (dp[i][(k*10+j)%13] + dp[i-1][k]) % mod
				}
			}
		}
		for k := 0; k < 13; k++ {
			dp[i][k] = dp[i][k] % mod
		}
	}
	fmt.Println(dp[n-1][5])
}
