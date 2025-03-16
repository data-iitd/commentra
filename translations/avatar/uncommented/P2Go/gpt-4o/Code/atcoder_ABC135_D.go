package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 1e9 + 7

func main() {
	reader := bufio.NewReader(os.Stdin)
	S, _ := reader.ReadString('\n')
	S = S[:len(S)-1] // Remove the newline character
	n := len(S)

	if n == 1 {
		if S == "5" || S == "?" {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
		return
	}

	dp := make([][13]int, n)

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
					dp[i][(k*10+int(S[i]-'0'))%13] += dp[i-1][k]
					dp[i][(k*10+int(S[i]-'0'))%13] %= mod
				}
			} else {
				for j := 0; j < 10; j++ {
					for k := 0; k < 13; k++ {
						dp[i][(k*10+j)%13] += dp[i-1][k]
						dp[i][(k*10+j)%13] %= mod
					}
				}
			}
		}
	}

	fmt.Println(dp[n-1][5])
}

// <END-OF-CODE>
