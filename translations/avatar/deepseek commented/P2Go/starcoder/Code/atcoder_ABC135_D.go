package main
import "fmt"

func main() {
	// Read input string
	var S string
	fmt.Scanf("%s", &S)
	// Get length of the string
	n := len(S)
	// Initialize dp array
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 13)
	}
	// Base case for the first character
	if S[0]!= '?' {
		dp[0][int(S[0])]++
	} else {
		for j := 0; j < 10; j++ {
			dp[0][j]++
		}
	}
	// General case for subsequent characters
	for i := 1; i < n; i++ {
		if S[i]!= '?' {
			for k := 0; k < 13; k++ {
				dp[i][(k*10+int(S[i]))%13] += dp[i-1][k]
			}
		} else {
			for j := 0; j < 10; j++ {
				for k := 0; k < 13; k++ {
					dp[i][(k*10+j)%13] += dp[i-1][k]
				}
			}
		}
		for k := 0; k < 13; k++ {
			dp[i][k] %= 1000000007
		}
	}
	// Print the result
	fmt.Println(dp[n-1][5])
}

