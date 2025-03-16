package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	S := input[:len(input)-1]
	n := len(S)

	if n == 1 {
		if S == "5" || S == "?" {
			fmt.Println(1)
		} else {
			fmt.Println(0)
			return
		}
	}

	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 13)
	}

	for i := 0; i < n; i++ {
		if i == 0 {
			if S[i] != '?' {
				dp[i][int(S[i]-'0')]++
			} else {
				for j := 0; j < 10; j++ {
					dp[i][j]++
				}
			}
		} else {
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
		}
	}

	fmt.Println(dp[n-1][5])
}
